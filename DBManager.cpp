//
//
 


#include "DBManager.h"
#include "sqlite3.h"

using namespace std;

#include <iostream>
#include <sstream>

static sqlite3 * db = NULL;


// GENERAL FUNCTIONS

// callback function
static int DBManager::callback( map< string, vector< string > > *map, int argc, char **argv, char **azColName)
{
  int i;
  for(i=0; i<argc; i++)
  {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}



// Initializes database
void DBManager::db_init() {
	int rc = sqlite3_open( "gsdb.db", &db );
	rc = sqlite3_open( "gsdb.db", &db );
	if ( rc ) {
		cerr << "Error opening SQLite3 database: " << sqlite3_errmsg( db ) << endl;
		sqlite3_close( db );
	} else {
		cout << "Opened gsdb " << endl << endl;
	}
	

}

// Closes database
void DBManager::db_close() {
	sqlite3_close( db );
}


// Links one data member to the other
void DBManager::linkAToB( string tablename, int aID, string aIDCol,
	int bID, string bIDCol ) {
	int rc;
	char* error;
	char **results = NULL;

	string sqladdstring = "INSERT INTO " + tablename + " (aIDCol, bIDCol) VALUES ('aID', 'bID');";
	const char* sqladd( sqladdstring.c_str() );
	rc = sqlite3_exec( db, sqladd, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}
}

// Unlinks where A and B are connected in the given tablename
void DBManager::unlinkAFromB( string tablename, int aID, string aIDCol,
	int bID, string bIDCol ) {
	int rc;
	char* error;
	char **results = NULL;

	// Convert aID to string value for concatenation
	std::string aIDValue;
	std::stringstream aout;
	aout << aID;
	aIDValue = aout.str();
	// Convert bID to string value for concatenation
	std::string bIDValue;
	std::stringstream bout;
	bout << bID;
	bIDValue = bout.str();

	string sqldelstring = "DELETE FROM " + tablename + " WHERE " + aIDCol + "= '" + aIDValue + "' AND " +
		bIDCol + " = '" + bIDValue + "';";

	const char* sqlselect( sqldelstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}
}

// Generalized make-thing method
void DBManager::makeDataObject( string tablename,  std::string name ) {
	int rc;
	char* error;

	string sqlinsertstring = "INSERT INTO " + tablename + " (name) VALUES('" + name + "');";
	const char* sqlinsert( sqlinsertstring.c_str() );
	rc = sqlite3_exec( db, sqlinsert, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	} 
}

	
// Generalized remove-thing method
void DBManager::removeDataObject( string tablename, int objectID, string colID ) {
	int rc;
	char* error;
	char **results = NULL;

	// Convert object ID to string for concatenation
	std::string oID;
	std::stringstream out;
	out << objectID;
	oID = out.str();

	string sqlselectstring = "DELETE FROM " + tablename + " WHERE " + colID + " = '" + oID  + "';";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

}

	
// Generalized set value method
void DBManager::setDataObjectValue( string tablename, int objectID,
	std::string colID, std::string colValue ) { 
	int rc;
	char* error;
	char **results = NULL;

	std::string oID;
	std::stringstream out;
	out << objectID;
	oID = out.str();

	string sqlselectstring = "UPDATE " + tablename +
		" SET " + colID + " = '" + colValue + "' WHERE  " + 
		tablename + "ID = '" + oID + "';";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

}

// Generalized get value method
string DBManager::getDataObjectValue( string tablename, int objectID,
	std::string colValue ) {

	int rc;
	char* error;
	char **results = NULL;
	map< string, vector< char* > > valMap;


	std::string objID;
	std::stringstream out;
	out << objectID;
	string strOID = out.str();

	string sqlselectstring = "SELECT " + colValue + " FROM " +
		tablename + " WHERE " + colValue + " = '" + strOID + "';";


	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast< callback_f >( &callback ), (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}
	return valMap.at( colValue ).at( 0 );
}

// 4a: Make generalized getID method
int DBManager::getDataObjectID( std::string tablename, std::string colID,
	std::string colValue ) {
		return -1;
}

//5: Make generalized set AllValue method - TODO
void DBManager::setEntireDataObjectValue( string tablename, int objectID,
	std::string colID, std::string colValue ) {
}
	
//6: Make gerneralized get AllValue method -TODO
	
	
//7: Make generalized getter - things-of-that method -TODO

	
//8: Make generalized setter - things-of-that method -TODO
void DBManager::setLinkedValues( string tablename, int aID, int bID,
	std::string aIDCol, std::string bIDCol,
	std::string commonCol, std::string commonColValue ) {

	int rc;
	char* error;
	char **results = NULL;

	// Set id values to string for concatenation
	std::string strAID;
	std::stringstream aout;
	aout << aID;
	strAID = aout.str();
	std::string strBID;
	std::stringstream bout;
	bout << bID;
	strBID = bout.str();


	string sqlselectstring = "UPDATE " + tablename + " SET " + commonCol
		+ " = '" + commonColValue + "' WHERE " + tablename + "ID = ";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback)
		, NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

}