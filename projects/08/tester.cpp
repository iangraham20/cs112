/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#include "ArrayQueueTester.h"
#include "PalindromeDetector.h"
#include "PalindromeTester.h"
#include "StackTester.h"
 
 int main() {
	StackTester st;
	st.runTests();
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	PalindromeTester pt;
 	pt.runTests();

	PalindromeDetector pd( "DrawnOnward.txt", "DrawnOnwardCopy.txt");
	pd.detectPalindromes();
 }
