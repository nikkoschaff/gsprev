/**
 * Assignment.cpp : Implementation for the assignment class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "Assignment.h"

using namespace std;

// Constructor for the assignment
Assignment::Assignment( std::map< std::string, std::string > data, int numQ, int id  )
:dataFields( data ), numQuestions( numQ ), ID( id ) {
	dbRead( ID );
}

// Destructor for the assignment
Assignment::~Assignment() {
}

// Declaration of the DataInterface method dbRead
void Assignment::dbRead( int id ) {
	// TODO
}

// Declaration of the DataInterface method dbWrite
void Assignment::dbWrite( int id )  {
	// TODO
}


// Declaration of the DataInterface method dbIdInside
bool Assignment::dbIdInside( int id ) {
	// TODO
	return true;
}

// Declaration of the DataInterface method putFieldValue
void Assignment::putFieldValue( string key, string value ) {
	dataFields.insert( pair<string,string>( key, value ) );
}

// Declaration of the DataInterface method getFieldValue
string Assignment::getFieldValue( string key ) {
	return dataFields.at( key );
}

// Getter for the assignment ID
int Assignment::getID() { 
	return ID;
}

// Setter for the number of questions on the assignment
void Assignment::setNumQuestions( int numQ ) {
	numQuestions = numQ;
}

// Getter for the number of questions on the assignment
int Assignment::getNumQuestions() {
	return numQuestions;
}


// Puts a filename of an assignment image in the map, keyed to the studentID
void Assignment::putFilename( int studentID, std::string filename ) {
	imageFilenameMap.insert( pair<int,string>( studentID, filename ) );
}


// Gets the assignment filename of the given student on this assignment
std::string Assignment::getFilename( int studentID ) {
	return imageFilenameMap.at( studentID );
}


// Puts a student's answer in their answers vector
void Assignment::setStudentAnswer( int studentID, int index, std::string answer ) {
	studentAnswerMap.at( studentID ).at( index ) = answer;
}

// Sets the student's answer array all at once
void Assignment::setStudentAnswerArray( int studentID, std::vector< std::string >
	answers ) {
	studentAnswerMap.insert( pair<int,vector<string> >( studentID,answers) );
}

// Gets a student's answer in their answers vector
std::string Assignment::getStudentAnswer( int studentID, int index ) { 
	return studentAnswerMap.at( studentID ).at( index );
}

// Gets the full array of student's answers for this assignment
std::vector< std::string > Assignment::getStudentAnswerArray( int studentID ) {
	return studentAnswerMap.at( studentID );
}

// Gets the full mapping of student answers
std::map< int, std::vector< std::string > > Assignment::getStudentAnswerMap() {
	return studentAnswerMap;
}
