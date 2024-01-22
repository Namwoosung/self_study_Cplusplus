//Date_10 & Date_11

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

/*기초문제 1
int main()
{
	vector<vector<int>> vec(2, vector<int>(3,0));
	for (vector<int>& row : vec)
	{
		for (int& elem : row)
		{
			cin >> elem;
		}
	}

	for (auto row : vec)
	{
		for (auto elem : row)
		{
			cout << elem << '\t';
		}
		cout << endl;
	}

	auto a = 10;
	auto b = 10.1;
	auto c = 'd';
	cout << a << ", " << b << ", " << c << endl;

	return 0;
}
*/

/*기초문제 2
int main()
{
	int ary[3] = { 1, 2 ,3 };

	cout << (ary + 0) << '\t' << *(ary + 0) << '\t' << ary[0] << endl;
	cout << (ary + 1) << '\t' << *(ary + 1) << '\t' << ary[1] << endl;
	cout << (ary + 2) << '\t' << *(ary + 2) << '\t' << ary[2] << endl;

	return 0;
}
*/

/*기초문제 3
void print(const int* ar, const int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << ar[i] << '\t';
	}
	cout << endl;
}

int sum(int* begin, int* end)
{
	int* curr = begin;
	int result = 0;
	while (curr != end)
	{
		result += *curr;
		curr++;
	}
	return result;
}

int main()
{
	int ary[] = { 10, 20, 30, 40, 50 };
	print(ary, 5);

	int* begin, * end;

	begin = ary;
	end = ary + 5;

	cout << sum(begin, end) << endl;

	return 0;
}
*/

/*기초문제 4
int main()
{
	int size;
	cout << "Size: ";
	cin >> size;
	const int len = 10;
	int staticArr[len];

	double* dynamicArr;
	dynamicArr = new double[size];

	for (int i = 0; i < size; i++)
	{
		cout << "dynamic\t";
	}
	cout << endl;

	delete[] dynamicArr;

	return 0;
}
*/

/*기초문제 5
int main()
{
	int matrix[2][3] = { {1,2,3}, {4,5,6} };

	int number = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = number;
			number++;
		}
	}

	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << matrix[row][col] << '\t';
		}
		cout << endl;
	}

	return 0;
}
*/

/*기초문제 6
bool found_char(const char* s, char c)
{
	while (*s != NULL)
	{
		if (*s == c)
		{
			return true;
		}
		s++;
	}
	return false;
}

int main()
{
	const char* ch = "phrase";

	for (char c = 'a'; c <= 'z'; c++)
	{
		cout << "[" << c << "] is ";
		if (!found_char(ch, c))
		{
			cout << "NOT ";
		}
		cout << "in " << ch << endl;
	}

	return 0;
}
*/

/*응용문제 1
void MakeVector(vector<vector<int>>& v);
void PrintVector(vector<vector<int>>& v);
void MulVector(vector<vector<int>>& A, vector<vector<int>>& B);

int main()
{
	srand(time(NULL));

	int A_row, A_col, B_row, B_col;

	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> A_row >> A_col;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> B_row >> B_col;
	cout << endl;

	if (A_row <= 0 || A_col <= 0 || B_row <= 0 || B_col <= 0)
	{
		cout << "행렬을 생성할 수 없습니다." << endl;
		exit(100);
	}

	vector<vector<int>> A(A_row, vector<int>(A_col, 0));
	vector<vector<int>> B(B_row, vector<int>(B_col, 0));

	MakeVector(A);
	MakeVector(B);

	cout << "A 행렬 :" << endl;
	PrintVector(A);
	cout << "B 행렬 :" << endl;
	PrintVector(B);
	cout << endl;

	if (A_col != B_row)
	{
		cout << "두 행렬을 곱할 수 없습니다." << endl;
		exit(100);
	}

	cout << "AB 곱행렬 :" << endl;
	MulVector(A, B);

	return 0;
}

void MakeVector(vector<vector<int>>& v)
{
	int number;

	for (vector<int>& row : v)
	{
		for (int& elem : row)
		{
			number = rand() % 19 - 9;
			elem = number;
		}
	}
}

void PrintVector(vector<vector<int>>& v)
{
	for (vector<int>& row : v)
	{
		for (int& elem : row)
		{
			cout << setw(4) << elem;
		}
		cout << endl;
	}
}

void MulVector(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int value = 0;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B[0].size(); j++)
		{
			for (int k = 0; k < A[i].size(); k++)
			{
				value += A[i][k] * B[k][j];
			}
			cout << value << '\t';
			value = 0;
		}
		cout << endl;
	}
}
*/

/*응용문제 2
int* make_arr(int n)
{
	int number = 1;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = number;
		number += 2;
	}
	return arr;
}
void print_arr(int* a, int n)
{
	cout << "\nOdd Number Array: " << endl;
	int number = 0;
	while (n)
	{
		cout << a[number] << " ";
		number++;
		n--;
	}
	cout << endl;
}

int sum_arr(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += *a;
		a++;
	}
	return s;
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int* arr = make_arr(n);
	print_arr(arr, n);

	int sum = sum_arr(arr, n);
	cout << "\nSum of the array: " << sum << endl;

	delete[] arr;
	return 0;
}
*/

/*응용문제 3
int main()
{
	while (true)
	{
		int len;
		cout << "Please enter a number: ";
		cin >> len;

		if (len < 2)
		{
			cout << "Wrong number!!!" << endl;
			exit(100);
		}

		cout << "Size of random array:" << len / 2 << endl;

		int* arr = new int[len / 2];
		for (int i = 0; i < len / 2; i++)
		{
			arr[i] = rand() % len + 1;
		}

		cout << "[ Array ]" << endl;
		for (int i = 0; i < len / 2; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		bool Is_Dup = false;

		for (int i = 0; i < len / 2 - 1; i++)
		{
			for (int j = i + 1; j < len / 2; j++)
			{
				if (arr[i] == arr[j])
				{
					Is_Dup = true;
					break;
				}
			}
			if (Is_Dup == true)
			{
				break;
			}
		}

		if (Is_Dup)
		{
			cout << "Duplicates found." << endl << endl;
		}
		else
		{
			cout << "Duplicates not found." << endl << endl;
		}
	}
}
*/

/*응용문제 4
int** buildTable(int n)
{
	int** Table = new int* [n];
	for (int i = 0; i < n; i++)
	{
		Table[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Table[i][j] = 0;
		}
	}

	return Table;
}

void make_identity_matrix(int** table, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				table[i][j] = 1;
			}
		}
	}
}
void printTable(int** table, int n)
{
	cout << "Output: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << table[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n = 0;
	cout << "N을 입력하시오: ";
	cin >> n;
	if (n < 1)
	{
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int** table = buildTable(n);
	make_identity_matrix(table, n);
	printTable(table, n);

	for (int i = 0; i < n; i++)
	{
		delete[] table[i];
	}
	delete[] table;

	return 0;
}
*/