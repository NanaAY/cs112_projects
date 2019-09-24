/* ReversePoem.cpp
 * Nana Osei Asiedu Yirenkyi (na29)
 *11/3/18
 *Project07
 */

#include "ReversePoem.h"

ReversePoem::ReversePoem(const string &file) {
	ifstream poem(file.c_str());
	assert( poem.is_open() );
	getline(poem, myTitle);
	getline(poem, myAuthor);
	Stack<string> myStack(1);
	string line;
	getline(poem, line);
	while (!poem.eof()) {
		getline(poem, line);
		if (line != "") {
			try {
				myStack.push(line);
			} catch (StackException& se) {
				myStack.setCapacity(myStack.getCapacity() * 2);
				myStack.push(line);
			}
			myBody += line += "\n";
		}
	}
	while (!myStack.isEmpty()) {
		myRevBody += myStack.pop() += "\n";
	}
}
