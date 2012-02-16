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
Teacher::Teacher( string newName ): name( newName ) {
	// TODO setter for ID
	ID = 0;
}


// Constructor for the Teacher
Teacher::Teacher( string newName, std::map< int, Class > newClasses ): name( newName ),
 classes( newClasses ) {
	// TODO setter for ID
	ID = 0;
}

	
// Destructor for the teacher
Teacher::~Teacher() {
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

// Getter for the Teacher name
std::string Teacher::getName() {
	return name;
}

	// Setter for the Teacher name
void Teacher::setName( std::string newName ) {
	name = newName;
}