/* Vec.h provides a simple vector class named Vec.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 21, 2017
 * Begun by: Joel Adams, for CS 112 lab 3 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	
	Vec& operator=(const Vec& original);
	unsigned getSize() const { return mySize; };
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	bool operator!=(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index); // write
	const Item& operator[](unsigned index) const; // read
	void readFrom(const string& fileName);
	void writeTo(const string& filename) const;
	Vec operator+(const Vec& v2);
	const Vec operator-(const Vec& v2) const;
	Item operator*(const Vec& v2);

private:
	unsigned mySize;
	Item *   myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
