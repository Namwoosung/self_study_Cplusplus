/*구조체 만들고 요소 입력받아 파일에 저장
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	struct student
	{
		string name;
		int age;
		int number;
	};

	student stu;

	cout << "이름을 입력해주세요." << endl;
	cin >> stu.name;
	cout << "나이를 입력해주세요." << endl;
	cin >> stu.age;
	cout << "학번를 입력해주세요." << endl;
	cin >> stu.number;

	ofstream fout;
	fout.open("student.txt");

	fout << stu.name << endl << stu.age << endl << stu.number << endl;

	fout.close();
}
*/

/* 배열만들고 요소 입력받아 파일에 저장
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string student[100] = { "", };

	cout << "이름을 입력해주세요." << endl;
	cin >> student[0];
	cout << "나이를 입력해주세요." << endl;
	cin >> student[1];
	cout << "학번를 입력해주세요." << endl;
	cin >> student[2];

	ofstream fout;
	fout.open("student.txt");

	fout << student[0] << endl << student[1] << endl << student[2] << endl;

	fout.close();
}
*/

/* 파일불러와서 배열에 저장, 출력
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("student.txt");

	string student[100] = { "", };

	char text[100];
	int number = 0;
	while (fin.getline(text, 100))
	{
		student[number] = text;
		number += 1;
	}

	fin.close();

	for (int i = 0; i < 100; i++)
	{
		cout << student[i] << endl;

		if (student[i] == "")
		{
			break;
		}
	}
}
*/

/* 랜덤행렬 생산, 행렬합, 행렬곱
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int Matrix1[2][2];
	int Matrix2[2][2];

	srand(time(NULL));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Matrix1[i][j] = rand() % 10;
			Matrix2[i][j] = rand() % 10;
		}
	}

	cout << "첫번째 행렬" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Matrix1[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "두번째 행렬" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Matrix2[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "행렬합" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Matrix1[i][j] + Matrix2[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "행렬곱" << endl;
	for (int i = 0; i < 2; i++)
	{
		int value = 0;
		int test_1 = 0;
		int test_2 = 1;

		for (int j = 0; j < 2; j++)
		{
			value += Matrix1[i][j] * Matrix2[j][test_1];
		}
		cout << value << '\t';

		value = 0;
		for (int k = 0; k < 2; k++)
		{
			value += Matrix1[i][k] * Matrix2[k][test_2];
		}
		cout << value << '\n';
	}
}
*/

/*포인터 변수지정
#include <iostream>

using namespace std;

int main()
{
	int number_1;
	int number_2;
	int* number_ptr = NULL;

	number_ptr = &number_1;
	*number_ptr = 10;
	number_ptr = &number_2;
	*number_ptr = 20;

	cout << number_1 << endl << number_2;
	return 0;
}
*/

/* 인트주소 4칸에 1바이트 변수넣기
#include <iostream>

using namespace std;

int main()
{
	int number;
	char* c_ptr;
	c_ptr = (char*)&number;
	char r, g, b, a;
	r = 0x00;
	g = 0xAA;
	b = 0xBB;
	a = 0xCC;
	*c_ptr = r;
	*(c_ptr + 1) = g;
	*(c_ptr + 2) = b;
	*(c_ptr + 3) = a;

	cout << hex << number;
}
*/

/*주소를 이용한 스왑하기
#include <iostream>

using namespace std;

void swap(int* x_p, int* y_p);

int main()
{
	int x = 10;
	int y = 20;
	int* x_ptr = &x;
	int* y_ptr = &y;

	swap(x_ptr, y_ptr);

	cout << x << '\t' << y;
}

void swap(int* x_p, int* y_p)
{
	int temp;

	temp = *x_p;
	*x_p = *y_p;
	*y_p = temp;
}
*/

/*동적활당 확인
#include <iostream>

using namespace std;

int* NewInt();

int main()
{
	int* new_number = NewInt();
	cout << new_number;
	delete new_number;
}

int* NewInt()
{
	int* grade = new int[10];
	return grade;
}
*/

/* 달팽이 배열 
#include <iostream>

using namespace std;

int main()
{
	bool judge = true;
	int user_choice;
	while (judge)
	{
		cout << "달팽이 배열의 크기를 입력하세요.0이하면 종료됩니다." << endl;
		cin >> user_choice;

		int number = 1;
		int standard_1 = 0;
		int standard_2 = 1;
		int standard_3 = 1;

		bool count_judge = true;

		if (user_choice <= 0)
		{
			judge = false;
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		
		int** arr = new int* [user_choice];
		for (int i = 0; i < user_choice; i++)
		{
			arr[i] = new int[user_choice];
		}
		
		for (int i = 0; i < user_choice; i++)
		{
			for (int j = 0; j < user_choice; j++)
			{
				arr[i][j] = 1;
			}
		}	

		while (count_judge)
		{
			for (int i = standard_1; i <= user_choice - standard_3; i++)
			{
				arr[standard_1][i] = number;
				number += 1;
			}
			for (int i = standard_2; i <= user_choice - standard_3; i++)
			{
				arr[i][user_choice - standard_2] = number;
				number += 1;
			}
			standard_3 += 1;
			for (int i = user_choice - standard_3; i >= standard_1; i--)
			{
				arr[user_choice - standard_1 - 1][i] = number;
				number += 1;
			}
			for (int i = user_choice - standard_3; i >= standard_2; i--)
			{
				arr[i][standard_2 - 1] = number;
				number += 1;
			}
			standard_1 += 1;
			standard_2 += 1;

			if (number >= user_choice * user_choice)
			{
				count_judge = false;
			}
		}
		
		if (user_choice % 2 == 1)
		{
			arr[user_choice / 2][user_choice / 2] = user_choice * user_choice;
		}

		for (int i = 0; i < user_choice; i++)
		{
			for (int j = 0; j < user_choice; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
*/

/*가위바위보 프로젝트
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
# include "calc.h"
#include <stdlib.h>

using namespace std;

int main()
{

	string user_name;
	cout << "당신의 이름을 입력하십시오," << endl;
	cin >> user_name;

	string all_user[100];
	int all_scores[100] = { 0, };
	int num_line = 0;
	int test_number = 0;
	int user_number;
	int number_value_user = 0;
	int number_value_score = 0;

	string* curr_user_ptr;

	struct user
	{
		string name;
		int max_scores;
	};

	bool name_check = false;

	ifstream fin("user.txt");

	char check[100];

	while (fin.getline(check, 100))
	{
		test_number += 1;
		num_line += 1;
		if (test_number % 2 == 1)
		{
			all_user[number_value_user] = check;
			number_value_user += 1;
		}
		else
		{
			all_scores[number_value_score] = atoi(check);
			number_value_score += 1;
		}
		if (user_name == check)
		{
			cout << "이용자 확인되었습니다" << endl;
			name_check = true;
			user_number = test_number / 2;
		}
	}
	fin.close();

	int num_user = num_line / 2;

	if (name_check == false)
	{
		cout << "신규이용자이십니다." << endl;
		all_user[num_user] = user_name;
		all_scores[num_user] = 0;
		user_number = num_user;
		num_user += 1;
	}

	srand(time(NULL));

	char ComChoice;
	bool judge = true;
	int scores = 0;

	while (judge)
	{
		int ComNumber = rand() % 3;

		char MyChoice;
		cout << "가위(s),바위(r),보(p) 중 하나를 고르십시오" << endl << "q를 입력하면 프로그램이 종료됩니다.";
		cin >> MyChoice;

		if (ComNumber == 1)
		{
			ComChoice = 'r';
		}
		else if (ComNumber == 2)
		{
			ComChoice = 's';
		}
		else
		{
			ComChoice = 'p';
		}

		print(MyChoice, ComChoice);
		judge_winner(MyChoice, ComChoice, scores, judge, all_scores[user_number]);
	}
	if (all_scores[user_number] < scores)
	{
		all_scores[user_number] = scores;
	}
	ofstream fout;
	fout.open("user.txt");

	for (int i = 0; i < num_user; i++)
	{
		fout << all_user[i] << endl;
		fout << all_scores[i] << endl;
	}

	fout.close();
}

void print(char MyChoice, char ComChoice)
{
	cout << "당신의 선택:" << MyChoice << endl;
	cout << "컴퓨터의 선택:" << ComChoice << endl;
	return;
}

void judge_winner(char MyChoice, char ComChoice, int& scores, bool& judge, int max_score)
{
	if ((MyChoice == 'r' && ComChoice == 's') || (MyChoice == 's' && ComChoice == 'p') || (MyChoice == 'p' && ComChoice == 'r'))
	{
		cout << "Win" << endl;
		scores += 1;
		cout << "현재점수:" << scores << endl;
	}
	else if (MyChoice == ComChoice)
	{
		cout << "Draw" << endl;
		cout << "현재점수:" << scores << endl;
	}
	else
	{
		cout << "Lose" << endl;
		cout << "당신의 점수:" << scores << endl;
		cout << "과거 당신의 최고점수:" << max_score << endl;
		judge = false;
	}
}
*/