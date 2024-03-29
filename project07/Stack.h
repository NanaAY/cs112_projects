/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Nana Osei Asiedu Yirenkyi
 * project07
 * Date: 11/3/2018
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
template <class Item>

class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty();
	bool isFull();
	Item peekTop() const;
	void push(const Item& it);
	Item pop();
	int getSize() const {return mySize;}
	int getCapacity() const {return myCapacity;}
	void setCapacity(int newCapacity);
	
protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template <class Item>
Stack<Item>::Stack(unsigned capacity) {
	if (capacity <= 0) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	}
	mySize = 0;
    myCapacity = capacity;
    myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template <class Item>
Stack<Item>::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template <class Item>
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
template <class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* Is Empty method that returns true if the stack is empty
 * Precondition: I am a empty
 */
template <class Item>
bool Stack<Item>::isEmpty() {
	if (mySize > 0) {return false;}
	return true;
}

/* Is Full method that returns true if the stack is full
 * Precondition: I am a full
 */
template <class Item>
bool Stack<Item>::isFull() {
	if (mySize == myCapacity) {return true;}
	return false;
}

/*PeekTop method
 * Postcondition: value of the top most item of stack
 */
template <class Item>
Item Stack<Item>::peekTop() const {
	if ( mySize <= 0 ) {
		throw StackException("peekTop()", "stack is empty");
	}
	return myArray[mySize-1];
   }


/*Push method
 *Parameter: an Item
 *PostCondition: a stack with a new item if there is space
 */
template <class Item>
void Stack<Item>::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full");
	}
	myArray[mySize] = it;
	mySize++;
   }

/*Pop method
 * PostCondition: removes and returns the top item from the Stack.
 */
template <class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty");
	}
	mySize--; return myArray[mySize];
   }


/*Set Cpacity method
 *Parameter: a newCapacity
 *PostCondition: a stack with a new capacity
 */
template <class Item>
void Stack<Item>::setCapacity(int newCapacity) {
	if (newCapacity < mySize) {
		throw StackException("setCapacity", "new capacity cannot be less than old capacity.");
	}
	Item* newArray = new Item[newCapacity];
	for (unsigned i = 0; i < mySize; i++) {
		newArray[i] = myArray[i];
	}
	delete[] myArray;
	myCapacity = newCapacity;
	myArray = newArray;

}
#endif
