/* PalindromeDetector.cpp
 * Ian Christensen, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#include "PalindromeDetector.h"

PalindromeDetector::PalindromeDetector( string input, string output ) {
	inputFile = input;
	outputFile = output;
}

void PalindromeDetector::detectPalindromes() {
	ifstream fin( inputFile.c_str() );
	assert( fin.is_open() );
	ofstream fout( outputFile.c_str() );
	assert( fout.is_open() );
	while( !fin.eof() ) {
		string tempStr;
		getline(fin, tempStr);
		fout << tempStr << flush;
		if ( isPalindrome(tempStr) ) {
			fout << " ***" << flush;
		}
		fout << "\n" << flush;
	}
	fout.close();
	fin.close();
}

bool PalindromeDetector::isPalindrome( string str ) {
	Stack<Item> tempStack(1);		// could also use str.length()
	ArrayQueue<Item> tempQueue(1);
	for ( unsigned i = 0; i < str.length(); i++ ) {
		if ( isalpha(str[i]) ) {
			try {
			tempStack.push( tolower( str[i] ) );
			tempQueue.append( tolower( str[i] ) );
			} catch (StackException& e) {
				tempStack.setCapacity(2*tempStack.getCapacity());
				tempQueue.setCapacity(2*tempQueue.getCapacity());
				tempStack.push( tolower( str[i] ) );
				tempQueue.append( tolower( str[i] ) );
			}
		}
	}
	if ( tempStack.getSize() == 0 ) {
		return false;
	}
	while ( !tempStack.isEmpty() ) {
		char stVal = tempStack.pop();
		char quVal = tempQueue.remove();
		if ( stVal != quVal ) {
			return false;
		}
	}
	return true;
}
