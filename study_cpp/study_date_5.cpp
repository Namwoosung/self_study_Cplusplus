/* class를 이용한 분수 계산기
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

	cout << "계산할 두 분자를 띄어써서 입력해주십시오.(분모혹은 분자에 0대입시 0으로 간주함)" << endl << "ex) 3/5 5/1" << endl;
	cin >> number_1 >> number_2;

	CalCul CalCul_number(number_1);
	CalCul PeCalCul_number(number_2);

	cout << "연산할 연산자를 입력해주십시오." << endl;
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

/* class를 통한 행렬 계산기
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

	cout << "첫번째 행렬의 행과 열의 수를 띄어쓰기 하여 입력하십시오" << endl;
	cin >> m >> n;
	CalMatrix Matrix1(m, n);
	cout << "두번째 행렬의 행과 열의 수를 띄어쓰기 하여 입력하십시오" << endl;
	cin >> m >> n;
	CalMatrix Matrix2(m, n);
	
	cout << "첫번째 행렬" << endl;
	Matrix1.print_Matrix();
	cout << "두번째 행렬" << endl;
	Matrix2.print_Matrix();

	cout << "연산할 연산자를 입력해 주십시오." << endl;
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
			cout << "행렬의 요소를 순서대로 하나씩 입력하십시오." << endl;
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
		cout << "연산할 수 있는 형태의 행렬이 아닙니다." << endl;
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
		cout << "연산할 수 있는 형태의 행렬이 아닙니다." << endl;
	}
}
void CalMatrix::mul_Matrix(CalMatrix another)
{
	if (this->n != another.m)
	{
		cout << "연산할 수 있는 형태의 행렬이 아닙니다." << endl;
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