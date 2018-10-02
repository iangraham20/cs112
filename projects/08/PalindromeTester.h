/* palindromeTester.h
 * Ian Christensen, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#ifndef PALINDROMETESTER_H_
#define PALINDROMETESTER_H_

#include "PalindromeDetector.h"	// Class being tested
#include <iostream>				// cout,
#include <cassert>      		// assert()
#include <cstdlib>      		// exit()
using namespace std;			//

class PalindromeTester {
public:
	void runTests();
	void testDetectPalindromes();
	void testIsPalindrome();
	void testApplication();
};

#endif /* PALINDROMETESTER_H_ */
