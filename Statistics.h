/**
 * Statistics.h - Naked functions used to compute statistics
 *
 * @author	Nikko Schaff
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include "DBManager.h"
#include "Grader.h"
#include "Helper.h"

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>
#include <iostream>

namespace Statistics {

	/**
	 * Mean - Returns the average/mean score of the exam
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return	double	Mean score on the exam
	 */
	double mean( int assignmentID, std::vector< int > studentIDs );

	/**
	 * Median - Returns the median value of the exam
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return	double	Median score on the exam
	 */
	double median( int assignmentID, std::vector< int > studentIDs );

	/**
	 * Mode - Returns the most-frequently found score on the exam
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return	pair< int, double >	Mode score on the exam with frequency
	 */
	std::pair< int, double > mode( int assignmentID, std::vector< int > studentIDs );
	
	/**
	 * gradeDistribution - Returns the distribution of grades for each letter
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return	vector< pair< char, double > >	Each letter and it's frequency
	 */
	std::vector< std::pair< char, double > > gradeDistribution( int assignmentID,
		std::vector< int > studentIDs );

	/**
	 * answerAccuracy - Returns correct answer for each Q with frequency chosen
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return vector< pair< string, double > >		Each answer and accuracy
	 */
	std::vector< std::pair< std::string, double > > answerAccuracy( int assignmentID,
		std::vector< int > studentIDs );

	/**
	 * incorrectAnswerAccuracy - Returns each most-chosen wrong answer with frequency
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 *
	 * @return vector< pair< string, double > >		Each most-chosen wrong answer
	 *		with frequency of choice
	 */
	std::vector< std::pair< std::string, double > > incorrectAnswerAccuracy( 
		int assignmentID, std::vector< int > studentIDs );

	/**
	 * StandardDeviation - Returns the standard deviation of scores on the exam
	 *
	 * @param	assignmentID	Assignment ID
	 * @param	studentIDs		Vector of studentIDs
	 * @param	mean	Mean value of the exam (default set to 0.0)
	 *
	 * @return	double	Standard deviation of the exam
	 */
	double standardDeviation( int assignmentID,
		std::vector< int > studentIDs, double mean = 0.0 ); 

};


#endif