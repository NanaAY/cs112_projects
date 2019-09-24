/* ReversePoemTester.cpp : test ReversePoem class
 * Nana Osei Asiedu Yirenkyi (na29)
 *11/3/18
 *Project07
 */

#include "ReversePoemTester.h"

void ReversePoemTester::runTests() {
	cout << "\nTesting ReversePoem class..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!" << endl;
}

void ReversePoemTester::testConstructor() {
	cout << "- Testing constructors..." << flush;
	string poem = "poems/cats.txt";
	ReversePoem revpoem(poem);
	cout << "passed!" << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle()..." << flush;
	string poem = "poems/cats.txt";
	ReversePoem revpoem(poem);

	assert( revpoem.getTitle() == "Cats" );
	cout << " 1 " << flush;

	string poem2 = "poems/love.txt";
	ReversePoem revpoem2(poem2);

	assert(revpoem2.getTitle() == "Love?");
	cout << " 2 " << flush;
	cout << "passed!" << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "- Testing getAuthor()..." << flush;
	string poem = "poems/cats.txt";
	ReversePoem revpoem(poem);

	assert(revpoem.getAuthor() == "Leo J. Smada");
	cout << " 1 " << flush;

	string poem2 = "poems/love.txt";
	ReversePoem revpoem2(poem2);

	assert(revpoem2.getAuthor() == "Anonymous");
	cout << " 2 " << flush;
	cout << "passed!" << endl;
}
void ReversePoemTester::testGetBody() {
	cout << "- Testing testGetBody()..." << flush;
	string poem = "poems/cats.txt";
	ReversePoem revpoem(poem);

	string line1 = "I love it when cats rub against me.";
	string line2 = "I could never say";
	string line3 = "I hate those furry felines.";

	string body = line1 + "\n" + line2 + "\n" + line3 + "\n";

	assert(revpoem.getBody() == body);

	cout << "passed!" << endl;
}
void ReversePoemTester::testGetBodyReversed() {
	cout << "- Testing testGetBodyReversed()..." << flush;

	string poem = "poems/cats.txt";
	ReversePoem revpoem(poem);

	string line1 = "I love it when cats rub against me.";
	string line2 = "I could never say";
	string line3 = "I hate those furry felines.";

	string body = line3 + '\n' + line2 + '\n' + line1 + '\n';
	assert(revpoem.getBodyReversed() == body);
	cout << "passed!" << endl;
}
