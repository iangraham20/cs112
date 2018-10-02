/* array.cpp defines "C style" array operations
 * Name: Ian Graham Christensen (igc2)
 * Date: February 20, 2017
 * Begun by: Joel Adams, for CS 112 project 2 at Calvin College.
 */
 
#include "array.h"
#include <iostream>
#include <fstream>
using namespace std;

void initialize( double *a, unsigned size ) {
	int val = 0;
	for ( unsigned i = 0; i < size; i++ ) {
		val = i + 1;
		a[i] = val;
	}
}
 
void print( double *a, unsigned size ) {
	for ( unsigned i = 0; i < size; i++ ) {
		cout << *a << '\t';
		a++;
	}
}		

double average( double *a, unsigned size ) {
	double total = 0;
	for ( unsigned i = 0; i < size; i++ ) {
		total += *a;
		a++;
	}
	return total/size;
}

double sum( double *a, int size ) {
	double sum = 0;
	for ( int i = 0; i < size; i++ ) {
		sum += *a;
		a++;
	}
	return sum;
}

void read( istream& in, double *a, int size ) {
	for ( int i = 0; i < size; i++ ) {
		in >> a[i];
	}
}

void fill( const string& fileName, double *&a, int &numValues ) {
	// step one: open ifstream to fileName
	ifstream fin ( fileName.c_str() );
	assert( fin.is_open() );

	// step two: read an integer into numValues
	fin >> numValues;

	// step three: dynamically allocate an array of values and store the addresses
	double* newArray = new double[numValues];

	// step four: read values into the dynamic array
	for( unsigned i = 0; i < numValues; i++ ) {
		fin >> newArray[i];
	}
	a = newArray;
	delete[]a;
	// step five: close the stream
	fin.close();
}

void resize( double *&a, int oldSize, int newSize ) {
	double* newArray = new double[newSize];
	for ( int i = 0; i < newSize; i++ ) {
		if ( i < oldSize ) {
			newArray[i] = a[i];
		}
		else {
			newArray[i] = 0;
		}
	}
	delete[] a;
	a = newArray;
}

void concat( double *a1, int size1, double *a2, int size2, double *&a3, int &size3 ) {
	unsigned i2 = 0;
	size3 = size1 + size2;
	double * allArray = NULL;
	allArray = new double[size3];
	for ( int i = 0; i < size1; i++ ) {
		allArray[i2] = a1[i];
		i2++;
	}
	for (int i = 0; i < size2; i++ ) {
		allArray[i2] = a2[i];
		i2++;
	}
	delete[] a3;
	a3 = allArray;
}
