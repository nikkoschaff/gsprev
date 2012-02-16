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
Assignment::Assignment( std::string theName )
:name( theName ) {
	// TODO handle extras as they come
}

// Destructor for the assignment
Assignment::~Assignment() {
}

// Getter for the assignment ID
int Assignment::getID() { 
	return ID;
}

// Getter for the assignment name
std::string Assignment::getName() {
	return name;
}

// Setter for the assignment name
void Assignment::setName( std::string newName ) {
	name = newName;
}

// Setter for the number of questions on the assignment
void Assignment::setNumQuestions( int numQ ) {
	numQuestions = numQ;
}

// Getter for the number of questions on the assignment
int Assignment::getNumQuestions() {
	return numQuestions;
}

// Getter for the due date on the assignment
std::string Assignment::getDueDate() {
	return dueDate;
}

// Setter for the due date on the assignment
void Assignment::setDueDate( std::string newDueDate ) {
	dueDate = newDueDate;
}

// Getter for the date when the assignment was assigned to students
std::string Assignment::getAssignedDate() {
	return assignedDate;
}

// Setter for the date the assignment will be given to students
void Assignment::setAssignedDate( std::string newAssignedDate ) {
	assignedDate = newAssignedDate;
}


// Places an answer at the given index
void Assignment::putAnswer( int answerID, std::string answer ) {
	answersList.at( answerID ) = answer;
}


//Getter for an answer at a given index
std::string Assignment::getAnswer( int answerID ) {
	return answersList.at( answerID );
}


// Puts a filename of an assignment image in the map, keyed to the studentID
void Assignment::putFilename( int studentID, std::string filename ) {
	imageFilenameMap.insert( pair<int,string>( studentID, filename ) );
	
}


// Gets the assignment filename of the given student on this assignment
std::string Assignment::getFilename( int studentID ) {
	return imageFilenameMap.at( studentID );
}


// Sets the date that a student handed in this assignment
void Assignment::setHandInDate( int studentID, std::string handInDate ) {
	studentHandInDateMap.insert( pair<int,string>( studentID, handInDate ) );
}

// Gets the hand in date for this assignemnt for the given student
std::string Assignment::getHandInDate( int studentID ) {
	return studentHandInDateMap.at( studentID );
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
