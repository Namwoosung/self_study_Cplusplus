/* 이름출력
#include  <iostream> 

using namespace std;

int main()
{
	char name[20];
	cin >> name;
	cout << "my name is " << name;
	return 0;
}
*/

/* 짝수 홀수 판단
#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;
	if (number % 2 == 0)
	{
		cout << "짝수입니다.";
	}
	else
	{
		cout << "홀수입니다";
	}
	return 0;
}
*/

/* 계산기
#include <iostream>

using namespace std;

int main()
{
	char sign;
	float number1, number2;
	cout << "숫자 두개를 띄어써서 입력하십시오.";
	cin >> number1 >> number2;
	cout << "연산자를 입력하십시오.";
	cin >> sign;

	switch (sign)
	{
	case '+':
		cout << number1 + number2;
		break;
	case '-':
		cout << number1 - number2;
		break;
	case '*':
		cout << number1 * number2;
		break;
	case '/':
		cout << number1 / number2;
		break;
	}
}
*/

/* 정사각형, 직각삼각형, 역삼각형
#include <iostream>

using namespace std;

int main()
{
	char star = '*';
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << star;
		}
		
		cout << endl;
	}
	cout << "--------" << endl;

	int number = 5;
	for (int i = 5; i > 0; i--)
	{
		for (int j = number; j > 0; j--)
		{
			cout << star;
		}
		cout << endl;
		number -= 1;
	}
	cout << "--------" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << star;
		}
		cout << endl;
	}
}
*/

/* 계산기(q누르면 중지)
#include <iostream>

using namespace std;

int main()
{
	bool blsRunning = true;
	while (blsRunning)
	{
		cout << "연산자 입력시 q를 입력하면 프로그램이 종료됩니다." << endl;
		
		char sign;
		float number1, number2;
		cout << "숫자 두개를 띄어써서 입력하십시오.";
		cin >> number1 >> number2;
		cout << "연산자를 입력하십시오.";
		cin >> sign;

		if (sign == 'q')
		{
			blsRunning = false;
		}

		switch (sign)
		{
		case '+':
			cout << number1 + number2;
			break;
		case '-':
			cout << number1 - number2;
			break;
		case '*':
			cout << number1 * number2;
			break;
		case '/':
			cout << number1 / number2;
			break;
		}
	}
}
*/

/* 이등변 별찍기
#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j < 10; j ++)
		{
			if (5 - i <= j && j <= 5 + i)
			{
				cout << '*';
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
*/

/* 정수 반올림
#include <iostream>

using namespace std;

int main()
{
	int value;
	cout << "반올림하고싶은 정수를 입력해주세요.";
	cin >> value;

	int value_one = value % 10;

	if (value_one < 5)
	{
		cout << value - value_one;
	}
	else
	{
		cout << value -value_one + 10;
	}

}
*/

/* 소수반올림
#include <iostream>

using namespace std;

int main()
{
	float value;
	cout << "반올림하고싶은 실수를 입력해주십시오.";
	cin >> value;

	float value_test = value * 10;
	int value_one = (int)value_test % 10;

	if (value_one < 5)
	{
		cout << int(value);
	}
	else
	{
		cout << int(value) + 1;
	}

}
*/

/* 삼항 연산자를 이용한 짝홀 판단
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "숫자를 입력해주십시오.";
	cin >> number;
	int number_test = number % 2;
	bool judge = (number_test > 0) ? (true) : (false);
	if (judge == true)
	{
		cout << "홀수입니다.";
	}
	else
	{
		cout << "짝수입니다.";
	}
}
*/

/* 가위바위보
#include <iostream>

using namespace std;

int main()
{
	char ComChoice;
	int ComNumber = 0;
	bool judge = true;
	while (judge)
	{
		char MyChoice;
		cout << "가위(s),바위(r),보(p) 중 하나를 고르십시오" << endl << "q를 입력하면 프로그램이 종료됩니다.";
		cin >> MyChoice;
		ComNumber += 1;

		if (MyChoice == 'q')
		{
			judge = false;
		}
		if (ComNumber % 3 == 1)
		{
			ComChoice = 'r';
		}
		else if (ComNumber % 3 == 2)
		{
			ComChoice = 's';
		}
		else
		{
			ComChoice = 'p';
		}

		cout << "당신의 선택:" << MyChoice << endl;
		cout << "컴퓨터의 선택:" << ComChoice << endl;

		if ((MyChoice == 'r' && ComChoice == 's') || (MyChoice == 's' && ComChoice == 'p') || (MyChoice == 'p' && ComChoice == 'r'))
		{
			cout << "Win" << endl;
		}
		else if (MyChoice == ComChoice)
		{
			cout << "Draw" << endl;
		}
		else
		{
			cout << "Lose" << endl;
		}
	}
}
*/