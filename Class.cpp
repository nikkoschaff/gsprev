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
Class::Class( std::string theName )
:name( theName ), totalPoints( 100 ) {
	// TODO adjust totalPoints to be default 100 unless selected
}

// Destructor for the Class
Class::~Class() {
}

// Grades exam from direct input - text/spreadsheet, user input, etc
void Class::gradeAssignment( int assignmentID, std::map< int, std::vector< std::string > >
	studentAnswersMap ) {
		// TODO
}

// Grades exam from image input - uses filename locations of images; doesn't
//	pass actual images
void Class::gradeAssignment( int assignmentID, std::map< int, std::vector< std::string > >
	studentAnswersMap, std::vector< std::string > filenames ) {
		// TODO
}

// Getter for the class name
std::string Class::getName() {
	return name;
}


// Setter for the class name
void Class::setName( std::string newName ) {
	name = newName;
}

// Getter for the class ID
int Class::getID() {
	return ID;
}

// Gets the student ID from a given name (may use iteration for now, when 
//	set up with a DB will likely use querying)
int Class::getStudentIDFromName( std::string name ) {
	// TODO
	return 0;
}

// Getter for total points
int Class::getTotalPoints() {
	return totalPoints;
}

// Setter for the total points
void Class::setTotalPoints( int points ) {
	totalPoints = points;
}

// Gets a given assignment in the class map by ID
Assignment Class::getAssignment( int assignmentID ) {
	return assignmentMap.at( assignmentID );
}