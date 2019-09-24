#include "BST_Tester.h"
#include <iostream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>

int main() {
	BST_Tester bstt;
	bstt.runTests();	

	//Application
	list<string> l1;
	l1.push_back("/home/cs/112/proj/09/randomInts01.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts02.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts03.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts04.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts05.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts06.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts07.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts08.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts09.txt");
	l1.push_back("/home/cs/112/proj/09/randomInts10.txt");
	string astr;
	string line;
	unsigned j = 0;
	cout << "...Testing BST..." << flush;
	for (unsigned i = 1; i < 11; i++) {
		cout << "\n\tBST" << i << flush;
		astr = l1.front();
		ifstream fin(astr.c_str());
		assert (fin.is_open());
		BST<long int> bst;
		while (!fin.eof()) {
			getline(fin, line);
			int i = atoi(line.c_str());
			try {
				bst.insert(i);
			}
			catch (Exception&) {
				j++;
			}
		}
		cout << "\nBST Height:" << bst.getHeight() << endl;
		cout << "No. of Exceptions: " << j << endl;
		l1.pop_front();
	}
}
