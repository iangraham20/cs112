/* LinkedQueue.h declares a Queue class using linked nodes.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 * 
 * Class Invariant: 
 *    mySize == 0 && myFirst == NULL && myLast == NULL ||
 *    mySize > 0 && myFirst == the address of a node containing the oldest item
 *               && myLast == the address of a node containing the newest item.
 */

#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include "QueueException.h"
typedef int Item;

class LinkedQueue {
public:

	// constructors (required functions)
	LinkedQueue();
	LinkedQueue				( const LinkedQueue& original );
	LinkedQueue& operator=	( const LinkedQueue& original );
	virtual 	~LinkedQueue();

	// accessors (constant functions)
	unsigned getSize() 	const { return mySize; }
	Item 	getFirst() 	const;
	Item 	 getLast() 	const;
	bool 	 isEmpty() 	const { return mySize == 0; }
	bool 	  isFull() 	const { return false; }

	// mutators (non-constant functions)
	void append( const Item& it );
	Item remove();

protected:
	void makeCopyOf( const LinkedQueue& original );

private:
	struct Node {
		Item myItem;
		Node * myNext;
		
		Node(const Item& it, Node* next) { myItem = it; myNext = next; }
		~Node() { delete myNext; }
	};

	// instance variables
	unsigned mySize;
	Node * 	 myFirst;
	Node * 	 myLast;

	// friend???
	friend class LinkedQueueTester;
};

#endif /*LINKED_QUEUE_H_*/
