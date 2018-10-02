/* BSTapp.h
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 */

#ifndef BSTAPP_H_
#define BSTAPP_H_

#include "BST.h"
#include "cstdlib"
#include "fstream"
#include "iostream"
#include "cassert"
using namespace std;

class BSTapp {
public:
	BSTapp();
	BSTapp(const string& filename);
	void readFrom(const string& fileName);
	void printHeight();
private:
	BST<long> bst;
	unsigned count = 0;
};

#endif /* BSTAPP_H_ */
