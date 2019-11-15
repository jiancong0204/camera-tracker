%module BaslerCamLib

%include "std_string.i"
%include "typemaps.i"
%include "std_vector.i"
%include "exception.i"
%include "opencv.i"
%cv_instantiate_all_defaults

%include BaslerGigECamera.i
%include BaslerUSBCamera.i

namespace std
{
  %template(StrVector) vector<std::string>;
}

%exception {
 try {
    $action
  } catch (std::exception &e) {
	SWIG_exception(SWIG_RuntimeError, const_cast<char*>(e.what()));
  }
}

