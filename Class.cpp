/**
 * Class.cpp : Implementation for the Class class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "Class.h"

using namespace std;

// Constructor for the Class
Class::Class( std::map< std::string, std::string > data, int id )
:dataFields( data ), ID( id ) {
	dbRead( ID );
}

// Destructor for the Class
Class::~Class() {
}

// Declaration of the DataInterface method dbRead
void Class::dbRead( int id ) {
	// TODO
}

// Declaration of the DataInterface method dbWrite
void Class::dbWrite( int id )  {
	// TODO
}


// Declaration of the DataInterface method dbIdInside
bool Class::dbIdInside( int id ) {
	// TODO
	return true;
}

// Declaration of the DataInterface method putFieldValue
void Class::putFieldValue( string key, string value ) {
	dataFields.insert( pair<string,string>( key, value ) );
}

// Declaration of the DataInterface method getFieldValue
string Class::getFieldValue( string key ) {
	return dataFields.at( key );
}

// Grades exam from direct input of results, evaluated at higher level to 
// be taken through user input, file I/O, etc
void Class::gradeAssignment( int assignmentID, std::map< int, std::vector< std::string > >
	studentAnswersMap ) {

	// Gets the assignment from the map
	Assignment gradingAssignment = assignmentMap.at( assignmentID );

	// Iterates through the map and assigns the answers to the answers map
	for( map<int,vector<string> >::iterator itr = studentAnswersMap.begin();
		itr != studentAnswersMap.end(); itr++ ) {
			gradingAssignment.setStudentAnswerArray( itr->first, itr->second );
	}
	// Stores the modified array in the assignments map
	assignmentMap.insert( pair<int,Assignment>( assignmentID, gradingAssignment ) );
}

// Grades exam from image input - uses filename locations of images; doesn't
//	pass actual images
void Class::gradeAssignment( int assignmentID, std::vector< std::string > filenames,
	bool knowNames ) {
		
	// Gets the assignment from the map
	Assignment gradingAssignment = assignmentMap.at( assignmentID );

	// If names known, give index vector of student IDs to helper by vector
	vector< int > studentIDs;
	if( knowNames ) {
		// TODO give index vector of student IDs to helper
	}

	// Gets an eval helper to grade the image from a file
	EvalHelper helper = EvalHelper( gradingAssignment, studentMap, filenames,
		studentIDs );

	// Grades and gets the assignment from EvalHelper
	helper.gradeAssignment();
	gradingAssignment = helper.getAssignment();

	// Iterates through the map and assigns the answers to the answers map
	for( map<int,vector<string> >::iterator itr = 
		gradingAssignment.getStudentAnswerMap().begin();
		itr != gradingAssignment.getStudentAnswerMap().end(); itr++ ) {
			gradingAssignment.setStudentAnswerArray( itr->first, itr->second );
	}

	// Stores the modified array in the assignments map
	assignmentMap.insert( pair<int,Assignment>( assignmentID, gradingAssignment ) );
}

// Getter for the class ID
int Class::getID() {
	return ID;
}

// Gets the student ID from a given name by quering the DB
int Class::getStudentIDFromName( std::string name ) {
	// TODO (query db)
	return 0;
}

// Gets a given assignment in the class map by ID
Assignment Class::getAssignment( int assignmentID ) {
	return assignmentMap.at( assignmentID );
}