/**
 *
 * Helper.h - List of common helper functions used throughout the program 
 *
 * @author Nikko Schaff
 */

#ifndef HELPER_H_
#define HELPER_H_

#include < string >
#include <vector>
#include <sstream>


namespace Helper {

	/**
	 * formatAnswersFromSimple - Returns a vector of answers from the 
	 *	simple format of strings
	 *
	 * @param	answerString	simple-formatted string of question/answers
	 * @return	vector<string>	Vector of simple-format answers
	 */
	std::vector< std::string > formatAnswersFromSimple( std::string answerString );

	/**
	 * formatAnswersFromQB - Returns a vector of anwers from QB-formatted
	 *	string
	 *
	 * @param	answerString	QB-formatted string of question/answers
	 * @return	vector<string>	Vector of QB-format answers
	 */
	std::vector< std::pair< std::string, std::vector< std::string > > >
		formatAnswersFromQB( std::string answerString );

	/**
	 * formatAnswersToSimple - Returns a string of simple format answers for DB
	 * Simple format - answers delimited by commas
	 * Ex: a,b,ac,de
	 *
	 * @param	answerVect	Vector of answers
	 * @return	string	Simple format of answers for DB
	 */
	std::string formatAnswersToSimple( std::vector< std::string > answerVect );


	/**
	 * formatAnswersToQB - Returns a string of QB format answers
	 * QB Format - QuestionID(option#1-5...),
	 * Ex: 154(1,5,3,2,4)+12(1,2,3,4,5)+53(5,2,4,3,1)
	 * 
	 * @param	answerVect	Vector of answers
	 * @return	string	QB format of answers for DB
	 */
	std::string formatAnswersToQB( 
		std::vector< std::pair< std::string, std::vector< std::string > > >
		answerVect );

};

#endif
