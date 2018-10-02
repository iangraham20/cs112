/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

typedef int Item;

template<class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty() { return mySize == 0; }
	bool isFull() { return mySize == myCapacity; }
	unsigned getSize() { return mySize; }
	unsigned getCapacity() { return myCapacity; }
	void setCapacity(unsigned newCapacity);
	void push(Item it);
	Item peekTop();
	Item pop();

protected:
	void makeCopyOf(const Stack& original);

private:
	unsigned myCapacity;
	unsigned mySize;
	Item* myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
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
template<class Item>
Stack<Item>::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack& original) {
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
template<class Item>
Stack<Item>::~Stack() {
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
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack& original) {
	if (this != &original) {
		delete[] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* peekTop
 * returns the top item in the stack
 *
 * @return	The top item in the stack
 */
template<class Item>
Item Stack<Item>::peekTop() {
	if (isEmpty()) {
		throw StackException("peekTop()", "Stack is Empty");
	} else {
		return myArray[mySize - 1];
	}
}

/* push
 * pushes value onto stack
 *
 * @param	it	Item being pushed onto the stack
 */
template<class Item>
void Stack<Item>::push(Item it) {
	if (isFull()) {
		throw StackException("push()", "Stack is Full");
	}
	myArray[mySize++] = it;
}

/* pop
 * returns and deletes the top item in the stack
 *
 * @return	The top item in the stack
 */
template<class Item>
Item Stack<Item>::pop() {
	if (isEmpty()) {
		throw StackException("pop()", "Stack is Empty");
	} else {
		return myArray[--mySize];
	}
}

/* setCapacity
 * reassigns the capacity value
 *
 * @param	newCapacity	The new value that capacity is being set to
 */
template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity < getSize()) {
		throw StackException("setCapacity()", "Stack is to small");
	}
	myCapacity = newCapacity;
	Item* newArray = new Item[newCapacity];
	for (unsigned i = 0; i < mySize; i++) {
		newArray[i] = myArray[i];
	}
	delete[] myArray;
	myArray = newArray;
}

#endif

