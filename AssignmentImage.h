/**
 * AssignmentImage.h : Storage intermediary between EvalHelper and ImageEval
 *		Primarily used to hold data extracted from the image, then sent to helper
 *
 * @author	Nikko Schaff
 *
 */

#include "stdafx.h"

#ifndef ASSIGNMENTIMAGE_H_
#define ASSIGNMENTIMAGE_H_

// Local Header includes

// System header includes
#include <string>
#include <map>
#include <vector>

class AssignmentImage {

public:

	/**
	 * Constructor for Assignment Image
	 * 
	 * @param	filename	The name (with directory) of the image file
	 * @param	studentName	The name of the student
	 * @param	answers		List of answers
	 *
	 */
	AssignmentImage( std::string theFilename, std::string theStudentName, 
		std::vector< std::string > theAnswers );

	/**
	 * Destructor for the Assignment Image
	 */	
	~AssignmentImage();

	/**
	 * Getter for the filename
	 *
	 * @return	string	Image filename
	 *
	 */
	std::string getFilename();

	/**
	 * Getter for the student name
	 *
	 *
	 * @return	string	Student name
	 */
	std::string getStudentName();

	/**
	 * Getter for the answers vector
	 *
	 * @return map<int,string>	The map of question numbers to answers
	 *
	 */
	std::vector< std::string > getAnswersList();


private:

	// The image filename
	std::string filename;

	// The student name
	std::string studentName;

	// The List of question numbers to answers
	std::vector< std::string > answersList;
};


#endif