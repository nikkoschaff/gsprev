/**
 * Helper.h - Implementation of the Helper module
 *
 * @author	Nikko Schaff
 */


#include "Helper.h"

using namespace std;

// Returns a vector of answers from the simple format of strings
std::vector< std::string > Helper::formatAnswersFromSimple( std::string answerString ) {

	vector< string > lettersVect;
	string at = "";

	for( unsigned int i = 0; i < answerString.size(); i++ ) {
		at = answerString.at( i );

		if( at.compare( "," ) == 0 ) {
			if ( i + 1 < answerString.size() ) {
				string thisAt = "";
				thisAt += answerString.at( i + 1 );
				
				if( thisAt.compare( "," ) == 0 ) {
					lettersVect.push_back( "" );
				}
			}
		} else {
			string letters = "";
			while ( i < answerString.size() && at.compare( "," ) != 0 ) {
				letters += answerString.at( i );
				i++;
				at = answerString.at( i );
			}
			lettersVect.push_back( letters );
			i--;
		}

	}

	return lettersVect;

}

// Returns a vector of answers from QB-formatted string
// TODO
std::vector< std::pair< std::string, std::vector< std::string > > >
	Helper::formatAnswersFromQB( std::string answerString ) {

	vector< pair< string, vector< string > > > lettersVect;

	int index = 0;
	int prevIndex = 0;

	// Gets the ID of the question
	while( index < answerString.size() ) {
		if( answerString.substr( index, 1 ).compare( "+" ) == 0 ) {

			lettersVect.push_back( answerString.substr( prevIndex, index-1 ) );
			prevIndex = index+1;
		}

		index++;
	}

	return lettersVect;
}


// Returns a string of simple format answer
string Helper::formatAnswersToSimple( vector< string > answerVect ) {

	string simpleString;
	stringstream stream;

	for( int i = 0; i < answerVect.size(); i++ ) {
		stream << answerVect.at( i ) << ",";
	}
	
	simpleString = stream.str();
	simpleString = simpleString.substr( 0, simpleString.length() - 2 );

	return simpleString;
}


// Returns a string of QB format answer
std::string Helper::formatAnswersToQB( 
	std::vector< std::pair< std::string, std::vector< std::string > > >
	answerVect ) {

	string qbAns;
	string qbMini;
	// Add each question in vector to the string
	for( int i = 0; i < answerVect.size(); i++ ) {
		// Add ID and opening paren
		qbMini = answerVect.at( i ).first + "(";
		// Add option order
		for( int k = 0; i < answerVect.at( i ).second.size(); k++ ) {
			qbMini = qbMini + answerVect.at( i ).second.at( k ) + ",";
		}
		// Replace last comma with )+
		qbMini.replace( qbMini.size() -1, ")+" );

		// Add to final answer
		qbAns.append( qbMini );
	}
	return qbAns;
}




