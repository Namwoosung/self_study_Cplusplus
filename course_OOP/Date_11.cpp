//#include <iostream>

//using namespace std;

/*array�� �ּ�
void print(int* begin, int* end)
{
	int* curr = begin;
	while (curr != end)
	{
		cout << *curr << '\t';
		curr++;
	}
	cout << endl;
}

int sum(int* begin, int* end)
{
	int result = 0;
	for (int* curr = begin; curr != end; curr++)
	{
		result += *curr;
	}

	return result;
}

int main()
{
	int list[3] = { 10, 20, 30 };

	cout << (list + 0) << '\t' << *(list + 0) << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;

	int* begin = list;
	int* end = list + 3;

	print(begin, end);

	cout << sum(begin, end) << endl;

	return 0;
}
*/

/*�����迭(static aray): ���α׷� ������ ����(�Ҵ�/����) �Ұ�
int main()
{
	const int size = 3;
	int list[size] = { 10, 20, 30 }; //�����迭�� -> size�� ����� ������(int size = 3�� �ϰ� size ���Խ� ���� �߻� -> constȭ �����־�� ��)


	return 0;
}
*/

/*�����迭(dynamic array): ���α׷� ������ ���� ����
int main()
{
	int size = 3;
	cin >> size;
	int* list = new int[size]; //�����迭 �Ҵ�(new)
	double* list_2 = new double[size];

	int* begin = list;
	int* end = list + size;

	for (int* curr = begin; curr != end; curr++)
	{
		cin >> *curr;
	}
	for (int* curr = begin; curr != end; curr++)
	{
		cout << *curr << '\t';
	}
	cout << endl;

	delete[] list;
	delete[] list_2; //�����迭 ���� �� �޸� �Ҵ� ������ ���־�� ��(���������� ������ �޸� ũ�⸦ ��� ��Ƹ���), delete[]���� []�� ����Ʈ�� �������ְڴٴ� �ǹ�

	return 0;
}
*/

/*2���� ���� �迭
void print(int** m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << m[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{

	//int mat[2][2] = { {1, 2},
	//				  {3, 4} }; //2���� ���� �迭
	//
	int nRow = 2, nCol = 2;
	int** mat = new int* [nRow]; //int** mat_2: int*�� �ּҸ� ����Ű�� ����, int*[nRow] -> mat_2�� element���� int*���̰� nRow��ŭ�� ũ�⸦ ������
	for (int i = 0; i < nRow; i++)
	{
		mat[i] = new int[nCol]; //mat_2�� element�鿡 ���� �����Ҵ��� ����
	} //2���� ���� �迭

	mat[0][0] = 1; mat[0][1] = 2;
	mat[1][0] = 3; mat[1][1] = 4;

	print(mat, nRow, nCol);

	for (int i = 0; i < nRow; i++)
	{
		delete[] mat[i]; //���� element���� �����迭 �Ҵ��� ����
	}
	delete[] mat; // 2���� ���� �迭 �Ҵ� ����

	return 0;
}
*/

/*���ڿ� �迭
//char�� �迭: ���ڿ��� ����
// 1) ���ڿ� ���� NULL(='\00') �ڵ� ����
// 2) cout << phrase �� ��� �ּҰ��� �ƴ� ���ڿ� ���
bool find_char(const char* s, char ch)
{
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return true;
		}
		s++;
	}
	return false;
}

int main()
{
	const char* phrase = "this is a phrase";// ĳ�������� �����Ϳ��� ������ �ּҰ����� \0(NULL)���� ������ -> ���� 4����Ʈ ¥�� ���ڿ��� char*�� �����ߴٸ� 5����Ʈ�ڸ� �ּҰ��� NULL ����
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		cout << ch << " is";
		if (!find_char(phrase, ch))
		{
			cout << " NOT";
		}

		cout << " in (" << phrase << ")" << endl;
	}

	return 0;
}
*/