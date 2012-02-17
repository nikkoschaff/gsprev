/**
 * EvalHelper.cpp : Implementation for the EvalHelper class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "EvalHelper.h"

using namespace std;

// Constructor for EvalHelper
EvalHelper::EvalHelper( Assignment theAssignment, map< int, Student > theStudentMap,
	vector< string > theFilenames, vector<int> IDs )
:assignment( theAssignment ), studentMap( theStudentMap ), filenames( theFilenames ),
	imgEval( theAssignment.getNumQuestions() ), studentIDsVector( IDs ) {
}

// Desctructor for EvalHelper
EvalHelper::~EvalHelper() {
}


// Grades the assignment by making an AssignmentImage through
//		ImageEvaluator, then extracing the data and placing it in the 
//		Assignment, for every image in the imagefile
void EvalHelper::gradeAssignment() {
	// TODO make filesystem directory (if not already there)

	// Lets the helper method do the reading and storage
	for( unsigned int i = 0; i < filenames.size(); i++ ) {
		readAndStoreImage( filenames.at( i ) );
	}
}

// Reads an image through ImageEvaluator, gets the resultant AssignImg,
//		Then extracts and stores the data accordintly
void EvalHelper::readAndStoreImage( std::string filename ) {
	// TODO implement


	// TODO consider whether name found or provided

	// TODO store in filesystem directory
}

// Gets the student ID by DB query may change to DB query later on)
int EvalHelper::getIDFromName( std::string studentName ) {
	// TODO - Either here or later, make sure name can be found when not "quite" perfect

	// Looks for the student's name in the map. 
	//	If found, it returns the ID
	for( map<int,Student>::iterator itr = studentMap.begin();
		itr != studentMap.end(); itr++ ) {

		if( itr->second.getFieldValue( "name" ).compare( studentName ) == 0 ) {
			return itr->second.getID();
		}
	}

	return -1;
}

// Getter for the assignment
Assignment EvalHelper::getAssignment() {
	return assignment;
}

