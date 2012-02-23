/**
 * ImageManager.cpp : Implementation for the ImageManager class
 *
 * @author Nikko Schaff
 * 
 */

// Local header includes
#include "ImageManager.h"

using namespace std;
using namespace cv;


// Constructor for ImageManager
ImageManager::ImageManager( int assignmentId, vector< string > theFilenames )
:assignmentID( assignmentId ), filenames( theFilenames ),imgEval( 20 ) {
	// TODO FIND NUM QUESTIONS FROM ASSIGNMENT
}

// Desctructor for ImageManager
ImageManager::~ImageManager() {
}


// Grades the assignment by making an AssignmentImage through
//		ImageEvaluator, then extracing the data and placing it in the 
//		Assignment, for every image in the imagefile
void ImageManager::gradeEntireAssignment( bool extract ) {

	// First makes sure all files are in the filesystem and extracts extras
	// If chosen
	synchWithFilesystem( extract );

	// Lets the helper method do the reading and storage
	for( unsigned int i = 0; i < filenames.size(); i++ ) {
		readAssignmentImage( filenames.at( i ) );
	}

}

// Reads an image through ImageEvaluator, gets the resultant data tuple
//		Then extracts and stores the data accordintly
void ImageManager::readAssignmentImage( std::string filename ) {
	// TODO find studentID from the name - LATER

	// Read the image
	vector< string > answers = imgEval.readExamImage( filename );
	// Store the name found from imgEval and remove it from the vector
	string studentName = answers.at( answers.size() - 1 );
	answers.pop_back();
	// Find the student's ID via DB query
	int studentID = DBManager::getDataObjectID( "Student", "name", studentName );

	// TODO store resultant data in the database
}

// Synchs files to be into the fileystem, and extracts ones there if specified
void ImageManager::synchWithFilesystem( bool extract ) {
	// TODO - Wait for FSManager to be finished first
	// TODO - ensure that the new filenames are the ones brought back from FSM
}
