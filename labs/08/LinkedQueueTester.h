/* ArrayQueueTester.h declares the class that tests class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#ifndef LINKEDQUEUETESTER_H_
#define LINKEDQUEUETESTER_H_

#include "LinkedQueue.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

class LinkedQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
};

#endif /*LINKEDQUEUETESTER_H_*/
