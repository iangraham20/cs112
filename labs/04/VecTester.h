/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 28, 2017
 * Begun by: Joel Adams, for CS 112 lab 4 at Calvin College.
 */
 
#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"

class VecTester {
public:
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testSubscript() const; // write
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testReadFromFile() const;
	void testWriteToFile() const;
};

#endif /*VECTESTER_H_*/
