#pragma once

#include "Matrix.h"

template<typename T>
class DiagonalMatrix : public Matrix<T>
{
protected:
	T* matrix;
public:
	DiagonalMatrix() {}
	~DiagonalMatrix() { delete[] matrix; }
	void set_matrix() override
	{
		string _name;
		int _length;

		cout << "Enter the name: ";
		cin >> _name;
		this->name = _name;
		cout << "Enter the length: ";
		cin >> _length;
		this->length = _length;

		matrix = new T [this->length];

		cout << "Enter the elements: ";

		for (int i = 0; i < this->length; i++)
		{
			cin >> matrix[i];
		}
	}
	void print() const override
	{
		cout << "(DiagonalMatrix matrix)" << endl;
		cout << "Name: " << this->name << endl;
		cout << "Length: " << this->length << endl;
		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				if (i == j)
				{
					cout << '\t' << matrix[i];
				}
				else
				{
					cout << '\t' << "0";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
};

