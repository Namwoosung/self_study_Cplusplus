//#include <iostream>

//using namespace std;

/*array와 주소
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

/*정적배열(static aray): 프로그램 실행중 변경(할당/해제) 불가
int main()
{
	const int size = 3;
	int list[size] = { 10, 20, 30 }; //정적배열임 -> size에 상수만 들어가야함(int size = 3을 하고 size 대입시 오류 발생 -> const화 시켜주어야 함)


	return 0;
}
*/

/*동적배열(dynamic array): 프로그램 실행중 변경 가능
int main()
{
	int size = 3;
	cin >> size;
	int* list = new int[size]; //동적배열 할당(new)
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
	delete[] list_2; //동적배열 선언 후 메모리 할당 해제를 해주어야 함(해제해주지 않으면 메모리 크기를 계속 잡아먹음), delete[]에서 []는 리스트를 제거해주겠다는 의미

	return 0;
}
*/

/*2차원 동적 배열
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
	//				  {3, 4} }; //2차원 정적 배열
	//
	int nRow = 2, nCol = 2;
	int** mat = new int* [nRow]; //int** mat_2: int*의 주소를 가르키는 변수, int*[nRow] -> mat_2속 element들이 int*형이고 nRow만큼의 크기를 가진다
	for (int i = 0; i < nRow; i++)
	{
		mat[i] = new int[nCol]; //mat_2속 element들에 각각 동적할당을 해줌
	} //2차원 동적 배열

	mat[0][0] = 1; mat[0][1] = 2;
	mat[1][0] = 3; mat[1][1] = 4;

	print(mat, nRow, nCol);

	for (int i = 0; i < nRow; i++)
	{
		delete[] mat[i]; //먼저 element들의 동적배열 할당을 해제
	}
	delete[] mat; // 2차원 동적 배열 할당 해제

	return 0;
}
*/

/*문자열 배열
//char형 배열: 문자열을 저장
// 1) 문자열 끝에 NULL(='\00') 자동 저장
// 2) cout << phrase 의 경우 주소값이 아닌 문자열 출력
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
	const char* phrase = "this is a phrase";// 캐릭터형의 포인터에서 마지막 주소값에는 \0(NULL)값을 저장함 -> 만약 4바이트 짜리 문자열을 char*에 저장했다면 5바이트자리 주소값에 NULL 저장
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