/**
 * EvalHelper.cpp : Implementation for the EvalHelper class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "stdafx.h"
#include "EvalHelper.h"

using namespace std;

// Constructor for EvalHelper
EvalHelper::EvalHelper( Assignment theAssignment, map< int, Student > theStudentMap,
	vector< string > theFilenames )
:assignment( theAssignment ), studentMap( theStudentMap ), filenames( theFilenames ),
imgEval( theAssignment.getNumQuestions() ) {
}

// Desctructor for EvalHelper
EvalHelper::~EvalHelper() {
}


// Grades the assignment by making an AssignmentImage through
//		ImageEvaluator, then extracing the data and placing it in the 
//		Assignment, for every image in the imagefile
void EvalHelper::gradeAssignment() {
	// TODO
}

// Reads an image through ImageEvaluator, gets the resultant AssignImg,
//		Then extracts and stores the data accordintly
void EvalHelper::readAndStoreImage( std::string filename ) {
	// TODO
}

// Gets the student ID via iteration in Map (may change to DB query later on)
int EvalHelper::getIDFromName( std::string studentName ) {
	// TODO
	return 0;
}

