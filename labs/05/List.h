/* List.h
 * Created on: Mar 7, 2017
 * Author: igc2
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
typedef double Item;

/* prototypes?
 *
 */
class List {
public:
	List();
	~List();
	List(const List& original);
	List& operator=(const List& original);
	unsigned getSize() const { return mySize; };
	Item getFirst() const;
	Item getLast() const;
	void append( const Item& it );
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
