#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*vector를 이용한 소수 구하는 프로그램
void get_data(int& low, int& high)
{
	cout << "Enter low and high value: ";
	cin >> low >> high;
}

bool is_prime(int n)
{
	if (n < 2)
	{
		return false;
	}

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

vector<int> primes(int low, int high)
{
	vector<int> v;
	for (int i = low; i <= high; i++)
	{
		if (is_prime(i))
		{
			v.push_back(i);
		}
	}
	return v;
}

void print(const vector<int>& v)
{
	for (int elem : v)
	{
		cout << elem << '\t';
	}
	cout << endl;
}

int main()
{
	//low, high를 키보드로부터 입력
	int low, high;
	get_data(low, high);

	//primes를 찾아서 vector에 저장
	vector<int> vec = primes(low, high);

	//vector를 print
	print(vec);

	return 0;
}
*/


/*vector의 2차원 배열 || vector로 matrix 출력
int main()
{
	//1) vector<vector<int>> vec{ {1, 2, 3},
	//						 {4, 5, 6} };

	//2)vector<vector<int>> vec(2, vector<int>(3,0));

	//일반적인 vector출력 방법
	for (unsigned row = 0; row < vec.size(); row++)
	{
		for (unsigned col = 0; col < vec[row].size(); col++)
		{
			cout << setw(4) << vec[row][col];
		}
		cout << endl;
	}

	//simplified for문을 이용해 vector출력
	for (vector<int> row : vec)
	{
		for (int elem : row)
		{
			cout << setw(4) << elem;
		}
		cout << endl;
	}

	return 0;
}
*/

/*array 선언 및 출력
void print(double* a, int size)//배열은 배열의 첫 번째 element의 시작 주소값을 가리키는 포인터라고 생각하면 됨
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
}

int main()
{
	double list[3] = { 10.1, 20.2, 30.3 };//array의 변수는 포인터 변수

	print(list, 3); //3도 파라미터로 넘겨주는 이유: array는 배열속 자료의 수를 반환해주는 함수가 없음 -> 크기를 넘겨줘야 print할 수 있음



	return 0;
}
*/

/*array 특징
int main()
{
	int ary[] = { 10, 20, 30 };

	cout << (ary + 0) << '\t' << *(ary + 0) << '\t' << ary[0] << endl;
	cout << (ary + 1) << '\t' << *(ary + 1) << '\t' << ary[1] << endl;
	cout << (ary + 2) << '\t' << *(ary + 2) << '\t' << ary[2] << endl;

	return 0;
}
*/

/*array특징 응용
int main()
{
	int ary[] = { 10, 20, 30 };
	int* begin, * end, * current;

	begin = ary;
	end = ary + 3;

	current = begin;
	while (current != end)
	{
		cout << *current << '\t';
		current++;
	}

	return 0;
}
*/