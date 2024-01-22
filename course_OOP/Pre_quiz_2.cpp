/*
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void get_command(string& command);
void get_size(int& size);
int** gen_matrix(int size);
void swap(int* a, int* b);
void sort_array(int* ary, int size);
void sort_matrix_row(int** matrix, int size);
void print_matrix(int** matrix, int size);
void save_matrix(int** matrix, int size);
void free_matrix(int** matrix, int size);

int main()
{
	string command;
	int** matrix = NULL;
	int size = 0;

	while (1)
	{
		get_command(command);
		if (command == "1")
		{
			get_size(size);
			matrix = gen_matrix(size);
		}
		else if (command == "2")
		{
			print_matrix(matrix, size);
		}
		else if (command == "3")
		{
			sort_matrix_row(matrix, size);
		}
		else if (command == "4")
		{
			save_matrix(matrix, size);
		}
		else if (command == "0")
		{
			free_matrix(matrix, size);
			cout << "Exit the program.." << endl;
			exit(104);
		}
		else
		{
			cout << "Wrong Command" << endl << endl;
		}
	}

	return 0;
}

void get_command(string& command)
{
	cout << "1. Generate matrix" << endl << "2. Print Matix" << endl << "3. Sort Matrix" << endl << "4. Save Matrix" << endl << "0. Exit program" << endl;
	cout << ">>";
	cin >> command;
}

void get_size(int& size)
{
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}

int** gen_matrix(int size)
{
	int** mat = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mat[i][j] = rand() % 101;
		}
	}

	return mat;
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(int* ary, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (ary[i] > ary[i + 1])
		{
			swap(ary[i], ary[i + 1]);
		}
	}
}

void sort_matrix_row(int** matrix, int size)
{
	int* row = new int;
	for (int i = 0; i < size; i++)
	{
		row = matrix[i];
		sort_array(row, size);
		matrix[i] = row;
	}

	cout << "Completed" << endl << endl;
}

void print_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void save_matrix(int** matrix, int size)
{
	ofstream fout;
	fout.open("matrix.txt");

	fout << size << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fout << setw(4) << matrix[i][j];
		}
		fout << endl;
	}

	fout.close();

	cout << "saved" << endl << endl;
}

void free_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
*/