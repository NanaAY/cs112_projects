/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Nana Osei Asiedu Yirenyki
 * Date: 11/19/2018
 *
 * 
 * Invariant: myTop == 0 && isEmpty() && !isFull()
 *         || myTop == myCapacity && !isEmpty() && isFull()
 *         || myTop > 0 && myTop < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member myTop always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or getTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
using namespace std;
//typedef string Item;
template<class Item>


class Stack {
public:
	Stack(unsigned size);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty();
	void push(const Item& it);
	bool isFull();
	Item getTop() const;
	Item pop();
	unsigned getSize();
	unsigned getCapacity();
	void setCapacity(int newCapacity);

	
protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned myTop;
	Item*    myArray;
	friend class StackTester;
};



/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned size) {
	if (size > 0) {
		myTop = 0;
		myCapacity = size;
		myArray = new Item[size];
	} else {
		throw StackException("Stack(size):", "size must be positive!.");
	}
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
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	myTop = original.myTop;
}

/* destructor
 * Postcondition: myCapacity == 0 && myTop == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete[] myArray;
	myArray = NULL;
	myCapacity = 0;
	myTop = 0;
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

/*isEmpty operator
 * Parameter: stack
 * Postcondition: whether or not I am empty
 */
template<class Item>
bool Stack<Item>::isEmpty() {
	if (myTop == 0) {
		return true;
	} else {
		return false;
	}
}

/*push operator
 *Parameter: an Item
 *PostCondition: a stack with a new item if there is space
 */
template<class Item>
void Stack<Item>::push(const Item& it) {
	if (myTop == myCapacity) {
		throw StackException("push()", "stack is full");
	} else {
		for (unsigned i = 0; i < myCapacity; i++) {
			myArray[myTop] = it;
		}
		myTop += 1;
	}
}
/*isFull operator
 * Parameter: stack
 * Postcondition: whether or not I am empty
 */
template<class Item>
bool Stack<Item>::isFull() {
	if (myTop == myCapacity) {
		return true;
	}
}
/*getTop operator
 * Parameter: a stack
 * Postcondition: value of the item on the top most on stack
 */
template<class Item>
Item Stack<Item>::getTop() const {
	if (myTop > 0) {
		return myArray[myTop - 1];
	} else {
		throw StackException("getTop()", "stack is empty");
	}
}

/* pop operator
 * Parameter: index
 * Postcondition: stack with the item at index myTop removed
 */
template<class Item>
Item Stack<Item>::pop() {
	if (isEmpty() == true) {
		throw StackException("pop()", " pop(): stack is empty!");
	} else {
		myTop -= 1;
		return myArray[myTop];
	}

}

/*getSize() method to obtain size of stack
 *@param: myTop
 *Postcondition: value of myTop stored as size
 */
template<class Item>
unsigned Stack<Item>::getSize() {
	return myTop;
}

/*getCapacity() method to obtain capacity of stack
 *@param: myCapacity
 *Postcondition: value of myCapacity stored as the capacity of stack
 */
template<class Item>
unsigned Stack<Item>::getCapacity() {
	return  myCapacity;
}
/*setCapacity() method to set the capacity of stack
 *@param: newCapacity
 *Postcondition: stack with new capacity from input, or error(if size > capacity)
 */

template<class Item>
void Stack<Item>::setCapacity(int nc) {
	if (nc < myTop) {
		throw StackException("setCapacity()", "New capacity cannot be smaller than myCapacity!");
	}
	Item * x = new Item[nc];
	for (unsigned i = 0; i<myTop; i++) {
		x[i] = myArray[i];
	}

	unsigned real = nc;
	delete [] myArray;
	myCapacity = real;
	myArray = x;
}

#endif
