/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Nana Osei Asiedu Yirenkyi
 * Date: 11/26/2018
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

typedef int Item;
template<class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	void insert(const Item& it);
	bool contains(const Item& it) const;
	unsigned getHeight() const;


private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void insert(const Item& it);
            bool contains(const Item& it) const;
            unsigned getHeight() const;

		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};


#include "BST.h"

template<class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

template<class Item>
void BST<Item>::insert(const Item& it) {
	if (isEmpty()) {
		Node * nNode = new Node(it);
		myRoot = nNode;
	} else if (myRoot != NULL) {
		try {
			myRoot->insert(it);
		} catch (Exception& e) {
			throw(e);
		}
	}
	myNumItems++;
}

/*Insert Item method for Node
 * @param: Item
 * Postcondition: nodes sorted left and right
 * 				  in terms of size compared to preceding node
 */
template<class Item>
void BST<Item>::Node::insert(const Item& it) {
	Node * nNode = new Node(it);
	if ((nNode->myItem) < myItem) {
		if (myLeft == NULL) {
			myLeft = nNode;
		}
		else {
			myLeft->insert(it);
		}
	}
	else if ((nNode->myItem) > myItem) {
		if (myRight == NULL) {
			myRight = nNode;
		}
		else {
			myRight->insert(it);
		}
	}
	else if ((nNode->myItem ) == myItem) {
		throw Exception("Line 77:", "Item already in BST!");
	}
}
/*Contains method
 * @param: Item
 */
template<class Item>
bool BST<Item>::contains(const Item& it) const {
	if (isEmpty()) {
		return false;
	}
	return myRoot->contains(it);
}

/*Contains method for Node
 * @param: Item
 * Postcondition: bool for if the values is contained
 */
template<class Item>
bool BST<Item>::Node::contains(const Item& it) const {
	if (it < myItem) {
		if (myLeft == NULL) {
			return false;
		}
		return myLeft->contains(it);
	}
	else if (it > myItem) {
		if (myRight == NULL) {
			return false;
		}
		return myRight->contains(it);
	}
	else if (it == myItem) {
		return true;
	}
	return true;
}

template<class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}


template<class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template<class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

/*getHeight method for class
 * @param: None
 * PostCondition: myRoot is returned to getHeight function
 */
template<class Item>
unsigned BST<Item>::getHeight() const {
	if (myRoot == NULL) {
		return 0;
	}
	return myRoot -> getHeight();
}

/*getHeight method for Node
 * @param: l or r
 * PostCondition: Item is passed right or left and height of tree is passed
 */
template<class Item>
unsigned BST<Item>::Node::getHeight() const {
	unsigned left = 0;
	unsigned right = 0;
	if (myLeft != NULL) {
		left = myLeft->getHeight();
	}
	if (myRight != NULL) {
		right = myRight->getHeight();
	}
	return (max(left, right) + 1);
}
#endif /*BST_H_*/

