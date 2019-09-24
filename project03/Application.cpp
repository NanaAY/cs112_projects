/*Application.cpp runs the program that displays the vectors
 * Student Name:Nana Osei Asiedu Yirenkyi
 * Date: Sept 25 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Application.h"
#include "Vec.h"

/*class constructor for application
 * initializes vector variables (myPos and myVec)
 */
Application::Application() {
	dimIn();
	myPos = Vec(myDim);
	myVec = Vec(myDim);
	getVec();
	display();
}


/*displayMenu() prints out the main menu for the
 * application
 */
void Application::displayMenu() {
	cout << "This is a Vector Application Program!" << endl <<
			"1. Add to vector" << endl <<
			"2. Output Position" << endl <<
			"3. Quit" << endl;
}



/* updates the position (sum of vectors entered)
 * using Vec +operator
 */
void Application::updatePos() {
	Vec temp(myVec);
	cout << "Input new vector: " << myDim << " dimensions needed: " << endl;
	for (unsigned i = 0; i < myDim; i++) {
		cout << "Index " << i << ": ";
		cin >> myVec[i];
	}
	myPos = myVec + temp;
}


//Print the position of the vector myPos
void Application::displayPos() {
	cout << "Postion: ";
	for (unsigned i=0; i < myDim; i++)
		cout << myPos[i] << " ";
	cout << endl;
}



//dimIn retrieve the number of dimensions from the user
void Application::dimIn() {
	cout << "Input number of dimensions for vector: ";
	cin >> myDim;
}



/*getVec prompts and receives input from the user at the
 * start of the application in order to get a starting position
 */
void Application::getVec() {
	cout << "Input starting position; " << myDim << " dimensions needed: " << endl;
	for (unsigned i=0; i < myDim; i++){
		cout << "Index " << i << ": ";
		cin >> myVec[i];
	}
	myPos = myVec;
}




/*display() pools together functions to display the
 * menus and receive input from the user
 */
void Application::display() {
	cout << endl;
	unsigned q = 0;
	while (q != 3) {
		cout << "Dimensions: " << myDim << "\n" << endl;
		displayMenu();
		cin >> q;
		if (q == 1)
			updatePos();
		else if (q == 2)
			displayPos();
		else
			cout << "Please enter a valid option!" << endl;
	}
	cout << "...Quitting..." << endl;
}


Application::~Application() {
	// TODO Auto-generated destructor stub
}
