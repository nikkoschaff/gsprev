/**
 * ImageManager.h : Helper class to facilitate image evaluation-based grading
 *
 * @author Nikko Schaff
 *
 */

#ifndef ImageManager_H_
#define ImageManager_H_

// Local header includes
#include "ImageEvaluator.h"
#include "DBManager.h"

// System header includes
#include <string>
#include <map>
#include <vector>


class ImageManager {

public:

	/**
	 * Constructor for the ImageManager
	 *
	 * @param	assignment	Assignment being modified by image evaluation
	 * @param	studentMap	Mapping of IDs to students
	 * @param	filenames	Filenames of the images
	 */	
	ImageManager( int assignmentId,
		std::vector< std::string > theFilenames );

	/**
	 * Destructor for ImageManager
	 */
	~ImageManager();

	/**
	 * Grades the assignment by making an AssignmentImage through
	 *		ImageEvaluator, then extracing the data and placing it in the 
	 *		Assignment, for every image in the imagefile
	 *
	 * @param	extract		Flag to tell if files should be extracted from fs
	 */
	void gradeEntireAssignment( bool extract );

	/**
	 * Reads an image through ImageEvaluator, gets the resultant AssignImg,
	 *		Then extracts and stores the data accordintly
	 * 
	 * @param	filename	Filename of image to be read
	 *
	 */
	void readAssignmentImage( std::string filename );


private:

	/**
	 * Makes sure all images relevent to this assignment are stored in the
	 *	correct directory, and extracts any extra images there if specified
	 *
	 * @param	extract		Flag to tell if the system should extract or not
	 * TOOD - build when we have time
	 */
	void synchWithFilesystem( bool extract );

	// The assignment being modified through image evaluation
	int assignmentID;

	// The Image Evaluator to read the exam from the image
	ImageEvaluator imgEval;

	// Array of filenames for image files
	std::vector< std::string > filenames;
};


#endif


