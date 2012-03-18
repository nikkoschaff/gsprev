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
	std::vector< std::pair< int, std::vector< std::string > > >
		ImageManager::readAssignmentSetFromImage( std::vector< 
		std::pair< int, std::string > > theFilenames, int numQ  ) {

	std::vector< std::pair< int, std::vector< std::string > > > results;
	ImageEvaluator imgEval( numQ );
	vector< string > answers;
	int id;
	
	// Reads through each and gets the answers
	for( unsigned int i = 0; i < theFilenames.size(); i++ ) {
		answers = imgEval.readExamImage( theFilenames.at( i ).second );
		id = theFilenames.at( i ).first;
		results.push_back( pair< int, vector< string > >( id, answers ) );
	}
	return results;
}

