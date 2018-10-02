/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 6, 2017
 * Begun by: Joel Adams, for CS 112 proj04 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include "iostream"
#include <cstdlib>
#include <stdexcept>
#include <cassert>

typedef double Item;

template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const { return myRows; };
	unsigned getColumns() const { return myColumns; };
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix<Item>& m2) const;
	bool operator!=(const Matrix<Item>& m2) const;
	void writeTo(const string& fileName) const;
	void writeTo(ostream& out) const;
	void readFrom(const string& fileName);
	void readFrom(istream& in);
	Matrix<Item> operator-(const Matrix<Item>& m2);
	Matrix<Item> operator+(const Matrix<Item>& m2);
	Matrix<Item> getTranspose();
private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

/* The default constructor
 * sets the matrix rows and columns
 * to the default value of zero.
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/* The explicit constructor
 * sets the matrix rows and columns
 * to their respective parameters.
 *
 * @param rows		The number of rows in the matrix
 * @param columns	The number of columns in the matrix
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
    myColumns = columns;
    myVec.setSize(rows);
    for (unsigned i = 0; i < rows; i++) {
    	myVec[i].setSize(columns);
    }
}

/* The read subscript operator
 *
 *
 * @param index		The index location being read from
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if ( index >= myRows ) {
		throw range_error( "Invalid index" );
	}
	return myVec[index];
}

/* The write subscript operator
 *
 *
 * @param index		The index location being written to
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[]( unsigned index ) {
	if ( index >= myRows ) {
		throw range_error( "Invalid index" );
	}
	return myVec[index];
}

/* The equality operator
 * compares two matrices
 * and returns a boolean
 *
 * @param m2	The matrix being compared
 * @return		The boolean expression True or False
 */
template<class Item>
bool Matrix<Item>::operator==( const Matrix<Item>& m2 ) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        return false;
   } else {
        return myVec == m2.myVec;
   }
}

/* The inequality operator
 * compares two matrices
 * and returns a boolean
 *
 * @param m2	The matrix being compared
 * @return		The boolean expression True or False
 */
template<class Item>
bool Matrix<Item>::operator!=( const Matrix<Item>& m2 ) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
   } else {
		return myVec != m2.myVec;
   }
}

/* Read From Stream
 *
 *
 * @param	fileName	The stream being read from
 */
template<class Item>
void Matrix<Item>::readFrom( istream& in ) {
	for ( unsigned i = 0; i < myRows; i++ ) {
		myVec[i].readFrom(in);
	}
}

/* Read From File
 *
 *
 * @param	fileName	The file being read from
 */
template<class Item>
void Matrix<Item>::readFrom( const string& fileName ) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );
	fin >> myRows;
	fin >> myColumns;
	myVec.setSize(myRows);
	for ( unsigned i = 0; i < myRows; i++ ) {
		myVec[i].setSize(myColumns);
		myVec[i].readFrom(fin);
	}
	fin.close();
}

/* Write To Stream
 *
 *
 * @param	out	The stream being written to
 */
template<class Item>
void Matrix<Item>::writeTo( ostream& out ) const {
	for ( unsigned i = 0; i < myRows; i++ ) {
		myVec[i].writeTo(out);
		out << "\n";
	}
}

/* Write To Stream
 *
 *
 * @param	fileName	The file being written to
 */
template<class Item>
void Matrix<Item>::writeTo( const string& fileName ) const {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );
	fout << myRows << "\t" << myColumns << endl;
	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			fout << myVec[i][j] << "\t";
		}
		fout << "\n";
	}
	fout.close();
}

/* The Addition Operator
 * sums up the values
 * contained in the two
 * matrices separately
 * and returns that sum
 *
 * @param m2	The second matrix in the sum
 * @return		The sum of the two matrices
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+( const Matrix<Item>& m2 ) {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw invalid_argument( "Unequal number of rows or columns" );
	} else {
		Matrix newMatrix( myRows, myColumns );
		for ( unsigned i = 0; i < myRows; i++ ) {
			for ( unsigned j = 0; j < myColumns; j++ ) {
				newMatrix[i][j] = myVec[i][j] + m2[i][j];
			}
		}
		return newMatrix;
	}
}

/* The Subtraction Operator
 * finds the difference of
 * the values contained in
 * the two matrices separately
 * and returns that difference
 *
 * @param m2	The second matrix in the difference
 * @return		The difference of the two matrices
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-( const Matrix<Item>& m2 ) {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw invalid_argument( "Unequal number of rows or columns" );
	} else {
		Matrix newMatrix( myRows, myColumns );
		for ( unsigned i = 0; i < myRows; i++ ) {
			for ( unsigned j = 0; j < myColumns; j++ ) {
				newMatrix[i][j] = myVec[i][j] - m2[i][j];
			}
		}
		return newMatrix;
	}
}

/* The Transpose Mutator
 * swaps a matrix's columns
 * with its rows and returns
 * the matrix
 *
 * @return		The transposed matrix
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() {
	Matrix newMatrix( myColumns, myRows );
	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			newMatrix[j][i] = myVec[i][j];
		}
	}
	return newMatrix;
}

#endif
