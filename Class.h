/**
 * Class.h : Main operator and storage for the teacher's class
 *
 * @author Nikko Schaff
 *
 */

#include "stdafx.h"

#ifndef CLASS_H_
#define CLASS_H_

// Local header includes
#include "EvalHelper.h"
#include "Student.h"
#include "Assignment.h"
//#include "DataInterface.h"
#include "sqlite3.h"


// System header includes
#include <string>
#include <vector>
#include <map>

class Class {

public:

	/**
	 * Constructor for the Class
	 *
	 * @param name
	 *
	 */
	Class( std::map< std::string, std::string > data, int id = -1  ); 

	/**
	 * Destructor for the Class
	 */
	~Class();

	// Declaration of the DataInterface method dbRead
	void dbRead( int id );

	// Declaration of the DataInterface method dbWrite
	void dbWrite( int id );

	// Declaration of the DataInterface method dbIdInside
	bool dbIdInside( int id );

	// Declaration of the DataInterface method putFieldValue
	void putFieldValue( std::string key, std::string value );

	// Declaration of the DataInterface method getFieldValue
	std::string getFieldValue( std::string key );

	/**
	 * Grades exam from direct input of results, evaluated at higher level to 
	 *	be taken through user input, file I/O, etc
	 *
	 * @param	assignmentID	ID for the assignment
	 * @param	studentAnswersMap	Map of student IDs to their answer arrays
	 *
	 */
	void gradeAssignment( int assignmentID, std::map< int, std::vector< std::string > >
		studentAnswersMap );

	/**
	 * Grades exam from image input - uses filename locations of images; doesn't
	 * pass actual images
	 *
	 * @param	assignmentID	ID for the assignment
	 * @param	studentAnswersMap	Map of student IDs to their answer arrays
	 *
	 */
	void gradeAssignment( int assignmentID, std::vector< std::string > filenames );

	/**
	 * Getter for the class ID
	 *
	 * @return	int	Class ID
	 *
	 */
	int getID();

	/**
	 * Gets the student ID from a given name by quering the DB
	 *
	 * @param	name	Name of the student to search
	 * @return	int		Student's ID
	 */
	int getStudentIDFromName( std::string name );

	/**
	 * Gets a given assignment in the class map by ID
	 *
	 * @param	assignmentID	int ID of the assignment
	 * @return	Assignment		Assignment
	 *
	 */
	Assignment getAssignment( int assignmentID );



private:

	// ID of the class - for internal use only
	int ID;

	// Map of data fields
	std::map< std::string, std::string > dataFields;

	// Mapping of student IDs to the student
	std::map< int, Student > studentMap;

	// Mapping of assignment IDs to Assignments
	std::map< int, Assignment > assignmentMap;

};



#endif