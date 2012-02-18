/**
 *
 * Teacher.h : Class to hold Teacher information, including name, ID,
 *		And the teacher's classes.
 *
 *
 * @author Nikko Schaff
 */


#include "stdafx.h"


#ifndef TEACHER_H_
#define TEACHER_H_

// Local header includes
#include "Class.h"
#include "GradeSnap.h"
#include "sqlite3.h"

// System header includes
#include <string>
#include <map>


class Teacher {

public:

	/**
	 * Constructor for the Teacher
	 *
	 * @param	name	The name of the teacher
	 *
	 */
	Teacher( std::map< std::string, std::string > data, int id = -1 );

	/**
	 * Constructor for the Teacher
	 *
	 * @param	name	The name of the teacher
	 * @param	classes	The map of classes to be added
	 *
	 */
	Teacher(  std::map< std::string, std::string > data, 
		std::map< int, Class > newClasses, int id = -1 );

	/**
	 * Destructor for the teacher
	 */
	~Teacher();

	// Declaration of the DataInterface method dbRead
	void dbRead( int id );

	// Declaration of the DataInterface method dbWrite
	void dbWrite( int id ) ;

	// Declaration of the DataInterface method dbIdInside
	bool dbIdInside( int id );

	// Declaration of the DataInterface method putFieldValue
	void putFieldValue( std::string key, std::string value );

	// Declaration of the DataInterface method getFieldValue
	std::string getFieldValue( std::string key );

	/**
	 * Puts a class into the classes map
	 *
	 * @param	classID	Class ID
	 * @param	class	Class to be added
	 */
	void putClass( int classID, Class theClass );

	/**
	 * Gets a class from the list based on ID
	 *
	 * @param	classID	The ID of the class
	 */
	Class getClass( int classID );

	/**
	 * Getter for the Teacher ID
	 *
	 * @return	int	Teacher ID
	 */
	int getID();

private:

	// Teacher's ID - for internal system use
	int ID;

	// Map of data fields
	std::map< std::string, std::string > dataFields;

	// Map of the teacher's classes
	// key -> classID
	// value -> Class
	std::map< int, Class > classes;


};

#endif