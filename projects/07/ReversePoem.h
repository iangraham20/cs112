/* ReversePoem.h declares methods for the reverse poem class
 * Ian Christensen, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;

class ReversePoem {
public:
	ReversePoem( string fileName );
	string getTitle() { return myTitle; }
	string getAuthor() { return myAuthor; }
	string getBody() { return myBody; }
	string getBodyReversed() {return myBodyReversed; }

private:
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;
};

#endif /* REVERSEPOEM_H_ */
