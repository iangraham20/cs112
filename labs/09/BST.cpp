/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112, lab 9 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 */
 
#include "BST.h"

/* default constructor
 * assigns minimum values
 * to variables
 */
BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

/* explicit node constructor
 *
 */
BST::Node::Node(const Item& item) {
   myItem = item;
   myLeft = NULL;
   myRight = NULL;
}

/* destructor
 * deletes the BST by
 * resetting values to
 * their default minimum
 */
BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* node destructor
 *
 */
BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* empty boolean
 * determines whether
 * BST is empty
 */
bool BST::isEmpty() const {
	return myNumItems == 0;
}

/* size accessor
 * determines the
 * size of the BST
 *
 * @return	myNumItems	The number of items contained in the BST
 */
unsigned BST::getNumItems() const {
	return myNumItems;
}

/* insert mutator
 * adds an item to the
 * BST in a specific
 * location depending
 * on the item's value
 *
 * @param	item	The item being inserted into the BST
 */
void BST::insert(const Item& item) {
	if (myRoot == NULL) {
		Node* nPtr;
		nPtr = new Node(item);
		myRoot = nPtr;
	} else {
		myRoot->insert(item);
	}
	myNumItems++;
}

/* insert recursion mutator
 * allows insert() to check
 * all potential locations
 * within the BST through
 * recursion
 *
 * @param	item	The item being inserted into the BST
 */
void BST::Node::insert(const Item& item) {
	if (item < myItem) {
		if (myLeft == NULL) {
			Node* nPtr;
			nPtr = new Node(item);
			myLeft = nPtr;
		} else {
			myLeft->insert(item);
		}
	} else if (item > myItem) {
		if (myRight == NULL) {
			Node* nPtr;
			nPtr = new Node(item);
			myRight = nPtr;
		} else {
			myRight->insert(item);
		}
	} else {
		throw Exception("Node::insert()", "item is equal to myItem");
	}
}

/* contains boolean
 * determines whether
 * the BST contains a
 * specific value
 *
 * @param	item	The value being searched for
 */
bool BST::contains(const Item& item) const {
	if (myRoot == NULL) {
		return false;
	} else {
	myRoot->contains(item);
	}
}

/* contains recursion boolean
 * allows contains() to check
 * all potential locations
 * within the BST through
 * recursion
 *
 * @param	item	The value being searched for
 */
bool BST::Node::contains(const Item& item) const {
	if (item == myItem) {
		return true;
		} else if (item < myItem) {
			if (myLeft == NULL) {
				return false;
			}
			myLeft->contains(item);
		} else if (item > myItem) {
			if (myRight == NULL) {
				return false;
			}
			myRight->contains(item);
		}
}

/*
 *
 */
void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/*
 *
 */
void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

/*
 *
 */
void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/*
 *
 */
void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/*
 *
 */
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/*
 *
 */
void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

/*
 *
 */
void BST::Node::processItem() {
		cout << ' ' << myItem;
}
