/* ������
#include <iostream>

using namespace std;

int main()
{
	cout << "TicTactoe" << endl;
	char arr[3][3] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	int P1C_1, P1C_2, P2C_1, P2C_2;
	int turn = 1;

	while (true)
	{
		int count = 0;
		turn = (turn + 3) % 2;
		if (turn == 0)
		{
			cout << "�÷��̾� [1]�� �����Դϴ�. ��ǥ�� �Է����ּ���." << endl;
			cin >> P1C_1 >> P1C_2;
			arr[P1C_1][P1C_2] = 'O';
		}
		else
		{
			cout << "�÷��̾� [2]�� �����Դϴ�. ��ǥ�� �Է����ּ���." << endl;
			cin >> P2C_1 >> P2C_2;
			arr[P2C_1][P2C_2] = 'X';
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < 3; i++)
		{
			if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != '*')
			{
				if (arr[i][0] == 'O')
				{
					cout << "�÷��̾� [1]�� �¸��Դϴ�." << endl;
					break;
				}
				else
				{
					cout << "�÷��̾� [2]�� �¸��Դϴ�." << endl;
					break;
				}
			}
		}
		for (int j = 0; j < 3; j++)
		{
			if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != '*' )
			{
				if (arr[0][j] == 'O')
				{
					cout << "�÷��̾� [1]�� �¸��Դϴ�." << endl;
					break;
				}
				else
				{
					cout << "�÷��̾� [2]�� �¸��Դϴ�." << endl;
					break;
				}
			}
		}
		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '*' )
		{
			if (arr[0][0] == 'O')
			{
				cout << "�÷��̾� [1]�� �¸��Դϴ�." << endl;
				break;
			}
			else
			{
				cout << "�÷��̾� [2]�� �¸��Դϴ�." << endl;
				break;
			}
		}
		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '*')
		{
			if (arr[0][0] == 'O')
			{
				cout << "�÷��̾� [1]�� �¸��Դϴ�." << endl;
				break;
			}
			else
			{
				cout << "�÷��̾� [2]�� �¸��Դϴ�." << endl;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == '*')
				{
					count += 1;
				}
			}
		}
		if (count == 0)
		{
			cout << "���º�" << endl;
			break;
		}
	}
}
*/

/* ���Ͽ� �̸� �Է�, ���
#include <iostream>

#include <fstream>

#include <string>

using namespace std;

int main()
{
	ofstream fout;
	fout.open("user.txt");

	while (true)
	{
		string user_name;
		cout << "�̸��� �Է����ֽʽÿ�.quit�� �Է��ϸ� ����˴ϴ�." << endl;
		cin >> user_name;

		if (user_name == "quit")
		{
			break;
		}
		
		fout << user_name << endl;
	}
	fout.close();

	ifstream in("user.txt");

	char user[1000];

	while (in.getline(user, 1000))
	{
		cout << user << endl;
	}
	in.close();
}
*/

/*���� ���� �״�� ���
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("text.txt");

	char achar;
	while (in.get(achar))
	{
		cout << achar;
	}
	in.close();
}
*/

/*���ϴ� �԰����� ���� ���
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int lenth;
	cout << "���α��̸� �Է����ֽʽÿ�." << endl;
	cin >> lenth;
	int number = 0;

	ifstream in("text.txt");

	char achar;
	while (in.get(achar))
	{
		if (achar != '\n')
		{
			cout << achar;
			number += 1;
		}
		if (number == lenth)
		{
			cout << endl;
			number = 0;
		}
	}
	in.close();
}
*/

/*���������� ������Ʈ
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
	cout << "����� �̸��� �Է��Ͻʽÿ�," << endl;
	cin >> user_name;

	string all_user[100];
	int all_scores[100] = { 0, };
	int num_line = 0;
	int test_number = 0;
	int user_number;
	int number_value_user = 0;
	int number_value_score = 0;

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
			cout << "�̿��� Ȯ�εǾ����ϴ�" << endl;
			name_check = true;
			user_number = test_number / 2;
		}
	}
	fin.close();

	int num_user = num_line / 2;

	if (name_check == false)
	{
		cout << "�ű��̿����̽ʴϴ�." << endl;
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
		cout << "����(s),����(r),��(p) �� �ϳ��� ���ʽÿ�" << endl << "q�� �Է��ϸ� ���α׷��� ����˴ϴ�.";
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
	cout << "����� ����:" << MyChoice << endl;
	cout << "��ǻ���� ����:" << ComChoice << endl;
	return;
}

void judge_winner(char MyChoice, char ComChoice, int &scores, bool &judge, int max_score)
{
	if ((MyChoice == 'r' && ComChoice == 's') || (MyChoice == 's' && ComChoice == 'p') || (MyChoice == 'p' && ComChoice == 'r'))
	{
		cout << "Win" << endl;
		scores += 1;
		cout << "��������:" << scores << endl;
	}
	else if (MyChoice == ComChoice)
	{
		cout << "Draw" << endl;
		cout << "��������:" << scores << endl;
	}
	else
	{
		cout << "Lose" << endl;
		cout << "����� ����:" << scores << endl;
		cout << "���� ����� �ְ�����:" << max_score << endl;
		judge = false;
	}
}
*/