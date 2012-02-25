
#include "GradeSnapModel.h"

using namespace std;


GradeSnapModel::GradeSnapModel() {

}


GradeSnapModel::~GradeSnapModel() {
}


// At this level the student-to-ID has either already been paired, or 
//	set unknown students to be of ID -1
void GradeSnapModel::evaluateImage( int assignmentID,int classID, 
	std::pair< int, std::string > keyFilePair,
	std::vector< std::pair< int, std::string > > filenames, int numQ )  {

	// Stores the key in a vector for image evaluation
	// Evaluates and returns the data from the image
	vector< pair< int, string > > keyVector;
	keyVector.push_back( keyFilePair );
	std::vector< std::pair< int, std::vector< std::string > > > keyResults;
	keyResults = ImageManager::readAssignmentSetFromImage( keyVector, numQ );

	// Stores the image data in a vector for image evaluation
	//	Evaluates and returns the data from the image
	std::vector< std::pair< int, std::vector< std::string > > > studentResults;
	studentResults = ImageManager::readAssignmentSetFromImage( filenames, numQ );

	// Grades the data and sends it to the database
	// TODO VERIFY - is this the right thing to do (sending data to db)?
	Grader::grade( assignmentID, keyResults.at( 0 ), studentResults );
}

// Prints the results to standard output
void GradeSnapModel::printResults( int assignmentID, int classID, int keyID,
	std::vector< int > studentIDs ) {

	cout << "Grading exam # " << assignmentID << endl;
	
	// Get the grades from each of the students recorded taking the exam

	string grade;

	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		vector< string > r = DBManager::getLinkedValues( "LinkerStudentAssignment",
			assignmentID, studentIDs.at( i ), "AssignmentID", "StudentID" );
		grade = DBManager::getDataObjectValue( "LinkerStudentAssignment",
			atoi( r.at( i ).c_str() ), "grade" );
				cout << "Student: " << studentIDs.at( i ) << " scored: " <<
			grade << "%" << endl;
	}

	cout << endl << "Done grading" << endl;
}

void GradeSnapModel::getStats( int assignmentID, int classID ) {
	// TODO implement
}