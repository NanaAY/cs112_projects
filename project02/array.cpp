/* array.cpp defines "C style" array operations
 * Name: Nana Osei Asiedu Yirenkyi
 * Date: 09/23/2018
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "array.h"
#include <iostream>



void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}

double average(double *a, unsigned size) {
	double sum = 0;
	for (unsigned i = 0; i < size; i++) {
		sum += *a;
		a++;
	}
	return sum/size;
}


//returns the sum of the values in the array
double sum(double *a, unsigned size) {
	double sum = 0;
	for (unsigned i = 0; i < size; i++) {
			sum += *a;
			a++;
		}
	return sum;
}


//reads size values from in and store them in a
void read(istream& in, double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		in >> *a;
		a++;
	}
}



//This function (i) opens an ifstream to the file named fileName,
//(ii) reads an integer from the file into numValues,
//(iii) dynamically allocates an array of numValues double values, storing its address in a,
//(iv)reads numValues values from the file, storing them in the dynamic array, and
//(v) closes the ifstream.
void fill(const string& fileName, double *&a, unsigned &numValues) {
	ifstream fin(fileName.c_str());
	fin >> numValues;
	double * newArray = new double[numValues];
	*&a = newArray;
	for (unsigned i = 0; i < numValues; i++) {
		fin >> *&a[i];
	}
	fin.close();
}



//changes the size of the array from oldSize to newSize.
void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double * newArray = new double[newSize];
	if (newSize > oldSize) {
		for (unsigned i = 0; i < oldSize; i++) {
			newArray[i] = a[i];
		}
	}
	else if (newSize < oldSize) {
		for (unsigned i = 0; i < newSize; i++) {
			newArray[i] = a[i];
		}
	}
	delete [] a;
	a = newArray;
}



void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	if (a3 != NULL) {
		delete [] a3;
	}
	size3 = size1 + size2;
	a3 = new double[size3];

	for (unsigned i = 0; i < size1; i++) {
		a3[i] = a1[i];
	}
	for (unsigned i = 0; i < size2; i++) {
		a3[i + size1] = a2[i];
	}
}
