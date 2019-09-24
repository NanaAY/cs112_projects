/* PalindromeDetectorTester.cpp defines methods for testing PalindromeDetector class
 *Joel Adams, for CS 112 at Calvin College.
 * Student name: Nana Osei Asiedu Yirenyki
 * Date: 11/19/2018
 */

#include "PalindromeDetectorTester.h"
#include <cassert>

void PalindromeDetectorTester::runTests() {
	cout << "Testing class PalindromeDetectorTester..." << endl;
	testingPalindrome();
	cout << "All tests passed!\n" << endl;
}


void PalindromeDetectorTester::testingPalindrome() {
cout << "- Testing Constructor & detectPal() & isPal()..." << endl;
	Palindrome a;
	a.detectPalindrome();
	assert (a.isPalindrome("Dude what up") == false);
	assert( a.isPalindrome("eye")== true);
	assert( a.isPalindrome("This project is long")== false);
	cout << " 1 " << flush;
	cout << " 2 " << flush;
	cout << "...Passed!" << endl;
//	Palindrome b;
//	b.detectPalindrome();


}

