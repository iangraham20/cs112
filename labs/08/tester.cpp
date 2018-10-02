/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

 #include "ArrayQueueTester.h"
 #include "LinkedQueueTester.h"
 
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	LinkedQueueTester lqt;
 	lqt.runTests();
 }
 
 
