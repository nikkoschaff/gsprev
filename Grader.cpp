
#include "Grader.h"

using namespace std;

// Main lead-in function for grading
// ALL it does is call the helper function to get the grade,
//	Then sets the score and answers
void Grader::grade( int assignmentID, int keyID,
	vector< int > studentIDs ) { 

	// TODO: 1 - Strict grading opiton
	// TODO: 2 - QB integration
	bool usingStrict = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "strictGrading" ).c_str() );
	bool usingSimple = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "usingSimpleAnswers" ).c_str() );

	// Gets the grade, sets the score
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {

		// Get score and convert type to double for db assignment
		double score = ( 
			Grader::gradeSimpleAssignment( assignmentID, studentIDs.at( i ),
				usingStrict ) * 100);

		string stringScore;
		stringstream s;
		s << score;
		stringScore = s.str();

		// Stores newfound grades to database
		DBManager::setLinkedValues( "LinkerStudentAssignment", studentIDs.at( i ), assignmentID, 
			"StudentID", "AssignmentID", "grade", stringScore );
	}
}

// Helper to grade a single assignment
double Grader::gradeSimpleAssignment( int assignmentID, int studentID,
	bool strict ) {

	double numCorrect = 0.0;

	int LSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID, studentID,
		"AssignmentID", "StudentID" ).at( 0 ).c_str() );
	vector< string > answers = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > key = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( int i = 0; i < key.size(); i++ ) {
			if( key.at( i ).compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( int i = 0; i < key.size(); i++ ) {
			for( int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
				if( key.at( i ).find( anslet ) != string::npos ) {
					numCorrect += 1 / key.at( i ).size();
				}
			}
		}
	}

	double finalScore = abs( numCorrect / key.size() );
	return finalScore;

}

// Helper to grade QB-based assignment
double Grader::gradeQBAssignment( int assignmentID, int studentID, bool strict ) {

	// TODO get to work with QB

	double numCorrect = 0.0;

	int LSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID, studentID,
		"AssignmentID", "StudentID" ).at( 0 ).c_str() );
	vector< string > answers = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > key = getQBLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( int i = 0; i < key.size(); i++ ) {
			if( key.at( i ).compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( int i = 0; i < key.size(); i++ ) {
			for( int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
				if( key.at( i ).find( anslet ) != string::npos ) {
					numCorrect += 1 / key.at( i ).size();
				}
			}
		}
	}

	double finalScore = abs( numCorrect / key.size() );
	return finalScore;
}

// Helper function to get answer vector from DB string
vector< string > Grader::getLettersVector( string answers ) {
	vector< string > lettersVect;
	string at = "";


	for( unsigned int i = 0; i < answers.size(); i++ ) {
		at = answers.at( i );

		if( at.compare( "," ) == 0 ) {
			if ( i + 1 < answers.size() ) {
				string thisAt = "";
				thisAt += answers.at( i + 1 );
				
				if( thisAt.compare( "," ) == 0 ) {
					lettersVect.push_back( "" );
				}
			}
		} else {
			string letters = "";
			while ( i < answers.size() && at.compare( "," ) != 0 ) {
				letters += answers.at( i );
				i++;
				at = answers.at( i );
			}
			lettersVect.push_back( letters );
			i--;
		}

	}

	return lettersVect;
}

// Helper function to get answer vector from DB/QB string
vector< string > Grader::getQBLettersVector( string answers ) {
	// TODO

	return vector< string >();
}