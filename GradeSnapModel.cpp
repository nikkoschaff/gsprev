
#include "GradeSnapModel.h"

using namespace std;

int GradeSnapModel::selKeyID = 0;
int GradeSnapModel::selAssignmentID = 0;
vector< int > GradeSnapModel::selStudentIDs;
int GradeSnapModel::selcurStudentID = 0;

GradeSnapModel::GradeSnapModel() {

}


GradeSnapModel::~GradeSnapModel() {
}


// At this point, NOTHING is explicitly known about the images.  Only the filenames
void GradeSnapModel::evaluateImage( int assignmentID,int classID, 
	string keyFilename,
	std::vector< string > filenames )  {

	// General members
	int numQ = atoi( DBManager::getDataObjectValue( "Assignment", assignmentID, "AssignmentID" ).c_str() );
	char* itoastr;

	// Key members
	string keyAmbiguous;
	string keyName;
	string keyAnswers;
	vector< string > keyVect;
	vector< vector< string > > keyReturnVect; 
	int keyImgFileID;
	int keyStudentID;
	int keyLSAID;
	string keyQs;

	// Student members
	string studentAmbiguous;
	string studentName;
	string studentAnswers;
	vector< string > studentVect;
	vector< vector< string > > studentReturnVect;
	vector< int > studentIDs;
	int studentImgFileID;
	int studentID;
	int studentLSAID;


	// ----- KEY HANDLING -----

	// Get the results from the key
	keyVect.push_back( keyFilename );
	keyReturnVect = ImageManager::readAssignmentSetFromImage(
		keyVect, numQ );
	keyVect = keyReturnVect.at( 0 );
	keyVect.pop_back();
	keyAmbiguous = keyVect.at( keyVect.size() - 1 );
	keyVect.pop_back();

	// Put key in DB at ImageFile
	keyImgFileID = DBManager::makeDataObject( "ImageFile", keyFilename );
	keyName = "KEY" + string( itoa( keyImgFileID, itoastr, 10 ) );
	itoastr = "";

	// Get studentID from key in Student table
	keyStudentID = DBManager::makeDataObject( "Student", keyName );

	// Fill out key ImageFile table values
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "StudentID",
		string( itoa( keyStudentID, itoastr, 10 ) ) );
	itoastr = "";
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "AssignmentID", 
		string( itoa( assignmentID, itoastr, 10 ) ) );
	itoastr = "";
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "graded", 
		string( itoa( 1, itoastr, 10 ) ) );
	itoastr = "";
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "AssignmentID", 
		string( itoa( assignmentID, itoastr, 10 ) ) );
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "ambiguousAnswers", 
		keyAmbiguous );
	keyAnswers = answersFromVector( keyVect );
	DBManager::setDataObjectValue( "ImageFile", keyImgFileID, "answers", keyAnswers );
	
	// Link key to LSA
	DBManager::linkAToB( "LinkerStudentAssignment", keyStudentID, "StudentID", 
		keyImgFileID, "ImageFileID" );

	// Set key LSA values
	keyLSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment",
		keyStudentID, keyImgFileID, "StudentID", "ImageFileID" ).at( 0 ).c_str() );
	DBManager::setDataObjectValue( "LinkerStudentAssignment", keyLSAID, "answers", keyAnswers );
	DBManager::setDataObjectValue( "LinkerStudentAssignment", keyLSAID, "key", "YES" );
	DBManager::setDataObjectValue( "LinkerStudentAssignment", keyLSAID,
		"AssignmentID", string( itoa( assignmentID, itoastr, 10 ) ) );
	itoastr = "";
	keyQs = questionsResultsFromAnswers( keyVect, assignmentID );
	DBManager::setDataObjectValue( "LinkerStudentAssignment", keyLSAID,
		"questions", keyQs );

	// ----- END KEY HANDLING -----

	// ----- STUDENT HANDLING -----

	studentReturnVect = ImageManager::readAssignmentSetFromImage( filenames, numQ );
	for( int i = 0; i < studentReturnVect.size(); i++ ) {
		// Get results from student
		studentVect = studentReturnVect.at( i );
		studentName = studentVect.at( studentVect.size() - 1 );
		studentVect.pop_back();
		studentAmbiguous = studentVect.at( studentVect.size() - 1 );
		studentVect.pop_back();

		// Put student in DB at ImageFile
		studentImgFileID = DBManager::makeDataObject( "ImageFile", filenames.at( i ) );
		studentID = findStudentIDFromName( studentName );
		// If name (and therefore ID) was found, link appropriately.
		// Otherwise, make a new student and link with the new ID
		if( studentID == -1 ) {
			studentID = DBManager::makeDataObject( "Student", filenames.at( i ) );
		}
		DBManager::setDataObjectValue( "ImageFile", studentImgFileID, "StudentID", 
			string( itoa( studentID, itoastr, 10 ) ) );
		itoastr = "";
		DBManager::setDataObjectValue( "ImageFile", studentImgFileID, "AssignmentID",
			string( itoa( assignmentID, itoastr, 10 ) ) );
		itoastr = "";
		DBManager::setDataObjectValue( "ImageFile", studentImgFileID,
			"ambiguousAnswers", studentAmbiguous );
		studentAnswers = answersFromVector( studentVect );
		DBManager::setDataObjectValue( "ImageFile", studentImgFileID, "answers",
			studentAnswers );

		// Link student to LSA
		DBManager::linkAToB( "LinkerStudentAssignment", studentID, "StudentID", 
			keyImgFileID, "ImageFileID" );
		studentLSAID = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment",
			keyStudentID, keyImgFileID, "StudentID", "ImageFileID" ).at( 0 ).c_str() );
		DBManager::setDataObjectValue( "LinkerStudentAssignment", studentLSAID, "answers", studentAnswers );
		DBManager::setDataObjectValue( "LinkerStudentAssignment", studentLSAID,
			"AssignmentID", string( itoa( assignmentID, itoastr, 10 ) ) );
		itoastr = "";
		DBManager::setDataObjectValue( "LinkerStudentAssignment", studentLSAID, 
			"questions", keyQs );

		// Add ID to vector of IDs
		studentIDs.push_back( studentID );
	}

	// ----- END STUDENT HANDLING -----

	// Grades the data and sends it to the database
	Grader::grade( assignmentID, keyLSAID, studentIDs );
}

// Returns the student ID if given name was found in the DB,
//	- Or if any close variations thereof ( John Smit = John Smith )
// Note - will not work if "(no name)"
// Returns -1 if not found or if no name
// TODO
int GradeSnapModel::findStudentIDFromName( std::string name ) {
	if( name.compare( "(no name)" ) == 0 ) {
		return -1;
	}

	return -1;
}

// Returns a DB-formatted string of answers
// (Letters delimited by commas)
std::string GradeSnapModel::answersFromVector( std::vector< std::string > answerVect ) {
	stringstream as;
	for( unsigned int i = 0; i < answerVect.size(); i++ ) {
			as << answerVect.at( i ) << ",";
	}
	return as.str();
}


// Returns a DB-formatted string of questions
// If using simple answers, format is just list of qIDs (A,B,E,D...)
// If not, returns "ERROR" (this can only work with simple answers)
std::string GradeSnapModel::questionsResultsFromAnswers( vector< string > answers, 
	int assignmentID ) {

	// Checks to see if current assignment is using simple answers
	int usingSimple = atoi( DBManager::getDataObjectValue( "Assignment", assignmentID,
		"usingSimpleAnswers").c_str() );
	if( usingSimple != 1 ) {
		return "ERROR";
	}
	
	// Adds the answers from the vector to the string,
	// Delimited by a comma (,)
	string simpleAnswers;
	for( unsigned int i = 0; i < answers.size(); i++ ) {
		simpleAnswers = simpleAnswers.at( i ) + ",";
	}

	return simpleAnswers;
}



// Prints the results to standard output
void GradeSnapModel::printResults( int assignmentID, int classID, int keyID,
	std::vector< int > studentIDs ) {

	cout << "Grading exam # " << assignmentID << endl;
	
	// Get the grades from each of the students recorded taking the exam

	string grade;

	for( unsigned int i = 0; i < studentIDs.size(); i++ ) {
		vector< string > r = DBManager::getLinkedValues( "LinkerStudentAssignment",
			assignmentID, studentIDs.at( i ), "AssignmentID", "StudentID" );
		grade = DBManager::getDataObjectValue( "LinkerStudentAssignment",
			atoi( r.at( 0 ).c_str() ), "grade" );
				cout << "Student: " << studentIDs.at( i ) << " scored: " <<
			grade << "%" << endl;
	}

	cout << endl << "Done grading" << endl << endl;
}

void GradeSnapModel::getStats( int assignmentID, int classID,
	int keyID, vector< int > studentIDs) {

	cout << "Printing statistics: " << endl << endl;

	cout << "Mean: " << Statistics::mean( assignmentID, studentIDs ) << "%" << endl << endl;

	cout << "Median: " << Statistics::median( assignmentID, studentIDs ) <<  "%" << endl << endl;

	pair< int, double > mode( Statistics::mode( assignmentID, studentIDs ) );
	cout << "Mode: " << mode.second  << "% with frequency of: " << mode.first  << endl << endl;

	cout << "Grade Distribution: " << endl;
	vector< pair< char, double > > dist = Statistics::gradeDistribution( 
		assignmentID, studentIDs, keyID );
	for( unsigned int i = 0; i < dist.size(); i++ ) {
		cout << dist.at( i ).first << ": " << dist.at( i ).second << "%" << endl;
	}

	cout << "Answer accuracy: " << endl << endl;
	vector< pair< string, double > > accuracy = Statistics::answerAccuracy( 
		assignmentID, studentIDs, keyID );
	for( unsigned int i = 0; i < accuracy.size(); i++ ) {
		cout << i + 1 << ": " <<  accuracy.at( i ).first << " - "
			<< accuracy.at( i ).second << "%" << endl;
	}


	cout << endl <<  "Standard deviation: ";
	cout << Statistics::standardDeviation( 
		assignmentID, studentIDs ) << endl;
}

void GradeSnapModel::setkeyid( int nid ) {
	GradeSnapModel::selKeyID = nid;
}

void GradeSnapModel::setassignmentid( int nid ) {
	GradeSnapModel::selAssignmentID = nid;
}

void GradeSnapModel::setstudentids( std::vector< int > nids ) {
	GradeSnapModel::selStudentIDs = nids;
}

void GradeSnapModel::setcurstudentid( int nid ) {
	GradeSnapModel::selcurStudentID = nid;
}

int GradeSnapModel::getkeyid() {
	int i = GradeSnapModel::selKeyID;
	return i;
}

int GradeSnapModel::getassignmentid() {
	int i = GradeSnapModel::selAssignmentID;
	return i;
}

std::vector< int > GradeSnapModel::getstudentids() {
	vector< int > is = GradeSnapModel::selStudentIDs;
	return is;
}

int GradeSnapModel::getselcurstudentid() {
	int i = GradeSnapModel::selcurStudentID;
	return i;
}