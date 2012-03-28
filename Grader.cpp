/**
 * Grader.cpp - Implementation for the Grader module
 *
 * @author	Nikko Schaff
 */


#include "Grader.h"

using namespace std;

// Main lead-in function for grading
// ALL it does is call the helper function to get the grade,
//	Then sets the score and answers
void Grader::grade( int assignmentID, int keyID,
	vector< int > studentIDs ) { 

	bool usingStrict = false;
	int usingStrictInt = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "strictGrading" ).c_str() );
	if( usingStrictInt == 1 ) usingStrict = true;

	bool usingSimple;
	int usingSimpleInt = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "usingSimpleAnswers" ).c_str() );
	if( usingSimpleInt == 1 ) usingSimple = true;

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
	vector< string > answers = Helper::formatAnswersFromSimple(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > key = Helper::formatAnswersFromSimple(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( unsigned int i = 0; i < key.size(); i++ ) {
			if( key.at( i ).compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( unsigned int i = 0; i < key.size(); i++ ) {
			for( unsigned int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
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
// TODO fix
double Grader::gradeQBAssignment( int assignmentID, int studentID, bool strict ) {

	double numCorrect = 0.0;
	int LSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID, studentID,
		"AssignmentID", "StudentID" ).at( 0 ).c_str() );
	vector< string > answers = Helper::formatAnswersFromSimple(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > questions = Helper::formatAnswersFromQB(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	// String of answers in answer format (from questions thorugh DB parsing)
	string qKey;


	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( unsigned int i = 0; i < questions.size(); i++ ) {
			qKey = answerLettersFromQB( questions.at( i ) );
			if( qKey.compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( unsigned int i = 0; i < questions.size(); i++ ) {
			qKey = answerLettersFromQB( questions.at( i ) );
			for( unsigned int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
				if( qKey.find( anslet ) != string::npos ) {
					numCorrect += 1 / qKey.size();
				}
			}
		}
	}
	double finalScore = abs( numCorrect / questions.size() );
	return finalScore;
}
