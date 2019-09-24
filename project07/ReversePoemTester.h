/* ReversePoemTester.h : declares methods for testing ReversePoem class
 * Nana Osei Asiedu Yirenkyi (na29)
 *11/3/18
 *Project07
 */

#ifndef REVERSEPOEMTESTER_H_
#define REVERSEPOEMTESTER_H_

#include "ReversePoem.h"
#include <iostream>  // cout, cerr, ...
#include <cassert> // assert()
#include <cstdlib>   // exit()
using namespace std;

class ReversePoemTester {
public:
	void runTests();
	void testConstructor();
	void testGetTitle();
	void testGetAuthor();
	void testGetBody();
	void testGetBodyReversed();

};

#endif /* REVERSEPOEMTESTER_H_ */
