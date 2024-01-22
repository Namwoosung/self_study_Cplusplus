#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*vector�� �̿��� �Ҽ� ���ϴ� ���α׷�
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
	//low, high�� Ű����κ��� �Է�
	int low, high;
	get_data(low, high);

	//primes�� ã�Ƽ� vector�� ����
	vector<int> vec = primes(low, high);

	//vector�� print
	print(vec);

	return 0;
}
*/


/*vector�� 2���� �迭 || vector�� matrix ���
int main()
{
	//1) vector<vector<int>> vec{ {1, 2, 3},
	//						 {4, 5, 6} };

	//2)vector<vector<int>> vec(2, vector<int>(3,0));

	//�Ϲ����� vector��� ���
	for (unsigned row = 0; row < vec.size(); row++)
	{
		for (unsigned col = 0; col < vec[row].size(); col++)
		{
			cout << setw(4) << vec[row][col];
		}
		cout << endl;
	}

	//simplified for���� �̿��� vector���
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

/*array ���� �� ���
void print(double* a, int size)//�迭�� �迭�� ù ��° element�� ���� �ּҰ��� ����Ű�� �����Ͷ�� �����ϸ� ��
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
}

int main()
{
	double list[3] = { 10.1, 20.2, 30.3 };//array�� ������ ������ ����

	print(list, 3); //3�� �Ķ���ͷ� �Ѱ��ִ� ����: array�� �迭�� �ڷ��� ���� ��ȯ���ִ� �Լ��� ���� -> ũ�⸦ �Ѱ���� print�� �� ����



	return 0;
}
*/

/*array Ư¡
int main()
{
	int ary[] = { 10, 20, 30 };

	cout << (ary + 0) << '\t' << *(ary + 0) << '\t' << ary[0] << endl;
	cout << (ary + 1) << '\t' << *(ary + 1) << '\t' << ary[1] << endl;
	cout << (ary + 2) << '\t' << *(ary + 2) << '\t' << ary[2] << endl;

	return 0;
}
*/

/*arrayƯ¡ ����
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