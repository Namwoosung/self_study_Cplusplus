#include <iostream>
#include <iomanip>

using namespace std;

/* bool 자료형
//bool 자료형 -> false면 0, true면 1
int main()
{
	bool a = true;
	bool b = (10 > 5);
	bool c = 0.01; //bool 자료형에 0대입하면 false로 인식, 0이아닌 모든수는 true(음수,소수 상관x)
	cout << a << endl << b << endl << c << endl;

	return 0;
}
*/

/*조건문
int main()
{
	int score;
	char grade = 'X';
	cout << "Enter the Score[0-100]: ";
	cin >> score;
	if (score >= 0 && score <= 100)
	{
		//if문 내에서 시행될 명령어가 한줄이라면 {}를 사용하지 않아도 됨
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
		else
		{
			grade = 'F';
		}
		cout << "Your Score is " << grade << endl;
	}
	else
	{
		cout << "The score (" << score << ") is invalid" << endl;
	}

	return 0;
}
*/

/*반복문-while
int main()
{
	int sum = 0, i = 1;
	int n;
	cout << "Enter the number: ";
	cin >> n;
	while (i <= n)
	{
		sum += i;
		cout << i << '\t' << sum << endl;
		i++;
	}

	return 0;
}
*/

/*반복문-while
int main()
{
	int row = 1, col = 1;
	while (row <= 5)
	{
		while (col <= 5)
		{
			int val = row * col;
			//int val = (row > col ? row : col);
			//int val = 0;
			if (row == col)
			{
				val = 1;
			}
			cout << setw(4) << val;
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
}
*/