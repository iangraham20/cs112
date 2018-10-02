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

protected:
	virtual void makeCopyOf(const ArrayQueue& original);

private:

	// instance variables
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item*    myArray;      // dynamic array of items

	// friend???
	friend class ArrayQueueTester;
};

#endif /*ARRAY_QUEUE_H_*/
