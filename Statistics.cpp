/**
 * Statistics.cpp - Implementation for the Statistics module
 *
 * @author	Nikko Schaff
 */


#include "Statistics.h"


using namespace std;


// Gets the average score
double Statistics::mean( int assignmentID, std::vector< int > studentIDs ) {

	vector< int > ids;
	double total = 0;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the grades for the corresponding
	for( unsigned int i = 0; i < ids.size(); i++ ) {
		total += strtod( ( DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( i ), "grade" ) ).c_str(), NULL );
	}
	
	// Return average score
	return total/ids.size();
}

// Returns the median value
double Statistics::median( int assignmentID, std::vector< int > studentIDs  ) {

	vector< int > ids;
	vector< double > results;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the grades for the corresponding
	for( unsigned int i = 0; i < ids.size(); i++ ) {
		results.push_back( strtod( ( DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( i ), "grade" ) ).c_str(), NULL ) );
	}

	// Sort and return the size
	sort( results.begin(), results.end() );
	return results.at( results.size() / 2 );
}

// Gets the mode
pair< int, double > Statistics::mode( int assignmentID, std::vector< int > studentIDs ) {

	vector< int > ids;
	vector< double > results;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the grades for the corresponding
	for( unsigned int i = 0; i < ids.size(); i++ ) {
		results.push_back( strtod( ( DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( i ), "grade" ) ).c_str(), NULL ) );
	}

	sort( results.begin(), results.end() );
	double num = 0;
	int count = 0;
	int max = 0;
	double mode = 0;
	for( unsigned int i = 0; i < results.size(); i++ ) {

		if ( num != results.at( i ) ) {
			num = results.at( i );
			count = 1;
		} else {
			count++;
		}

		if ( count > max ) {
			max = count;
			mode = num;
		}
	}
	pair< int, double > modePair( max, mode );

	return modePair;
}

// Gets the accuracy for each question
// TODO fix
std::vector< std::pair< std::string, double > > Statistics::answerAccuracy( int assignmentID,
		std::vector< int > studentIDs ) {

	vector< int > ids;
	vector< pair< string, double > > results;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the answers from the key
	int key = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
		keyID, "AssignmentID", "StudentID" ).at( 0 ).c_str() );
	string keyAnswers = DBManager::getDataObjectValue( "LinkerStudentAssignment", 
		key, "answers" );

	// Set up key vector and use to set up results
	vector< string > keyVect = Statistics::getLettersVector( keyAnswers );
	for( unsigned int i = 0; i < keyVect.size(); i++ ) {
		results.push_back( pair< string, double >( keyVect.at( i ), 0 ) );
	}

	// Get the answers from the studentID and add 1 to results for every correct one
	vector< string > answersVect;
	for( unsigned int sIndex = 0; sIndex < ids.size(); sIndex++ ) {
		
		// String of student answers
		string studentAnswers = DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( sIndex ), "answers" );

		answersVect = Statistics::getLettersVector( studentAnswers );

		// Through every answer - grade here and add 1 to results if good
		for( unsigned int i = 0; i < keyVect.size(); i++ ) {
			if ( i < answersVect.size() && 
				( answersVect.at( i ).compare( keyVect.at( i ) ) == 0 ) ) {
				results.at( i ).second = results.at( i ).second + 1;
			}
		}
		
	}

	// Goes through results and derives the average for each answer from given total
	for( unsigned int i = 0; i < results.size(); i++ ) {
		results.at( i ).second = ( results.at( i ).second / ids.size() ) * 100;
	}
	
	return results;
}

// Percentage of the most-chosen incorrect answers
// TODO fix
std::vector< std::pair< std::string, double > > Statistics::incorrectAnswerAccuracy( 
		int assignmentID, std::vector< int > studentIDs ) {


	vector< pair< string, double > > badAnswers;
	
	vector< int > ids;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the answers from the key
	int key = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
		keyID, "AssignmentID", "StudentID" ).at( 0 ).c_str() );
	string keyAnswers = DBManager::getDataObjectValue( "LinkerStudentAssignment", 
		key, "answers" );	

	// Vector to hold every answer entered for each question asked
	vector< map< string, int > > fullAnswers = vector< map< string, int > >();

	// Set up key vector and use to set up results
	vector< string > keyVect = Statistics::getLettersVector( keyAnswers );
	for( unsigned int i = 0; i < keyVect.size(); i++ ) {
		results.push_back( pair< string, double >( keyVect.at( i ), 0 ) );
	}

	vector< string > studentVect;

	// Get the answers from the studentID and add 1 to results for every correct one
	vector< string > answersVect;
	map< string, int >::iterator mapIt;
	for( unsigned int sIndex = 0; sIndex < ids.size(); sIndex++ ) {
		
		// String of student answers
		string studentAnswers = DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( sIndex ), "answers" );

		answersVect = Statistics::getLettersVector( studentAnswers );

		// Either adds a blank or a character, or increments the count if already there
		for( unsigned int i = 0; i < keyVect.size(); i++ ) {
			if ( i >= answersVect.size() ) {
				if( ( mapIt = fullAnswers.at( i ).find( "" ) ) == fullAnswers.end() ) {
					fullAnswers.at( i ).insert( pair< string, int >( "", 0 ) );
				} else {
					fullAnswers.at( i ).find( "" )->second++;
				}
			} else {
				if( ( mapIt = fullAnswers.at( i ).find( answersVect.at( i ) ) ) == fullAnswers.end()  ) {
					fullAnswers.at( i ).insert( pair< string, int >( answersVect.at( i ), 0 ) );
				} else {
					fullAnswers.at( i ).find( answersVect.at( i ) )->second++;
				}
			}

		}		
	}

	// Find (incorrect) letter with highest frequency.  Save % in badAnswers
	pair< string, double > letterAndFreq;
	for( unsigned int i = 0; i < fullAnswers.size(); i++ ) {

		string letter;
		int freq = 0;
		double freqPercentage;

		for( mapIt = fullAnswers.at( i ).begin();
			mapIt != fullAnswers.at( i ).end(); i++ ) {

			if( mapIt->second > freq && mapIt->first.compare( keyVect.at( i ) ) != 0 ) {
				freq = mapIt->second;
				letter = mapIt->first;
			}
		}

		freqPercentage = freq / studentIDs.size();

		badAnswers.push_back( pair< string, double >( letter, freqPercentage ) );
	}
	return badAnswers;
}

// Shows the distribution for letter grades
std::vector< std::pair< char, double > > Statistics::gradeDistribution( int assignmentID,
	std::vector< int > studentIDs ) {

	vector< pair< char, double > > dist;
	for( unsigned int i = 0; i < 5; i++ ) {
		dist.push_back( pair< char, double >( 'a', 0 ) );
	}
	dist.at( 0 ).first = 'A';
	dist.at( 1 ).first = 'B';
	dist.at( 2 ).first = 'C';
	dist.at( 3 ).first = 'D';
	dist.at( 4 ).first = 'F';

	// Get the IDs of the rows containing the grades and set them
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		int sID = ( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );

		double grade = ( atol( DBManager::getDataObjectValue( "LinkerStudentAssignment", sID,
			"grade" ).c_str() ) );

		if ( grade <= 100 && grade >= 90 ) {
			dist.at( 0 ).second++;
		} else if ( grade < 90 && grade >= 80 ) {
			dist.at( 1 ).second++;
		} else if ( grade < 80 && grade >= 70 ) {
			dist.at( 2 ).second++;
		} else if ( grade < 70 && grade >= 65 ) {
			dist.at( 3 ).second++;
		} else {
			dist.at( 4 ).second++;
		}
	}

	// Goes through results and derives the average for each answer from given total
	for( unsigned int i = 0; i < dist.size(); i++ ) {
		dist.at( i ).second = ( dist.at( i ).second / studentIDs.size() ) * 100;
	}

	return dist;
}

// normal distribution
double Statistics::standardDeviation( int assignmentID,
	std::vector< int > studentIDs, double mean  ) {

	vector< int > ids;
	vector< double > grades;
	double total = 0;

	// Get the IDs of the rows containing the grades
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		ids.push_back( atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID,
			studentIDs.at( i ), "AssignmentID", "StudentID" ).at( 0 ).c_str() ) );
	}

	// Get the grades for the corresponding
	for( unsigned int i = 0; i < ids.size(); i++ ) {
		grades.push_back( strtod( ( DBManager::getDataObjectValue( "LinkerStudentAssignment",
			ids.at( i ), "grade" ) ).c_str(), NULL ) );
		total += grades.at( grades.size() - 1 );
	}
	
	//Get the mean
	if ( mean == 0.0 ) {
		mean =  total/ids.size();
	}


	double numerator = 0;
	double denominator = grades.size();

	for( unsigned int i = 0; i < denominator; i++ ) {
		numerator = numerator + pow( ( grades.at( i ) - mean ), 2 );
	}

	double standardDeviation = sqrt ( numerator / denominator );

	return standardDeviation;
}

