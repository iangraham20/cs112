/* PalindromeTester.cpp
 * Ian Christensen, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#include "PalindromeTester.h"

void PalindromeTester::runTests() {
	cout << "Testing class palindromeDetector..." << endl;
	testApplication();
	cout << "All tests passed!\n" << endl;
}


void PalindromeTester::testApplication() {
	cout << "- Testing detectPalindromes()..." << flush;
	PalindromeDetector pd( "PalindromeTest.txt", "PalindromeTestCopy.txt");
	pd.detectPalindromes();
	ifstream fin( "PalindromeTestCopy.txt" );
	assert( fin.is_open() );
	string tempStr;
	// test for palindrome detection
	getline(fin, tempStr);
	assert( tempStr == "BOB ***" );
	cout << " 1a " << flush;
	getline(fin, tempStr);
	assert( tempStr == "wow ***" );
	cout << " 1b " << flush;
	getline(fin, tempStr);
	assert( tempStr == "race car! ***" );
	cout << " 1c " << flush;
	getline(fin, tempStr);
	cout << " 1d " << flush;

	// test for non-palindrome detection
	getline(fin, tempStr);
	assert( tempStr == "NotaPalindrome" );
	cout << " 2a " << flush;
	getline(fin, tempStr);
	assert( tempStr == "This line is not either" );
	cout << " 2b " << flush;
	getline(fin, tempStr);
	assert( tempStr == "Let's try some chars!" );
	cout << " 2c " << flush;
	getline(fin, tempStr);
	assert( tempStr == "!@#$%^&*()_+" );
	cout << " 2d " << flush;

	cout << "Passed!" << endl;
}
