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
Student::Student( string newName ): name( newName ) {

	// TODO id-getting
	ID = 0;
}

// Destructor for the student
Student::~Student() {
}

// Setter for the student name
void Student::setName( string newName ) {
	name = newName;
}

// Getter for the student name
string Student::getName() {
	return name;
}

// Getter for the student ID
int Student::getID() {
	return ID;
}