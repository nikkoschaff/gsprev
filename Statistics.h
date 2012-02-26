// Module for statistic functions - namespace

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include "DBManager.h"
#include "Grader.h"

#include <string>
#include <vector>
#include <algorithm>

namespace Statistics {

	// Gets the average score
	double mean( int assignmentID, std::vector< int > studentIDs );

	// Returns the median value
	double median( int assignmentID, std::vector< int > studentIDs );

	// Gets the mode of the assignment
	std::pair< int, double > mode( int assignmentID, std::vector< int > studentIDs );
	
	// Shows the distribution for letter grades
	std::vector< std::pair< char, double > > gradeDistribution( int assignmentID,
		std::vector< int > studentIDs, int keyID );

	// accuracy (show percentage right for each question in exam)
	std::vector< std::pair< std::string, double > > answerAccuracy( int assignmentID,
		std::vector< int > studentIDs, int keyID );

	// TODO normal distribution (don't implement until header is good)
	// Mention if there IS NO normal distribution
	std::vector< int > standardDeviation( int assignmentID,
		std::vector< int > studentIDs ); 



	// Helper function to get an array of letters from the answer letters
	std::vector< std::string > getLettersVector( std::string answers );

};


#endif