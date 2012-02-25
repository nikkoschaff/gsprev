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
	 * Grades the assignment by making an AssignmentImage through
	 *		ImageEvaluator, then extracing the data and placing it in the 
	 *		Assignment, for every image in the imagefile
	 *
	 * @param	extract		Flag to tell if files should be extracted from fs
	 */
	std::pair< std::vector< std::string >,
		std::vector< std::vector< std::string > > > 
		readAssignmentSetFromImage( std::string theKeyFilename,
		std::vector< std::string > theFilenames, int numQ );

};


#endif


