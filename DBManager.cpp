//
//



#include "stdafx.h"
#include "DBManager.h"
#include "sqlite3.h"

using namespace std;

#include <iostream>


// TODO SET UP THE GODDAMN POINTER
static sqlite3 * db = NULL;

// GENERAL FUNCTIONS

void DBManager::db_init() {
	int rc = sqlite3_open( "GSBackend.db", &db );
	rc = sqlite3_open( "GSBackend.cb", &db );
	if ( rc ) {
		cerr << "Error opening SQLite3 database: " << sqlite3_errmsg( db ) << endl;
		sqlite3_close( db );
	} else {
		cout << "Opened GSBackend.db " << endl << endl;
	}
	

}

void DBManager::db_close() {
	sqlite3_close( db );
}


std::string DBManager::getData( int primekey, std::string colField ) {
	return "";
}

std::string DBManager::getData( int primekey, int colField ) {
	return "";
}

void DBManager::setData( int primekey, std::string colField, std::string colValue ) {
	
}

/// TEACHER


void DBManager::makeTeacher( std::string name ) {
}


void DBManager::removeTeacher( int teacherID ) {
}


int DBManager::getTeacherIDFromName( std::string name ) {
	return -1;
}


std::string DBManager::getTeacherName( int teacherID ) {
	return "";
}


void DBManager::addClassToTeacher( int teacherID, int classID ) {
}


void DBManager::removeClassFromTeacher( int teacherID, int classID ) {
}


std::set<std::string> DBManager::getStudentsOfTeacher( int teacherID ) {
	return set<string>();
}


std::set<std::string> DBManager::getClassesOfTeacher( int teacherID ) {
	return set<string>();
}

/// STUDENT


void DBManager::makeStudent( std::string name ) {
}


void DBManager::removeStudent( int studentID ) {
}


int DBManager::getStudentIDFromName( std::string name ) {
	return -1;
}


std::string DBManager::getStudentName( int StudentID ) {
	return "";
}


void DBManager::addClasstoStudent( int studentID, int classID ) {
}


void DBManager::removeClassFromStudent( int studentID, int classID ) {
}


void DBManager::addAssignmentToStudent( int studentID, int assignmentID ) {
}

void DBManager::removeAssignmentFromStudent( int studentID, int assignmentID ) {
}


std::set<std::string> DBManager::getClassesOfStudent( int studentID ) {
	return set<string>();
}

std::set<std::string> DBManager::getAssignmentsOfStudent( int studentID ) {
	return set<string>();
}


/// ASSIGNMENT


void DBManager::makeAssignment( std::string name ) {
}

void DBManager::removeAssignment( int assignmentID ) {
}

int DBManager::getAssignmentIDFromName( std::string name ) {
	return -1;
}

std::string DBManager::getAssignmentName( int id ) {
	return "";
}


void DBManager::addClasstoAssignment( int assignmentID, int classID ) {
}


void DBManager::removeClassFromAssignment( int assignmentID, int classID ) {
}


void DBManager::addStudentToAssignment( int assignmentID, int studentID ) {
}


void DBManager::removeStudentFromAssignment( int assignmentID, int studentID ) {
}


std::set<std::string> DBManager::getClassesOfAssignment( int assignmentID ) {
	return set<string>();
}


std::set<std::string> DBManager::getStudentsOfAssignment( int assignmentID ) {
	return set<string>();
}


double DBManager::getStudentGrade( int assignmentID, int studentID ) {
	return -1;
}


void DBManager::setStudentGrade( int assignmentID, int studentID, double grade ) {
}

/// CLASS

void DBManager::makeClass( std::string name ) {

}


void DBManager::removeClass( int classID ) {
}


int DBManager::getClassIDFromName( std::string name ) {
	return -1;
}


std::string DBManager::getClassName( int classID ) {
	return "";
}


void DBManager::addStudentToClass( int classID, int studentID ) {
}

void DBManager::removeStudentFromClass( int classID, int studentID ) {
}

void DBManager::addAssignmentToClass( int classID, int assignmentID ) {
}


void DBManager::removeAssignmentFromClass( int classID, int assignmentID ) {
}

void DBManager::addTeacherToClass( int classID, int teacherID ) {
}


void DBManager::removeTeacherFromClass( int classID, int teacherID ) {
}



std::set<std::string> DBManager::getStudentsOfClass( int classID ) {
	return set<string>();
}


std::set<std::string> DBManager::getAssignmentsOfClass( int classID ) {
	return set<string>();
}


std::set<std::string> DBManager::getTeachersOfClass( int classID ) {
	return set<string>();
}