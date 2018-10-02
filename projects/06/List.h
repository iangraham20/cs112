/*
 * List.h provides a class for manipulating lists made of nodes
 *
 *  Created on: Mar 6, 2017
 *      Author: Carolyn Lindemulder, Ian Chistensen
 *      For CS 112 at Calvin College
 *
 *  Carolyn Lindemulder: ==, readFrom(istream), writeTo(string), prepend, insert
 *  Ian Christensen: !=, writeTo(ostream), readFrom(string), getIndexOf, remove
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

template<class Item>

class List {
public:
	List();
	List(const List& original);
	virtual ~List();
	unsigned getSize() const {
		return mySize;
	}
	const Item getFirst();
	const Item getLast();
	void append(const Item& item);
	List& operator=(const List& original);
	bool operator==(const List& l2) const;
	void readFrom(istream& in);
	void writeTo(const string& fileName);
	void prepend(const Item& item);
	void insert(const Item& item, const int& index);
	bool operator!=(const List<Item>& L2) const;
	void writeTo(ostream& out, const string& delimeter);
	void readFrom(const string& fileName);
	int getIndexOf(const Item& it);
	Item remove(int index);
	bool insertAfter(const string& otherName, const Item yourName);
	bool insertBefore(const Item& otherName, const Item yourName);
private:
	struct Node {
		Node();
		Node(Item item, Node* next);
		~Node();
		Item myItem;
		Node* myNext;
	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	friend class ListTester;
};

//default node constructor
template<class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = NULL;
}

//explicit node constructor
template<class Item>
List<Item>::Node::Node(Item item, Node* next) {
	myItem = item;
	myNext = next;
}

//node destructor
template<class Item>
List<Item>::Node::~Node() {
	delete myNext;
}

//default list constructor
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = NULL;
}

//list copy constructor
template<class Item>
List<Item>::List(const List<Item>& original) {
	myFirst = myLast = NULL;
	mySize = 0;
	if (original.getSize() > 0) {
		Node* oPtr = original.myFirst;
		while (oPtr != NULL) {
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
}

//list destructor
template<class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

/*getter method for the first item in a list
 underflow_error thrown if list is empty*/
template<class Item>
const Item List<Item>::getFirst() {
	if (mySize == 0) {
		throw underflow_error("This is an empty list");
	} else {
		return myFirst->myItem;
	}
}

/*getter method for last item in list
 underflow_error thrown if list is empty*/
template<class Item>
const Item List<Item>::getLast() {
	if (mySize == 0) {
		throw underflow_error("This is an empty list");
	} else {
		return myLast->myItem;
	}
}

/*append method
 * parameter: item, an Item (currently defined as a double)
 * post-condition: item will be appended to the end of the list
 */
template<class Item>
void List<Item>::append(const Item& item) {
	Node* ptr = new Node(item, NULL);
	if (mySize == 0) {
		myFirst = ptr;
	} else {
		myLast->myNext = ptr;
	}

	myLast = ptr;
	mySize++;
}

/*assignment operation
 * parameter: original, a List
 * returns: a List that is a copy of original in a different memory address
 */
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
	if (&*this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* nPtr = original.myFirst;
			while (nPtr != NULL) {
				this->append(nPtr->myItem);
				nPtr = nPtr->myNext;
			}
		}
	}
	return *this;
}

/*equality operator
 * written by: Carolyn Lindemulder
 * parameter: l2, a List
 * returns: true if the contents of lists are equal, false otherwise
 */
template<class Item>
bool List<Item>::operator==(const List<Item>& l2) const {
	if (mySize != l2.getSize()) {
		return false;
	}
	Node* myPtr = myFirst;
	Node* l2Ptr = l2.myFirst;
	if (myPtr != NULL) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myPtr == NULL) {
				break;
			}
			if (myPtr->myItem != l2Ptr->myItem) {
				return false;
			}
			myPtr = myPtr->myNext;
			l2Ptr = l2Ptr->myNext;
		}
	}
	return true;
}

/*read from stream
 * written by: Carolyn Lindemulder
 * parameter: in, an istream
 * pre-condition: values are separated by spaces
 * 					end of values indicated with a newline
 * post-condition: the list will contain the values from in
 */
template<class Item>
void List<Item>::readFrom(istream& in) {
	Item item;
	//in >> item method from stack overflow
	while (in >> item) {
		this->append(item);
	}
}

/*write to file
 * written by: Carolyn Lindemulder
 * parameter: fileName, the name of the file as a string
 * post-condition: values in list will be written to file
 * 					one value will be written on each line in the file
 */
template<class Item>
void List<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	Node* ptr = myFirst;
	while (true) {
		fout << ptr->myItem << endl;
		if (ptr == myLast) {
			break;
		}
		ptr = ptr->myNext;
	}
}

/*prepend method
 * written by: Carolyn Lindemulder
 * parameter: item, an Item (currently defined as a double)
 * post-condition: item will become the first member of the list
 */
template<class Item>
void List<Item>::prepend(const Item& item) {
	if (mySize == 0) {
		append(item);
	} else {
		Node* originalFirst = myFirst;
		myFirst = new Node(item, originalFirst);
		mySize++;
	}
}

/*insertion method
 * written by: Carolyn Lindemulder
 * parameters: item, an Item (currently defined as double)
 *				index, an int
 * post-condition: item will be inserted into the list at the location given by index
 */
template<class Item>
void List<Item>::insert(const Item& item, const int& index) {
	if (index <= 0) {
		prepend(item);
	} else if (index >= mySize) {
		append(item);
	} else {
		Node* ptr = myFirst;
		for (int i = 0; i < (index - 1); i++) {
			ptr = ptr->myNext;
		}
		Node* insertion = new Node(item, ptr->myNext);
		ptr->myNext = insertion;
		mySize++;
	}
}

/* The inequality Operator
 * compares two lists and
 * returns a boolean
 *
 * @param	L2	The List being compared
 * @return		The boolean expression True or False
 */
template<class Item>
bool List<Item>::operator!=(const List<Item>& L2) const {
	if (mySize != L2.getSize()) {
		return true;
	} else {
		Node* myNode = myFirst;
		Node* L2Node = L2.myFirst;
		while (myNode != NULL) {
			if (myNode->myItem != L2Node->myItem) {
				return true;
			}
			myNode = myNode->myNext;
			L2Node = L2Node->myNext;
		}
		return false;
	}
}

/* The Write To Stream Operation
 *
 */
template<class Item>
void List<Item>::writeTo(ostream& out, const string& delimeter) {
	Node* myNode = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		out << myNode->myItem << flush;
		if (myNode->myNext != NULL) {
			out << delimeter << flush;
		}
		myNode = myNode->myNext;
	}
	out << endl;
}

/* The Read From String Operation
 *
 */
template<class Item>
void List<Item>::readFrom(const string& fileName) {
	Item item;
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	while (fin >> item) {
		this->append(item);
	}
	fin.close();
}

/* The Index Accessor
 * allows the user to
 * find the index of a
 * given item in a list
 *
 * @param	it	The item being searched for
 */
template<class Item>
int List<Item>::getIndexOf(const Item& it) {
	Node* myNode = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		if (it == myNode->myItem) {
			return i;
		}
		myNode = myNode->myNext;
	}
	return -1;
}

/* The Remove Operation
 * allows the user to
 * delete an item locate
 * at the given index
 *
 * @param	index	The index of the item being removed from the list
 */
template<class Item>
Item List<Item>::remove(int index) {
	if (mySize == 0) {
		throw logic_error("empty");
	}
	Item myItem = myFirst->myItem;
	if (index <= 0 || mySize == 1) {
		Node* tempNode = myFirst;
		myFirst = myFirst->myNext;
		tempNode->myNext = NULL;
		mySize--;
		delete tempNode;
		return myItem;
	} else if (index >= mySize - 1) {
		Node* tempNode = myFirst;
		for (unsigned i = 0; i < (mySize - 2); i++) {
			tempNode = tempNode->myNext;
		}
		myLast = tempNode;
		tempNode = tempNode->myNext;
		myItem = tempNode->myItem;
		myLast->myNext = NULL;
		mySize--;
		delete tempNode;
		return myItem;
	} else {
		Node* tempNode1 = myFirst;
		Node* tempNode2 = myFirst;
		for (int i = 0; i <= (index - 1); i++) {
			tempNode2 = tempNode1;
			tempNode1 = tempNode1->myNext;
		}
		Item Val = tempNode1->myItem;
		tempNode2->myNext = tempNode1->myNext;
		tempNode1->myNext = NULL;
		mySize--;
		delete tempNode1;
		return Val;
	}
}

/*
 *
 */
template<class Item>
bool List<Item>::insertAfter(const string& otherName, const Item yourName) {
	if (mySize < 1) {
		throw underflow_error("cannot insert before empty list");
	}
	Node* ptr = myFirst;
	int index = getIndexOf(otherName);
	if (index == -1) {
		return false;
	}
	for (int i = 0; i < getIndexOf(otherName); i++) {
		ptr = ptr->myNext;
	}
	Node* insertion = new Node(yourName, ptr->myNext);
	ptr->myNext = insertion;
	if (ptr == myLast) {
		myLast = insertion;
	}
	mySize++;
	return true;
}

/*
 *
 */
template<class Item>
bool List<Item>::insertBefore(const Item& otherName, const Item yourName) {
	Node* ptr = myFirst;
	if (getIndexOf(otherName) == 0) {
		prepend(yourName);
	} else if (getIndexOf(otherName) == -1) {
		return false;
	} else {
		for (int i = 0; i < getIndexOf(otherName) - 1; i++) {
			ptr = ptr->myNext;
		}
		Node* insertion = new Node(yourName, ptr->myNext);
		ptr->myNext = insertion;
		mySize++;
	}
	return true;
}

template<class Item>
ostream& operator<<(ostream& out, List<Item>& original) {
	original.writeTo(out, "=>");
	return out;
}

#endif /* LIST_H_ */
