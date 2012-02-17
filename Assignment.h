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
//#include "DataInterface.h"
#include "sqlite3.h"

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
	Assignment( std::map< std::string, std::string > data, int numQ, int id = -1 );

	/**
	 * Destructor for the assignment
	 */
	~Assignment();

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
	 * Getter for the assignment ID
	 *
	 * @return	int	AssignmentID
	 *
	 */
	int getID();

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

	/**
	 * Gets the full map of student answers
	 * 
	 * @return	map<int, vector<string> >	studentAnswerMap
	 */
	std::map< int, std::vector< std::string > > getStudentAnswerMap();

private:

	// ID - For internal use only
	int ID;

	// Map of data fields
	std::map< std::string, std::string > dataFields;

	// Number of questions on the assignment
	int numQuestions;

	// Map of answer IDs to answers
	std::vector< std::string > answersList;

	// Map of student IDs to image filenames, not necessary in all implementations
	std::map< int, std::string > imageFilenameMap;

	// Map of the student IDs to the list of their answers
	std::map< int, std::vector< std::string > > studentAnswerMap;


};


#endif