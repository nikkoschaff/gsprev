

#ifndef DBOUTOFBOUNDSEXCEPTION_H_
#define DBOUTOFBOUNDSEXCEPTION_H_

#include < iostream >
#include < exception >
#include < string >

class DBOutOfBoundsException: public std::exception {

	virtual const char* what() const throw() {
		return "DB access request out of bounds";
	}

} DBOutOfBoundsException;

#endif