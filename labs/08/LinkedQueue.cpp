/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ian Christensen
 * Date: April 13, 2017
 */

#include "LinkedQueue.h"

/* default constructor
 * assigns minimum values
 * to instance variables
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirst = myLast = NULL;
}

/* getFirst accessor
 * retrieves the first
 * item in the queue
 *
 * @return	myFirst	The first item in the queue
 */
Item LinkedQueue::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException( "getFirst" );
	}
	return myFirst->myItem;
}

/* getLast accessor
 * retrieves the last
 * item in the queue
 *
 * @return	myLast	The last item in the queue
 */
Item LinkedQueue::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException( "getFirst" );
	}
	return myLast->myItem;
}

/* append mutator
 * adds an item to
 * the queue
 *
 * @param	it	the item being appended to the queue
 */
void LinkedQueue::append( const Item& it ) {
	Node * nPtr;
	nPtr = new Node(it, NULL);
	if ( isEmpty() ) {
		myFirst = nPtr;
	} else {
		myLast->myNext = nPtr;
	}
	mySize++;
	myLast = nPtr;
}

/* remove mutator
 * removes an item
 * from the queue
 *
 * @param	it	the item being removed from the queue
 */
Item LinkedQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException( "LinkedQueue::remove()" );
	}
	Item result = myFirst->myItem;
	Node * nPtr = myFirst;
	myFirst = myFirst->myNext;
	nPtr->myNext = NULL;
	delete nPtr;
	mySize--;
	return result;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirst = myLast = NULL;
	} else {
		myFirst = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirst->myNext;
		Node * temp1 = myFirst;
		while (temp0 != NULL) {
			temp1->myNext = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNext;
			temp0 = temp0->myNext;
		}
		myLast = temp1;
	}
}

/* destructor
 * deletes and deallocates queue
 */
LinkedQueue::~LinkedQueue() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

/* assignment operator
 *
 * @param	aQueue
 */
LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirst;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}
