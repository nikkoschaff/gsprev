


#ifndef DBMANAGER_H_
#define DBMANAGER_H_


// System header includes
#include <string>
#include <set>

// Local header includes
#include "sqlite3.h"


namespace DBManager {

	//static sqlite3 *db;

	// GENERAL FUNCTIONS


	void db_init();

	void db_close();

	std::string getData( int primekey, std::string colField );

	std::string getData( int primekey, int colField );

	void setData( int primekey, std::string colField, std::string colValue );


	// TEACHER

	void makeTeacher( std::string name = "" );

	void  removeTeacher( int teacherID );


	int getTeacherIDFromName( std::string name = "" );


	std::string  getTeacherName( int teacherID );


	void addClassToTeacher( int teacherID, int classID );


	void  removeClassFromTeacher( int teacherID, int classID );

	void addStudentToTeacher( int teacherID, int studentID );

	void removeStudentFromTeacher( int teacherID, int studentID );

	std::set<std::string>  getClassesOfTeacher( int teacherID );


	std::set<std::string> getStudentsOfTeacher( int teacherID );


	// STUDENT

	void makeStudent( std::string name = "" );


	void removeStudent( int studentID );


	int getStudentIDFromName( std::string name );


	std::string getStudentName( int StudentID );


	void addClasstoStudent( int studentID, int classID );


	void removeClassFromStudent( int studentID, int classID );


	void addAssignmentToStudent( int studentID, int assignmentID );

	void removeAssignmentFromStudent( int studentID, int assignmentID );


	std::set<std::string> getClassesOfStudent( int studentID );

	std::set<std::string> getAssignmentsOfStudent( int studentID );



	// ASSIGNMENT

	void makeAssignment( std::string name = "" );

	void removeAssignment( int assignmentID );

	int getAssignmentIDFromName( std::string name );

	std::string getAssignmentName( int id );


	void addClasstoAssignment( int assignmentID, int classID );


	void removeClassFromAssignment( int assignmentID, int classID );


	void addStudentToAssignment( int assignmentID, int studentID );


	void removeStudentFromAssignment( int assignmentID, int studentID );


	std::set<std::string> getClassesOfAssignment( int assignmentID );


	std::set<std::string> getStudentsOfAssignment( int assignmentID );


	double getStudentGrade( int assignmentID, int studentID );


	void setStudentGrade( int assignmentID, int studentID, double grade );


	// CLASS

	void makeClass( std::string name = "" );


	void removeClass( int classID );


	int getClassIDFromName( std::string name );


	std::string getClassName( int classID );


	void addStudentToClass( int classID, int studentID );

	void removeStudentFromClass( int classID, int studentID );

	void addAssignmentToClass( int classID, int assignmentID );


	void  removeAssignmentFromClass( int classID, int assignmentID );

	void addTeacherToClass( int classID, int teacherID );


	void removeTeacherFromClass( int classID, int teacherID );


	std::set<std::string> getStudentsOfClass( int classID );


	std::set<std::string> getAssignmentsOfClass( int classID );


	std::set<std::string> getTeachersOfClass( int classID );

};


#endif