/* �̸����
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

/* ¦�� Ȧ�� �Ǵ�
#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;
	if (number % 2 == 0)
	{
		cout << "¦���Դϴ�.";
	}
	else
	{
		cout << "Ȧ���Դϴ�";
	}
	return 0;
}
*/

/* ����
#include <iostream>

using namespace std;

int main()
{
	char sign;
	float number1, number2;
	cout << "���� �ΰ��� ���Ἥ �Է��Ͻʽÿ�.";
	cin >> number1 >> number2;
	cout << "�����ڸ� �Է��Ͻʽÿ�.";
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

/* ���簢��, �����ﰢ��, ���ﰢ��
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

/* ����(q������ ����)
#include <iostream>

using namespace std;

int main()
{
	bool blsRunning = true;
	while (blsRunning)
	{
		cout << "������ �Է½� q�� �Է��ϸ� ���α׷��� ����˴ϴ�." << endl;
		
		char sign;
		float number1, number2;
		cout << "���� �ΰ��� ���Ἥ �Է��Ͻʽÿ�.";
		cin >> number1 >> number2;
		cout << "�����ڸ� �Է��Ͻʽÿ�.";
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

/* �̵ �����
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

/* ���� �ݿø�
#include <iostream>

using namespace std;

int main()
{
	int value;
	cout << "�ݿø��ϰ���� ������ �Է����ּ���.";
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

/* �Ҽ��ݿø�
#include <iostream>

using namespace std;

int main()
{
	float value;
	cout << "�ݿø��ϰ���� �Ǽ��� �Է����ֽʽÿ�.";
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

/* ���� �����ڸ� �̿��� ¦Ȧ �Ǵ�
#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "���ڸ� �Է����ֽʽÿ�.";
	cin >> number;
	int number_test = number % 2;
	bool judge = (number_test > 0) ? (true) : (false);
	if (judge == true)
	{
		cout << "Ȧ���Դϴ�.";
	}
	else
	{
		cout << "¦���Դϴ�.";
	}
}
*/

/* ����������
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
		cout << "����(s),����(r),��(p) �� �ϳ��� ���ʽÿ�" << endl << "q�� �Է��ϸ� ���α׷��� ����˴ϴ�.";
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

		cout << "����� ����:" << MyChoice << endl;
		cout << "��ǻ���� ����:" << ComChoice << endl;

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