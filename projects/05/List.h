/* List.h
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 13, 2017
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdexcept>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;
typedef double Item;

/* prototypes
 *
 */
class List {
public:
	List();
	~List();
	List( const List& original );
	List& operator=( const List& original );
	unsigned getSize() const { return mySize; };
	Item getFirst() const;
	Item getLast() const;
	void append( const Item& it );

	bool operator==( const List& L2 ) const;
	bool operator!=( const List& L2 ) const;
	void readFrom( istream& in );
	void writeTo( ostream& out );
	void readFrom( const string& fileName );
	void writeTo( const string& fileName );
//	List prepend( Item );
	int getIndexOf( const Item& it );
//	List insert( Item, unsigned index );
	int remove( unsigned index );

private:
	struct Node {
		Node();
		Node( Item it,  Node* next );
		~Node();
		Item	myItem;
		Node*	myNext;
	};
	unsigned	mySize;
	Node*		myFirst;
	Node*		myLast;
	friend class ListTester;
};



#endif /* LIST_H_ */
