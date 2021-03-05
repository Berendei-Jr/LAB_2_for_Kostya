#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Vector
{
	int n;
	int* data;
public:
	Vector();
	Vector(int n, int* data);
	Vector(const Vector& other);
	Vector(Vector&& other);
	Vector& operator = (const Vector& other);
	Vector& operator = (Vector&& other);
	int& operator [] (int index);
	int getN();
	int* getData();
	void setVector(int n, int* data);
	friend ostream& operator<<(ostream& out, Vector& vec);
	friend istream& operator>>(istream& in, Vector& vec);
	friend Vector& operator^(int* array, Vector& vec);
	~Vector();
};

