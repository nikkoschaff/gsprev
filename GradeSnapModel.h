/**
 * GradeSnapModel.h - General-use model used throughout the program for a single user.
 *	Contains data about currently-selected user (current keyID, etc)
 *	Also has methods used to simplify entry between the GUI and the underlying tech
 * 
 * @author	Nikko Schaff
 */

#ifndef GRADESNAPMODEL_H_
#define GRADESNAPMODEL_H_

#include <vector>
#include <string>
#include <iostream>


#include "ImageManager.h"
#include "Grader.h"
#include "DBManager.h"
#include "Statistics.h"
#include "Helper.h"

class GradeSnapModel {

public:

	/**
	 * GradeSnapModel - Constructor for GradeSnapModel
	 */
	GradeSnapModel(); 

	/**
	 * ~GradeSnapModel - Destructor for GradeSnapModel
	 */
	~GradeSnapModel();


	/**
	 * EvaluateImage - Evalutes the image based on the key and given images
	 * At this point, NOTHING is explicitly known about the images.  Only the filenames
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	classID			ClassID
	 * @param	keyFilename		Filename of the key
	 * @param	filenames		Vector of the students' filenames
	 */
	void evaluateImage( int assignmentID,int classID, 
		std::string keyFilename,
		std::vector< std::string > filenames );

	/**
	 * printResults - Prints the results to standard I/O
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	classID			ClassID
	 * @param	studentIDs		Vector of student IDs
	 */
	void printResults( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );
	
	/**
	 * getStats - Prints the results of the statistics for an assignment
	 *	to standard I/O
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	classID			ClassID
	 * @param	studentIDs		Vector of student IDs
	 */
	void getStats( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );

	// Returns the student ID if given name was found in the DB,
	//	- Or if any close variations thereof ( John Smit = John Smith )
	// Note - will not work if "(no name)"
	// Returns -1 if not found or if no name
	int findStudentIDFromName( std::string name, int assignmentID, int classID );

	/**
	 * setKeyId - Sets the selected key ID
	 *
	 * @param	nid		New key ID
	 */
	void setKeyID( int nid );


	/**
	 * setAssignmentID - Sets the selected assignment ID
	 *
	 * @param	nid		New assignment ID
	 */
	void setAssignmentID( int nid );


	/**
	 * setstudentids - Sets the selected student IDs
	 *
	 * @param	nids	Vector of new student IDs
	 */
	void setStudentIDs( std::vector< int > nids );


	/**
	 * setCurStudentID - Sets the currently-selected student ID
	 *
	 *
	 */
	void setCurStudentID( int nid );

	/**
	 * getKeyID - Gets the selected key ID
	 *
	 * @return	int	selected key ID
	 */
	int getKeyID();

	/**
	 * getAssignmentID - Gets the selected assignmentID
	 *
	 * @return	int	selected assignmentID
	 */
	int getAssignmentID();

	/**
	 * getStudentIDs - Gets the selected student IDs
	 *
	 * @return	vector< ing >	selected student IDs
	 */
	std::vector< int > getStudentIDs();

	/**
	 * getSelCurStudentID - Sets the currently-selected student
	 *
	 * @return	int	Currently-selected student ID
	 */
	int getSelCurStudentID();


	// Selected Key ID
	static int selKeyID;

	// Selected assignment ID
	static int selAssignmentID;

	// Selected studentIDs
	static std::vector< int > selStudentIDs;

	// Currently-selected Student ID
	static int selcurStudentID;

private:


};

#endif