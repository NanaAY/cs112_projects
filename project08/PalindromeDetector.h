/*PalindromeDetector.h declares methods for the PalindromeDetector class
 *Joel Adams, for CS 112 at Calvin College.
 * Student name: Nana Osei Asiedu Yirenyki
 * Date: 11/19/2018
 */


#ifndef PALINDROME_H_
#define PALINDROME_H_

#include "Stack.h"
#include "ArrayQueue.h"
#include <iostream>
#include <cstdlib>//setting the Value of an Item//to include file
#include <stdexcept>//setting the value of an Item//to throw range_error exception
#include <fstream>//to read and write to file
#include <cassert>//allows assertion

using namespace std;

class Palindrome {
public:
	Palindrome();
	virtual ~Palindrome();
	bool isPalindrome(string str);
	void detectPalindrome();
private:
	string InputFile;
	string OutputFile;

};
#endif /* PALINDROME_H_ */
