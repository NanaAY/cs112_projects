/* List.h
 * Student Name:Nana Osei Asiedu Yirenkyi(na29)
 * Date: Oct 21 2018
 * PROJECT06
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cassert>

using namespace std;
template <class Item>

class List {
public:
	List();
	virtual ~List();
	void append(const Item& it);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	List(const List<Item>& original);
	List<Item>& operator=(const List<Item>& original);
	bool operator!=(const List<Item>& original);
	void readFrom(const string& fileName);
	void writeTo(ostream& out, const char seperator) const;
	int getIndexOf(Item it) const;
	Item remove(int index);
	bool operator==(const List<Item>& original);
	void readFrom(istream& in);
	void writeTo(string  filename, const char divider);
	void prepend(const Item & item);
	void insert(const Item& it, unsigned index);
	bool insertAfter(const Item& otherPersonsName, const Item& yourName);
	bool insertBefore(const Item& otherPersonsName, const Item& yourName);
	void Output(ostream& out) const;




private:
	struct Node{
		Node();
		~Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;

	};
	int mySize;
	Node* myFirst;
	Node* myLast;
	void makeCopyOf(const List<Item>& original);
	void deallocation();

	friend class ListTester;

};



//Default List Constructor
template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = NULL;
}


//Explicit List Constructor
template <class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
  }


//Default Node Constructor
template <class Item>
List<Item>::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}


//Adds an item to the end of the list
template <class Item>
void List<Item>::append(const Item& it){
	Node* nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	}
	else { myLast -> myNext = nodePtr;

	}
	myLast = nodePtr;
	mySize ++;
}


//Acceses and returns the size of the list
template <class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}


//Acceses and returns the first Item in the first node
template <class Item>
Item List<Item>::getFirst() const{
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of list is too small.");
	}
	return myFirst -> myItem;
}


//Acceses and returns the last Item in the last node
template <class Item>
Item List<Item>::getLast() const {
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of list is too small.");
	}
	return myLast -> myItem;
}

template<class Item>
void List<Item>::deallocation() {
	delete myFirst; // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0; // clear mySize (optional)
}

//List Destructor
template <class Item>
List<Item>::~List() {
	deallocation();
}


//Node Destructor
template <class Item>
List<Item>::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
                           // (does nothing if myNext == NULL)
   }


//Copy Method that makes a copy of a List
template <class Item>
void List<Item>::makeCopyOf(const List<Item>& original) {
	Node* oPtr = original.myFirst; //  start at the first node
	while (oPtr != NULL) {
		//  while there are nodes to copy:
		append(oPtr->myItem); //   append the item in that node
		oPtr = oPtr->myNext; //   advance to next node
	}
}


//List copy constructor that makes use of copy method
template <class Item>
List<Item>::List(const List<Item>& original) {
	myFirst = myLast = NULL; //  set pointers
	mySize = 0; //   and size to 'empty' values
	makeCopyOf(original);
   }


// Assignment operator assigns the left hand side of  operand to the right hand side
template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
	if (this != &original) {
		deallocation();
		makeCopyOf(original);
	}
	return *this;
   }


//Inequality operator checks that left and right operand are different
template <class Item>
bool List<Item>::operator!=(const List<Item>& original) {
	if (this == &original) {
		return false;
	}
	else if (this->mySize != original.mySize) {
		return true;
	}
	for (int i = 0; i < mySize; i++) {
		Node* oPtr = original.myFirst;
		if (this->myFirst != oPtr) {
			return true;
		}
	}
	return false;
}


//Readfrom method that reads from a file
template<class Item>
void List<Item>::readFrom(const string& fileName) {
	if (mySize != 0) {deallocation();}
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );
	while(!fin.eof() ) {
		if(fin.peek() == '\n') {
			break;
		}
		Item it;
		fin >> it;
		append(it);
	}
	fin.close();
}


//WriteTo method that writes to the ostream
template<class Item>
void List<Item>::writeTo(ostream& out, const char seperator) const {
	Node* oPtr = myFirst;
	for (int i = 0; i < mySize; i++) {
		if (oPtr->myNext == NULL) {
			cout << oPtr->myItem << seperator << '\n';
		}
		else {
			cout << oPtr->myItem << seperator;
			oPtr = oPtr->myNext;
		}
	}
}



//Gets index of item in list
template<class Item>
int List<Item>::getIndexOf(Item it) const {
	Node* oPtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		if (it == oPtr->myItem){
			return i;
		}
		else if (it != oPtr-> myItem) {
			oPtr = oPtr->myNext;
		}
	}
	return -1;
}




template<class Item>
Item List<Item>::remove(int index){
	Item temp;
	if (mySize == 0){
		return 0;
	}

	else if (mySize == 1){
		temp = myFirst -> myItem;
		myFirst = myLast = NULL;
		mySize = 0;
		return temp;
	}
	else if (index >= mySize){
		Node* oPtr = myFirst;
		temp = myLast -> myItem;
		mySize = mySize - 1;
		for (int i = 0; i < mySize; i++){
			oPtr = oPtr -> myNext;
		}
		myLast = oPtr;
		delete oPtr -> myNext;
		myLast -> myNext = NULL;
		return temp;
	}
	else if(index <= 0){
		Node* oPtr = myFirst;
		temp = myFirst -> myItem;
		mySize = mySize - 1;
		myFirst = oPtr -> myNext;
		oPtr -> myNext = NULL;
		delete oPtr;
		return temp;
	}
	else {
		Node* oPtr = myFirst;
		for(int i = 1; i < index; i++) {
			oPtr = oPtr-> myNext;
		}
		temp = oPtr-> myNext-> myItem;
		mySize = mySize - 1;
		Node* tPtr = oPtr -> myNext;
		oPtr -> myNext = tPtr -> myNext;
		tPtr -> myNext = NULL;
		delete tPtr;
		return temp;
	}
}


/* Written By: hans langford
 * Purpose: check equality of lists
 */
template<class Item>
bool List<Item>::operator==(const List<Item>& original) {
        //sizes not equal so false
		if(original.mySize!=mySize){return false;}

			if(original.myFirst->myItem==myFirst->myItem){
				if(original.myLast->myItem==myLast->myItem){return true;}
			}

		return false;
}


/* Written By: hans langford
 * Purpose: read from a stream
 */
template<class Item>
void List<Item>::readFrom(istream& in) {
	this->~List();
	mySize=0;
	myFirst = myLast = NULL;
	Item a;

	for(int i=0;i<3;i++){
		in>>a;
		this->append(a);
	}
}


/* Written By: hans langford
 * Purpose: write to a file
 */
template<class Item>
void List<Item>::writeTo(string  filename, const char divider){
ofstream fout(filename.c_str());
assert(fout.is_open());
Node*temp=myFirst;
while(temp !=NULL){
	fout<<temp->myItem<<divider<<flush;
	temp=temp->myNext;
}
fout.close();
	}

/* Written By: hans langford
 * Purpose: add item to start of list
 */
template<class Item>
void List<Item>::prepend(const Item & item){
Node * nodePtr = new Node(item,NULL);

//if its empty
if(mySize==0){myFirst=nodePtr;}

//otherwise swap the next chained node with the first one
else{nodePtr->myNext=myFirst;
myFirst=nodePtr;}

mySize++;

}

/* Written By: hans langford
 * Purpose: insert item into a list
 */
template<class Item>
void List<Item>::insert(const Item& it, unsigned index) {
	if(index<=mySize && index>0){
		Node* temp = myFirst;
		Node* newNode = new Node(it, NULL);

		//this takes us to where we want to change
		for (unsigned i = 0; i < index -1; i++) {
			temp = temp->myNext;
		}
		//chain new node to the next one
		newNode->myNext = temp->myNext;
		temp->myNext = newNode;
		++mySize;
}
	else if (index <= 0) {
		this->prepend(it);
	}
	else if (index > mySize) {
		this->append(it);
	}
}


template<class Item>
bool List<Item>::insertAfter(const Item& otherPersonsName, const Item& yourName) {
	int index = getIndexOf(otherPersonsName);
	if (index < 0) {return false;}
	Node* nPtr = myFirst;
	while (nPtr) {
		if (nPtr->myItem == otherPersonsName) {
			Node* newPtr = new Node(yourName, nPtr->myNext);
			nPtr->myNext = newPtr;
			mySize++;
			return true;
		}
		nPtr = nPtr->myNext;
	}
	return false;
}



template<class Item>
bool List<Item>::insertBefore(const Item& otherPersonsName, const Item& yourName) {
	int index = getIndexOf(otherPersonsName);
	if (index < 0) {return false;}
	else {
		this -> insert(yourName, index);
		return true;
	}
}


template<class Item>
void List<Item>::Output(ostream& out) const {
	Node* nPtr = myFirst;
	if (mySize == 0) {
		out << nPtr->myItem << "\t" << flush;
	}
	else {
		while (nPtr) {
			if (nPtr == myLast) {
				out << nPtr->myItem;
			}
			else {
				out << nPtr->myItem;
			}
			nPtr = nPtr->myNext;
		}
	}
}

#endif /* LIST_H_ */
