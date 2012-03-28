/**
 * ImageManager.cpp : Implementation for the ImageManager namespace
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "ImageManager.h"

using namespace std;

// Grades the assignment by making an AssignmentImage through
//		ImageEvaluator, then extracing the data and placing it in the 
//		Assignment, for every image in the imagefile
std::vector< vector< string > >
	ImageManager::readAssignmentSetFromImage( std::vector< 
	std::string > theFilenames, int numQ  ) {

	std::vector< std::vector< std::string > > results;
	ImageEvaluator imgEval( numQ );
	vector< string > answers;

	// Reads through each and gets the answers
	for( unsigned int i = 0; i < theFilenames.size(); i++ ) {
		answers = imgEval.readExamImage( theFilenames.at( i ) );;
		results.push_back( answers );
	}
	return results;
}

