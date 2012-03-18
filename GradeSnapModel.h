

#ifndef GRADESNAPMODEL_H_
#define GRADESNAPMODEL_H_

#include <vector>
#include <string>
#include <iostream>


#include "ImageManager.h"
#include "Grader.h"
#include "DBManager.h"
#include "Statistics.h"

class GradeSnapModel {

public:

	GradeSnapModel(); 


	~GradeSnapModel();


	/**
	 *
	 * At this point, NOTHING is explicitly known about the images.  Only the filenames
	 */
	void evaluateImage( int assignmentID,int classID, 
		std::string keyFilename,
		std::vector< std::string > filenames );

	void printResults( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );
	
	void getStats( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );

	// Returns the student ID if given name was found in the DB,
	//	- Or if any close variations thereof ( John Smit = John Smith )
	// Note - will not work if "(no name)"
	// Returns -1 if not found or if no name
	int findStudentIDFromName( std::string name );

	// Returns a DB-formatted string of answers
	// (Letters delimited by commas)
	std::string answersFromVector( std::vector< std::string > answerVect );


	// Returns a DB-formatted string of questions
	// If using simple answers, format is just list of qIDs (1,4,2,1,3,2,1...)
	// If not, returns "ERROR" (this can only work with simple answers)
	std::string questionsResultsFromAnswers( std::vector< std::string > answers, int assignmentID );

	void setkeyid( int nid );

	void setassignmentid( int nid );

	void setstudentids( std::vector< int > nids );

	void setcurstudentid( int nid );

	int getkeyid();

	int getassignmentid();

	std::vector< int > getstudentids();

	int getselcurstudentid();


	// Selected info
	static int selKeyID;
	static int selAssignmentID;
	static std::vector< int > selStudentIDs;
	static int selcurStudentID;

private:


};

#endif