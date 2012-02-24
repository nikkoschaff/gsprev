

#include "GradeSnap.h"

#include <iostream>
using namespace std;

int main ( int argc, char* argv[] ) {

	DBManager::db_init();

	// BASICS

	// get value at ID and colvalue
	cout << "!!!!!" << DBManager::getDataObjectValue( "Assignment", 2, "name" ) << endl;
	cout << "done" << endl;

	int x;
	cin >> x;


	DBManager::db_close();


	return 0;
}