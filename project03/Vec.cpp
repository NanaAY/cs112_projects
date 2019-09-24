/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:Nana Osei Asiedu Yirenkyi(na29) and Luke Chen(lc33)
 * Date: Sept 25 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 *
 *
 * operator[] (read version), operator!=(), readFrom(), operator-() methods written by Nana Osei (na29)
 * operator[] (write version), writeTo(), operator+(), operator*() methods written by Luke Chen (lc33)
 */

 
#include "Vec.h"

//Default constructor
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

//Explicit Constructor
Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size];
		for (unsigned i = 0; i < mySize; i++){
			myArray[i] = 0;
		}
	}
	else myArray = NULL;
}

/*copy constructor that makes a distinct copy of the object,
 *  including its dynamically allocated memory.
 */
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	else myArray = NULL;
}


// Destructor
// returns dynamically allocated memory to the system using the delete operation
Vec::~Vec() {
	 delete[] myArray;
	 myArray = NULL;
	 mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize > 0) {
			delete [] myArray;
			myArray = NULL;
		}
		if (original.mySize > 0) {
			myArray = new Item[original.mySize];
		}
		mySize = original.mySize;
	}
	for (unsigned i = 0; i < mySize; i++) {
		myArray[i] = original.myArray[i];
	}
	return *this;
   }


//obtains the size of the vector
unsigned Vec::getSize() const {
	return mySize;
}

//sets a particular item in the vector to a certain value
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize){
		throw range_error("Out of range");
	}
	else {
		myArray[index] = it;
	}
}

//gets a value of an item at a particular index in vector
Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Out of range");
	}
	else {
		return myArray[index];
	}
}

//sets the size of an vector
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			myArray = NULL;
			mySize = 0;
		}
		else {
			Item* newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++) {
					newArray[i] = 0;
				}
			}
			else {
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

//finds out if items in vector are equal
bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

//outputs items in a vector to a text file
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << "\n";
	}
}

//reads in values to indices in the vector
void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

																//NANA OSEI//
/*Inequality operator != checks if myArray and v2.myArray
 * 		are NOT equal
 * @param: v2, a Vec class object
 * Return: true/false
 */
bool Vec::operator!=(const Vec& v2) {
	if (mySize != v2.mySize) {
		return true;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return true;
		}
	}
	return false;
}



/*Vector subtraction operator subtracts two vectors and sets a third
 * 		vector as equal to them
 *@param: v2, a Vec class object
 *Return: v3, a Vec class object equal to the values in
 *		myArray minus the values in v2.myArray
 */
Vec Vec::operator-(const Vec& v2) {
	Vec v3(mySize);
	if (mySize != v2.mySize) {
		throw invalid_argument("Invalid Argument!");
	}
	else if (v2.mySize == 0) {
		return v3;
	}
	for (unsigned i = 0; i < mySize; i++) {
		v3.myArray[i] = myArray[i] - v2.myArray[i];
	}
	return v3;
}


/* Vec readFrom reads values from a filename directly
 * 		into myArray; the first values read in the
 * 		file will be mySize
 * @filename: a string object, will be used as
 * 		the file read from
 */
void Vec::readFrom(string fileName) {
	ifstream fin(fileName.c_str());
	fin >> mySize;
	myArray = new Item[mySize];
	for (unsigned i = 0; i <= mySize; i++) {
		fin >> myArray[i];
	}
	fin.close();
}



/* Subscript to retrieve value method for constant
 * 		reference values
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myArray[index]
 * (read)
 */
const Item& Vec::operator[] (unsigned index) const {
	if (index >= mySize) {
		throw range_error ("Invalid Subscript.");
	}
	else {
		return myArray[index];
	}
}



														//LUKE CHEN//

/* define a subscript operator [i] to allow user to change the value of Vec at index i
 * @param: unsigned index i
 * postcondition: change the value of Vec at index i
 * built by: Luke Chen lc33
 */
Item & Vec::operator[](unsigned index) {
    if (index >= mySize) {
        throw range_error("Index out of range");
    }
    return myArray[index];
}



/* define a writeTo function to write all the values in a Vec to the file named by fileName
 * @param: string& fileName
 * postcondition: the values of the Vec are written in the file
 * built by: Luke Chen lc33
 */
void Vec::writeTo(const string& fileName) const {
    ofstream fout( fileName.c_str() );
    assert( fout.is_open() );
    fout << mySize << '\n';
    for (unsigned i = 0; i < mySize; i++) {
        fout << myArray[i] << '\n';
    }
    fout.close();
}



/* define an addition operator + to allow addition of vector values
 * return: newArray.myArray[i] = myArray[i] + v2.myArray[i]
 * built by: Luke Chen lc33
 */
Vec Vec::operator+(const Vec& v2) {
    Vec newVec(mySize);
    if (mySize != v2.mySize) {
        throw invalid_argument("vectors have different sizes");
    } else if (v2.mySize == 0) {
        return newVec;
    }
    for (unsigned i = 0; i < mySize; i++) {
        newVec.myArray[i] = myArray[i] + v2.myArray[i];
    }
    return newVec;
}




/* define a dot product operator * to allow dot production of vector values
 * return: product += myArray[i] * v2.myArray[i]
 * built by: Luke Chen lc33
 */
Item Vec::operator*(const Vec& v2) {
    Item product = 0;
    if (mySize != v2.mySize) {
        throw invalid_argument("vectors have different sizes");
    } else if (v2.mySize == 0) {
        return product;
    }
    for (unsigned i = 0; i < mySize; i++) {
        product += myArray[i] * v2.myArray[i];
    }
    return product;
}
