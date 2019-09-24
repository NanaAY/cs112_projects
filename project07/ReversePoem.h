/*ReversePoem.h
 * Nana Osei Asiedu Yirenkyi (na29)
 *11/3/18
 *Project07
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ostream>
#include "Stack.h"

using namespace std;

class ReversePoem {
public:
	ReversePoem(const string &file);
	string getTitle() {return myTitle;}
	string getAuthor() {return myAuthor;}
	string getBody() {return myBody;}
	string getBodyReversed() {return myRevBody;}
private:
	string myTitle;
	string myAuthor;
	string myBody;
	string myRevBody;
};

#endif /* REVERSEPOEM_H_ */
