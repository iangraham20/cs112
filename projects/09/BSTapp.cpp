/* BSTapp.cpp
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 */

#include "BSTapp.h"

/* default constructor
 * this can be used to
 * allow a user to enter
 * their own files rather
 * than hard-coding the
 * filenames in
 */
BSTapp::BSTapp() {
	cout << "\nenter a filename: " <<  endl;
	string filename;
	cin >> filename;
	readFrom(filename);
	printHeight();
}

/* explicit constructor
 * allows the coder to
 * hard-code values into
 * the program.
 */
BSTapp::BSTapp(const string& filename) {
	cout <<  "\nfilename: " << filename << endl;
	readFrom(filename);
	printHeight();
}

/* readFrom input
 * reads in file
 * contents into
 * a BST structure
 */
void BSTapp::readFrom(const string& filename) {
	string tempStr;
	long longInt;
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	while(true) {
		try {
		fin >> longInt;
		if (fin.eof()) {
			break;
		}
		bst.insert(longInt);
		} catch (Exception& e) {
			count++;
		}
	}
	fin.close();
}

/* printHeight mutator
 * prints the data that
 * a BST contains to
 * the console
 */
void BSTapp::printHeight() {
	cout << "The binary search tree's height is: " << bst.getHeight() << endl;
	cout << "The number of duplicate numbers is: " << count << endl;
}
