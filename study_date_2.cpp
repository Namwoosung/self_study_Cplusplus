/* ���� ����
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

/* ���شٿ����
#include <iostream>

#include <ctime>

using namespace std;

int main()
{
	
	int MyChoice;
	cout << "100���� 200������ ������ �Է����ֽʽÿ�." << endl;
	cin >> MyChoice;
	int ComChoice;

	srand(time(NULL));
	ComChoice = rand() % 101 + 100;

	bool judge = true;
	while (judge)
	{
		if (MyChoice < ComChoice)
		{
			cout << "�Է��� ���ں��� Ů�ϴ�." << endl;
			cout << "100���� 200������ ������ �Է����ֽʽÿ�." << endl;
			cin >> MyChoice;
		}

		else if (MyChoice > ComChoice)
		{
			cout << "�Է��� ���ں��� �۽��ϴ�." << endl;
			cout << "100���� 200������ ������ �Է����ֽʽÿ�." << endl;
			cin >> MyChoice;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			break;
		}
	}
}
*/

/* ����(�Լ����)
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
	cout << "������ ���� ���� �Ͽ� �ΰ��� �Է��Ͻʽÿ�." << endl;
	cin >> x >> y;

	char sign;
	cout << "���������� ��ȣ�� ����Ͽ� �Է��Ͻʽÿ�." << endl;
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

/* ����(�Լ� ����,���� �κ� ����)
#include <iostream>

using namespace std;

int plus_number(int x, int y);
int subtract(int x, int y);
int multiple(int x, int y);
int divide(int x, int y);

int main()
{
	int x, y, z;
	cout << "������ ���� ���� �Ͽ� �ΰ��� �Է��Ͻʽÿ�." << endl;
	cin >> x >> y;

	char sign;
	cout << "���������� ��ȣ�� ����Ͽ� �Է��Ͻʽÿ�." << endl;
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

/* �Լ� �����ε�
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

/* �� �ٲٴ� �Լ�
#include <iostream>

using namespace std;

void swap(int& x, int& y);

int main()
{
	int x = 10;
	int y = 20;

	swap(x, y);

	cout << "�Լ� x��" << x << endl;
	cout << "�Լ� y��" << y << endl;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
*/

/* ���丮��(�ݺ��� �̿�)
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "���丮�� �� ���� �Է��Ͻʽÿ�.";
	cin >> number;

	int value = 1;

	for (int i = number; i > 0; i--)
	{
		value *= i;
	}
	cout << value << endl;
}
*/

/* ���丮��(����Լ�)
#include <iostream>

using namespace std;

int facto(int number);

int main()
{
	int number;
	cout << "���丮�� �� ���� �Է��Ͻʽÿ�.";
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

/* �Ǻ���ġ ����(�ݺ���)
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "�Ǻ���ġ ������ �˰���� ������ �Է��Ͻʽÿ�." << endl;
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

/* �Ǻ���ġ ����(����Լ�)
#include <iostream>

using namespace std;

int fibo(int number);

int main()
{
	int number;
	cout << "�Ǻ���ġ ������ �˰���� ������ �Է��Ͻʽÿ�." << endl;
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

/* �ּҰ���� �ִ����� ���ϱ�(�ݺ���)
#include <iostream>

using namespace std;

int main()
{
	int given_number_1, given_number_2;
	cout << "���� 2���� ���Ἥ �Է��Ͻʽÿ�." << endl;
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
				cout << "�ִ�������" << given_number_2;
				cout << "�ּҰ������" << number_1 * number_2 / given_number_2;
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
				cout << "�ִ�������" << given_number_1;
				cout << "�ּҰ������" << number_1 * number_2 / given_number_1;
			}
			else
			{
				given_number_2 = left_number;
			}
		}
		else
		{
			judge = false;
			cout << "�ִ�������" << given_number_1;
			cout << "�ּҰ������" << number_1 * number_2 / given_number_1;
		}
		
	}
}
*/

/* �ִ����� �ּҰ���� (��͹�)
#include <iostream>

using namespace std;

int GCD(int given_number_1, int given_number_2);
int GCM(int given_number_1, int given_number_2);

int main()
{
	int given_number_1, given_number_2;
	cout << "���� 2���� �����Ͽ� �Է��Ͻʽÿ�." << endl;
	cin >> given_number_1 >> given_number_2;

	cout << "�ִ�������" << GCD(given_number_1, given_number_2) << endl;
	cout << "�ּҰ������" << GCM(given_number_1, given_number_2) << endl;
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

/* �Ҽ��Ǻ�
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "�Ҽ������� �Ǻ��� ���� �Է����ֽʽÿ�." << endl;
	cin >> number;
	
	if (number == 1 || number == 2)
	{
		cout << "�Ҽ��Դϴ�." << endl;
	}
	else
	{
		for (int i = 2; i < number ; i++)
		{
			if (number % i == 0)
			{
				cout << "�Ҽ��� �ƴմϴ�." << endl;
				break;
			}
			if (i == number - 1)
			{
				cout << "�Ҽ��Դϴ�." << endl;
			}
		}
	}
}
*/

/* ��ǰ���(�����Ѱ�)
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
		cout << "[��ǰ���]���ĺ��ϳ��� �Է��ϼ���!" << endl;
		cin >> given_sign;

		for (int i = 0; i < 7; i++)
		{
			if (given_sign == answer[i])
			{
				cout << "������ϴ�!" << endl;
				arr[i] = given_sign;
				cout << arr << endl;
				score += 1;
				cout << "life:" << life << endl;
				break;
			}

			if (i == 6)
			{
				cout << "Ʋ�Ƚ��ϴ�!" << endl;
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
				cout << "�����ϼ̽��ϴ�!" << endl;
			}
			else
			{
				cout << "�����ϼ̽��ϴ�!" << endl;
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
			cout << "[��ǰ���]���ĺ��ϳ��� �Է��ϼ���!" << endl;
			cin >> given_sign;

			for (int i = 0; i < 7; i++)
			{
				if (given_sign == answer[i])
				{
					cout << "������ϴ�!" << endl;
					arr[i] = given_sign;
					cout << arr << endl;
					score += 1;
					cout << "life:" << life << endl;
					break;
				}

				if (i == 6)
				{
					cout << "Ʋ�Ƚ��ϴ�!" << endl;
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
					cout << "�����ϼ̽��ϴ�!" << endl;
				}
				else
				{
					cout << "�����ϼ̽��ϴ�!" << endl;
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
			cout << "[��ǰ���]���ĺ��ϳ��� �Է��ϼ���!" << endl;
			cin >> given_sign;

			for (int i = 0; i < 6; i++)
			{
				if (given_sign == answer[i])
				{
					cout << "������ϴ�!" << endl;
					arr[i] = given_sign;
					cout << arr << endl;
					score += 1;
					cout << "life:" << life << endl;
					break;
				}

				if (i == 5)
				{
					cout << "Ʋ�Ƚ��ϴ�!" << endl;
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
					cout << "�����ϼ̽��ϴ�!" << endl;
				}
				else
				{
					cout << "�����ϼ̽��ϴ�!" << endl;
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
		cout << "[��ǰ���]���ĺ��ϳ��� �Է��ϼ���!" << endl;
		cin >> given_sign;

		for (int i = 0; i < 8; i++)
		{
			if (given_sign == answer[i])
			{
				cout << "������ϴ�!" << endl;
				arr[i] = given_sign;
				cout << arr << endl;
				score += 1;
				cout << "life:" << life << endl;
				break;
			}

			if (i == 7)
			{
				cout << "Ʋ�Ƚ��ϴ�!" << endl;
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
				cout << "�����ϼ̽��ϴ�!" << endl;
			}
			else
			{
				cout << "�����ϼ̽��ϴ�!" << endl;
			}
		}
	}
}