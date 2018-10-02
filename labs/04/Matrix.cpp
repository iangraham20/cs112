/* Matrix.cpp defines Matrix class methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
         myRows = rows;
         myColumns = columns;
         myVec.setSize(rows);
         for (unsigned i = 0; i < rows; i++) {
             myVec[i].setSize(columns);
         }
}

// read
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if ( index >= myRows ) {
		throw range_error( "Invalid index" );
	}
	return myVec[index];
}

// write
Vec<Item>& Matrix::operator[](unsigned index) {
	if ( index >= myRows ) {
		throw range_error( "Invalid index" );
	}
	return myVec[index];
}


bool Matrix::operator==(const Matrix& m2) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        return false;
   } else {
        return myVec == m2.myVec;
   }
}
