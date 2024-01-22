#pragma once

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T>
{
private:
	T** matrix;
public:
	SquareMatrix() {}
	~SquareMatrix()
	{
		for (int i = 0; i < this->length; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
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

		matrix = new T * [this->length];
		for (int i = 0; i < this->length; i++)
		{
			matrix[i] = new T[this->length];
		}

		cout << "Enter the elements: ";

		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}
	void print() const override
	{
		cout << "(Square matrix)" << endl;
		cout << "Name: " << this->name << endl;
		cout << "Length: " << this->length << endl;
		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				cout << '\t' << matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	void load_matrix(ifstream& fin) override
	{

	}

	void save_matrix(ofstream& fout) override
	{
		fout << "(Square Matrix)" << endl;
		fout << "Name: " << this->name << endl;
		fout << "Length: " << this->length << endl;
		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				fout << '\t' << matrix[i][j];
			}
			fout << endl;
		}
		fout << endl;
	}
};

