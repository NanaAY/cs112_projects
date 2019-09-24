/* Vec.h provides a simple vector class named Vec.
 * Student Name:Nana Osei Asiedu Yirenkyi
 * Date: Sept 25 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	Vec operator-(const Vec& v2);
	Vec operator+(const Vec& v2);
	unsigned getSize() const;
	Item getItem(unsigned index) const;
	Item& operator[] (const unsigned index);
	Item operator*(const Vec& v2);
	bool operator==(const Vec& v2);
	bool operator!=(const Vec& v2);
	void setItem(unsigned index, const Item& it);
	void setSize(unsigned newSize);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	void readFrom(string fileName);
	void writeTo(const string& fileName) const;
	const Item& operator[] (unsigned index) const;
	virtual ~Vec();
	
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;

};

#endif /*VEC_H_*/
