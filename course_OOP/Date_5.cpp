#include <iostream>
#include <iomanip>

using namespace std;

/* break, continue
int main()
{
	int sum = 0;
	int input;

	while (true)
	{
		cout << "Enter a number: ";
		cin >> input;

		if (input < 0)
		{
			break; // while �� Ż��
			continue; // �� �κ� ���� x, ó������ ���ư�
		}

		sum += input; // sum = sum + input
		cout << "Sum: " << sum << endl;
	}

	return 0;
}
*/

/* do-while
int main()
{
	int input;

	do
	{
		cout << "Enter a number[0 - 10]: ";
		cin >> input;
	} while ( !(input >= 0 && input <= 10) );

	cout << "Output: " << input << endl;

}
*/

/* for��
int main()
{
	int sum = 0;

	//for��
	for (int i = 1; i <= 100; i++) // i��� ������ for�� �������� �����ϴ� Local Variable
	{
		sum += i;
	}
	cout << sum << endl;


	////for�������� while������ ǥ��
	//int i = 1; //�ʱ�ȭ(initialization)

	//while (i <= 100) //�ݺ����� (condition)
	//{
	//	sum += i; //statement, block, body
	//	i++; //������Ʈ(modification)
	//}
}
*/

/*for���� ���� ��Ʈ���� ����
int main()
{
	int size;
	cout << "Enter a size: ";
	cin >> size;

	for (int row = 1; row <= size; row++)
	{
		for(int col = 1; col <= size; col++)
		{
			int val = row * col;

			cout << setw(5) << val;
		}
		cout << endl;
	}
}
*/


/*switch��
int main()
{
	char input;

	cout << "Enter a key: ";
	cin >> input;

	switch (input)
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
}
*/