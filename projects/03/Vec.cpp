/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 21, 2017
 * Begun by: Joel Adams, for CS 112 lab 3 at Calvin College.
 * Ian's Methods: Subscript (write), writeTo, addition, multiplication
 * Thomas's Methods: Subscript (read), readTo, subtraction, inequality
 */
 
#include "Vec.h"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>

// The default constructor method for the vec class sets the size to zero and the pointer to null
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

// The explicit constructor method for the vec class sets the size and assigns default vales to the array
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

// The copy constructor method for the vec class copies only the values of the array
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

// The destructor method for the vec class eliminates any memory leaks
Vec::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}

// The assignment operator for the vec class copies one vec into another
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

// The value mutator for the vec class allows the user to set an index
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

// The value accessor for the vec class allows the user to get an index
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

// The size mutator for the vec class sets the size of the array
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

// The equality operator for the vec class compares two arrays and checks that they are equal
bool Vec::operator==(const Vec& v2) const {
	if ( mySize != v2.mySize ) {
		return false;
	}
	for ( unsigned i = 0; i < mySize; i++ ) {
		if ( myArray[i] != v2.myArray[i] ) {
			return false;
		}
	}
	return true;
}


// The inequality operator for the vec class compares two arrays and checks that they are not equal
bool Vec::operator!=(const Vec& v2) const {
	return !operator==(v2);
}

// The write method for the vec class writes values to the output stream
void Vec::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++ ) {
		out << myArray[i] << "\n";
	}
}

// The read method for the vec class reads values from the input stream
void Vec::readFrom(istream& in) {
	if(myArray != NULL) {
		delete [] myArray;
	}

	myArray = new Item[mySize];
	for ( unsigned i = 0; i < mySize; i++ ) {
		in >> myArray[i];
	}
}

// Subscript read operator
const Item& Vec::operator[](unsigned index) const {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
	return myArray[index];
	}


// Subscript write operator
Item& Vec::operator[](unsigned index) {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
	return myArray[index];
	}

// write to file
void Vec::writeTo(const string& filename) const {
	ofstream fout( filename.c_str() );
	fout << mySize << '\n';
	writeTo(fout);
	fout.close();
}

// read from file
void Vec::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str() );
	fin >> mySize;
	readFrom(fin);
	fin.close();
}

// Addition operator
Vec Vec::operator+( const Vec& v2 ) {
	if ( mySize != v2.getSize() ) {
		throw invalid_argument( "The vector sizes were not equal" );
	}
	else {
		Vec newVec(mySize);
		for ( unsigned i = 0; i < mySize; i++ ) {
			newVec[i] = myArray[i] + v2[i];
		}
		return newVec;
	}
}

// Subtraction operator
const Vec Vec::operator-(const Vec& v2) const {
	if (v2.mySize != mySize) {
		throw invalid_argument("Vec::operator-(): The two Vecs are different sizes, and cannot be subtracted.");
	}
	Vec subVec(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		subVec.setItem(i, getItem(i) - v2.getItem(i));
	}
	return subVec;
}

// Multiplication operator
Item Vec::operator*( const Vec& v2 ) {
	Item total = 0;
	if ( mySize != v2.getSize() ) {
		throw invalid_argument( "The vector sizes were not equal" );
	}
	else {
		for ( unsigned i = 0; i < mySize; i++ ) {
			total += myArray[i] * v2[i];
		}
		return total;
	}
}
