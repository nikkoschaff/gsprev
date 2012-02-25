
#include "Grader.h"
#include <iostream>

using namespace std;

// Main lead-in function for grading
// ALL it does is call the helper function to get the grade,
//	Then sets the score and answers
void Grader::grade( int assignmentID, std::pair< int, std::vector< std::string > > keyAnswers,
	vector< pair< int, vector< string > > > studentAnswers ) {

	// Gets the grade, sets the score
	for( unsigned int i = 0; i < studentAnswers.size(); i++ ) {

	// Get score and convert type to double for db assignment
		double score = ( Grader::gradeSingleAssignment( keyAnswers.second, studentAnswers.at( i ).second ) * 100);
	string stringScore;
	stringstream s;
	s << score;
	stringScore = s.str();
	string ans;
	stringstream as;
	for( unsigned int j = 0; j < studentAnswers.at( i ).second.size(); j++ ) {
			as << studentAnswers.at( i ).second.at( j ) << ",";
	}

	ans = as.str();
	// Stores newfound grades and answers to database
	int sID = studentAnswers.at( i ).first;
	DBManager::setLinkedValues( "LinkerStudentAssignment", sID, assignmentID, 
		"StudentID", "AssignmentID", "answers", ans );
	DBManager::setLinkedValues( "LinkerStudentAssignment", sID, assignmentID, 
		"StudentID", "AssignmentID", "grade", stringScore );
	}

	string s;
	for( unsigned int i = 0; i < keyAnswers.second.size(); i++ ) {
		s.append( keyAnswers.second.at( i ) );
		s.append( "," );
	}

	// Store the key results for reference
	DBManager::setDataObjectValue( "LinkerStudentAssignment", keyAnswers.first,
		"answers", s );

}

// Helper to grade a single assignment
double Grader::gradeSingleAssignment( vector< string > key, vector< string > answers ) {
	double numCorrect = 0.0;

	for ( unsigned int i = 0; i < key.size(); i++ ) {

		//cout << "#" << i << "----KEY: " << key.at( i ) << "  -----ANSWER: " << answers.at( i ) << endl;
		
		if ( key.at( i ).compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
		}
	}
	cout << endl;
	double finalScore = abs( numCorrect / key.size() );
	return finalScore;

}