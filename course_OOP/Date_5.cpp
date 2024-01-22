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
			break; // while 문 탈출
			continue; // 뒷 부분 시행 x, 처음으로 돌아감
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

/* for문
int main()
{
	int sum = 0;

	//for문
	for (int i = 1; i <= 100; i++) // i라는 변수는 for문 내에서만 존재하는 Local Variable
	{
		sum += i;
	}
	cout << sum << endl;


	////for문동작을 while문으로 표현
	//int i = 1; //초기화(initialization)

	//while (i <= 100) //반복조건 (condition)
	//{
	//	sum += i; //statement, block, body
	//	i++; //업데이트(modification)
	//}
}
*/

/*for문을 통한 매트릭스 구현
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


/*switch문
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