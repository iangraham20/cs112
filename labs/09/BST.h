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

class BST {
public:
	// constructor prototypes
	BST();
	virtual ~BST();

	// accessor prototypes
	bool isEmpty() const;
	unsigned getNumItems() const;

	// mutator prototypes
	void insert(const Item& item);
	bool contains(const Item& item) const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

private:
	struct Node {
	    Node(const Item& item);
            virtual ~Node();

            void insert(const Item& item);
            bool contains(const Item& item) const;
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

#endif /*BST_H_*/
