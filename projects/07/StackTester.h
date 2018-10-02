/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Joel Adams, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_

class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushPeekTopAndIsFull();
	void testPushAndIsFull();
	void testGetTop();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();
	void testGetSizeGetCapacitySetCapacity();
};

#endif /*STACKTESTER_H_*/

