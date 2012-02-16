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
	Teacher( std::string newName );

	/**
	 * Constructor for the Teacher
	 *
	 * @param	name	The name of the teacher
	 * @param	classes	The map of classes to be added
	 *
	 */
	Teacher( std::string newName, std::map< int, Class > newClasses );

	/**
	 * Destructor for the teacher
	 */
	~Teacher();

	/**
	 * Puts a class into the classes map
	 *
	 * @param	classID	Class ID
	 * @param	class	Class to be added
	 */
	// TODO reflect change in DD
	void putClass( int classID, Class theClass );

	/**
	 * Gets a class from the list based on ID
	 *
	 * @param	classID	The ID of the class
	 */
	// TODO reflect change in DD
	Class getClass( int classID );

	/**
	 * Getter for the Teacher ID
	 *
	 * @return	int	Teacher ID
	 */
	// TODO reflect change in DD
	int getID();

	/**
	 * Getter for the Teacher name
	 *
	 * @return	string	Teacher name
	 */
	// TODO reflect change in DD
	std::string getName();

	/**
	 * Setter for the Teacher name
	 *
	 * @param	string	New Teacher name
	 */
	// TODO reflect change in DD
	void setName( std::string newName );

private:

	// Teacher's ID - for internal system use
	int ID;

	// Teacher's name
	std::string name;

	// Map of the teacher's classes
	// key -> classID
	// value -> Class
	std::map< int, Class > classes;

};

#endif