/**
 * Student.cpp : Implementation for the student
 *
 *
 * @author	Nikko Schaff
 */

// Local header includes
#include "stdafx.h"
#include "Student.h"

using namespace std;

// Constructor for the student
Student::Student( std::map< std::string, std::string > data, int id )
:dataFields( data ), ID( id ) {
	dbRead( ID );
}

// Destructor for the student
Student::~Student() {
}

// Declaration of the DataInterface method dbRead
void Student::dbRead( int id ) {
	// TODO
}

// Declaration of the DataInterface method dbWrite
void Student::dbWrite( int id )  {
	// TODO
}

// Declaration of the DataInterface method dbIdInside
bool Student::dbIdInside( int id ) {
	// TODO
	return true;
}

// Declaration of the DataInterface method putFieldValue
void Student::putFieldValue( string key, string value ) {
	dataFields.insert( pair<string,string>( key, value ) );
}

// Declaration of the DataInterface method getFieldValue
string Student::getFieldValue( string key ) {
	return dataFields.at( key );
}

// Getter for the student ID
int Student::getID() {
	return ID;
}