///
/// File: ImageEvaluator.h Header for the ImageEvaluator, which reads tests
///
/// @author Nikko Schaff
///
/// /////////////////////////////////////////////////////////////////

#ifndef IMAGEEVALUATOR_H_
#define IMAGEEVALUATOR_H_

//Local header includes
#include "highgui.h"
#include "AssignmentImage.h"

//System header includes
#include "opencv2\opencv.hpp"
#include < vector >
#include < cassert >
#include < math.h >
#include < string >



class ImageEvaluator {

public:
	
	///
	/// Name: ImageEvaluator constructor
	/// 
	/// @param: int numQ  Number of questions on the exam.
	///
	ImageEvaluator( int numQ );

	///
	/// Name: ImageEvaluator desstructor
	///
	~ImageEvaluator();

	///
	/// Name: setImage  Loads the image from the given filename
	///		Also sets the base image
	///
	/// @param char* eFilename  Character array of filename
	/// @precondition  eFilename is a valid filename
	/// @postcondition  examImage was set to a valid exam
	/// 
	void setImage( std::string eFilename );

	///
	/// Name: cv_setAnswerRegions  Sets the ROIs for each question.
	/// Prints error message to STDIO if test is unreadable
	/// --Later: Will offer suggestions, or go as planned, only show where was bad
	/// 
	/// Method flow ( It's a rather long method ):
	/// 1: Setup info, use dilation to find calibration corner points
	/// 2: Narrow down # of points to the extreme corner points
	/// 3: Transform perspective the image so that the points are aligned properly
	/// 4: Calculate and find each question ROI within range of numQ
	/// 5: Return the vector of ROIs
	///
	/// @paramaters: int numQuestions  The number of questions (therefore regions)
	/// @postcondition:   examImage was readable, returned ROIs are readable
	/// @returns: vector< CvRect >  The vector of ROIs for each question
	///
	void cv_setAnswerRegions();

	///
	/// Name: getAnswer  Returns the character array of the answer for a region
	///
	/// @param: CvRect answerRegion  The ROI for that particular Q and answer
	/// @precondition:  The ROI is valid and readable
	/// @returns:  string  The string representing the answer(s) in that Q
	///
	std::string cv_getAnswer( cv::Rect answerRegion );

	///
	/// Name: readExam  Reads and interprets the exam, returning the answers
	///
	/// Returns: vector< string >  Vector of answers on the test
	///
	std::vector< std::string > readExam();

	///
	/// Name: compCalibCorners	Computes the main calibration corner points
	///
	/// @postcondition: The four calibration corner points have been set
	///
	void cv_compCalibCorners();

	///
	/// Name: orientImage	Adjust image orentation to be readable
	///
	/// @precondition: The four calibration points have been set and adjusted
	/// @postcondition: examImage will be scaled, rotated, and adjusted for read
	///
	void cv_orientImage();

	///
	/// Name: getExamImage  Getter for the pointer to the exam image
	///
	/// @return: Mat	Matrix of the exam image
	///
	cv::Mat getExamImage() const;

	///
	/// Name: GetRegionsFromEval  Returns the regions vector
	/// @return: vector< CvRect >  The regions vector
	///
	std::vector< cv::Rect > getRegions();

	/// 
	/// Name: operator= Copies the ImageEvaluator class
	///
	/// @param: ImageEvaluator  ie  The ImageEvaluator object being copied
	///
	ImageEvaluator& operator=( const ImageEvaluator &nIE );

	/**
	 * Newer method - Reads from a filename and returns a completed
	 *		AssignmentImage
	 * 
	 * @param	filename	The image filename
	 * 
	 * @return	AssignmentImage	Assignment Image formed from the read
	 */
	AssignmentImage readImage( std::string filename );

	/**
	 * Sets the name to be what was found from the exam image
	 *
	 * @postcondition	name has been set 
	 */
	void setName();

	/**
	 * Finds and sets the name letter regions on the exam
	 *
	 * @postcondition	Each of the Rects for the nameLetterRegions created
	 */
	void setNameLetterRegions();

	/**
	 * Gets the letter found in the answer bubble region
	 *
	 * @param	nameLetterRegion	Region of the answer bubble column
	 *
	 * @return	char	The letter character found
	 */
	char getNameLetter( cv::Rect nameLetterRegion );

private:

	/// The exam image being used 
	cv::Mat examImage;
	/// The base image used for comparison
	cv::Mat baseImage;
	/// The number of questions on the test
	int numQuestions;
	/// AnswerRegion vector
	std::vector< cv::Rect > regions;
	// Name letter region vector
	std::vector< cv::Rect > nameLetterRegions;
	// Answers vector
	std::vector< std::string > answersVector;
	// Name of the test-taker (taken from image bubbles)
	std::string name;

	/// Calibration corner points
	/// Upper-Left
	cv::Point2f UL;
	/// Upper-Right
	cv::Point2f UR;
	/// Lower-Left
	cv::Point2f LL;
	/// Lower-Right
	cv::Point2f LR;

	/// Main calibration corner points
	/// Upper-Left
	cv::Point2f mainUL;
	/// Upper-Right
	cv::Point2f mainUR;
	/// Lower-Left
	cv::Point2f mainLL;
	/// Lower-Right
	cv::Point2f mainLR;

	//Ratio between main and given resolutionn (width)
	double resRatioWidth;
	//Ratio between main and given resolution (height)
	double resRatioHeight;

	///The width of the main image's resolution
	static const int MAIN_RES_WIDTH = 2550;
	///The height of the main image's resolution
	static const int MAIN_RES_HEIGHT = 3300;

	///The width ratio to finding the main X offset
	const double MAIN_X_OFFSET; //7.169230769
	///The height ratio to finding the main Y offset
	const double MAIN_Y_OFFSET; //35.58974359
	///The x-width ratio for the second question column
	//const double 2C; // 1.24799143

	/// The width of a question bounding box
	static const int QUESTION_ROI_WIDTH = 395;
	/// The height of a question bounding box
	static const int QUESTION_ROI_HEIGHT = 75;

	/// The X offset from starting position
	static const int OFFSET_X_FROM_START = 1431;
	/// The Y offset from starting position
	static const int OFFSET_Y_FROM_START = 106; //Change once found

	// Rough expected area of calib corner rectangles
	static const int CALIB_RECT_AREA_LOWER = 16500;
	static const int CALIB_RECT_AREA_HIGHER = 23500;

}; // ImageEvaluator

#endif