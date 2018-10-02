/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 21, 2017
 * Begun by: Joel Adams, for CS 112 lab 3 at Calvin College.
 */
 
#include "Vec.h"
#include <stdexcept>
#include <iostream>

// Default Constructor
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

// Explicit Constructor
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size];
	if ( size > 0 ) {
		for ( unsigned i = 0; i < size; i++ ) {
			myArray[i] = 0;
		}
	}
	else {
			myArray = NULL;
		}
	}

// Copy Constructor
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( original.mySize > 0 ) {
		myArray = new Item[mySize];
		for ( unsigned i = 0; i < mySize; i++ ) {
			myArray[i] = original.myArray[i];
		}
	}
	else {
		myArray = NULL;
	}
}

// Destructor
Vec::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}

// Assignment Operator
Vec& Vec::operator=(const Vec& original) {
	if ( this != &original ) {
		if ( mySize > 0 ) {
			delete[] myArray;
			myArray = NULL;
		}
		if ( original.mySize > 0 ) {
			myArray = new Item[original.mySize];
		}
	mySize = original.mySize;
	}
	for ( unsigned i = 0; i < mySize; i++ ) {
		myArray[i] = original.myArray[i];
	}
return *this;
}

// Value Mutator
void Vec::setItem(unsigned index, const Item& it) {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
 	if ( index < 0 ) {
		throw range_error( "index cannot be less than zero" );
	}
	else {
		myArray[index] = it;
	}
}

// Value Accessor
Item Vec::getItem(unsigned index) const {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
 	if ( index < 0 ) {
		throw range_error( "index cannot be less than zero" );
	}
	else {
		return myArray[index];
	}
}

// Size Mutator
void Vec::setSize(unsigned newSize) {
	if ( mySize != newSize ) {
		Item* newArray = new Item[newSize];

		if ( newSize == 0 ) {
			delete [] myArray;
			myArray = NULL;
			mySize = 0;
			return;
			}

		else if ( newSize > mySize ) {
			for ( unsigned i = 0; i < mySize; i++ ) {
				newArray[i] = myArray[i];
			}
			for ( unsigned i = mySize; i < newSize; i++ ) {
				newArray[i] = 0;
			}
		}
		else {
			for ( unsigned i = 0; i < newSize; i++ ) {
				newArray[i] = myArray[i];
			}
		}
		mySize = newSize;
		delete [] myArray;
		myArray = newArray;
	}
}

// Equality Operator
bool Vec::operator==(const Vec& v2) {
	if ( mySize == v2.mySize ) {
		for ( unsigned i; i < mySize; i++ ) {
			if ( myArray[i] == v2.myArray[i] ) {
			}
			else {
				return false;
			}
		}
		return true;
	}
	return false;
}

// Vec Write
void Vec::writeTo(ostream& out) const {
	for ( unsigned i; i < mySize; i++ ) {
		out << myArray[i] << "\n";
	}
}

// Vec Read
void Vec::readFrom(istream& in) {
	for ( unsigned i = 0; i < mySize; i++ ) {
		in >> myArray[i];
	}
}

// Subscript operator
void Vec::operator[](unsigned index) {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
 	if ( index < 0 ) {
		throw range_error( "index cannot be less than zero" );
	}
	else {
		for ( unsigned i = 0; i < mySize; i++ ) {
			v[i] = it;
		}
	}
}
