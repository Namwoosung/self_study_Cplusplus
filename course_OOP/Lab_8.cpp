//Date_8 & Date_9

//#include <iostream>
//#include <vector>
//#include <string>
//#include <iomanip>
//
//using namespace std;

/*기초문제 1
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a = 10, b = 20;
	cout << a << ", " << b << endl;
	swap(&a, &b);
	cout << a << ", " << b << endl;
	return 0;
}
*/

/*기초문제 2
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }

int evaluate(int(*func)(int, int), int x, int y)
{
	return func(x, y);
}

int main()
{
	int (*func)(int, int);
	func = &sum;
	cout << func(10, 20) << endl;
	func = &mult;
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;
}
*/

/*기초문제 3
void print(const vector<int>& v)
{
	for (unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
}

int main()
{
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;
	print(vec);

	vec.push_back(400);
	print(vec);

	vec.pop_back();
	print(vec);

	cout << endl;
	for (int& elem : vec)
	{
		cout << "enter an element of vactor v: ";
		cin >> elem;
	}

	cout << endl << "[ vector v ]" << endl;
	for (int elem : vec)
	{
		cout << elem << '\t';
	}
	cout << endl;

	return 0;
}
*/

/*기초문제 4
bool is_prime(int num)
{
	if (num < 2)
	{
		return false;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

vector<int> primes(int lower, int upper)
{
	vector<int> v;
	for (int i = lower; i <= upper; i++)
	{
		if (is_prime(i))
		{
			v.push_back(i);
		}
	}
	return v;
}

int main()
{
	int lower = 10, upper = 100;
	vector<int> vec;
	vec = primes(10, 100);
	for (int elem : vec)
	{
		cout << elem << setw(5);
	}
	cout << endl;

	return 0;

}
*/

/*응용문제 1
void self_mul(int* x)
{
	*x = *x * *x;
}

int main()
{
	int number;

	cout << "input> ";
	cin >> number;

	self_mul(&number);
	cout << "제곱값> " << number << endl;
}
*/

/*응용문제 2
void change_string(string* str)
{
	string new_str;
	cout << "input> ";
	cin >> new_str;

	*str = new_str;
}

int main()
{
	string str = "This is default value";
	cout << "기본값 출력> " << str << endl;
	change_string(&str);
	cout << "변환된 값 출력> " << str << endl;
	return 0;
}
*/

/*응용문제 3
void swap_vec(vector<int>& vec)
{
	int temp;
	int len;
	len = vec.size();
	for (int i = 0; i < len / 2; i++)
	{
		temp = vec[i];
		vec[i] = vec[(len - 1) - i];
		vec[(len - 1) - i] = temp;
	}
}

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "기본 vector 값:" << endl;
	for (int elem : vec)
	{
		cout << elem << '\t';
	}
	cout << endl;

	swap_vec(vec);
	cout << "함수 실행 후 vector 값:" << endl;
	for (int elem : vec)
	{
		cout << elem << '\t';
	}
	cout << endl;
}
*/

/*응용문제 4
int inputGrade(float grade)
{
	cin >> grade;
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100)
	{
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		return (int)grade;
	}
}

int* topGrade(const vector<int>& grade)
{
	int* TopGrade = 0;
	int nowgrade = 0;

	for (unsigned int i = 0; i < grade.size() - 1; i++)
	{
		if (grade.at(i) >= grade.at(i + 1))
		{
			nowgrade = grade.at(i);
		}
		else
		{
			nowgrade = grade.at(i + 1);
		}
	}
	TopGrade = &nowgrade;
	return TopGrade;
}

int main()
{
	vector<int> grades;
	float _grade = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Input " << i << "-th grade(0 ~ 100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}

	cout << "Top Grade: " << *topGrade(grades) << endl;

	return 0;
}
*/