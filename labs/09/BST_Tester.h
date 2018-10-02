/* BST_Tester.h declares a class to test class BST.
 * Joel Adams, for CS 112, lab 9 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 */

#ifndef BST_TESTER_H_
#define BST_TESTER_H_

#include "BST.h"
#include <iostream>
#include <cassert>
using namespace std;

class BST_Tester
{
public:
	// test prototypes
	void runTests();
	void testConstructor();
	void testInsert();
	void testContains();
	void testTraverse();
	void testGetHeight();
};

#endif /*BST_TESTER_H_*/
