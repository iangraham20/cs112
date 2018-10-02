/* ReversePoem.cpp allows a user to reverse the order of poems
 * Ian Christensen, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 */

#include "ReversePoem.h"

/* constructor method
 * defines private variables
 *
 * @param	fileName	The poem file that is being reversed
 */
ReversePoem::ReversePoem( string fileName ) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	getline(fin, myTitle);
	getline(fin, myAuthor);
	string newLine;
	getline(fin, newLine);
	Stack<string> tempStack(1);
	while(true) {
		string tempStr;
		getline(fin, tempStr);
		if (!fin) {
			break;
		}
		try {
			tempStack.push(tempStr);
			myBody = myBody + tempStr + "\n";
		} catch (StackException& se) {
			tempStack.setCapacity( tempStack.getCapacity() * 2);
			tempStack.push(tempStr);
			myBody = myBody + tempStr + "\n";
		}
	}
	while(true) {
		myBodyReversed = myBodyReversed + tempStack.pop() + "\n";
		if (tempStack.isEmpty()) {
			break;
		}
	}
}
