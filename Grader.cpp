
#include "Grader.h"

using namespace std;

// Main lead-in function for grading
// ALL it does is call the helper function to get the grade,
//	Then sets the score and answers
void Grader::grade( int assignmentID, int keyID,
	vector< int > studentIDs ) { 

	bool usingStrict = false;
	int usingStrictInt = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "strictGrading" ).c_str() );
	if( usingStrictInt == 1 ) usingStrict = true;

	bool usingSimple;
	int usingSimpleInt = atoi( DBManager::getDataObjectValue( "Assignment", 
		assignmentID, "usingSimpleAnswers" ).c_str() );
	if( usingSimpleInt == 1 ) usingSimple = true;

	// Gets the grade, sets the score
	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {

		// Get score and convert type to double for db assignment
		double score = ( 
			Grader::gradeSimpleAssignment( assignmentID, studentIDs.at( i ),
				usingStrict ) * 100);

		string stringScore;
		stringstream s;
		s << score;
		stringScore = s.str();

		// Stores newfound grades to database
		DBManager::setLinkedValues( "LinkerStudentAssignment", studentIDs.at( i ), assignmentID, 
			"StudentID", "AssignmentID", "grade", stringScore );
	}
}

// Helper to grade a single assignment
double Grader::gradeSimpleAssignment( int assignmentID, int studentID,
	bool strict ) {

	double numCorrect = 0.0;

	int LSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID, studentID,
		"AssignmentID", "StudentID" ).at( 0 ).c_str() );
	vector< string > answers = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > key = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( unsigned int i = 0; i < key.size(); i++ ) {
			if( key.at( i ).compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( unsigned int i = 0; i < key.size(); i++ ) {
			for( unsigned int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
				if( key.at( i ).find( anslet ) != string::npos ) {
					numCorrect += 1 / key.at( i ).size();
				}
			}
		}
	}

	double finalScore = abs( numCorrect / key.size() );
	return finalScore;

}

// Helper to grade QB-based assignment
double Grader::gradeQBAssignment( int assignmentID, int studentID, bool strict ) {

	double numCorrect = 0.0;
	int LSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", assignmentID, studentID,
		"AssignmentID", "StudentID" ).at( 0 ).c_str() );
	vector< string > answers = getLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "answers" ) );
	vector< string > questions = getQBLettersVector(
		DBManager::getDataObjectValue( "LinkerStudentAssignment", LSAID, "questions" ) );

	// String of answers in answer format (from questions thorugh DB parsing)
	string qKey;


	if( strict ) {
		// Grades by only saying if answer matches key exactly
		for( unsigned int i = 0; i < questions.size(); i++ ) {
			qKey = answerLettersFromQB( questions.at( i ) );
			if( qKey.compare( answers.at( i ) ) == 0 ) {
				numCorrect++;
			}
		}
	} else {
		// Grades by giving partial credit as percentage of answers
		// (ex: answered 1/2, numCorrect += .5)
		for( unsigned int i = 0; i < questions.size(); i++ ) {
			qKey = answerLettersFromQB( questions.at( i ) );
			for( unsigned int anslet = 0; anslet < answers.at( i ).size(); anslet++ ) {
				if( qKey.find( anslet ) != string::npos ) {
					numCorrect += 1 / qKey.size();
				}
			}
		}
	}
	double finalScore = abs( numCorrect / questions.size() );
	return finalScore;
}

// Helper function to get the letters of the corect answers (in answer format)
std::string Grader::answerLettersFromQB( std::string question ) {

	string qID = "";
	int index = 0;
	vector< string > options;
	string optionstr;
	string goodLetter;

	// Gets the ID of the question
	while( index < question.size() && question.substr( index, 1 ).compare( "(" ) != 0 ) {
		qID = qID + question.at( index );
		index++;
	}
	index++;

	question = question.substr( index, question.size() - index );

	// For each option, check to see if it was right or wrong
	//	If correct, it remembers it according to the index of the question
	for( unsigned int i = 1; i < question.size(); i += 2 ) {
		goodLetter = "";

		// Get the option answer from the DB/QB
		optionstr = DBManager::getDataObjectValue( 
			"QuestionBank", atoi( qID.c_str() ), "answer" + question.substr( i, 1 ) ).at( 0 );
		
		// Checks correctness and applies at correct location
		if( optionstr.substr( 0, 1 ).compare( "C" ) ) {
			if( i == 1 + index ) {
				goodLetter = goodLetter + "A";
			} else if ( i == 3) {
				goodLetter = goodLetter + "B";
			} else if ( i == 5 ) {
				goodLetter = goodLetter + "C";
			} else if ( i == 7 ) {
				goodLetter = goodLetter + "D";
			} else if ( i == 9 ) {
				goodLetter = goodLetter + "E";
			}
		}
	}

	return goodLetter;
}

// Helper function to get answer vector from DB string
vector< string > Grader::getLettersVector( string answers ) {
	vector< string > lettersVect;
	string at = "";


	for( unsigned int i = 0; i < answers.size(); i++ ) {
		at = answers.at( i );

		if( at.compare( "," ) == 0 ) {
			if ( i + 1 < answers.size() ) {
				string thisAt = "";
				thisAt += answers.at( i + 1 );
				
				if( thisAt.compare( "," ) == 0 ) {
					lettersVect.push_back( "" );
				}
			}
		} else {
			string letters = "";
			while ( i < answers.size() && at.compare( "," ) != 0 ) {
				letters += answers.at( i );
				i++;
				at = answers.at( i );
			}
			lettersVect.push_back( letters );
			i--;
		}

	}

	return lettersVect;
}

// Helper function to get answer vector from DB/QB string
// ID(1,2,3,4,5)+ID(5,4,3,2,1)
vector< string > Grader::getQBLettersVector( string qbKey ) {

	vector< string > lettersVect;
	int index = 0;
	int prevIndex = 0;

	// Gets the ID of the question
	while( index < qbKey.size() ) {
		if( qbKey.substr( index, 1 ).compare( "+" ) == 0 ) {
			lettersVect.push_back( qbKey.substr( prevIndex, index-1 ) );
			prevIndex = index+1;
		}

		index++;
	}


	return lettersVect;
}