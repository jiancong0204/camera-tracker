/**
* @file Chessboard.h
* 
* @brief This file contains the declaration of the Chessboard class.
* 
* 
* @author Jiancong Zheng 
* @date 2020-05-29
* 
*/

#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

/**
* @class Chessboard
* @brief Creation of chessboard.
*
* This class wraps the creation of a chessboard.
**/
class Chessboard
{
public:
    /**
    * @brief Constructor of Chessboard class.
    * 
    * @param width Width of the chessboard.
    * @param height Height of the chessboard.
    * @param size Side length of each block.
    **/
    Chessboard(int width, int height, float size);

    /**
    * @brief Deconstructor of Chessboard class.
    **/
    ~Chessboard() {};

    /**
    * @brief Function used to obtain the width of the chessboard (number of the blocks).
    **/
    int getWidth();

    /**
    * @brief Function uesd to obtain the height of the chessboard (number of the blocks).
    **/
    int getHeight();

    /**
    * @brief Function used to obtain the size of the block (mm).
    **/
    float getSize();

    /**
    * @brief Function used to get the coordinates of all the corners.
    * 
    * @return A vector of three-dimensional points. 
    **/
    std::vector<cv::Point3f> getGrid();

private:
    std::vector<cv::Point3f>    grid;     /**< The coordinates of all the corners in the chessboard. */
    int                         width;    /**< The width of the chessboard (number of the blocks). */
    int                         height;   /**< The height of the chessboard (number of the blocks). */
    float                       size;     /**< The size of the block. */
    
    /**
    * @brief Function that estimates the coordinates of each corners.
    *
    * @return A vector of three-dimensional points.
    **/
    std::vector<cv::Point3f> _computeGrid();
};