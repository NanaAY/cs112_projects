/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:Nana Osei Asiedu Yirenkyi
 * project08
 * Date: 11/19/2018
 *
 * Class Invariant:
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 *
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>      // memcpy()
using namespace std;
typedef int Item;
template<class Item>

class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	ArrayQueue(unsigned capacity);
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& newItem);
	Item& remove();
	void makeCopyOf(const ArrayQueue& original);
	void setCapacity(unsigned nc);

protected:
//	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item* myArray;      // dynamic array of items

	friend class ArrayQueueTester;
};

template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity * sizeof(Item));
}
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete[] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete[] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/*ArrayQueue constructor makes an Array of certain size
 *@param none
 *Postcondition: an array with size of input value
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
	if (capacity > 0) {
		myCapacity = capacity;
		mySize = myFirst = myLast = 0;
		Item * newArray = new Item[capacity];
		myArray = newArray;
	} else {
		throw QueueException("Thrown at line 63:",
				"Queue capacity must be greater than 0.");
	}
}

/*myFirst accessor finds and returns the first value in the array
 *@param: none
 *Postcondition: the first value in the array is returned to the ostream
 */
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("Thrown at line 70");
	} else {
		return myArray[myFirst];
	}
}

/*myLast accessor finds and returns the last value in the array
 *@param:none
 *Postcondition: the last item in the array is returned to ostream
 */
template<class Item>
Item ArrayQueue<Item>::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("Thrown at line 81:");
	} else {
		return myArray[((myLast - 1) + myCapacity) % myCapacity];
	}
}

/* append method appends a new item to the end of the array
 * @param: Item from input
 * Postcondition: array with additional item at end and size refreshed
 */
template<class Item>
void ArrayQueue<Item>::append(const Item& newItem) {
	if (mySize == myCapacity) {
		throw FullQueueException("Thrown at line 95:");
	} else {
		myArray[myLast] = newItem;
		myLast = (myLast + 1) % myCapacity;
		mySize++;
	}
}

/* remove() method removes and returns first item on array
 * @param: takes in item (from node)
 * Postcondition: item in the array that the node was
 *  pointing to is removed and returned
 */
template<class Item>
Item& ArrayQueue<Item>::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("Thrown at line 108:");
	} else {
		Item& result = myArray[myFirst];
		myFirst = (myFirst + 1) % myCapacity;
		mySize = mySize - 1;
		return result;
	}
}
/*setCapacity() method allocates array with new capacity (keeps old values)
 * @param: new Capacity
 * Postcondition: Throw exception if newCapacity < getSize(),
 * copy values from old array to new one, deallocate old array memory
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned nc) {
	if (nc == 0 || nc < getSize()) {
		throw QueueException("Thrown at line 148: ",
				"Capacity cannot be zero or less then size of queue!");
	}
	unsigned j = myFirst;
	Item * newArray = new Item[nc];
	for (unsigned i = 0; i < nc; i++) {
		newArray[i] = myArray[j % myCapacity];
		j++;
	}
	myFirst = 0;
	myLast = mySize;
	delete[] myArray;
	myCapacity = nc;
	myArray = newArray;

}

#endif /*ARRAY_QUEUE_H_*/

