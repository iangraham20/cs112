/* ListTester.cpp defines the test methods for class List.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * 3/11/17
 * Additional Tests by:
 *  Carolyn Lindemulder: ==, readFrom(istream), writeTo(string), prepend, insert
 *  Ian Christensen: !=, writeTo(ostream), readFrom(string), getIndexOf, remove
 */

#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>		// ifstream
#include <ostream>
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();
	testInequality();
	testWriteToStream();
	testReadFromString();
	testGetIndexOf();
	testRemove();
	testInsertAfter();
	testInsertBefore();
	testOutput();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<int> aList;
	assert(aList.mySize == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert(aNode.myItem == 0);
	assert(aNode.myNext == NULL);
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<int>::Node n1(11, NULL);
	assert(n1.myItem == 11);
	assert(n1.myNext == NULL);
	cout << " 1 " << flush;

	List<int>::Node *n3 = new List<int>::Node(33, NULL);
	List<int>::Node n2(22, n3);
	assert(n2.myItem == 22);
	assert(n2.myNext == n3);
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<int> aList;
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert(aList.getSize() == 1);
	assert(aList.myFirst != NULL);
	assert(aList.myLast == aList.myFirst);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 11);
	assert(aList.myFirst->myNext == NULL);
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert(aList.getSize() == 2);
	assert(aList.myFirst != NULL);
	assert(aList.myLast != NULL);
	assert(aList.myFirst != aList.myLast);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 22);
	assert(aList.myFirst->myNext != NULL);
	assert(aList.myLast->myNext == NULL);
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert(aList.getSize() == 3);
	assert(aList.myFirst != NULL);
	assert(aList.myLast != NULL);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 33);
	assert(aList.myFirst->myNext->myItem == 22);
	assert(aList.myLast->myNext == NULL);
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert(list2.getSize() == 0);
	assert(list2.myFirst == NULL);
	assert(list2.myLast == NULL);
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert(list4.getSize() == 3);
	assert(list4.getFirst() == 11);
	assert(list4.getLast() == 33);
	assert(list4.myFirst->myNext->myItem == 22);
	assert(list4.myFirst != list3.myFirst);
	assert(list4.myLast != list3.myLast);
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert(list2.getSize() == 0);
	assert(list2.myFirst == NULL);
	assert(list2.myLast == NULL);
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert(list4.getSize() == 3);
	assert(list4.getFirst() == 11);
	assert(list4.getLast() == 33);
	assert(list4.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list4.myFirst != list3.myFirst);
	assert(list4.myFirst->myNext != list3.myFirst->myNext);
	assert(list4.myLast != list3.myLast);
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert(list5.getSize() == 3);
	assert(list5.getFirst() == 11);
	assert(list5.getLast() == 33);
	assert(list5.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list5.myFirst != list3.myFirst);
	assert(list5.myFirst->myNext != list3.myFirst->myNext);
	assert(list5.myLast != list3.myLast);
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert(list6.getSize() == 0);
	assert(list6.myFirst == NULL);
	assert(list6.myLast == NULL);
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert(list8.getSize() == 3);
	assert(list8.getFirst() == 11);
	assert(list8.getLast() == 33);
	assert(list8.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list8.myFirst != list3.myFirst);
	assert(list8.myFirst->myNext != list3.myFirst->myNext);
	assert(list8.myLast != list3.myLast);
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert(list10.getSize() == 3);
	assert(list10.getFirst() == 11);
	assert(list10.getLast() == 33);
	assert(list10.myFirst->myNext->myItem == 22);
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert(list11.getSize() == 3);
	assert(list11.getFirst() == 11);
	assert(list11.getLast() == 33);
	assert(list11.myFirst->myNext->myItem == 22);
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

//written by: Carolyn Lindemulder
void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	List<double> list1, list2, list3;
	for (unsigned i = 1; i < 4; i++) {
		list1.append(i * 11);
		list2.append(i * 11);
	}

	//two empty lists
	List<double> list4;
	assert(list3 == list4);
	cout << " 0 " << flush;

	//non-empty and empty list
	assert(!(list1 == list3));
	cout << " 1 " << flush;

	//two equal-sized, non-equal lists
	List<double> list5;
	list5.append(11);
	list5.append(2);
	list5.append(3);
	assert(!(list1 == list5));
	cout << " 2 " << flush;

	//two non-equally sized lists
	List<double> list6;
	list5.append(11);
	list5.append(22);
	assert(!(list1 == list6));
	cout << " 3 " << flush;

	//two equal non-empty lists
	assert(list1 == list2);
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}

//written by: Carolyn Lindemulder
void ListTester::testReadFromStream() {
	cout << "Testing readFrom(istream)... " << flush;
	ifstream fin("ListTest1.txt");
	assert(fin.is_open());

	List<double> list3;
	list3.readFrom(fin);

	assert(list3.getSize() == 3);
	assert(list3.getFirst() == 11);
	assert(list3.myFirst->myNext->myItem == 22);
	assert(list3.myFirst->myNext->myNext->myItem == 33);
	assert(list3.myFirst->myNext->myNext->myNext == NULL);
	assert(list3.getLast() == 33);

	fin.close();

	cout << "Passed!" << endl;
}

//written by: Carolyn Lindemulder
void ListTester::testWriteToFile() {
	cout << "Testing writeTo(string)... " << flush;
	ifstream fin;
	fin.open("ListTest1.txt");
	assert(fin.is_open());
	List<double> list3;
	list3.readFrom(fin);
	fin.close();

	list3.writeTo("ListTest1Copy1.txt");

	List<double> list1;
	list1.readFrom("ListTest1Copy1.txt");
	assert(list3 == list1);
	assert(list3.getFirst() == 11);
	assert(list3.myFirst->myNext->myItem == 22);
	assert(list3.myFirst->myNext->myNext->myItem == 33);
	assert(list3.myFirst->myNext->myNext->myNext == NULL);
	assert(list3.getLast() == 33);

	cout << "Passed!" << endl;
}

//written by: Carolyn Lindemulder
void ListTester::testPrepend() {
	cout << "Testing prepend... " << flush;
	List<double> list1, list2;
	for (unsigned i = 1; i < 4; i++) {
		list1.append(i * 11);
	}

	//prepend to an empty list
	list2.prepend(-1);
	assert(list2.getSize() == 1);
	assert(list2.getFirst() == -1);
	assert(list2.getLast() == -1);
	cout << " 0 " << flush;

	//prepend to a non-empty list
	list1.prepend(-1);
	assert(list1.getSize() == 4);
	assert(list1.getFirst() == -1);
	assert(list1.myFirst->myNext->myItem == 11);
	assert(list1.myFirst->myNext->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myNext->myItem == 33);
	assert(list1.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == 33);
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

//written by: Carolyn Lindemulder
void ListTester::testInsert() {
	cout << "Testing insertion... " << flush;
	List<double> list1, list2;
	for (unsigned i = 1; i < 4; i++) {
		list1.append(i * 11);
	}

	//insert into an empty list
	list2.insert(0, 0);
	assert(list2.getSize() == 1);
	assert(list2.getFirst() == 0);
	cout << " 0 " << flush;

	//insert into non-empty list
	list1.insert(20, 1);
	assert(list1.getSize() == 4);
	assert(list1.getFirst() == 11);
	assert(list1.myFirst->myNext->myItem == 20);
	assert(list1.myFirst->myNext->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myNext->myItem == 33);
	assert(list1.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == 33);
	cout << " 1 " << flush;

	//negative index
	list1.insert(-1, -1);
	assert(list1.getSize() == 5);
	assert(list1.getFirst() == -1);
	assert(list1.myFirst->myNext->myItem == 11);
	assert(list1.myFirst->myNext->myNext->myItem == 20);
	assert(list1.myFirst->myNext->myNext->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myItem == 33);
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == 33);
	cout << " 2 " << flush;

	//larger index than end of list
	list2.insert(1, 10);
	assert(list2.getSize() == 2);
	assert(list2.getFirst() == 0);
	assert(list2.myFirst->myNext->myItem == 1);
	assert(list2.getLast() == 1);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	// test empty
	List<double> list1;
	List<double> list2;
	assert(!(list1 != list2));
	cout << " 1 " << flush;

	// test empty against non-empty
	list2.append(1);
	assert(list1 != list2);
	cout << " 2 " << flush;

	// test equal non-empty against non-empty
	list1.append(1);
	assert(!(list1 != list2));
	cout << " 3 " << flush;

	// test unequal non-empty against non-empty
	list2.append(2);
	assert(list1 != list2);
	cout << " 4 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testWriteToStream() {
	cout << "Testing writeToStream... " << flush;

	List<double> list1;
	ifstream fin("ListTest3.txt");
	assert(fin.is_open());
	list1.readFrom(fin);
	fin.close();

	ofstream fout("ListTest3Copy.txt");
	assert(fout.is_open());
	list1.writeTo(fout, "\t");
	fout.close();

	List<double> list2;
	fin.open("ListTest3Copy.txt");
	assert(fin.is_open());
	list2.readFrom(fin);
	fin.close();

	assert(list2.mySize == 4);
	assert(list2.myFirst->myItem == 0);
	assert(list2.myFirst->myNext->myItem == 1);
	assert(list2.myFirst->myNext->myNext->myItem == 2);
	assert(list2.myFirst->myNext->myNext->myNext->myItem == 3);
	assert(list2.myLast->myItem == 3);

	cout << "Passed! " << endl;
}

void ListTester::testReadFromString() {
	cout << "Testing readFromString... " << flush;
	List<double> alist;
	alist.readFrom("ListTest2.txt");

	assert(alist.mySize == 4);
	assert(alist.myFirst->myItem == 0);
	assert(alist.myFirst->myNext->myItem == 1);
	assert(alist.myFirst->myNext->myNext->myItem == 2);
	assert(alist.myFirst->myNext->myNext->myNext->myItem == 3);
	assert(alist.myLast->myItem == 3);

	cout << "Passed! " << endl;
}

void ListTester::testGetIndexOf() {
	cout << "Testing GetIndexOf... " << flush;
	// test empty
	List<double> List1;
	assert(List1.getIndexOf(5) == -1);
	assert(List1.getIndexOf(-5) == -1);
	cout << " 1 " << flush;

	// test non-empty
	List1.append(1);
	List1.append(2);
	List1.append(3);
	assert(List1.getIndexOf(1) == 0);
	assert(List1.getIndexOf(2) == 1);
	assert(List1.getIndexOf(3) == 2);
	assert(List1.getIndexOf(5) == -1);
	cout << " 2 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testRemove() {
	cout << "Testing Remove... " << flush;
	List<double> List1;
	// test empty
	try {
		List1.remove(10);
	} catch (logic_error&) {
		cout << " 1 " << flush;
	}

	// test non-empty first case
	for (unsigned i = 1; i < 4; i++) {
		List1.append(i * 11);
	}
	assert(List1.mySize == 3);
	assert(List1.getFirst() == 11);

	assert(List1.remove(-5) == 11);
	assert(List1.mySize == 2);
	assert(List1.getFirst() == 22);

	assert(List1.remove(-5) == 22);
	assert(List1.mySize == 1);
	assert(List1.getFirst() == 33);

	assert(List1.remove(-5) == 33);
	assert(List1.mySize == 0);

	cout << " 2 " << flush;

	// test non-empty second case
	for (unsigned i = 1; i < 4; i++) {
		List1.append(i * 11);
	}
	assert(List1.mySize == 3);
	assert(List1.remove(5) == 33);
	assert(List1.mySize == 2);
	assert(List1.remove(5) == 22);
	assert(List1.mySize == 1);
	assert(List1.remove(5) == 11);
	assert(List1.mySize == 0);

	// test non-empty center case
	for (unsigned i = 1; i < 4; i++) {
		List1.append(i * 11);
	}
	assert(List1.mySize == 3);
	assert(List1.remove(1) == 22);
	assert(List1.mySize == 2);
	assert(List1.remove(5) == 33);
	assert(List1.mySize == 1);
	assert(List1.remove(5) == 11);
	assert(List1.mySize == 0);

	cout << " 3 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing InsertAfter... " << flush;
	List<string> list1;

	// insert into an empty list
	try {
		list1.insertAfter("", "Bob");
	} catch (underflow_error) {
		cout << " 0 " << flush;
	}

	// insert into a list of one
	list1.append("Bob");
	assert(list1.getSize() == 1);

	list1.insertAfter("Bob", "Ann");
	assert(list1.getSize() == 2);
	assert(list1.getFirst() == "Bob");
	assert(list1.myFirst->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext == NULL);
	assert(list1.getLast() == "Ann");
	cout << " 1 " << flush;

	// insert after first person of the list
	list1.insertAfter("Bob", "Joe");
	assert(list1.getSize() == 3);
	assert(list1.getFirst() == "Bob");
	assert(list1.myFirst->myNext->myItem == "Joe");
	assert(list1.myFirst->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Ann");
	cout << " 2 " << flush;

	// insert after last person in the list
	list1.insertAfter("Ann", "Peter");
	assert(list1.getSize() == 4);
	assert(list1.getFirst() == "Bob");
	assert(list1.myFirst->myNext->myItem == "Joe");
	assert(list1.myFirst->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext->myItem == "Peter");
	assert(list1.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Peter");
	cout << " 3 " << flush;

	// insert after middle person
	list1.insertAfter("Bob", "Jake");
	assert(list1.getSize() == 5);
	assert(list1.getFirst() == "Bob");
	assert(list1.myFirst->myNext->myItem == "Jake");
	assert(list1.myFirst->myNext->myNext->myItem == "Joe");
	assert(list1.myFirst->myNext->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myItem == "Peter");
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Peter");
	cout << " 4 " << flush;

	// insert after non-existent person
//	assert( list1.insertAfter("Calvin", "Austin") == false );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertBefore() {
	cout << "Testing InsertBefore... " << flush;
	List<string> list1;
	list1.append("Bob");
	list1.append("Ann");

	// insert before first person of the list
	list1.insertBefore("Bob", "Joe");
	assert(list1.getSize() == 3);
	assert(list1.getFirst() == "Joe");
	assert(list1.myFirst->myNext->myItem == "Bob");
	assert(list1.myFirst->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Ann");
	cout << " 0 " << flush;

	// insert before last person in the list
	list1.insertBefore("Ann", "Peter");
	assert(list1.getSize() == 4);
	assert(list1.getFirst() == "Joe");
	assert(list1.myFirst->myNext->myItem == "Bob");
	assert(list1.myFirst->myNext->myNext->myItem == "Peter");
	assert(list1.myFirst->myNext->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Ann");
	cout << " 1 " << flush;

	// insert after middle person
	list1.insertBefore("Bob", "Jake");
	assert(list1.getSize() == 5);
	assert(list1.getFirst() == "Joe");
	assert(list1.myFirst->myNext->myItem == "Jake");
	assert(list1.myFirst->myNext->myNext->myItem == "Bob");
	assert(list1.myFirst->myNext->myNext->myNext->myItem == "Peter");
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myItem == "Ann");
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(list1.getLast() == "Ann");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testOutput() {
	cout << "Testing Output... " << flush;

	List<string> list1;
	ofstream fout1("ListTest4.txt");
	assert(fout1.is_open());
	fout1 << list1;
	fout1.close();
	string list2;
	ifstream fin1("ListTest4.txt");
	assert(fin1.is_open());
	getline(fin1, list2);
	fin1.close();
	assert(list2 == "");
	fin1.close();
	cout << " 0 " << flush;

	list1.append("Bob");
	ofstream fout2("ListTest4.txt");
	assert(fout2.is_open());
	fout2 << list1;
	fout2.close();
	string list3;
	ifstream fin2("ListTest4.txt");
	assert(fin2.is_open());
	getline(fin2, list3);
	fin2.close();
	assert(list3 == "Bob");
	fin2.close();

	cout << " 1 " << flush;

	list1.append("Ann");
	ofstream fout3("ListTest4.txt");
	assert(fout3.is_open());
	fout3 << list1;
	fout3.close();
	string list4;
	ifstream fin3("ListTest4.txt");
	assert(fin3.is_open());
	getline(fin3, list4);
	fin3.close();
	assert(list4 == "Bob=>Ann");
	fin3.close();
	cout << " 2 " << flush;

	cout << "Passed! " << endl;
}
