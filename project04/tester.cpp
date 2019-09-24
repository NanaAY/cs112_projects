/* tester.cpp drives the testing of our Vec template and Matrix class.
  * Student Name: Nana Osei Asiedu Yirenkyi
 * Date: Oct 6 2018
 * PROJECT04
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

//#include "VecTester.h"
#include "MatrixTester.h"

int main() {
//	VecTester vt;
//	vt.runTests();
	MatrixTester mt;
	mt.runTests();





	/*displayMenu() prints out the main menu for the
	 * application
	 */
	cout << "\nWelcome to the matrix application." << endl;
	while (true) {
		cout << "Please choose an operation\n "
				"1. + Addition\n "
				"2. - Subtraction\n "
				"3. Transpose\n "
				"4. exit\n Option:" << flush;
			int choice;
			cin >> choice;

			//exits the program if user chooses option 4 is
			if (choice == 4) {
				cout << "Ending...";
				break;
			}

			Matrix<double> mat1;
			cout << "Enter the file name for 1st Matrix:";
			string fileName;
			cin >> fileName;
			mat1.readFrom(fileName);
			mat1.writeTo(cout);


			/* outputs the value of a third matrix
			 * using Matrix + operator or the Matrix - operator
			 */
			if (choice == 1 || choice == 2) {

				cout << "Enter the filename for the 2nd Matrix: ";
				Matrix<double> mat2;
				cin >> fileName;
				mat2.readFrom(fileName);
				mat2.writeTo(cout);

				cout << "The result is:\n";

				Matrix<double> mat3;
				if (choice == 1)
					mat3 = mat1 + mat2;
				else if (choice == 2)
					mat3 = mat1 - mat2;
				mat3.writeTo(cout);
			}
			/* outputs the value of a third matrix
				 * which transposes two matrices contained files
				 */
			else if (choice == 3) {
				cout << "Transposition is:\n";
				Matrix<double> mat4;
				mat4 = mat1.getTranspose();
				mat4.writeTo(cout);
			}

		}

}



