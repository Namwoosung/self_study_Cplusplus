#include <iostream>
#include <iomanip>

using namespace std;

/* bool �ڷ���
//bool �ڷ��� -> false�� 0, true�� 1
int main()
{
	bool a = true;
	bool b = (10 > 5);
	bool c = 0.01; //bool �ڷ����� 0�����ϸ� false�� �ν�, 0�̾ƴ� ������ true(����,�Ҽ� ���x)
	cout << a << endl << b << endl << c << endl;

	return 0;
}
*/

/*���ǹ�
int main()
{
	int score;
	char grade = 'X';
	cout << "Enter the Score[0-100]: ";
	cin >> score;
	if (score >= 0 && score <= 100)
	{
		//if�� ������ ����� ��ɾ �����̶�� {}�� ������� �ʾƵ� ��
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

/*�ݺ���-while
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

/*�ݺ���-while
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