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

// System header includes
#include <string>

class Student {

public:

	/**
	 * Constructor for the student
	 *
	 * @param	name	Name of the student
	 *
	 */
	Student( std::string newName );

	/**
	 * Destructor for the student
	 */
	~Student();

	/**
	 * Setter for the student name
	 *
	 * @param	name	New student name
	 *
	 */
	void setName( std::string newName );

	/**
	 * Getter for the name
	 *
	 *
	 * @return	string	Student name
	 */
	std::string getName();


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

	// Student name
	std::string name;

};

#endif