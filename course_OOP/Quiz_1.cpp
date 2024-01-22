/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void get_data(string& filename, int& row, int& col);
void generate_matrix(string filename, int row, int col);
void display_matrix(string filename, int row, int col);
void get_min_max(string filename, int& min, int& max);

int main()
{
	string filename;
	int row, col, minVal, maxVal;

	get_data(filename, row, col);
	generate_matrix(filename, row, col);
	display_matrix(filename, row, col);
	get_min_max(filename, minVal, maxVal);

	cout << "Minimum element: " << minVal << endl;
	cout << "Maxinum element: " << maxVal << endl;

	return 0;
}

void get_data(string& filename, int& row, int& col)
{
	cout << "Enter the file name: ";
	cin >> filename;

	cout << "Enter the row and column numbers: ";
	cin >> row >> col;
}

void generate_matrix(string filename, int row, int col)
{
	ofstream fout;
	int number;

	fout.open(filename);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			number = rand() % 101;

			fout.width(4);
			fout << number;
		}
		fout << endl;
	}

	fout.close();
}

void display_matrix(string filename, int row, int col)
{
	ifstream fin;
	char ch;

	fin.open(filename);
	if (!fin)
	{
		cout << "Erroe" << endl;
		exit(100);
	}

	cout << "Display Matrix:" << endl;

	while (true)
	{
		fin.get(ch);
		if (!fin)
		{
			break;
		}
		cout << ch;
	}

	fin.close();
}

void get_min_max(string filename, int& min, int& max)
{
	ifstream fin;
	int now_num = 0, max_num = 0, min_num = 101;

	fin.open(filename);
	if (!fin)
	{
		cout << "Erroe" << endl;
		exit(100);
	}

	while (true)
	{
		fin >> now_num;
		if (!fin)
		{
			break;
		}
		if (now_num > max_num)
		{
			max_num = now_num;
		}

		if (now_num < min_num)
		{
			min_num = now_num;
		}
	}

	min = min_num;
	max = max_num;

	fin.close();
}
*/