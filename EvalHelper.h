/**
 * EvalHelper.h : Helper class to facilitate image evaluation-based grading
 *
 * @author Nikko Schaff
 *
 */

#include "stdafx.h"

#ifndef EVALHELPER_H_
#define EVALHELPER_H_

// Local header includes
#include "Assignment.h"
#include "ImageEvaluator.h"
#include "AssignmentImage.h"
#include "Student.h"

// System header includes
#include <string>
#include <map>
#include <vector>


class EvalHelper {

public:

	/**
	 * Constructor for the EvalHelper
	 *
	 * @param	assignment	Assignment being modified by image evaluation
	 * @param	studentMap	Mapping of IDs to students
	 * @param	filenames	Filenames of the images
	 */	
	EvalHelper( Assignment theAssignment, std::map< int, Student > theStudentMap,
		std::vector< std::string > theFilenames );

	/**
	 * Destructor for EvalHelper
	 */
	~EvalHelper();

	/**
	 * Grades the assignment by making an AssignmentImage through
	 *		ImageEvaluator, then extracing the data and placing it in the 
	 *		Assignment, for every image in the imagefile
	 *
	 */
	void gradeAssignment();

	/**
	 * Reads an image through ImageEvaluator, gets the resultant AssignImg,
	 *		Then extracts and stores the data accordintly
	 * 
	 * @param	filename	Filename of image to be read
	 *
	 */
	void readAndStoreImage( std::string filename );

	/**
	 * 
	 * Gets the student ID via iteration in Map
	 *
	 * @param	studentName	The student's name
	 * @return	int		The student's matching ID, -1 if not found
	 */
	int getIDFromName( std::string studentName );

	/**
	 * Getter for the assignment
	 *
	 * @return	assignment	The assignment in this helper class
	 */
	Assignment getAssignment();


private:

	// The assignment being modified through image evaluation
	Assignment assignment;

	// The Image Evaluator to read the exam from the image
	ImageEvaluator imgEval;

	// Array of filenames for image files
	std::vector< std::string > filenames;

	// Mapping of studentIDs to students
	std::map< int, Student > studentMap;

	// Mapping of student IDs to image files
	std::map< int, std::string > imageFilenames;
};


#endif


