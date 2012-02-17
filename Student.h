/**
 * Student.h : Storage class for a Student.  Since all info is stored in 
 *		Assignments and Class and such, it only needs name and ID
 *		NOTE: Post-alpha, will include various other data (age, grade, etc)
 *
 *	@author	Nikko Schaff
 *
 */

#include "stdafx.h"

#ifndef STUDENT_H_
#define STUDENT_H_

// Local header includes
//#include "DataInterface.h"
#include "sqlite3.h"

// System header includes
#include <string>
#include <map>

class Student {

public:

	/**
	 * Constructor for the student
	 *
	 * @param	name	Name of the student
	 *
	 */
	Student( std::map< std::string, std::string > data, int id = -1 );

	/**
	 * Destructor for the student
	 */
	~Student();

	// Declaration of the DataInterface method dbRead
	void dbRead( int id ) ;

	// Declaration of the DataInterface method dbWrite
	void dbWrite( int id );

	// Declaration of the DataInterface method dbIdInside
	bool dbIdInside( int id );

	// Declaration of the DataInterface method putFieldValue
	void putFieldValue( std::string key, std::string value );

	// Declaration of the DataInterface method getFieldValue
	std::string getFieldValue( std::string key );	

	/**
	 * Getter for the ID
	 *
	 * @return	int		studentID
	 *
	 */
	int getID();

private:

	// Student ID - for internal use only
	int ID;

	// Map of data fields
	std::map< std::string, std::string > dataFields;

};

#endif