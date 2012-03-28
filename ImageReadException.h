///
/// File: ImageReadException.h  An exception to be called whenever an image 
///		cannot be read
///
/// @author Nikko Schaff
///
/// //////////////////////////////////////////////////////////////////////

#ifndef IMAGEREADEXCEPTION_H_
#define IMAGEREADEXCEPTION_H_

#include < iostream >
#include < exception >
#include < string >

/**
 * ImageReadException - Exception thrown when image cannot be read
 *
 */
class ImageReadException: public std::exception {

	/**
	 * what - Message displayed when image cannot be read
	 * @return char*	The message displayed expanding on the exception's problem
	 */
	virtual const char* what() const throw() {
		return "Error reading image. Check to see if all 4 corner points in view with scribbles on page";
	}
} ImageReadException;

#endif