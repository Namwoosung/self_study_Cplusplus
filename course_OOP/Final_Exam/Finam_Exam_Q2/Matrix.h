#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
class Matrix
{
protected:
	string name;
	int length;
public:
	Matrix(string _name = "", int _length = 0) : name(_name), length(_length) {}
	~Matrix() {}
	int get_length() const { return length; }
	string get_name() const { return name; }
	virtual void set_matrix() = 0;
	virtual void print() const = 0;
	virtual void load_matrix(ifstream& fin) = 0;
	virtual void save_matrix(ofstream& fout) = 0;
};
