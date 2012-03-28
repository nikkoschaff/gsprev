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
	 * @param	*valmap		pointer to map containing data
	 * @param	argc	number of arguments provided
	 * @param	**argv	Array of char array
	 * @param	**azColName		Array of column names associated with argv
	 *
	 * @return	static int	Results of callback
	 */
	static int callback(  std::map< std::string, std::vector< std::string > > *valmap,
		int argc, char **argv, char **azColName);

	/**
	 * db_init - Opens the database
	 *
	 * @precondition - DB is openable/readable
	 * @postcondition - DB successfully opened
	 */
	void db_init();

	/**
	 * db_close - Closes the database
	 *
	 * @precondition - DB is closeable/readable
	 * @postcondition - DB successfully closed
	 */
	void db_close();

	/**
	 * makeDataObject - Generalized make-thing method
	 *
	 * @param	tablename	String name of the table
	 * @param	name	Name of new object, optional.  Otherwise ""
	 * @return	int		Row ID of the object created
	 */
	int makeDataObject( std::string tablename, std::string name = "" );
	
	/**
	 * removeDataObject - Generalized remove-thing method
	 * 
	 * @param	rowID	ID of the row
	 */
	void removeDataObject( std::string tablename,
		int rowID );

	/**
	 * setDataObjectValue - Sets the value at the given column in the table
	 * 
	 * @param	tablename	String name of the table
	 * @param	rowID	ID of the row
	 * @param	colName		Name of the column selected
	 * @param	colValue	Value for the row at colName to be set to
	 */
	void setDataObjectValue( std::string tablename, int objectID, 
		std::string colName, std::string colValue );
	
	// Generalized get value method
	/**
	 * getDataObjectValue - Gets the value of the given column in the table
	 *
	 * @param	tablename	String name of the table
	 * @param	rowID		ID of the row
	 * @param	colName		Name of the column selected
	 * @return	string		Value for the row at colName selected
	 */
	std::string getDataObjectValue( std::string tablename, int rowID,
		std::string colName );

	// Generalized getID method
	/**
	 * Get the ID of an object at a particular row (UNUSED)
	 *
	 * @param	tablename	String name of the table
	 * @param	colName		Name of the column selected
	 * @param	colValue		Value found at the particular column
	 * @return	vector< int >	All instances of the ID for the colNme
	 */
	std::vector< int > getDataObjectID( std::string tablename, std::string colName,
		std::string colValue );

	// Generalized set AllValue method - Sets every row with the colID to colValue
	/**
	 * setAllDataObjectValues - Sets all instances of the colName to be the colValue
	 *
	 * @param	tablename	String name of the table
	 * @param	colName		Name of the column selected
	 * @param	colValue		Value found at the particular column
	 */
	void setAllDataObjectValues( std::string tablename, 
		std::string colName, std::string colValue );
	
	/**
	 * getAllDataObjectValues - Gets all instances of the colName values
	 *
	 * @param	tablename	String name of the table
	 * @param	colName		Name of the column selected
	 * @return	vector< string >	Vector of all values in the col of colName
	 */
	std::vector< std::string > getAllDataObjectValues( std::string tablename,
		std::string colName );
	
	// Links one data member to the other
	/**
	 * linkAToB - Places A and B in a linker table
	 *
	 * @param	tablename	String name of the table
	 * @param	aID		ID of A
	 * @param	aColName	Name of the ID column for A
	 * @param	bID		ID of B
	 * @param	bColName	Name of the ID column for B
	 */
	void linkAToB(std::string tablename, int aID,
		std::string aColName, int bID, std::string bColName );

	/**
	 * unlinkAFromB - Unlinks where A and B are connected in the given table
	 *
	 * @param	tablename	String name of the table
	 * @param	aID		ID of A
	 * @param	aColName	Name of the ID column for A
	 * @param	bID		ID of B
	 * @param	bColName	Name of the ID column for B
	 */
	void unlinkAFromB( std::string tablename, int aID, std::string aColName,
		int bID, std::string bColName );

	/**
	 * getLinkedValues - Returns all row IDs where both aID and bID exist
	 *
	 * @param	tablename	String name of the table
	 * @param	aID		ID of A
	 * @param	aColName	Name of the ID column for A
	 * @param	bID		ID of B
	 * @param	bColName	Name of the ID column for B
	 * @return	vector< string >	String IDs of all valid instances of A and B
	 */
	std::vector< std::string > getLinkedValues( std::string tablename,
		int aID, std::string aColName, int bID, std::string bColName );

	// Generalized linked setter - sets all rows at commoncol to commonvalue 
	//	where both aID and bID exist
	/**
	 * setLinkedValues - Sets all rows at commonColName to commonValue
	 *		Where both aID and bID exist
	 *
	 * @param	tablename	String name of the table
	 * @param	aID		ID of A
	 * @param	aColName	Name of the ID column for A
	 * @param	bID		ID of B
	 * @param	bColName	Name of the ID column for B
	 * @param	commonColName	Name of the column of shared data
	 * @param	commonColValue	Value to be stored in the common column
	 */
	void setLinkedValues( std::string tablename, int aID, 
		std::string aColName, int bID, std::string bColName,
		std::string commonColName, std::string commonColValue );

};


#endif