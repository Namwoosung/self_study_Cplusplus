/*
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int sum(int a, int b) { return a + b; }
int subt(int a, int b) { return a - b; }
void get_size(int& row, int& col);
vector<vector<int>> get_matrix(string text, int row, int col);
void get_operator(string& oper);
vector<vector<int>> evaluate(string oper, const vector<vector<int>>& mat1, const vector<vector<int>>& mat2);
void print(string text, const vector<vector<int>>& mat);

int main()
{
	int nRow, nCol;
	string command;
	get_size(nRow, nCol);
	vector<vector<int>> mat1 = get_matrix("[matrix1]", nRow, nCol);
	vector<vector<int>> mat2 = get_matrix("[matrix2]", nRow, nCol);


	get_operator(command);
	vector<vector<int>> mat3 = evaluate(command, mat1, mat2);

	print("[matrix1]", mat1);
	print("[matrix2]", mat2);
	print("[matrix3]", mat3);

	return 0;
}

void get_size(int& row, int& col)
{
	bool Is_correct = false;
	while (!Is_correct)
	{
		cout << "Enter nRow and nCol in (nRow x nCol):";
		cin >> row >> col;
		cout << endl;

		if (row >= 1 && col >= 1)
		{
			Is_correct = true;
		}
	}
}

vector<vector<int>> get_matrix(string text, int row, int col)
{
	vector<vector<int>> mat(row, vector<int>(col, 0));

	cout << text << "Enter elements:" << endl;

	for (vector<int>& line : mat)
	{
		for (int& elem : line)
		{
			cin >> elem;
		}
	}

	return mat;
}

void get_operator(string& oper)
{
	bool Is_correct = false;
	do
	{
		cout << "Enter a operator(+, -): ";
		cin >> oper;

		if (oper == "+" || oper == "-")
		{
			Is_correct = true;
		}
	} while (!Is_correct);
}

vector<vector<int>> evaluate(string oper, const vector<vector<int>>& mat1, const vector<vector<int>>& mat2)
{
	vector<vector<int>> mat(mat1.size(), vector<int>(mat1[0].size(), 0));

	int(*func)(int, int) = &subt;
	if (oper == "+")
	{
		func = &sum;
	}
	else if (oper == "-")
	{
		func = &subt;
	}

	for (unsigned int i = 0; i < mat1.size(); i++)
	{
		for (unsigned int j = 0; j < mat1[0].size(); j++)
		{
			mat[i][j] = func(mat1[i][j], mat2[i][j]);
		}
	}
	cout << endl;
	return mat;
}

void print(string text, const vector<vector<int>>& mat)
{
	cout << text << endl;

	for (vector<int> row : mat)
	{
		for (int elem : row)
		{
			cout << setw(4) << elem;
		}
		cout << endl;
	}
}
*/