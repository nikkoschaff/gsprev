

#ifndef GRADESNAPMODEL_H_
#define GRADESNAPMODEL_H_

#include <vector>
#include <string>


#include "ImageManager.h"
#include "Grader.h"
#include "DBManager.h"

class GradeSnapModel {

public:

	GradeSnapModel(); 


	~GradeSnapModel();

	// At this level the student-ID pair should already be made
	void evaluateImage( int assignmentID,int classID,
		std::string keyFilename, std::vector< std::string > filenames );

	void printResults( int assignmentID, int classID, std::string keyfilename );
	
	void getStats( int assignmentID, int classID );





};

#endif