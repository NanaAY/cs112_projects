/* ListTester.cpp defines the test methods for class List.
 * Student Name:Nana Osei Asiedu Yirenkyi(na29)
 * Date: Oct 21 2018
 * PROJECT06
 * Joel Adams, for CS 112 at Calvin College.
 *
 * testInequality(), testWriteToStream(), testReadFromString(),	testGetIndexOf() and testRemove() tests written by Nana Osei (na29)
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testInequality(); //NANA OSEI (NA29)
	testWriteToStream(); //NANA OSEI (NA29)
	testReadFromString(); //NANA OSEI (NA29)
	testGetIndexOf(); //NANA OSEI (NA29)
	testRemove(); //NANA OSEI (NA29)
	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();
	testInsertAfter();
	testInsertBefore();
	testOutput();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == 0 );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}


//############################################################ PROJECT05 ############################################################

//############################################################ NANA OSEI (NA29) ######################################################

void ListTester::testInequality() {
	cout << "Testing Inequality... " << flush;
	// two empty lists
	List<double> list1;
	List<double> list2;
	assert( !(list1 != list1) );
	cout << " 1 " << flush;

	// a non-empty list
	List<double> list3;
	list3.append(33);		// [33]
	assert(list3 != list1);
	cout << " 2 " << flush;

	// equal, non-empty lists of the same size
	List<double> list4;
	list4.append(44);		// [33]
	assert( list4 != list3 );
	assert( list3 != list4 );
	cout << " 3 " << flush;

	// unequal, non-empty lists of the same size
	list3.append(55);		// [33,55]
	List<double> list5;
	list5.append(44);		// [44]
	list5.append(55);		// [44,55]
	assert (list5 != list3);
	assert (list3 != list5);
	cout << " 4 " << flush;

	// unequal non-empty lists of different sizes
	list4.append(44);		// [33,44]
	list4.append(55);		// [33,44,55]
	assert (list4 != list5);
	assert(list5 != list4);
	assert(list5 != list3);
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}



void ListTester::testWriteToStream() const {
	cout << "Testing writeTo(ostream)... " << flush;
	List<double> List1;
	assert( List1.getSize() == 0 );
	assert( List1.myFirst == NULL );
	assert( List1.myLast == NULL );
	// append to empty list
	List1.append(11);
	List1.append(22);
	List1.append(33);//[11,22,33]
	assert(List1.mySize == 3);
	cout << " 1 " << flush;

	// write to an ofstream instead of cout, to automate the test
	ofstream fout("ListStreamOut.txt");//writing to file "ListStreamOut.txt
	assert( fout.is_open() );//assert if open
	List1.writeTo(fout, '\t');//use WriteTo method
	fout.close();//close stream
	cout << "Passed! See 'ListStreamOut.txt' for values..." <<
			flush;

	List<double> List2;//create new empty list
	assert( List2.getSize() == 0 );//make sure new list is empty
	assert( List2.myFirst == NULL );
	assert( List2.myLast == NULL );
	//check to see if values passed into file is correct
	List2.readFrom("ListStreamOut.txt");
	cout << List2.getSize() << endl;

	assert(List2.getSize() == 3);//check
	assert(List2.getFirst() == 11);
	assert(List2.getLast() == 33);
	assert(List2.myFirst->myNext-> myItem == 22);//check for myItem in 2nd node
	cout << " 2 " << flush;
	cout << "Passed!" << endl;

}

void ListTester::testReadFromString() const {
	cout << "Testing readFrom()... " << flush;
	List<double> List3;
	List3.readFrom("ListStreamOut.txt");//call function
	cout << " 1 " << flush;
	List3.writeTo(cout, '\t');
	assert( List3.getSize() == 3 );
	assert( List3.myFirst != NULL );
	assert( List3.getFirst() == 11 );
	assert( List3.getLast() == 33 );
	assert( List3.myFirst->myNext->myItem == 22);//check for myItem in 2nd node
	cout << "Passed!" << endl;

}


void ListTester::testGetIndexOf() {
	cout << "Testing GetIndexOf()... " << flush;
	List<double> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	list1.append(33); //[11,22,33,33]


	int index = list1.getIndexOf(11);//call function
	assert(index == 0);//check to see if index is correct
	index = list1.getIndexOf(22);//call function
	assert(index == 1);
	index = list1.getIndexOf(33);//call function
	assert(index == 2);
	cout << " 1 " << flush;
	assert(index != 3);
	cout << " 2 " << flush;

	//if item not available
	List<double> list2;
	list2.append(11);
	list2.append(22);
	list2.append(33);
	assert(list2.getSize() == 3);
	int index2 = list2.getIndexOf(44);//call function
	assert(index2 == -1);
	cout << " 3 " << flush;
	cout << "Passed!" << endl;

}

void ListTester::testRemove(){
	cout << "Testing remove()... " << flush;
	List<double> list1;//empty list
	list1.append(11);
	list1.append(22);
	list1.append(33);
	int it = list1.remove(8);//index greater than list
	assert(it == 33);
	assert(list1.getSize()==2);
	cout << " 1 " << flush;

	List<double> list2;
	list2.append(44);
	list2.append(55);
	list2.append(66);
	list2.append(77);
	int it2 = list2.remove(0);
	assert(it2 == 44);

	assert(list2.getFirst()== 55);
	assert(list2.getLast()==77);
	cout << " 2 " << flush;

	List<double> list3;
	list3.append(11);
	list3.append(11);
	list3.append(22);
	list3.append(33);
	int it3 = list3.remove(3);
	assert(it3 == 33);
	cout << " 3 " << flush;

	List<double> list4;
	list4.append(11);
	list4.append(11);
	list4.append(22);
	list4.append(33);
	int it4 = list4.remove(1);
	assert(it4 == 11);
	assert(list4.getSize()==3);
	assert(list4.getFirst()==11);
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}
//########################################################################################################################

/* Written By: hans langford
 * Purpose: are they equal ?
 */
void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	List<double> lista;
	List<double> listb;

	//test same
	for (int i = 0; i < 3; i++) {
		lista.append(i);
		listb.append(i);
	}
	assert( lista.myFirst->myItem == 0 );
    assert( lista.myFirst->myNext->myItem == 1 );
	assert( lista.myLast->myItem == 2 );
	assert( listb.myFirst->myItem == 0 );
	assert( listb.myFirst->myNext->myItem == 1 );
	assert( listb.myLast->myItem == 2 );
	assert( lista == listb );
	cout << " 0 " << flush;

	//make b different and test that they are different
	listb.append(100);
	assert( listb.myLast->myItem != lista.myLast->myItem );
	assert( !(lista == listb) );
	cout << " 1 " << flush;
	cout << "Passed!" << endl;
}



/* Written By: hans langford
 * Purpose: i will make one list, append, create another list and fill with values from a stream, then check if ==
 */
void ListTester::testReadFromStream() {
	cout << "Testing readFromString... " << flush;
	List<double> lista,listb;
	for (int i = 0; i < 3; i++) {
		lista.append(i);
	}

	ifstream fin("readFromTest.txt");
	assert( fin.is_open() );
	listb.readFrom(fin);
	assert( lista == listb );
	fin.close();
	cout << " 0 " << flush;
	cout << "Passed!" << endl;
}


/* Written By: hans langford
 * Purpose: read from one file, write to another, then see if they are the same
 */
void ListTester::testWriteToFile() {
	cout << "Testing writeToFile... " << flush;
	List<double> a;
	List<double> b;
	ifstream fin("readFromTest.txt");
	a.readFrom(fin);
    a.writeTo("testOut.txt",'\n');
    fin.close();
    ifstream newfin("testOut.txt");
	b.readFrom(newfin);
	assert(a==b);
	 cout << " 0 " << flush;

cout << "Passed!" << endl;

}


/* Written By: hans langford
 * Purpose: test that the item is inserted before and the list is correct
 */
void ListTester::testPrepend() {
    cout << "Testing prepend... " << flush;
    // test a non-empty list
    List<double> list1;
    ifstream fin("readFromTest.txt");
    list1.readFrom(fin);
	list1.prepend(1);
	list1.prepend(0);
	//this is checking that the chain of node is in prepend order
    assert( list1.myFirst->myItem == 0 );
    assert( list1.myFirst->myNext->myItem == 1 );
    assert( list1.myFirst->myNext->myNext->myItem == 0 );
    assert( list1.myFirst->myNext->myNext->myNext->myItem == 1 );
    assert( list1.myLast->myItem == 2 );
    cout << " 0 " << flush;

    // test an empty list
    List<double> list0;
    list0.prepend(0);
    assert( list0.mySize == 1 );
    assert( list0.myFirst->myItem == 0 );
    cout << " 1 " << flush;

    cout << "Passed!" << endl;
}


/* Written By: hans langford
 * Purpose: test write to a file
 */
void ListTester::testInsert() {
	cout << "Testing insert... " << flush;

	List<double> list1;
	ifstream fin("readFromTest.txt");
	list1.readFrom(fin);
	// test inserting at 0
	list1.insert(5, 0);
	assert( list1.myFirst->myItem == 5 );
	assert( list1.myFirst->myNext->myItem == 0 );
	assert( list1.myFirst->myNext->myNext->myItem == 1 );
	assert( list1.myLast->myItem == 2 );
	cout << " 0 " << flush;
	// tryy at 1
	list1.insert(5, 1);
	assert( list1.myFirst->myItem == 5 );
	assert( list1.myFirst->myNext->myItem == 5 );
	assert( list1.myFirst->myNext->myNext->myItem == 0 );
	assert( list1.myFirst->myNext->myNext->myNext->myItem == 1 );
	assert( list1.myLast->myItem == 2 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}


void ListTester::testInsertBefore() {
	cout << "Testing insertBefore()..." << flush;

	// empty list
	List<string> list1;
	list1.insertBefore("Nana", "Osei");
	assert(list1.mySize == 0);
	assert(list1.insertBefore("Nana", "Osei") == false);
	cout << " 0 " << flush;

	// a non-empty list
	List<string> list2;
	list2.append("Bas");
	list2.insertBefore("Bas", "Cole");
	assert(list2.getIndexOf("Bas") == 1);
	cout << " 1 " << flush;

	// a larger non-empty list
	List<string> list3;
	list3.append("Roro");
	list3.append("Popo");
	list3.append("Nono");
	list3.append("Zozo");
	assert(list3.insertBefore("Nono", "yoyo"));
	cout << " 2a " << flush;
	assert(list3.mySize == 5);
	cout << " 2b " << flush;
	assert(list3.getIndexOf("Hoho") == -1);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing insertAfter()..." << flush;

	// empty list
	List<string> list1;
	list1.insertAfter("Nana", "Osei");
	assert(list1.mySize == 0);
	assert(list1.insertBefore("Nana", "Osei") == false);
	cout << " 0 " << flush;

	// a non-empty list
	List<string> list2;
	list2.append("Bas");
	list2.insertAfter("Bas", "Cole");
	assert(list2.getIndexOf("Cole") == 1);
	cout << " 1 " << flush;

	// a larger non-empty list
	List<string> list4;
	list4.append("R");
	list4.append("P");
	list4.append("C");
	list4.append("Z");
	assert(list4.insertAfter("C", "D"));
	assert(list4.mySize == 5);
	assert(list4.getIndexOf("D") == 3);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testOutput() {
	cout << "Testing operator<<()..." << flush;

	List<double> list1;
	list1.append(10);
	list1.append(100);
	list1.append(1000);
	list1.append(10000);
	list1.append(100000);
	assert(list1.mySize == 5);
	cout << " 0 " << flush;
//	cout << list1 << flush;
	cout << " 1 " << flush;
	cout << "Passed!" << endl;
}
