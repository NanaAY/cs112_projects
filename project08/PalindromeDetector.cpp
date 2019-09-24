/*PalindromeDetector.cpp defines methods for the class PalindromeDetector.h
 *Joel Adams, for CS 112 at Calvin College.
 * Student name: Nana Osei Asiedu Yirenyki
 * Date: 11/19/2018
 */

#include "PalindromeDetector.h"
using namespace std;

/*
 * Palindrome() constructs a Palindrome
 * @param: a name for the file
 * Postcondition: a file is used as input and the result is output into another file
 */
Palindrome::Palindrome() {
	cout << "Enter Input file name: " << flush;
	cin >> InputFile;
	cout << "Enter Output file name: " << flush;
	cin >> OutputFile;
}
/*~Palindrome() Destructor
 * Postcondition: destructed and deallocated memory used by Palindrome
 */
Palindrome::~Palindrome() {
}

/*
 * detectPalindrome() Read, write, check file for palindrome
 * @param:none
 * Postcondition: open iostream to files reads in line by line and
 * finds *** and outputs it to the stream
 */
void Palindrome::detectPalindrome() {
	ifstream fin(InputFile.c_str());
	ofstream fout(OutputFile.c_str());
	string line;
	assert(fin.is_open());
	while (not fin.eof()) {

		getline(fin, line);
		fout << line << flush;
		if (isPalindrome(line)) {

			fout << " *** " << endl;
		} else {
			fout << "" << endl;
		}
	}
	fout.close();
	fin.close();
}

/*
 * isPalindrome() detecting method says yes or no
 * @param: line of text in the input file
 * Postcondition: try catch blocks, intitialize, return bool true or false,
 * if char in string, push to stack, append to queue, if queue != 0, pop char from stack
 * remove char from queue and return false, else return true
 */
bool Palindrome::isPalindrome(string str) {
	Stack<char> so(1);
	ArrayQueue<char> go(1);
	char ch1;
	char ch2;
	for (unsigned i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			char cs = tolower(str[i]);
			try {
				so.push(cs);
			} catch (StackException) {
				so.setCapacity(so.getCapacity() * 2);
				so.push(cs);
			}
			try {
				go.append(cs);
			} catch (FullQueueException) {
				go.setCapacity(go.getCapacity() * 2);
				go.append(cs);
			}
		}
	}
	if ((so.isEmpty()) && (go.isEmpty())) {
		return false;
	}
	while (!(so.isEmpty()) && !(go.isEmpty())) {
		ch1 = so.pop();
		ch2 = go.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}
