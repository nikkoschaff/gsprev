

#include "GradeSnap.h"


#include <iostream>
using namespace std;

int main ( int argc, char* argv[] ) {



	// Beta Testing algorithm
	cout << "Welcome to GradeSnap!" << endl << endl;

	// Gets number of questions on exam
	int numVerify = 0;
	int numQuestions = 5;
	/*
	while( numVerify == 0 ) {
		char numQChar[ 4 ];
		cout << "How many questions will there be on this exam? (1-50): ";
		cin >> numQChar;
		cout << endl;
		numQuestions = atoi( numQChar );
		if ( numQuestions < 1 || numQuestions > 50 ) {
			cout << "Oops! -- Number of questions entered incorrectly. " << 
				"Will be discarded. -- " << endl << endl;
		} else {
			numVerify++;
		}
	}

	*/
	// Gets the key file name
	int fileVerify = 0;
	string keyFilename = "s2-2.jpeg";
	/*
	while ( fileVerify == 0 ) {
		keyFilename = "";
		cout << "Please enter the name of the key file (with file extension): ";
		cin >> keyFilename;
		cout << endl;
		transform( keyFilename.begin(), keyFilename.end(), keyFilename.begin(), tolower );

		// Checking for proper names and extensions

		// Index of the dot for extension
		int dotIndex = keyFilename.find( '.' );

		// Return false if no dot '.'
		if ( dotIndex == -1 ) {
			if ( keyFilename.compare( "end" ) != 0 ) {
				cout << "Oops! -- Bad file input.  Will be discarded -- " << endl << endl;
			}
		} else {

			// Checks if the extension is allowed
			string extension = keyFilename.substr( dotIndex, ( keyFilename.size() - dotIndex ) );
			if ( ( extension.compare( ".jpg" ) == 0 )
				|| ( extension.compare( ".bmp" ) == 0 ) 
				|| ( extension.compare( ".dib" ) == 0 ) 
				|| ( extension.compare( ".jpeg" ) == 0 ) 
				|| ( extension.compare( ".jpe" ) == 0 ) 
				|| ( extension.compare( ".png" ) == 0 ) 
				|| ( extension.compare( ".pbm" ) == 0 ) 
				|| ( extension.compare( ".pgm" ) == 0 ) 
				|| ( extension.compare( ".ppm" ) == 0 ) 
				|| ( extension.compare( ".sr" ) == 0 ) 
				|| ( extension.compare( ".ras" ) == 0 ) 
				|| ( extension.compare( ".tff" ) == 0 ) 
				|| ( extension.compare( ".tiff" ) == 0 ) ) {

				
				//Checks if the file actually now exists
				FILE * kFile;
				kFile = fopen( keyFilename.c_str(), "r" );
				if ( kFile != NULL ) {
					fileVerify++;
				} else {
					cout << "Oops! -- Bad file input.  Will be discarded -- "
						<< endl << endl;
				}
				kFile = 0;

			} else {
				cout << "Oops! -- Bad file input.  Will be discarded -- "
					<< endl << endl;
			}

		}


	}
	*/

	// Gets student exam filenames
	vector< string > studentExamFilenames;
	studentExamFilenames.push_back( "s2-2.jpeg" );
	/*
	string testFilename;
	string end( "end" );

	// Continue to take in student exam filenames
	cout << "Entering student exam file names. " << 
		"Type 'end' (no quotes), hit enter to finish" << endl << endl;
	while ( testFilename.compare( end ) != 0 ) {
		testFilename = "";
		cout << "Please test file name with file extension: ";
		cin >> testFilename;
		cout << endl;
		// Turns the filename to lower-case
		transform( testFilename.begin(), testFilename.end(), testFilename.begin(), tolower );

		// Checking for proper names and extensions

		// Index of the dot for extension
		int dotIndex = testFilename.find( '.' );

		// Return false if no dot '.'
		if ( dotIndex == -1 ) {
			if ( testFilename.compare( "end" ) != 0 ) {
				cout << "Oops! -- Bad file input.  Will be discarded -- " << endl << endl;
			} 
		} else {
			// Checks if the extension is allowed
			string extension = testFilename.substr( dotIndex, ( testFilename.size() - dotIndex ) );
			if ( ( extension.compare( ".jpg" ) == 0 )
				|| ( extension.compare( ".bmp" ) == 0 ) 
				|| ( extension.compare( ".dib" ) == 0 ) 
				|| ( extension.compare( ".jpeg" ) == 0 ) 
				|| ( extension.compare( ".jpe" ) == 0 ) 
				|| ( extension.compare( ".png" ) == 0 ) 
				|| ( extension.compare( ".pbm" ) == 0 ) 
				|| ( extension.compare( ".pgm" ) == 0 ) 
				|| ( extension.compare( ".ppm" ) == 0 ) 
				|| ( extension.compare( ".sr" ) == 0 ) 
				|| ( extension.compare( ".ras" ) == 0 ) 
				|| ( extension.compare( ".tff" ) == 0 ) 
				|| ( extension.compare( ".tiff" ) == 0 ) ) {



				//Checks if the file actually now exists
				FILE * tFile;
				tFile = fopen( testFilename.c_str(), "r" );
				if ( tFile != NULL ) {
					studentExamFilenames.push_back( testFilename );
				} else {
					cout << "Oops! -- Bad file input.  Will be discarded -- "
						<< endl << endl;
				}
				tFile = 0;


			} else {
				cout << "Oops! -- Bad file input.  Will be discarded -- "
					<< endl << endl;
			}
		}
	}
	*/


	//Checks to see if there was no file name entered
	if ( studentExamFilenames.size() == 0 ) {
		cout << "No student exam filenames entered.  "
			<< "Program will now close." << endl;
		
		int stop = 1;
		cout << "Press any key and enter to exit ";
		cin >> stop;
		return( 1 );
	}


	DBManager::db_init();
	// TODO clear the database for testing purposes (LATER-ish)

	
	// --- TOP LEVEL ----  
	int classID = 1;
	int assignmentID = 1;

	// Create key, link to assignment, set filename
	int keyID =	DBManager::makeDataObject( "Student", keyFilename );

	DBManager::linkAToB( "LinkerStudentAssignment", assignmentID, "AssignmentID", 
		keyID, "StudentID" );
	DBManager::setLinkedValues( "LinkerStudentAssignment", keyID, assignmentID, 
		"StudentID", "AssignmentID", "key", "YES" );
	DBManager::setLinkedValues( "LinkerStudentAssignment", keyID, assignmentID,
		"StudentID", "AssignmentID", "filename", keyFilename );

	// Pair for use in the model
	pair< int, string > keyFilePair( keyID, keyFilename );

	// Vector of pairs for the student IDs and filenames
	vector< pair< int, string > > studentFilePairs;
	// Vector of student IDs
	vector< int > studentIDs;

	// Gets student IDs by setting them to be in the DB and finding their ID
	//	Links the necessary student data and pushes their info into the pair vector
	for( unsigned int i = 0; i < studentExamFilenames.size(); i++ ) {
		string name = studentExamFilenames.at( i );

		// Extracts information about the studentID and places corresponding
		//	student data into the database
		int sID = DBManager::makeDataObject( "Student", name );
		DBManager::linkAToB( "LinkerStudentAssignment", assignmentID, "AssignmentID", 
			sID, "StudentID" );
		DBManager::linkAToB( "LinkerClassStudent", classID, "ClassID", sID, "StudentID" );
		DBManager::setLinkedValues( "LinkerStudentAssignment", sID, assignmentID,
			"StudentID", "AssignmentID", "filename", name );
		// Pushes student ID and name to the student pair vector
		studentFilePairs.push_back( pair< int, string >( sID, name ) );
		studentIDs.push_back( sID );
	}

	GradeSnapModel gsm;
	gsm.evaluateImage( assignmentID, classID, keyFilePair, studentFilePairs, numQuestions );
	gsm.printResults( assignmentID, classID, keyID, studentIDs  );


	int x;
	cin >> x;
	DBManager::db_close();


	return 0;
}