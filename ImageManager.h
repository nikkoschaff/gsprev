/**
 * ImageManager.h : Helper class to facilitate image evaluation-based grading
 *
 * @author Nikko Schaff
 *
 */

#ifndef ImageManager_H_
#define ImageManager_H_

// Local header includes
#include "ImageEvaluator.h"

// System header includes
#include <string>
#include <iostream>
#include <vector>


namespace ImageManager {

	/**
	 * Read each file from the given filename and return the answers selected
	 *
	 * @param	theFilenames	Vector of filenames
	 * @param	numQ	Number of questions on the exam
	 * @return	vector< vector< string > >	Each exam with answers, name filled in
	 */
	std::vector< std::vector< std::string > >
		readAssignmentSetFromImage( std::vector< 
		std::string > theFilenames, int numQ );
};


#endif


