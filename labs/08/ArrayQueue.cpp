/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#include "ArrayQueue.h"

/* default constructor
 * assigns minimum values
 * to instance variables
 *
 * @param	capacity	storage limit
 */
ArrayQueue::ArrayQueue( unsigned capacity ) {
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
unsigned ArrayQueue::getFirst() const {
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
unsigned ArrayQueue::getLast() const {
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
void ArrayQueue::append( const Item& it ) {
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
Item ArrayQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException( "remove" );
	}
	Item result;
	result = myArray[ myFirst ];
	myFirst = ( myFirst + 1 ) % myCapacity;
	mySize--;
	return result;
}

ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
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
ArrayQueue::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

/* assignment operator
 *
 * @param	aQueue
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

//bool ArrayQueue::isEmpty() const {
//	return mySize == 0;
//}
//
//bool ArrayQueue::isFull() const {
//	return getSize() == myCapacity;
//}

/* getCapacity accessor
 * determines the maximum
 * number of items that
 * the queue can store
 *
 * @return	myCapacity	The maximum size of the queue
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* getSize accessor
 * determines the
 * number of items
 * currently stored
 * in the queue
 *
 * @return	mySize	The current size of the queue
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

