/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112, lab 9 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

typedef int Item;
template<class Item>
class BST {
public:
	// constructor and destructor prototypes
	BST();
	virtual ~BST();

	// accessor prototypes
	bool isEmpty() const;
	unsigned getNumItems() const;
	unsigned getHeight() const;

	// mutator prototypes
	void insert(const Item& item);
	bool contains(const Item& item) const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

private:
	struct Node {
			// node constructor and destructor prototypes
	    	Node(const Item& item);
            virtual ~Node();

            // node recursion method prototypes
            void insert(const Item& item);
            bool contains(const Item& item) const;
            unsigned getHeight() const;
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();

            // global node variables
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	// global variables
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

/* default constructor
 * assigns minimum values
 * to variables
 */
template<class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

/* explicit node constructor
 *
 */
template<class Item>
BST<Item>::Node::Node(const Item& item) {
   myItem = item;
   myLeft = NULL;
   myRight = NULL;
}

/* destructor
 * deletes the BST by
 * resetting values to
 * their default minimum
 */
template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* node destructor
 *
 */
template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* empty boolean
 * determines whether
 * BST is empty
 */
template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

/* size accessor
 * determines the
 * size of the BST
 *
 * @return	myNumItems	The number of items contained in the BST
 */
template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

/*
 *
 */
template<class Item>
unsigned BST<Item>::getHeight() const {
	unsigned height = 0;
	if ( getNumItems() == 1 ) {
		return 1;
	}
	if ( !isEmpty() ) {
		height = myRoot->getHeight();
	}
	return height;
}

template<class Item>
unsigned BST<Item>::Node::getHeight() const {
	unsigned leftHeight = 0;
	if (myLeft != NULL) {
		leftHeight = myLeft->getHeight();
	}
	unsigned rightHeight = 0;
	if (myRight != NULL) {
		rightHeight = myRight->getHeight();
	}
	if ( leftHeight > rightHeight ) {
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
	}
}

/* insert mutator
 * adds an item to the
 * BST in a specific
 * location depending
 * on the item's value
 *
 * @param	item	The item being inserted into the BST
 */
template<class Item>
void BST<Item>::insert(const Item& item) {
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
template<class Item>
void BST<Item>::Node::insert(const Item& item) {
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
template<class Item>
bool BST<Item>::contains(const Item& item) const {
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
template<class Item>
bool BST<Item>::Node::contains(const Item& item) const {
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
template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/*
 *
 */
template<class Item>
void BST<Item>::Node::traversePreorder() {
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
template<class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/*
 *
 */
template<class Item>
void BST<Item>::Node::traversePostorder() {
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
template<class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/*
 *
 */
template<class Item>
void BST<Item>::Node::traverseInorder() {
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
template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

#endif /*BST_H_*/
