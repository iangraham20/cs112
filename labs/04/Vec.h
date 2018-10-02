/* Vec.h provides a simple vector class named Vec.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 28, 2017
 * Begun by: Joel Adams, for CS 112 lab 4 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	virtual ~Vec();

	Vec<Item>& operator=(const Vec<Item>& original);
	unsigned getSize() const { return mySize; };
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec<Item>& v2) const;
	bool operator!=(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index); // write
	const Item& operator[](unsigned index) const; // read
	void readFrom(const string& fileName);
	void writeTo(const string& filename) const;
	Vec<Item> operator+(const Vec<Item>& v2);
	const Vec<Item> operator-(const Vec<Item>& v2) const;
	Item operator*(const Vec<Item>& v2);

private:
	unsigned mySize;
	Item *   myArray;
	friend class VecTester;
};

// The default constructor method for the vec class sets the size to zero and the pointer to null
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

// The explicit constructor method for the vec class sets the size and assigns default vales to the array
template<class Item>
Vec<Item>::Vec(unsigned size) {
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
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
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
template<class Item>
Vec<Item>::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}

// The assignment operator for the vec class copies one vec into another
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
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
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
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
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
	return !operator==(v2);
}

// The write method for the vec class writes values to the output stream
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++ ) {
		out << myArray[i] << "\n";
	}
}

// The read method for the vec class reads values from the input stream
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	if(myArray != NULL) {
		delete [] myArray;
	}

	myArray = new Item[mySize];
	for ( unsigned i = 0; i < mySize; i++ ) {
		in >> myArray[i];
	}
}

// Subscript read operator
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
	return myArray[index];
	}


// Subscript write operator
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if ( mySize == 0 ) {
		throw range_error( "The vec is empty" );
	}
	if ( index >= mySize ) {
		throw range_error( "The set location is out of range" );
	}
	return myArray[index];
	}

// write to file
template<class Item>
void Vec<Item>::writeTo(const string& filename) const {
	ofstream fout( filename.c_str() );
	fout << mySize << '\n';
	writeTo(fout);
	fout.close();
}

// read from file
template<class Item>
void Vec<Item>::readFrom(const string& fileName) {
	ifstream fin( fileName.c_str() );
	fin >> mySize;
	readFrom(fin);
	fin.close();
}

// Addition operator
template<class Item>
Vec<Item> Vec<Item>::operator+( const Vec<Item>& v2 ) {
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
template<class Item>
const Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const {
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
template<class Item>
Item Vec<Item>::operator*( const Vec<Item>& v2 ) {
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

#endif /*VEC_H_*/
