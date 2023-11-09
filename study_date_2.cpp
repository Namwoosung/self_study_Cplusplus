/* 난수 생성
#include <iostream>

#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int random_number;
	random_number = rand() % 101 + 100;
	cout << random_number;
}
*/

/* 업앤다운게임
#include <iostream>

#include <ctime>

using namespace std;

int main()
{
	
	int MyChoice;
	cout << "100부터 200까지의 정수를 입력해주십시오." << endl;
	cin >> MyChoice;
	int ComChoice;

	srand(time(NULL));
	ComChoice = rand() % 101 + 100;

	bool judge = true;
	while (judge)
	{
		if (MyChoice < ComChoice)
		{
			cout << "입력한 숫자보다 큽니다." << endl;
			cout << "100부터 200까지의 정수를 입력해주십시오." << endl;
			cin >> MyChoice;
		}

		else if (MyChoice > ComChoice)
		{
			cout << "입력한 숫자보다 작습니다." << endl;
			cout << "100부터 200까지의 정수를 입력해주십시오." << endl;
			cin >> MyChoice;
		}
		else
		{
			cout << "정답입니다." << endl;
			break;
		}
	}
}
*/

/* 연산(함수사용)
#include <iostream>

using namespace std;

int plus_number(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiple(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

int main()
{
	int x, y, z;
	cout << "연산할 수를 띄어쓰기 하여 두개를 입력하십시오." << endl;
	cin >> x >> y;

	char sign;
	cout << "연산종류를 기호를 사용하여 입력하십시오." << endl;
	cin >> sign;

	switch (sign)
	{
	case '+':
		z = plus_number(x, y);
		cout << z << endl;
		break;
	case '-':
		z = subtract(x, y);
		cout << z << endl;
		break;
	case '*':
		z = multiple(x, y);
		cout << z << endl;
		break;
	case '/':
		z = divide(x, y);
		cout << z << endl;
		break;
	}
}
*/

/* 연산(함수 선언,정의 부분 구분)
#include <iostream>

using namespace std;

int plus_number(int x, int y);
int subtract(int x, int y);
int multiple(int x, int y);
int divide(int x, int y);

int main()
{
	int x, y, z;
	cout << "연산할 수를 띄어쓰기 하여 두개를 입력하십시오." << endl;
	cin >> x >> y;

	char sign;
	cout << "연산종류를 기호를 사용하여 입력하십시오." << endl;
	cin >> sign;

	switch (sign)
	{
	case '+':
		z = plus_number(x, y);
		cout << z << endl;
		break;
		
	case '-':
		z = subtract(x, y);
		cout << z << endl;
		break;

	case '*':
		z = multiple(x, y);
		cout << z << endl;
		break;
	case '/':
		z = divide(x, y);
		cout << z << endl;
		break;
}
int plus_number(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}
int multiple(int x, int y)
{
	return x * y;
}
int divide(int x, int y)
{
	return x / y;
}
*/

/* 함수 오버로드
#include <iostream>

using namespace std;

int Plus(int x, int y)
{
	return x + y;
}

float Plus(float x, float y)
{
	return x + y;
}

double Plus(double x, double y)
{
	return x + y;
}

int maid()
{
	float z = Plus(13.2, 12.5);
	cout << z;
}
*/

/* 값 바꾸는 함수
#include <iostream>

using namespace std;

void swap(int& x, int& y);

int main()
{
	int x = 10;
	int y = 20;

	swap(x, y);

	cout << "함수 x는" << x << endl;
	cout << "함수 y는" << y << endl;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
*/

/* 팩토리얼(반복문 이용)
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "팩토리얼 할 수를 입력하십시오.";
	cin >> number;

	int value = 1;

	for (int i = number; i > 0; i--)
	{
		value *= i;
	}
	cout << value << endl;
}
*/

/* 팩토리얼(재귀함수)
#include <iostream>

using namespace std;

int facto(int number);

int main()
{
	int number;
	cout << "팩토리얼 할 수를 입력하십시오.";
	cin >> number;
	cout << facto(number);
}

int facto(int number)
{

	if (number <= 0)
	{
		return 1;
	}
	else
	{
		return number * facto(number - 1);
	}
}
*/

/* 피보나치 수열(반복문)
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "피보나치 수열의 알고싶은 순서를 입력하십시오." << endl;
	cin >> number;
	int value_1 = 1;
	int value_2 = 1;
	int value = 0;

	if (number <= 2)
	{
		cout << "1" << endl;
	}
	else
	{
		for (int i = 3; i <= number; i++)
		{
			value = value_1 + value_2;
			value_2 = value_1;
			value_1 = value;
		}
		cout << value << endl;
	}
}
*/

/* 피보나치 수열(재귀함수)
#include <iostream>

using namespace std;

int fibo(int number);

int main()
{
	int number;
	cout << "피보나치 수열의 알고싶은 순서를 입력하십시오." << endl;
	cin >> number;
	cout << fibo(number);
}

int fibo(int number)
{
	if (number <= 0)
	{
		return 0;
	}
	else if (1 <= number && number <= 2)
	{
		return 1;
	}
	else
	{
		return fibo(number - 1) + fibo(number - 2);
	}
}
*/

/* 최소공배수 최대공약수 구하기(반복문)
#include <iostream>

using namespace std;

int main()
{
	int given_number_1, given_number_2;
	cout << "숫자 2개를 띄어써서 입력하십시오." << endl;
	cin >> given_number_1 >> given_number_2;
	int left_number;

	int number_1 = given_number_1;
	int number_2 = given_number_2;

	bool judge = true;
	while (judge)
	{
		if (given_number_1 > given_number_2)
		{
			left_number = given_number_1 % given_number_2;
			if (left_number == 0)
			{
				judge = false;
				cout << "최대공약수는" << given_number_2;
				cout << "최소공배수는" << number_1 * number_2 / given_number_2;
			}
			else
			{
				given_number_1 = left_number;
			}
		}
		else if (given_number_1 < given_number_2)
		{
			left_number = given_number_2 % given_number_1;
			if(left_number == 0)
			{
				judge = false;
				cout << "최대공약수는" << given_number_1;
				cout << "최소공배수는" << number_1 * number_2 / given_number_1;
			}
			else
			{
				given_number_2 = left_number;
			}
		}
		else
		{
			judge = false;
			cout << "최대공약수는" << given_number_1;
			cout << "최소공배수는" << number_1 * number_2 / given_number_1;
		}
		
	}
}
*/

/* 최대공약수 최소공배수 (재귀문)
#include <iostream>

using namespace std;

int GCD(int given_number_1, int given_number_2);
int GCM(int given_number_1, int given_number_2);

int main()
{
	int given_number_1, given_number_2;
	cout << "숫자 2개를 띄어쓰기하여 입력하십시오." << endl;
	cin >> given_number_1 >> given_number_2;

	cout << "최대공약수는" << GCD(given_number_1, given_number_2) << endl;
	cout << "최소공배수는" << GCM(given_number_1, given_number_2) << endl;
}

int GCD(int given_number_1, int given_number_2)
{
	if (given_number_1 > given_number_2)
	{
		given_number_1 = given_number_1 % given_number_2;
		if (given_number_1 == 0)
		{
			return given_number_2;
		}
		else
		{
			GCD(given_number_1, given_number_2);
		}
	}
	else if (given_number_1 < given_number_2)
	{
		given_number_2 = given_number_2 % given_number_1;
		if (given_number_2 == 0)
		{
			return given_number_1;
		}
		else
		{
			GCD(given_number_1, given_number_2);
		}
	}
	else
	{
		return given_number_1;
	}
}

int GCM(int given_number_1, int given_number_2)
{
	return given_number_1 * given_number_2 / GCD(given_number_1, given_number_2);
}
*/

/* 소수판별
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "소수인지를 판별할 수를 입력해주십시오." << endl;
	cin >> number;
	
	if (number == 1 || number == 2)
	{
		cout << "소수입니다." << endl;
	}
	else
	{
		for (int i = 2; i < number ; i++)
		{
			if (number % i == 0)
			{
				cout << "소수가 아닙니다." << endl;
				break;
			}
			if (i == number - 1)
			{
				cout << "소수입니다." << endl;
			}
		}
	}
}
*/

/* 행맨게임(정답한개)
#include <iostream>

using namespace std;

int main()
{
	char arr[7] = { '_','_','_','_','_','_','\0' };
	char answer[7] = { 'p','y','t','h','o','n','\0'};
	bool chance = true;
	int life = 5;
	int score = 0;
	
	cout << arr << endl;
	while (chance)
	{
		char given_sign;
		cout << "[행맨게임]알파벳하나를 입력하세요!" << endl;
		cin >> given_sign;

		for (int i = 0; i < 7; i++)
		{
			if (given_sign == answer[i])
			{
				cout << "맞췄습니다!" << endl;
				arr[i] = given_sign;
				cout << arr << endl;
				score += 1;
				cout << "life:" << life << endl;
				break;
			}

			if (i == 6)
			{
				cout << "틀렸습니다!" << endl;
				life -= 1;
				cout << arr << endl;
				cout << "life:" << life << endl;
			}
		}

		if (life == 0 || score == 6)
		{
			chance = false;
			if (life == 0)
			{
				cout << "실패하셨습니다!" << endl;
			}
			else
			{
				cout << "성공하셨습니다!" << endl;
			}
		}
	}
}
*/

#include <iostream>

#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int number_choice = rand() % 3;
	if (number_choice == 0)
	{
		char arr[7] = { '_','_','_','_','_','_','\0' };
		char answer[7] = { 'p','y','t','h','o','n','\0' };
		bool chance = true;
		int life = 5;
		int score = 0;

		cout << arr << endl;
		while (chance)
		{
			char given_sign;
			cout << "[행맨게임]알파벳하나를 입력하세요!" << endl;
			cin >> given_sign;

			for (int i = 0; i < 7; i++)
			{
				if (given_sign == answer[i])
				{
					cout << "맞췄습니다!" << endl;
					arr[i] = given_sign;
					cout << arr << endl;
					score += 1;
					cout << "life:" << life << endl;
					break;
				}

				if (i == 6)
				{
					cout << "틀렸습니다!" << endl;
					life -= 1;
					cout << arr << endl;
					cout << "life:" << life << endl;
				}
			}

			if (life == 0 || score == 6)
			{
				chance = false;
				if (life == 0)
				{
					cout << "실패하셨습니다!" << endl;
				}
				else
				{
					cout << "성공하셨습니다!" << endl;
				}
			}
		}
	}
	else if (number_choice == 1)
	{
		char arr[6] = { '_','_','_','_','_','\0' };
		char answer[6] = { 'h','o','u','s','e','\0' };
		bool chance = true;
		int life = 5;
		int score = 0;

		cout << arr << endl;
		while (chance)
		{
			char given_sign;
			cout << "[행맨게임]알파벳하나를 입력하세요!" << endl;
			cin >> given_sign;

			for (int i = 0; i < 6; i++)
			{
				if (given_sign == answer[i])
				{
					cout << "맞췄습니다!" << endl;
					arr[i] = given_sign;
					cout << arr << endl;
					score += 1;
					cout << "life:" << life << endl;
					break;
				}

				if (i == 5)
				{
					cout << "틀렸습니다!" << endl;
					life -= 1;
					cout << arr << endl;
					cout << "life:" << life << endl;
				}
			}

			if (life == 0 || score == 5)
			{
				chance = false;
				if (life == 0)
				{
					cout << "실패하셨습니다!" << endl;
				}
				else
				{
					cout << "성공하셨습니다!" << endl;
				}
			}
		}
	}
	else
	{
	char arr[8] = { '_','_','_','_','_','_','_','\0' };
	char answer[8] = { 'c','e','n','t','u','r','y','\0' };
	bool chance = true;
	int life = 5;
	int score = 0;

	cout << arr << endl;
	while (chance)
	{
		char given_sign;
		cout << "[행맨게임]알파벳하나를 입력하세요!" << endl;
		cin >> given_sign;

		for (int i = 0; i < 8; i++)
		{
			if (given_sign == answer[i])
			{
				cout << "맞췄습니다!" << endl;
				arr[i] = given_sign;
				cout << arr << endl;
				score += 1;
				cout << "life:" << life << endl;
				break;
			}

			if (i == 7)
			{
				cout << "틀렸습니다!" << endl;
				life -= 1;
				cout << arr << endl;
				cout << "life:" << life << endl;
			}
		}

		if (life == 0 || score == 7)
		{
			chance = false;
			if (life == 0)
			{
				cout << "실패하셨습니다!" << endl;
			}
			else
			{
				cout << "성공하셨습니다!" << endl;
			}
		}
	}
}