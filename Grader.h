/**
 * Grader.h - Takes information to compare and grade.  The functions to grade are only
 *	reliant on input.  They require a key (explicit or ID if info is in XML),
 *	assignmentID, answers ( studentID and answers, explicit or ID if info is in XML).
 *	After comparing responses to key, the data is then stored in the database, including
 *	storage of grade and responses
 *	Grades are stored as a value out of 100, so a 95% result will be stored as 95
 *
 * @author Nikko Schaff
 */

#ifndef GRADER_H_
#define GRADER_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "DBManager.h"
#include "Helper.h"


namespace Grader {

	/**
	 * Main lead-in function for grading
	 *		ALL it does is call the helper function to get the grade,
	 *		Then sets the score and answers
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 */
	void grade( int assignmentID, int keyID, 
		std::vector< int > studentIDs );

	/**
	 * Helper to grade a simple assignment
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 * @return	double	Grade of the assignment
	 */
	double gradeSimpleAssignment( int assignmentID, int studentID, bool strict );

	/**
	 * Helper to grade a QB assignment
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 * @return	double	Grade of the assignment
	 */
	double gradeQBAssignment( int assignmentID, int studentID, bool strict );


};

#endif