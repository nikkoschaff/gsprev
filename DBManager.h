


#ifndef DBMANAGER_H_
#define DBMANAGER_H_



// System header includes
#include <string>
#include <set>
#include <vector>
#include <map>

// Local header includes
#include "sqlite3.h"

namespace DBManager {

	// GENERAL FUNCTIONS

typedef int (*callback_f)(void*,int,char**,char**);


static int callback(  std::map< std::string, std::vector< std::string > > *map,
	int argc, char **argv, char **azColName);



	void db_init();

	void db_close();


	// Links one data member to the other
	void linkAToB(std::string tablename, int aID,
		std::string aIDCol, int bID, std::string bIDCol );

	// Unlinks where A and B are connected in the given tablename
	void unlinkAFromB( std::string tablename, int aID, std::string aIDCol,
		int bID, std::string bIDCol );

	// Generalized make-thing method
	void makeDataObject( std::string tablename, std::string name = "" );
	
	// Generalized remove-thing method
	void removeDataObject( std::string tablename,
		int objectID, std::string colID );

	// Generalized set value method
	void setDataObjectValue( std::string tablename, int objectID, 
		std::string colID, std::string colValue );
	

	// Generalized get value method
	std::string getDataObjectValue( std::string tablename, int objectID,
		std::string colValue );

	// 4a: Make generalized getID method
	int getDataObjectID( std::string tablename, std::string colID,
		std::string colValue );

	
	//5: Make generalized set AllValue method
	void setEntireDataObjectValue( std::string tablename, int objectID,
		std::string colID, std::string colValue );
	
	//6: Make gerneralized get AllValue method
	
	
	//7: Make generalized getter - things-of-that method

	
	//8: Make generalized setter - things-of-that method
	void setLinkedValues( std::string tablename, int aID, int bID,
		std::string aIDCol, std::string bIDCol,
		std::string commonCol, std::string commonColValue );

};


#endif