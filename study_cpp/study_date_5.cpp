/* class�� �̿��� �м� ����
#include <iostream>
#include <string>

using namespace std;

class CalCul
{
public:
	CalCul(string number);

private:
	int number_1;
	int number_2;

public:
	int GCD(int given_number_1, int given_number_2);
	void add(CalCul another);
	void sub(CalCul another);
	void mul(CalCul another);
	void div(CalCul another);
};

int main()
{
	string number_1, number_2;
	char sign;

	cout << "����� �� ���ڸ� ���Ἥ �Է����ֽʽÿ�.(�и�Ȥ�� ���ڿ� 0���Խ� 0���� ������)" << endl << "ex) 3/5 5/1" << endl;
	cin >> number_1 >> number_2;

	CalCul CalCul_number(number_1);
	CalCul PeCalCul_number(number_2);

	cout << "������ �����ڸ� �Է����ֽʽÿ�." << endl;
	cin >> sign;

	switch (sign)
	{
	case '+':
		CalCul_number.add(PeCalCul_number);
		break;
	case '-':
		CalCul_number.sub(PeCalCul_number);
		break;
	case '*':
		CalCul_number.mul(PeCalCul_number);
		break;
	case '/':
		CalCul_number.div(PeCalCul_number);
		break;
	}

}

CalCul::CalCul(string number)
{
	int position = number.find('/');
	number_1 = atoi(number.substr(position - 1).c_str());
	number_2 = atoi((number.substr(position + 1, number.size() - position)).c_str());

	if (number_1 == 0 || number_2 == 0)
	{
		number_1 = 0;
		number_2 = 1;
	}
}
int CalCul::GCD(int given_number_1, int given_number_2)
{
	int left_number;

	bool judge = true;
	while (judge)
	{
		if (given_number_1 > given_number_2)
		{
			left_number = given_number_1 % given_number_2;
			if (left_number == 0)
			{
				judge = false;
				return given_number_2;
			}
			else
			{
				given_number_1 = left_number;
			}
		}
		else if (given_number_1 < given_number_2)
		{
			left_number = given_number_2 % given_number_1;
			if (left_number == 0)
			{
				judge = false;
				return given_number_1;
			}
			else
			{
				given_number_2 = left_number;
			}
		}
		else
		{
			judge = false;
			return given_number_1;
		}
	}
}
void CalCul::add(CalCul another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_2 + number_2 * another.number_1;
	int GCD_number = GCD(num_down, num_up);
	cout << num_up / GCD_number << "/" << num_down / GCD_number;
}
void CalCul::sub(CalCul another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_2 - number_2 * another.number_1;
	int GCD_number = GCD(num_down, num_up);
	cout << num_up / GCD_number << "/" << num_down / GCD_number;
}
void CalCul::mul(CalCul another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_1;
	int GCD_number = GCD(num_down, num_up);
	cout << num_up / GCD_number << "/" << num_down / GCD_number;
}
void CalCul::div(CalCul another)
{
	int num_down = number_2 * another.number_1;
	int num_up = number_1 * another.number_2;
	int GCD_number = GCD(num_down, num_up);
	cout << num_up / GCD_number << "/" << num_down / GCD_number;
}
*/

/* class�� ���� ��� ����
#include <iostream>

using namespace std;

class CalMatrix
{
public:
	CalMatrix(int _m, int _n);
	void add_Matrix(CalMatrix another);
	void sub_Matrix(CalMatrix another);
	void mul_Matrix(CalMatrix another);
	void print_Matrix();

private:
	int m, n, k;
	int** arr;
};

int main()
{
	int m, n;
	char sign;

	cout << "ù��° ����� ��� ���� ���� ���� �Ͽ� �Է��Ͻʽÿ�" << endl;
	cin >> m >> n;
	CalMatrix Matrix1(m, n);
	cout << "�ι�° ����� ��� ���� ���� ���� �Ͽ� �Է��Ͻʽÿ�" << endl;
	cin >> m >> n;
	CalMatrix Matrix2(m, n);
	
	cout << "ù��° ���" << endl;
	Matrix1.print_Matrix();
	cout << "�ι�° ���" << endl;
	Matrix2.print_Matrix();

	cout << "������ �����ڸ� �Է��� �ֽʽÿ�." << endl;
	cin >> sign;

	switch (sign)
	{
	case '+':
		Matrix1.add_Matrix(Matrix2);
		break;
	case '-':
		Matrix1.sub_Matrix(Matrix2);
		break;
	case '*':
		Matrix1.mul_Matrix(Matrix2);
		break;
	}
}

CalMatrix::CalMatrix(int _m, int _n)
{
	m = _m;
	n = _n;
	arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "����� ��Ҹ� ������� �ϳ��� �Է��Ͻʽÿ�." << endl;
			cin >> k;
			arr[i][j] = k;
		}
	}
}
void CalMatrix::add_Matrix(CalMatrix another)
{
	if ((this->m == another.m) && (this->n == another.n))
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << this->arr[i][j] + another.arr[i][j] << '\t';
			}
			cout << endl;
		}
		
	}	
	else
	{
		cout << "������ �� �ִ� ������ ����� �ƴմϴ�." << endl;
	}
}
void CalMatrix::sub_Matrix(CalMatrix another)
{
	if ((this->m == another.m) && (this->n == another.n))
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << this->arr[i][j] - another.arr[i][j] << '\t';
			}
			cout << endl;
		}

	}
	else
	{
		cout << "������ �� �ִ� ������ ����� �ƴմϴ�." << endl;
	}
}
void CalMatrix::mul_Matrix(CalMatrix another)
{
	if (this->n != another.m)
	{
		cout << "������ �� �ִ� ������ ����� �ƴմϴ�." << endl;
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			bool judge = true;

			int value = 0;
			int test = 0;

			while (judge)
			{
				if (test >= n - 2)
				{
					judge = false;
				}

				for (int j = 0; j < n; j++)
				{
					value += this->arr[i][j] * another.arr[j][test];
				}
				cout << value << '\t';
				test += 1;
				value = 0;
			}
			for (int j = 0; j < n; j++)
			{
				value += this->arr[i][j] * another.arr[j][test];
			}
			cout << value << '\n';
		}
	}
}

void CalMatrix::print_Matrix()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << this->arr[i][j] << '\t';
		}
		cout << endl;
	}
}
*/