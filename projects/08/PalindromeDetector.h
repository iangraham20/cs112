/* palindromeDetector.h
 * Ian Christensen, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "Stack.h"
#include "ArrayQueue.h"
using namespace std;

class PalindromeDetector {
public:
	PalindromeDetector( string input, string output );
	void detectPalindromes();
	bool isPalindrome( string str );
private:
	string inputFile;
	string outputFile;
};

#endif /* PALINDROMEDETECTOR_H_ */
