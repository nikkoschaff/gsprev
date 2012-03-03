

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

	// At this level the student-ID pair should already be made
	void evaluateImage( int assignmentID,int classID, 
		std::pair< int, std::string > keyFilePair,
		std::vector< std::pair< int, std::string > > filenames, int numQ );

	void printResults( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );
	
	void getStats( int assignmentID, int classID, int keyID,
		std::vector< int > studentIDs );


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