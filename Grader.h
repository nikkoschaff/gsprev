

#ifndef GRADER_H_
#define GRADER_H_

#include <vector>
#include <string>
#include <sstream>
#include "DBManager.h"


namespace Grader {

	// Main lead-in function for grading
	// ALL it does is call the helper function to get the grade,
	//	Then sets the score and answers
	void grade( int assignmentID, std::vector< std::string > key, int keyID,
		std::vector< std::pair< int, std::vector< std::string > > > studentAnswers );

	// Helper to grade a single assignment
	double gradeSingleAssignment( std::vector< std::string > key,
		std::vector< std::string > answers );

};

#endif