//Date_4 & Date_5

//#include <iostream>
//#include <iomanip>
//
//using namespace std;

/*기초문제 1
int main()
{
	int score;
	char grade = 'X';
	cout << "Enter your score: ";
	cin >> score;
	if (score >= 0 && score <= 100)
	{
		if (score >= 90)
			grade = 'A';
		else if (score >= 80)
		{
			grade = 'B';
		}
		else if (score >= 70)
		{
			grade = 'C';
		}
		else if (score >= 60)
		{
			grade = 'D';
		}
		else
		{
			grade = 'F';
		}
		cout << "Your grade is " << grade << endl;
	}
	else
	{
		cout << "The score (" << score << ") is invalid" << endl;
	}

	return 0;
}
*/

/*기초문제 2
int main()
{
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));

	while (count <= 20)
	{
		num *= 2;
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}

	return 0;
}
*/

/*기초문제 3
int main()
{
	int column = 1, row = 1;
	while (row <= 10)
	{
		while (column <= 10)
		{
			int num;
			if (row == column)
			{
				num = 1;
			}
			else
			{
				num = 0;
			}
			cout << setw(4) << num;
			column++;
		}
		cout << endl;
		row++;
		column = 1;
	}


	return 0;
}
*/

/*기초문제 4-1
int main()
{
	int num;

	while (true)
	{
		cout << "Enter the number (0, 10]: ";
		cin >> num;
		if (num > 0 && num <= 10)
		{
			break;
		}
	}

	cout << "Success!" << endl;
	return 0;
}
*/

/*기초문제 4-2
int main()
{
	int num;
	do
	{
		cout << "Enter the number (0, 10]: ";
		cin >> num;
	} while (!(num > 0 && num <= 10));
	cout << "Success!" << endl;
	return 0;
}
*/

/*기초문제 5
int main()
{
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int value = i * j;
			cout << setw(5) << value;
		}
		cout << endl;
	}

	return 0;
}
*/

/*기초문제 6
int main()
{
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch (key)
	{
	case 'P':
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
		break;
	}

	return 0;
}
*/

/*응용문제 1
int main()
{
	int number = 1;
	while (number > 0)
	{
		cout << "number: ";
		cin >> number;
		if (number % 2 == 1)
		{
			cout << number << "은 홀수입니다." << endl;
		}
		else
		{
			cout << number << "은 짝수입니다." << endl;
		}
	}
	cout << "잘못된 숫자입니다." << endl;

	return 0;
}
*/

/*응용문제 2
int main()
{
	int number;
	int count = 1, value = 0;
	cout << "number: ";
	cin >> number;

	while (count <= number)
	{
		value += count;
		count++;
	}

	cout << value << endl;

	return 0;
}
*/

/*응용문제 3
int main()
{
	int n;
	int count = 1, value = 0;
	cout << "number: ";
	cin >> n;

	while (count <= n)
	{
		if (count % 2 != 0 && count % 3 != 0)
		{
			value += count;
		}
		count++;
	}
	cout << "sum: " << value << endl;
}
*/

/*응용문제 4
int main()
{
	int number;

	while (true)
	{
		cout << "number: ";
		cin >> number;

		if (!(number > 0 && number < 10))
		{
			break;
		}

		for (int i = 1; i < 10; i++)
		{
			cout << number << '*' << i << " = " << number * i << "  ";
		}
		cout << endl;
	}

	cout << "잘못된 숫자입니다." << endl;
	return 0;
}
*/

/*응용문제 5
int Cal_gcd(int x, int y);

int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	cout << '(' << x << ',' << y << ')' << " = " << Cal_gcd(x, y) << endl;
	return 0;
}

int Cal_gcd(int x, int y)
{
	int temp_x = x, temp_y = y;
	if (temp_x % temp_y != 0)
	{
		x = temp_y;
		y = temp_x % temp_y;
		Cal_gcd(x, y);
	}
	else
	{
		return y;
	}
}
*/