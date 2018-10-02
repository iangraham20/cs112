/* ListTester.h declares the test-class for class List.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 13, 2017
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_
#include "List.h"

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testReadFromStream();
	void testWriteToStream();
	void testReadFromString();
	void testWriteToString();
	void testPrepend();
	void testGetIndexOf();
	void testInsert();
	void testRemove();
};

#endif /*LISTTESTER_H_*/
