/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Joel Adams, for CS 112 lab 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 28, 2017
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
};

#endif /*STACKTESTER_H_*/

