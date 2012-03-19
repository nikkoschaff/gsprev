

#ifndef GRADER_H_
#define GRADER_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "DBManager.h"

// Takes information to compare and grade.  The functions to grade are only
//	reliant on input.  They require a key (explicit or ID if info is in XML),
//	assignmentID, answers ( studentID and answers, explicit or ID if info is in XML).
//	After comparing responses to key, the data is then stored in the database, including
//	storage of grade and responses
//	Grades are stored as a value out of 100, so a 95% result will be stored as 95
namespace Grader {

	// Main lead-in function for grading
	// ALL it does is call the helper function to get the grade,
	//	Then sets the score and answers
	void grade( int assignmentID, int keyID, 
		std::vector< int > studentIDs );

	// Helper to grade a single assignment
	double gradeSimpleAssignment( int assignmentID, int studentID, bool strict );

	// Helper to grade QB-based assignment
	double gradeQBAssignment( int assignmentID, int studentID, bool strict );

	// Helper function to get the letters of the corect answers (in answer format)
	std::string answerLettersFromQB( std::string question );

	// Helper function to get answer vector from DB string
	std::vector< std::string > getLettersVector( std::string answers );

	// Helper function to get answer vector from DB/QB string
	std::vector< std::string > getQBLettersVector( std::string qbKey );

};

#endif