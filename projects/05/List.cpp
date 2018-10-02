/* List.cpp
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 13, 2017
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

/* The equality Operator
 * compares two lists and
 * returns a boolean
 *
 * @param	L2	The List being compared
 * @return		The boolean expression True or False
 */
bool List::operator==( const List& L2 ) const {
	if ( mySize != L2.getSize() ) {
		return false;
	} else {
		Node* myNode = myFirst;
		Node* L2Node = L2.myFirst;
		while ( myNode != NULL) {
			if ( myNode->myItem != L2Node->myItem ) {
				return false;
			}
			myNode = myNode->myNext;
			L2Node = L2Node->myNext;
		}
		return true;
	}
}

/* The inequality Operator
 * compares two lists and
 * returns a boolean
 *
 * @param	L2	The List being compared
 * @return		The boolean expression True or False
 */
bool List::operator!=( const List& L2 ) const {
	if ( mySize != L2.getSize() ) {
		return true;
	} else {
		Node* myNode = myFirst;
		Node* L2Node = L2.myFirst;
		while ( myNode != NULL) {
			if ( myNode->myItem != L2Node->myItem ) {
				return true;
			}
			myNode = myNode->myNext;
			L2Node = L2Node->myNext;
		}
		return false;
	}
}

/* The Read From Stream Operation
 *
 *
 *@param	in	Stream being read from
 */
void List::readFrom( istream& in ) {
	Node* myNode = myFirst;
	while ( myNode != NULL) {
		in >> myNode->myItem;
		myNode = myNode->myNext;
	}
}

/* The Write To Stream Operation
 *
 */
void List::writeTo( ostream& out ) {
	Node* myNode = myFirst;
	for ( unsigned i = 0; i < mySize; i++ ) {
			out << myNode->myItem << "\n";
		}
}

/* The Read From String Operation
 *
 */
void List::readFrom( const string& fileName ) {
	Node* myNode = myFirst;
	ifstream fin( fileName.c_str() );
		assert( fin.is_open() );
		while ( !(fin.eof()) ) {
			fin >> myNode->myItem;
			myNode = myNode->myNext;
		}
		fin.close();
}

/* The Write To String Operation
 *
 */
void List::writeTo( const string& fileName ) {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );
	Node* myNode = myFirst;
	for ( unsigned i = 0; i < mySize; i++ ) {
			fout << myNode->myItem << "\n";
	}
	fout.close();
}

///* The Prepend Operation
// *
// */
//List List::prepend( Item ) {
//
//}

/* The Index Accessor
 * allows the user to
 * find the index of a
 * given item in a list
 *
 * @param	it	The item being searched for
 */
int List::getIndexOf( const Item& it ) {
	Node* myNode = myFirst;
	int index = 0;
	while ( it != myNode->myItem ) {
		if ( myNode == NULL ) {
			throw range_error( "No item exists");
		} else {
		myNode = myNode->myNext;
		index += 1;
		}
	}
	return index;
}

///* The Insertion Operation
// *
// */
//List List::insert( Item, unsigned index ) {
//
//}

/* The Remove Operation
 * allows the user to
 * delete an item locate
 * at the given index
 *
 * @param	index	The index of the item being removed from the list
 */
int List::remove( unsigned index ) {
	Node* myNode = myFirst;
	for ( unsigned i = 0; i < index; i++ ) {
		if ( i == index ) {
			delete myNode;
			myNode = NULL;
		} else {
			myNode = myNode->myNext;
		}
	}
	return myNode->myItem;
}
