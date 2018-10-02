/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast-1] == getLast().
 * 
 *  (When I am not empty:
 *     myFirst is the index of my oldest value;
 *     myLast is the index of the spot where the next
 *       item to be appended will be placed.)      
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"	//
#include <cstring>      	// memcpy()
using namespace std;		//

typedef int Item;

template<class Item>
class ArrayQueue {
public:

	// constructors (required functions)
	ArrayQueue				( unsigned capacity );
	ArrayQueue				( const ArrayQueue& original);
	ArrayQueue& operator=	( const ArrayQueue& original);
	virtual ~ArrayQueue();

	// accessors (constant functions)
	unsigned 	getSize() 		const;
	unsigned 	getCapacity() 	const;
	bool 		isEmpty() 		const	{ return mySize == 0; 			}
	bool 		isFull() 		const	{ return mySize == myCapacity; 	}
	unsigned 	getFirst() 		const;
	unsigned 	getLast() 		const;

	// mutators (non-constant functions)
	void append( const Item& it );
	Item remove();
	void setCapacity( unsigned newCapacity );

protected:
	virtual void makeCopyOf( const ArrayQueue& original );

private:

	// instance variables
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item*    myArray;      // dynamic array of items

	// friend
	friend class ArrayQueueTester;
};

/* default constructor
 * assigns minimum values
 * to instance variables
 *
 * @param	capacity	storage limit
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue( unsigned capacity ) {
	if ( capacity <= 0 ) {
		throw QueueException( "Constructor", "Capacity cannot be negative" );
	} else {
		myArray = new Item[capacity];
	}
	myCapacity = capacity;
	mySize = myFirst = myLast = 0;
 }

/* getFirst accessor
 * retrieves the first
 * item in the queue
 *
 * @return	myFirst	The first item in the queue
 */
template<class Item>
unsigned ArrayQueue<Item>::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException( "getFirst" );
	}
	return myArray[ myFirst ];
}

/* getLast accessor
 * retrieves the last
 * item in the queue
 *
 * @return	myLast	The last item in the queue
 */
template<class Item>
unsigned ArrayQueue<Item>::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException( "getFirst" );
	}
	return myArray[ ( myLast - 1 + myCapacity ) % myCapacity ];
}

/* append mutator
 * adds an item to
 * the queue
 *
 * @param	it	the item being appended to the queue
 */
template<class Item>
void ArrayQueue<Item>::append( const Item& it ) {
	if ( isFull() ) {
		throw FullQueueException( "append" );
	}
	myArray[ myLast ] = it;
	myLast = ( myLast + 1 ) % myCapacity;
	mySize++;
}

/* remove mutator
 * removes an item
 * from the queue
 *
 * @param	it	the item being removed from the queue
 */
template<class Item>
Item ArrayQueue<Item>::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException( "remove" );
	}
	Item result;
	result = myArray[ myFirst ];
	myFirst = ( myFirst + 1 ) % myCapacity;
	mySize--;
	return result;
}

template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity*sizeof(Item) );
}

/* destructor
 * deletes and deallocates queue
 */
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

/* assignment operator
 *
 * @param	aQueue
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* getCapacity accessor
 * determines the maximum
 * number of items that
 * the queue can store
 *
 * @return	myCapacity	The maximum size of the queue
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* setCapacity mutator
 * changes the maximum
 * number of items that
 * the queue can store
 *
 *
 */
template<class Item>
void ArrayQueue<Item>::setCapacity( unsigned newCapacity ) {
	if ( newCapacity == 0 || newCapacity < getSize() ) {
		throw QueueException("setCapacity()", "Stack is to small");
	}
	Item* newArray = new Item[newCapacity];
	for (unsigned i = myFirst; i < mySize + myFirst; i++) {
		newArray[i - myFirst] = myArray[i % myCapacity];
	}
	myCapacity = newCapacity;
	delete[] myArray;
	myArray = newArray;
	myFirst = 0;
	myLast = mySize;
}

/* getSize accessor
 * determines the
 * number of items
 * currently stored
 * in the queue
 *
 * @return	mySize	The current size of the queue
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

#endif /*ARRAY_QUEUE_H_*/
