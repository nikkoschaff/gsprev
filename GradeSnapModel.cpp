
#include "GradeSnapModel.h"

using namespace std;


GradeSnapModel::GradeSnapModel() {

}


GradeSnapModel::~GradeSnapModel() {
}


// At this level the student-to-ID has either already been paired, or 
//	set unknown students to be of ID -1
void GradeSnapModel::evaluateImage( int assignmentID, int classID,
	string keyFilename, vector< string > filenames )  {

	// Read the images and hold the answers locally
	int numQ = atoi( DBManager::getDataObjectValue( "Assignment", assignmentID, "numQuestions" ).c_str() );
	pair< vector< string >, vector< vector< string > > > readResults(
		ImageManager::readAssignmentSetFromImage( keyFilename, filenames, numQ ) );

	int keyID = DBManager::getDataObjectID( "Student", "name", keyFilename ).at( 0 );
	readResults.first.pop_back();

	vector< pair< int, vector< string > > > studentAnswers;
	for( unsigned int i = 0; i < readResults.second.size(); i++ ) {
			// TODO Sets name if found, removes name from each vector
		int sID = DBManager::getDataObjectID( "Student", "name", filenames.at( i ) ).at( 0 );
		string name = readResults.second.at( i ).at( i );
		readResults.second.at( i ).pop_back();
		studentAnswers.push_back( pair< int, vector< string > >( sID, 
			readResults.second.at( i ) ) );
	}

	// Send answers to the Grader for evaluation and storage
	Grader::grade( assignmentID, readResults.first, keyID, studentAnswers );

}

// Prints the results to standard output
void GradeSnapModel::printResults( int assignmentID, int classID, string keyFilename ) {
	// TODO - A big one.  Can only be sure of backend when testing here.


	/*
	// Get all the students in the Class
	vector< string > studentIDs = DBManager::getAllDataObjectValues( "LinkerClassStudent", "StudentID" );

	// Get the KEY from assignment
	int keyID = DBManager::getDataObjectID( "Student", "name", keyFilename ).at( 0 );
	*/

	//int keyID = DBManager::getLinkedValues( "LinkerStudentAssignment", 

	// TODO for each student, get their grade and show it
	
}

void GradeSnapModel::getStats( int assignmentID, int classID ) {
	// TODO implement
}