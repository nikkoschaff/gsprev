/**
 * AssignmentImage.cpp : Implementation for the AssignmentImage class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "AssignmentImage.h"

using namespace std;

	
// Constructor for Assignment Image
AssignmentImage::AssignmentImage( std::string theFilename, std::string theStudentName, 
	std::vector< std::string > theAnswers )
:filename( theFilename ), studentName( theStudentName ), answersList( theAnswers ) {
}

// Destructor for the assignment image
AssignmentImage::~AssignmentImage() {
}

// Getter for the filename
std::string AssignmentImage::getFilename() {
	return filename;
}

// Getter for the student name
std::string AssignmentImage::getStudentName() {
	return studentName;
}

// Getter for the answers vector
std::vector< std::string > AssignmentImage::getAnswersList() {
	return answersList;
}