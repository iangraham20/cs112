/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 lab 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 28, 2017
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
	if (capacity < 1) {
		throw StackException("Constructor", "Capacity cannot be less than 1");
	}
	mySize = 0;
	myCapacity = capacity;
	myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete[] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete[] myArray;
		makeCopyOf(original);
	}
	return *this;
}

Item Stack::peekTop() {
	if (isEmpty()) {
		throw StackException("peekTop()", "Stack is Empty");
	} else {
		return myArray[mySize - 1];
	}
}

void Stack::push(Item it) {
	if (isFull()) {
		throw StackException("push()", "Stack is Full");
	}
	myArray[mySize++] = it;
}

Item Stack::pop() {
	if (isEmpty()) {
		throw StackException("pop()", "Stack is Empty");
	} else {
		return myArray[--mySize];
	}
}
