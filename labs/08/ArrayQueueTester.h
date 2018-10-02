/* ArrayQueueTester.h declares the class that tests class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */
 
#ifndef QUEUETESTER_H_
#define QUEUETESTER_H_

#include "ArrayQueue.h"			// Class being tested
#include "QueueException.h"		// EmptyQueueException, FullQueueException, QueueException
#include <iostream>				// cout,
#include <cassert>      		// assert()
#include <cstdlib>      		// exit()
using namespace std;			//

class ArrayQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
};

#endif /*QUEUETESTER_H_*/
