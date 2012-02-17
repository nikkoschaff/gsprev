/**
 * Teacher.cpp : Implementation for the teacher class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "Teacher.h"


using namespace std;

	
// Constructor for the Teacher
Teacher::Teacher( std::map< std::string, std::string > data, int id )
: dataFields( data ), ID( id )  {
	dbRead( ID );
}


// Constructor for the Teacher
Teacher::Teacher( std::map< std::string, std::string > data, 
	std::map< int, Class > newClasses, int id )
: dataFields( data ), classes( newClasses ), ID( id ) {
	dbRead( ID );
}

	
// Destructor for the teacher
Teacher::~Teacher() {
}

// Declaration of the DataInterface method dbRead
void Teacher::dbRead( int id ) {
	// TODO
}

// Declaration of the DataInterface method dbWrite
void Teacher::dbWrite( int id )  {
	// TODO
}


// Declaration of the DataInterface method dbIdInside
bool Teacher::dbIdInside( int id ) {
	// TODO
	return true;
}

// Declaration of the DataInterface method putFieldValue
void Teacher::putFieldValue( string key, string value ) {
	dataFields.insert( pair<string,string>( key, value ) );
}

// Declaration of the DataInterface method getFieldValue
string Teacher::getFieldValue( string key ) {
	return dataFields.at( key );
}

// Puts a class into the classes map
void Teacher::putClass( int classID, Class theClass ) {
	classes.insert( pair< int, Class >( classID, theClass ) );
}

// Gets a class from the list based on ID
Class Teacher::getClass( int classID ) {
	return classes.at( classID );
}

// Getter for the Teacher ID
int Teacher::getID() {
	return ID;
}
