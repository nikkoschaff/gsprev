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
static int DBManager::callback( map< string, vector< string > > *valmap,
	int argc, char **argv, char **azColName) {
	for(int i = 0; i<argc; i++) {


		std::string azString;
		std::stringstream azout;
		azout << azColName[ i ];
		azString = azout.str();

		std::string argString;
		std::stringstream argout;
		argout << argv[ i ];
		argString = argout.str();
		
		vector< string > v;
		v.push_back( argString );

		 // If found, it pushes one back.  If not, it makes a new and pushes back
		map< string, vector< string > >::iterator it = valmap->find( azString );
		if ( it != valmap->end() ) {
			valmap->find( azString )->second.push_back( argString );
		} else {
			valmap->insert( pair< string, vector< string > >( azString,  v ) );
		}
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	//printf("\n");
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
		//cout << "Opened gsdb " << endl << endl;
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

	string sqladdstring = "INSERT INTO " + tablename + " (" + aIDCol + ", "
		+ bIDCol + ") VALUES ('" + aIDValue + "', '" + bIDValue + "'  );";
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
	map< string, vector< string > > valMap;


	std::string objID;
	std::stringstream out;
	out << objectID;
	string strOID = out.str();

	string sqlselectstring = "SELECT " + colValue + " FROM " +
		tablename + " WHERE " + tablename + "ID = '" + strOID + "';";


	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast< callback_f >( &callback ), (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}
	string key( colValue );
	if ( valMap.find( key )->second.at( 0 ).size() == 0 ) {
		return "NULL";
	} else {
		string ret = valMap.find( key )->second.at( 0 );
		return ret;
	}
}

// Generalized getID method
vector< int > DBManager::getDataObjectID( std::string tablename, std::string colID,
	std::string colValue ) {
	int rc;
	char* error;
	char **results = NULL;
	map< string, vector< string > > valMap;


	string sqlselectstring = "SELECT " + tablename + "ID FROM " +
		tablename + " WHERE " + colID + " = '" + colValue + "';";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast< callback_f >( &callback ), (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}
	string key( tablename + "ID" );
	vector< string > returnstr;


	vector< int > returnint;
	for( unsigned int i = 0; i < 	valMap.find( key )->second.at( 0 ).size(); i++ ) {
		returnint.push_back( atoi( 	valMap.find( key )->second.at( i ).c_str() ) );
	}

	if ( returnint.size() == 0 ) {
		returnint.push_back( -1 );
	}

	return returnint;
}

// Generalized set AllValue method - Sets every row with the colID to colValue
void DBManager::setAllDataObjectValues( string tablename,
	std::string colID, std::string colValue ) {

	int rc;
	char* error;
	char **results = NULL;


	string sqlselectstring = "UPDATE " + tablename +
		" SET " + colID + " = '" + colValue + "';";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback), NULL, &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}


}
	
// Generalized get all values in the specified column category in the table
vector< string > DBManager::getAllDataObjectValues( string tablename, string colID ) {

	int rc;
	char* error;
	char **results = NULL;
	map< string, vector< string > > valMap;

	string sqlselectstring = "SELECT " + colID + " FROM " +
		tablename + ";";


	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast< callback_f >( &callback ), (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

	// Convert char* values to string
	vector< string > values;
	for( unsigned int i = 0; i < valMap.at( colID ).size(); i++ ) {
		values.push_back( valMap.at( colID  ).at( i ) );
	}
	return values;
}
	
// Generalized linked getter - returns all IDs where both aID and bID exist
std::vector< std::string > DBManager::getLinkedValues( std::string tablename,
	int aID, int bID, string aCol, string bCol ) {

	int rc;
	char* error;
	char **results = NULL;
	map< string, vector< string > > valMap;


	// Convert object ID to string for concatenation
	std::string aColID;
	std::stringstream aout;
	aout << aID;
	aColID = aout.str();
	// Convert object ID to string for concatenation
	std::string bColID;
	std::stringstream bout;
	bout << bID;
	bColID = bout.str();

	// Get all the IDs
	string sqlselectstring = "SELECT " + tablename + "ID FROM " + tablename + " WHERE " +
		 aCol + " = '" + aColID + "' AND " + bCol + " = '" + bColID + "';";


	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast< callback_f >( &callback ), (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

	// Convert char* values to string
	vector< string > values;
	for( unsigned int i = 0; i < valMap.at( tablename + "ID" ).size(); i++ ) {
		values.push_back( valMap.at( tablename + "ID" ).at( i ) );
	}
	return values;
}
	
// Generalized linked setter - sets all rows at commoncol to commonvalue
//	where both aID and bID exist
void DBManager::setLinkedValues( string tablename, int aID, int bID,
	std::string aIDCol, std::string bIDCol,
	std::string commonCol, std::string commonColValue ) {

	int rc;
	char* error;
	char **results = NULL;
	map< string, vector< string > > valMap;

	// Set id values to string for concatenation
	std::string aColID;
	std::stringstream aout;
	aout << aID;
	aColID = aout.str();
	std::string bColID;
	std::stringstream bout;
	bout << bID;
	bColID = bout.str();

	string sqlselectstring = "UPDATE " + tablename + " SET " + commonCol
		+ " = '" + commonColValue + "' WHERE "
		+ aIDCol + " = '" + aColID + "' AND " + bIDCol + " = '" + bColID + "';";

	const char* sqlselect( sqlselectstring.c_str() );
	rc = sqlite3_exec( db, sqlselect, reinterpret_cast<callback_f>(&callback)
		, (&valMap), &error );
	if ( rc ) {
		cerr << "Error: " << sqlite3_errmsg( db ) << endl << endl;
		sqlite3_free( error );
	}

}