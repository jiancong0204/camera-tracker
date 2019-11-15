/** @file utils.cpp
* @brief Implemention of common used utility functions.
*
* @author Matthias Bodenbenner
* @date 27.04.2017
*/

//#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "constants.h"
#include "utils.h"

void utils::resize(const cv::Mat& src, cv::Mat& dst, int max_axis)
{
	// cout << "src:" << endl << src << endl;
	int height = src.rows;
	int width = src.cols;
	//cout << "height: " << height << endl;
	//cout << "width: " << width << endl;

	//if (height > max_axis || width > max_axis)
	//{
	double factor;
	if (height > width)
	{
		factor = max_axis / double(height);
	}
	else
	{
		factor = max_axis / double(width);
	}
	resize(src, dst, cv::Size(), factor, factor, CV_INTER_LANCZOS4);
	//}
}

void utils::resize(const cv::Rect& src, cv::Rect& dst, int max_axis)
{
	double factor;
	if (src.height > src.width)
	{
		factor = max_axis / double(src.height);
	}
	else
	{
		factor = max_axis / double(src.width);
	}
	dst = src;
	dst.height *= factor;
	dst.width *= factor;
}

void utils::resize(const cv::Mat& src, cv::Mat& dst, double factor)
{
	resize(src, dst, cv::Size(), factor, factor, CV_INTER_LANCZOS4);
}

void utils::resize(const cv::Mat& src, cv::Mat& dst, int length, int axis)
{
	// cout << "src:" << endl << src << endl;
	int height = src.rows;
	int width = src.cols;
	//cout << "height: " << height << endl;
	//cout << "width: " << width << endl;

	double factor;
	if (axis == 0)
	{
		factor = length / double(width);
	}
	else if (axis == 1)
	{
		factor = length / double(height);
	}
	else
	{
		throw std::exception("Axis does not exist!");
	}
	resize(src, dst, cv::Size(), factor, factor, CV_INTER_LANCZOS4);
}

void utils::rotate(const cv::Mat& src, cv::Mat& dst, int angle)
{
	int width = src.cols;
	int height = src.rows;
	double radiant_angle = angle * PI / 180.;

	// calculate new image width and height
	int new_width = abs(sin(radiant_angle) * height) + abs(cos(radiant_angle) * width);
	int new_height = abs(cos(radiant_angle) * height) + abs(sin(radiant_angle) * width);

	// ask OpenCV for the rotation cv::Matrix
	cv::Mat rot_mat = cv::getRotationMatrix2D(cv::Point2f(new_width * 0.5, new_height * 0.5), angle, 1);

	// calculate the move from the old center to the new center combined with the rotation
	double arr[3] = {(new_width - width) * 0.5, (new_height - height) * 0.5, 0};
	cv::Mat help_mat = cv::Mat(3, 1, CV_64F, &arr);
	//cout << "help_mat: " << help_mat << endl;
	//cout << "rot_mat: " << rot_mat << endl;
	cv::Mat rot_move = rot_mat * help_mat;
	//cout << "rot_move: " << rot_move << endl;

	// the move only affects the translation, so update the translation part of the transform
	rot_mat.at<double>(0, 2) += rot_move.at<double>(0);
	rot_mat.at<double>(1, 2) += rot_move.at<double>(1);
	warpAffine(src, dst, rot_mat, cv::Size(ceil(new_width), ceil(new_height)), CV_INTER_LANCZOS4);
	//cout << "dst.size(): " << dst->size() << endl;
}

/*
 * Performs edge detection and cuts the image to the corners of the contour
 */
bool utils::autocut(const cv::Mat& src, cv::Mat& dst, cv::Rect& rect)
{
	cv::Mat edges;
	Canny(src, edges, CANNY_MIN_THRESHOLD, CANNY_MAX_THRESHOLD);

	DSHOW("Edges", edges, MAX_IMAGE_AXIS);

	std::vector<cv::Point> non_zero_pixels;
	findNonZero(edges, non_zero_pixels);
	if (non_zero_pixels.empty())
	{
		rect = cv::Rect(0, 0, src.cols, src.rows);
		return false;
	}

	int min_x = src.cols;
	int min_y = src.rows;
	int max_x = 0;
	int max_y = 0;
	for (auto it = non_zero_pixels.begin(); it != non_zero_pixels.end(); ++it)
	{
		min_x = (it->x < min_x) ? it->x : min_x;
		min_y = (it->y < min_y) ? it->y : min_y;
		max_x = (it->x > max_x) ? it->x : max_x;
		max_y = (it->y > max_y) ? it->y : max_y;
	}
	//	cout << "min_x: " << min_x << ", max_x: " << max_x << endl;
	//	cout << "min_y: " << min_y << ", max_y: " << max_y << endl;

	int height = max_y - min_y;
	int width = max_x - min_x;
	rect = cv::Rect(min_x, min_y, width, height);
	//	cout << "rect: " << rect << endl;
	//	cout << "image size: " << src.size() << endl;
	dst = src(rect);

	return true;
}

void utils::showImage(const char* window_name, cv::Mat& image, int size)
{
	cv::Mat help;
	if (MAX(image.cols, image.rows) > size)
		utils::resize(image, help, size, 0);
	else
		help = image;
	imshow(window_name, help);
	cv::moveWindow(window_name, 1500, 200);
	cv::waitKey(50);
}

void utils::showStereoImage(const char* window_name, std::vector<cv::Mat>& images, int size)
{
	assert(images.size() == 2); // TODO hacky

	cv::Mat img = cv::Mat::zeros(images[0].rows, images[0].cols + images[1].cols,CV_32FC3);
	hconcat(images[0], images[1], img);
	line(img, cv::Point2i(images[0].cols, 0), cv::Point2i(images[0].cols, images[0].rows), cv::Scalar(255, 0, 0), 2);
	if (MAX(img.cols, img.rows) > size)
		utils::resize(img, img, size, 0);
	else
		img = img;
	imshow(window_name, img);
	cv::moveWindow(window_name, 0, 200);
	cv::waitKey();
}

void utils::showCombinedImages(const char* window_name, std::vector<cv::Mat>& images, int size)
{
	std::vector<cv::Mat> imgs(2);
	imgs[0] = images[0];
	for (int i = 1; i < images.size(); ++i)
	{
		// check dimensions
		if (images[i].rows < imgs[0].rows)
		{
			imgs[0] = imgs[0](cv::Range(0, images[i].rows), cv::Range(0, imgs[0].cols));
		}
		else if (images[i].rows > imgs[0].rows)
		{
			images[i] = images[i](cv::Range(0, imgs[0].rows), cv::Range(0, images[i].cols));
		}

		imgs[1] = cv::Mat::zeros(imgs[0].rows, imgs[0].cols + images[i].cols, CV_32FC3);
		hconcat(imgs[0], images[i], imgs[1]);
		line(imgs[1], cv::Point2i(imgs[0].cols, 0), cv::Point2i(imgs[0].cols, imgs[0].rows), cv::Scalar(255, 0, 0), 2);
		imgs[1].copyTo(imgs[0]);
	}

	if (MAX(imgs[0].cols, imgs[0].rows) > size)
		utils::resize(imgs[0], imgs[0], size, 0);
	imshow(window_name, imgs[0]);
	cv::moveWindow(window_name, 0, 200);
	cv::waitKey();
}

void utils::showStereoImage(const char* window_name, const cv::Mat& left_image, const cv::Mat& right_image, int size)
{
	cv::Mat img = cv::Mat::zeros(left_image.rows, left_image.cols + right_image.cols, CV_32FC3);
	hconcat(left_image, right_image, img);
	line(img, cv::Point2i(left_image.cols, 0), cv::Point2i(left_image.cols, left_image.rows), cv::Scalar(255, 0, 0), 2);
	if (MAX(img.cols, img.rows) > size)
		utils::resize(img, img, size, 0);
	else
		img = img;
	imshow(window_name, img);
	cv::moveWindow(window_name, 0, 200);
	cv::waitKey();
}

int utils::min_size(cv::Size size)
{
	int h = size.height;
	int w = size.width;

	if (h < w)
	{
		return h;
	}
	return w;
}

int utils::max_size(cv::Size size)
{
	int h = size.height;
	int w = size.width;

	if (h > w)
	{
		return h;
	}
	return w;
}

void utils::getCoordinates(const std::vector<cv::KeyPoint>& src, std::vector<cv::Point2f>& dst)
{
	dst.clear();
	for (auto it = src.begin(); it != src.end(); ++it)
	{
		dst.push_back(cv::Point2f(it->pt));
	}
}

cv::Mat utils::PointToMat(const cv::Point3f& point)
{
	cv::Mat res(3, 1, CV_64F);
	res.at<double>(0, 0) = double(point.x);
	res.at<double>(1, 0) = double(point.y);
	res.at<double>(2, 0) = double(point.z);
	return res;
}

cv::Point3f utils::MatToPoint(const cv::Mat& mat)
{
	assert((mat.type() == CV_64F || mat.type() == CV_32F) && mat.rows == 3 && mat.cols == 1);
	cv::Point3f res;
	if(mat.type() == CV_64F)
	{
		res.x = mat.at<double>(0, 0);
		res.y = mat.at<double>(1, 0);
		res.z = mat.at<double>(2, 0);
	} else
	{
		res.x = mat.at<float>(0, 0);
		res.y = mat.at<float>(1, 0);
		res.z = mat.at<float>(2, 0);
	}
	return res;
}

void utils::crossproductMatrix(const cv::Mat& src, cv::Mat& dst)
{
	assert(src.rows == 3 && src.cols == 1 && src.type() == CV_64F);
	dst = cv::Mat::zeros(3, 3, CV_64F);
	dst.at<double>(0, 1) = -src.at<double>(2, 0);
	dst.at<double>(0, 2) = src.at<double>(1, 0);
	dst.at<double>(1, 0) = src.at<double>(2, 0);
	dst.at<double>(1, 2) = -src.at<double>(0, 0);
	dst.at<double>(2, 0) = -src.at<double>(1, 0);
	dst.at<double>(2, 1) = src.at<double>(0, 0);
}

void utils::convertPointsToHomogeneous(const cv::Mat& src, cv::Mat& dst)
{
	dst = cv::Mat::ones(src.rows + 1, src.cols, src.type());
	src.copyTo(dst.rowRange(0, src.rows));
}

void utils::convertPointsFromHomogeneous(const cv::Mat& src, cv::Mat& dst)
{
	assert(src.type() == CV_32F || src.type() == CV_64F);
	//	cout << "src: " << src << endl;
	//	cout << "src.type(): " << utils::cvMatTypeToString(src.type()) << endl;

	cv::Mat help;
	src.copyTo(help);
	for (int c = 0; c < help.cols; ++c)
	{
		switch (src.type())
		{
		case CV_32F:
			help.at<float>(0, c) /= help.at<float>(3, c);
			help.at<float>(1, c) /= help.at<float>(3, c);
			help.at<float>(2, c) /= help.at<float>(3, c);
			break;
		case CV_64F:
			help.at<double>(0, c) /= help.at<double>(3, c);
			help.at<double>(1, c) /= help.at<double>(3, c);
			help.at<double>(2, c) /= help.at<double>(3, c);
			break;
		default:
			break;
		}
	}
	help.rowRange(0, 3).copyTo(dst);
	//	cout << "dst: " << dst << endl;
}

bool utils::intersection(cv::Point2f p1, cv::Point2f p2, cv::Point2f q1, cv::Point2f q2,
	cv::Point2f& r)
{
	cv::Point2f x = q1 - p1;
	cv::Point2f op = p2 - p1;
	cv::Point2f oq = q2 - q1;

	float cross = op.x * oq.y - op.y * oq.x;
	if (abs(cross) < /*EPS*/1e-8)
		return false;

	double t1 = (x.x * oq.y - x.y * oq.x) / cross;
	r = p1 + op * t1;
	r.x = round(r.x);
	r.y = round(r.y);

	// Mathematically not entirely correct
	if (r.x >= MIN(p1.x,p2.x) && r.x <= MAX(p1.x, p2.x) &&
		r.x >= MIN(q1.x, q2.x) && r.x <= MAX(q1.x, q2.x) &&
		r.y >= MIN(p1.y, p2.y) && r.y <= MAX(p1.y, p2.y) &&
		r.y >= MIN(q1.y, q2.y) && r.y <= MAX(q1.y, q2.y))
		return true;

	return false;
}

void utils::PointsOnLine(cv::Vec4f& line, cv::Point2f& p1, cv::Point2f& p2, int length)
{
	cv::Point2f o(line[0], line[1]);
	p1.x = line[2] - o.x * (length / 2) ,
		p1.y = line[3] - o.y * (length / 2);
	p2.x = line[2] + o.x * (length / 2);
	p2.y = line[3] + o.y * (length / 2);
}

void utils::computeDistanceMatrix(std::vector<cv::KeyPoint>& keypoints, cv::Mat& dist_mat)
{
	int nr_keypoints = keypoints.size();
	dist_mat = cv::Mat::zeros(nr_keypoints, nr_keypoints, CV_32F);

	for (int i = 0; i < nr_keypoints; ++i)
		for (int k = i; k < nr_keypoints; ++k)
		{
			dist_mat.at<float>(i, k) = norm(keypoints[i].pt - keypoints[k].pt);
			dist_mat.at<float>(k, i) = norm(keypoints[i].pt - keypoints[k].pt);
		}
	//	DOUT("utils::computeDistanceMatrix - " << "dist_mat[0]: " << dist_mat.row(0) << endl)
}

cv::Point3f utils::computeCenter(const std::vector<cv::Point3f>& pts)
{
	if (!pts.empty()) {
		cv::Mat c;
		reduce(pts, c, 1, CV_REDUCE_AVG);
		return cv::Point3f(c.at<float>(0, 0), c.at<float>(0, 1), c.at<float>(0,2));
	}
	return cv::Point3f(-1, -1, -1);
}

cv::Point3f utils::split(const std::string& str, const char delim)
{
	std::vector<std::string> v;
	auto i = 0;
	auto pos = str.find(delim);
	while (pos != std::string::npos) {
		v.push_back(str.substr(i, pos - i));


		i = ++pos;
		pos = str.find(delim, pos);

		if (pos == std::string::npos)
			v.push_back(str.substr(i, str.length()));
	}

	return cv::Point3f(std::stof(v[0]), std::stof(v[1]), std::stof(v[2]));
}

cv::Point2f utils::computeCenter(const std::vector<cv::Point2f>& pts)
{
	if (!pts.empty()) {
		cv::Mat c;
		reduce(pts, c, 1, CV_REDUCE_AVG);
		return cv::Point2f(c.at<float>(0, 0), c.at<float>(0, 1));
	}
	return cv::Point2f(-1, -1);
}
