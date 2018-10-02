/*
 * List.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: igc2
 */

#include "List.h"

/* The Default Constructor
 *
 */
List::List() {
	mySize = 0;
	myFirst = myLast = NULL;
}

/* The Default Node Constructor
 *
 */
List::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

/* The Explicit Node Constructor
 *
 *
 * @param	it
 * @param	next
 */
List::Node::Node( Item it,  Node* next ) {
	myItem = it;
	myNext = next;
}

/* The getFirst Accessor
 *
 */
Item List::getFirst() const {
	if ( mySize == 0 || myFirst == NULL ) {
		throw underflow_error( "underflow error" );
	}
	return myFirst->myItem;
}

/* The getLast Accessor
 *
 */
Item List::getLast() const {
	if ( mySize == 0 || myLast == NULL ) {
		throw underflow_error( "underflow error" );
	}
	return myLast->myItem;
}

/* The Append Operation
 *
 */
void List::append( const Item& it ) {
	Node* newNode;
	newNode = new Node( it, NULL );
	if ( mySize == 0 ) {
		myFirst = newNode;
	} else {
		myLast->myNext = newNode;
	}
	mySize++;
	myLast = newNode;
}

/* The Destuctor
 *
 */
List::~List() {
   delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
   myFirst = myLast = NULL; // clear myFirst and myLast (optional)
   mySize = 0;              // clear mySize (optional)
}

/* The Node Destructor
 *
 */
List::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item " << myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
                        // (does nothing if myNext == NULL)
}

/* The Copy Constructor
 *
 * @param	original
 */
List::List(const List& original) {
      myFirst = myLast = NULL;          //  set pointers
      mySize = 0;                       //   and size to 'empty' values
      if (original.getSize() > 0) {     //  if there are nodes to copy:
         Node* oPtr = original.myFirst; //  start at the first node
         while (oPtr != NULL) {         //  while there are more nodes:
            append(oPtr->myItem);       //   append the item in that node
            oPtr = oPtr->myNext;        //   advance to next node
         }
      }
   }

/* The Assignment Operator
 *
 * @param	original
 */
List& List::operator=(const List& original) {
	if ( this != &original ) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* nPtr = original.myFirst;
			while (nPtr != NULL) {
				append(nPtr->myItem);
				nPtr = nPtr->myNext;
			}
		}
	}
	return *this;
}
