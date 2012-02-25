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
	std::pair< std::vector< std::string >,
		std::vector< std::vector< std::string > > > 
	ImageManager::readAssignmentSetFromImage( std::string theKeyFilename,
		std::vector< std::string > theFilenames, int numQ  ) {

	ImageEvaluator imgEval( numQ );
	vector< string > keyAnswers( imgEval.readExamImage( theKeyFilename ) );
	vector< vector< string > > studentAnswers;

	// Reads through each and gets the answers
	for( unsigned int i = 0; i < theFilenames.size(); i++ ) {
		studentAnswers.push_back( ( imgEval.readExamImage( theFilenames.at( i ) ) ) );
	}

	return pair< vector< string >,
		vector< vector< string > > >( keyAnswers, studentAnswers );
}

