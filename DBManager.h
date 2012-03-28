/**
 * DBManager.h - Wrapper around the SQL commands used to access the DB
 * @author	Nikko Schaff
 */


#ifndef DBMANAGER_H_
#define DBMANAGER_H_



// System header includes
#include <string>
#include <set>
#include <vector>
#include <map>
#include <tchar.h>

#include <iostream>
#include <sstream>

// Local header includes
#include "sqlite3.h"

namespace DBManager {

	// GENERAL FUNCTIONS

	// Typedef to allow callback to use any type of pointer for first arg
	typedef int (*callback_f)(void*,int,char**,char**);

	/**
	 * callback - Callback function for response from db action
	 *
	 * 
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	static int callback(  std::map< std::string, std::vector< std::string > > *valmap,
		int argc, char **argv, char **azColName);

	// Opens the database
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void db_init();

	// Closes the database
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void db_close();



	// Generalized make-thing method
	// Returns the row the object was made at
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	int makeDataObject( std::string tablename, std::string name = "" );
	
	// Generalized remove-thing method
	// TODO - could do without colID - already knows colname
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void removeDataObject( std::string tablename,
		int objectID, std::string colID );

	// Generalized set value method
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void setDataObjectValue( std::string tablename, int objectID, 
		std::string colID, std::string colValue );
	
	// Generalized get value method
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	std::string getDataObjectValue( std::string tablename, int objectID,
		std::string colValue );

	// Generalized getID method
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	std::vector< int > getDataObjectID( std::string tablename, std::string colID,
		std::string colValue );

	// Generalized set AllValue method - Sets every row with the colID to colValue
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void setAllDataObjectValues( std::string tablename, 
		std::string colID, std::string colValue );
	
	// Generalized get all values in the specified column category in the table
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	std::vector< std::string > getAllDataObjectValues( std::string tablename,
		std::string colID );
	
	// Links one data member to the other
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void linkAToB(std::string tablename, int aID,
		std::string aIDCol, int bID, std::string bIDCol );

	// Unlinks where A and B are connected in the given tablename
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void unlinkAFromB( std::string tablename, int aID, std::string aIDCol,
		int bID, std::string bIDCol );

	// Generalized linked getter - returns all IDs where both aID and bID exist
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	std::vector< std::string > getLinkedValues( std::string tablename,
		int aID, int bID, std::string aCol, std::string bCol );

	// Generalized linked setter - sets all rows at commoncol to commonvalue 
	//	where both aID and bID exist
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void setLinkedValues( std::string tablename, int aID, int bID,
		std::string aIDCol, std::string bIDCol,
		std::string commonCol, std::string commonColValue );

};


#endif