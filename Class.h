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
	// TODO reflect changes/add more in DD for different inputs for class constructor
	Class( std::string theName ); 

	/**
	 * Destructor for the Class
	 */
	~Class();

	/**
	 * Grades exam from direct input - text/spreadsheet, user input, etc
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
	void gradeAssignment( int assignmentID, std::map< int, std::vector< std::string > >
		studentAnswersMap, std::vector< std::string > filenames );

	/**
	 * Getter for the class name
	 *
	 * @return	string	Class name
	 *
	 */
	std::string getName();


	/**
	 * Setter for the class name
	 *
	 * @param	newName	New class name
	 *
	 */
	void setName( std::string newName );

	/**
	 * Getter for the class ID
	 *
	 * @return	int	Class ID
	 *
	 */
	int getID();

	/**
	 * Gets the student ID from a given name (may use iteration for now, when 
	 *	set up with a DB will likely use querying)
	 *
	 * @param	name	Name of the student to search
	 * @return	int		Student's ID
	 */
	int getStudentIDFromName( std::string name );

	/**
	 * Getter for total points
	 *
	 * @return	int	Total points in the class
	 *
	 */
	int getTotalPoints();

	/**
	 * Setter for the total points
	 *
	 * @param	points	New total points for the class
	 *
	 */
	void setTotalPoints( int points );

	/**
	 * Gets a given assignment in the class map by ID
	 *
	 * @param	assignmentID	int ID of the assignment
	 * @return	Assignment		Assignment
	 *
	 */
	Assignment getAssignment( int assignmentID );



private:


	// Name of the class
	std::string name;

	// ID of the class - for internal use only
	int ID;

	// Mapping of student IDs to the student
	std::map< int, Student > studentMap;

	// Total points in a class, typically at 100 but can vary
	int totalPoints;

	// Mapping of assignment IDs to Assignments
	std::map< int, Assignment > assignmentMap;

};



#endif