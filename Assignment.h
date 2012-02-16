/**
 * Assignment.h : Data storage for assignment information
 *
 * @author Nikko Schaff
 *
 */

#include "stdafx.h"

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_


// Local header includes

// System header includes
#include <string>
#include <map>
#include <vector>


class Assignment {

public:

	/**
	 * Constructor for the assignment
	 *
	 * @param	name	Name of the assignment
	 *
	 */
	// TODO reflect changes for including name, weight, and number of questions in constructor
	Assignment( std::string theName );


	/**
	 * Destructor for the assignment
	 */
	~Assignment();

	/**
	 * Getter for the assignment ID
	 *
	 * @return	int	AssignmentID
	 *
	 */
	int getID();

	/**
	 * Getter for the assignment name
	 *
	 * @return	string	Assignment name
	 *
	 */
	std::string getName();

	/**
	 * Setter for the assignment name
	 *
	 * @param newName	String of the new name
	 *
	 */
	void setName( std::string newName );

	/**
	 * Setter for the number of questions on the assignment
	 *
	 * @param	numQ	Integer number of questions for the assignment
	 *
	 */
	void setNumQuestions( int numQ );

	/**
	 * Getter for the number of questions on the assignment
	 *
	 * @return	int	Number of questions on an exam
	 *
	 */
	int getNumQuestions();

	/**
	 * Getter for the due date on the assignment
	 *
	 * @return	string	string representation of the due date
	 * 
	 */
	std::string getDueDate();

	/**
	 * Setter for the due date on the assignment
	 *
	 * @param	string	string of the due date
	 * 
	 */
	void setDueDate( std::string newDueDate );

	/**
	 * Getter for the date when the assignment was assigned to students
	 *
	 * @return	string	String of the assigned date
	 * 
	 */
	std::string getAssignedDate();

	/**
	 * Setter for the date the assignment will be given to students
	 *
	 * @param	newAssignedDate	Assignment date
	 * 
	 */
	void setAssignedDate( std::string newAssignedDate );

	/**
	 * Places an answer at the given index
	 * 
	 * @param	int		The index expected (answerID)
	 * @param	string	The new answer
	 * 
	 */
	void putAnswer( int answerID, std::string answer );

	/**
	 * Getter for an answer at a given index
	 *
	 * @param	int		Index expected (answerID)
	 * @return	string	Answer for the question at the index queried
	 */
	std::string getAnswer( int answerID );

	/**
	 * Puts a filename of an assignment image in the map, keyed to the studentID
	 *
	 * @param	studentID	student's ID
	 * @param	filename	Filename of the assignment image on disk
	 */
	void putFilename( int studentID, std::string filename );

	/**
	 * Gets the assignment filename of the given student on this assignment
	 *
	 * @param	studentID	Student's ID
	 * @return	string		Image filename
	 */
	std::string getFilename( int studentID );

	/**
	 * Sets the date that a student handed in this assignment
	 *
	 * @param	handInDate	Date that the student handed in this assignment
	 * 
	 */
	void setHandInDate( int studentID, std::string handInDate );

	/**
	 * Gets the hand in date for this assignemnt for the given student
	 *
	 * @param	studentID	Student's ID
	 * @return	string		Student's date of handing in the assignment
	 */
	std::string getHandInDate( int studentID );

	/**
	 * Puts a student's answer in their answers vector
	 *
	 * @param	studentID	Student's ID number
	 * @param	index		Index of the answer
	 * @param	answer		String of the student's answer
	 *
	 */
	void setStudentAnswer( int studentID, int index, std::string answer );

	/**
	 * Sets the student's answer array all at once
	 *
	 * @param	studentID	Student's ID number
	 * @param	vector<string>	Vector containing all of the student's answers	
	 * 
	 */
	// TODO reflect changes of full vector in the map
	void setStudentAnswerArray( int studentID, std::vector< std::string >
		answers );

	/**
	 * Gets a student's answer in their answers vector
	 *
	 * @param	studentID	Student's ID number
	 * @param	index		Index of the answer
	 * 
	 * @return	string		String of the student's answer
	 *
	 */
	std::string getStudentAnswer( int studentID, int index );

	/**
	 * Gets the full array of student's answers for this assignment
	 *
	 * @param	studentID	Student's ID number
	 *
	 * @return	vector<string>	Vector containing student's answers
	 *
	 */
	// TOODO reflect in design document
	std::vector< std::string > getStudentAnswerArray( int studentID );

private:

	// ID - For internal use only
	int ID;

	// Name of the assignment
	std::string name;

	// Weight of the assignment, assumed to be between 0 and 100
	double weight;

	// Number of questions on the assignment
	int numQuestions;

	// String detailing the due date
	std::string dueDate;

	// String of the date assigned to students
	std::string assignedDate;

	// Map of answer IDs to answers
	std::vector< std::string > answersList;

	// Map of student IDs to image filenames, not necessary in all implementations
	std::map< int, std::string > imageFilenameMap;

	// Map of the student IDs to the hand-in date
	std::map< int, std::string > studentHandInDateMap;

	// Map of the student IDs to the list of their answers
	std::map< int, std::vector< std::string > > studentAnswerMap;


};


#endif