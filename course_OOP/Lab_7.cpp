//Date_6 & Date_7

//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <ctime>
//
//using namespace std;

/*���ʹ��� 1
int main()
{
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl;

	cout << s1.empty() << endl;
	s1.clear();
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 = s1 + "-bye";

	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl;
	cout << (s1 == "Good-bye") << endl;
	cout << (s1 == "good-bye") << endl;
	cout << (s1 >= "z") << endl << endl;

	cout << s1.substr(5, 3) << endl;
	cout << s1.substr(2, 2) << endl;
	cout << s1.find("od") << endl;
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2);
	cout << (s1.find("korea") == string::npos) << endl;

	return 0;
}
*/

/*���ʹ��� 2
int main()
{
	ofstream fout;
	fout.open("example.txt");

	string s2 = "Objective Oriented Programming";
	fout << s2 << endl;
	fout << "Random variables" << endl;
	fout << "Linear Algebra" << endl;

	fout.close();

	ifstream fin;
	string s1;

	fin.open("example.txt");
	if (!fin)
	{
		cout << "Erroe, no such file exists" << endl;
		exit(100);
	}

	while (getline(fin, s1))
	{
		cout << s1 << endl;
	}

	//while (1)
	//{
	//	fin >> s1;
	//	if (!fin)
	//	{
	//		break;
	//	}
	//	cout << s1 << endl;
	//}

	fin.close();

	return 0;
}
*/

/*���ʹ���3
int main()
{
	double d1 = 1.23456789;

	cout << d1 << endl;

	cout.width(10);
	cout.precision(3);

	cout << d1 << endl;

	char ch1;
	char ch2;

	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;

	cin.ignore();

	cin.unsetf(ios::skipws);
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;
	cin.setf(ios::skipws);

	return 0;
}
*/

/*���ʹ��� 4
bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3)
{
	fin >> id >> exam1 >> exam2 >> exam3;
	if (!fin)
	{
		return false;
	}
	return true;
}
void calcAvgGrade(int exam1, int exam2, int exam3, int& avg, char& grade)
{
	avg = (exam1 + exam2 + exam3) / 3;
	if (avg >= 90)
	{
		grade = 'A';
	}
	else if (avg >= 80)
	{
		grade = 'B';
	}
	else
	{
		grade = 'F';
	}
}
void writeStu(ofstream& fout, int id, int avg, char grade)
{
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(4) << avg;
	fout << setw(4) << grade << endl;
}
int main()
{
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");

	int id, exam1, exam2, exam3, avg;
	char grade;

	while (getStu(fin, id, exam1, exam2, exam3))
	{
		calcAvgGrade(exam1, exam2, exam3, avg, grade);
		writeStu(fout, id, avg, grade);
	}
	fin.close();
	fout.close();

	cout << "end";

	return 0;
}
*/

/*���빮�� 1
int main()
{
	string address, city, area, street, building;

	cout << "�� : ";
	cin >> city;
	cout << "�� : ";
	cin >> area;
	cout << "�� : ";
	cin >> street;
	cout << "�ǹ��� : ";
	cin >> building;

	address = city + area + street + building;

	cout << "�� �ּ� : " << address << endl;
}
*/

/*���빮�� 2
int main()
{
	string data = "���, ���α׷���, ����, ����� �ٺ�, ���뿪, õ���ǻ��, �����, ��ü����";
	string keyword;

	int block_start = 0, block_end = 0;

	cout << "Ű���� : ";
	cin >> keyword;

	cout << "�˻���� : ";
	while (data.find(',', block_start) != string::npos)
	{
		block_end = data.find(',', block_start + 1);
		if (data.find(keyword, block_start) < block_end)
		{
			cout << data.substr(block_start, block_end - block_start) << '\t';
		}
		block_start = block_end + 2;
	}
	cout << endl;

	return 0;
}
*/

/*���빮�� 3
int main()
{
	int number;

	srand(time(NULL));


	ofstream fout;
	fout.open("temp.txt");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			number = rand() % 101;
			fout << number << "  ";
		}
		fout << endl;
	}

	fout.close();
	return 0;
}
*/

/*���빮�� 4
int main()
{

	ifstream fin1;
	ifstream fin2;
	ofstream fout;

	char ch;

	fin1.open("temp1.txt");
	if (!fin1)
	{
		cout << "erroe: no such file exists" << endl;
		exit(100); // ���α׷� ���� ����
	}
	fin2.open("temp2.txt");
	if (!fin2)
	{
		cout << "erroe: no such file exists" << endl;
		exit(100); // ���α׷� ���� ����
	}
	fout.open("AllTemp.txt");

	while (true)
	{
		fin1.get(ch);
		if (!fin1)
		{
			break;
		}
		fout << ch;
	}
	fout << endl << endl;
	while (true)
	{
		fin2.get(ch);
		if (!fin2)
		{
			break;
		}
		fout << ch;
	}

	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}
*/

/*���빮�� 5
int main()
{
	ifstream fin;
	ofstream fout;

	int length = 0;
	char ch;

	cout << "length = ";
	cin >> length;

	fin.open("temp3.txt");
	if (!fin)
	{
		cout << "erroe: no such file exists" << endl;
		exit(100); // ���α׷� ���� ����
	}

	fout.open("NewTemp.txt");

	while (true)
	{
		for (int i = 0; i < length; i++)
		{
			fin.get(ch);
			if (!fin)
			{
				break;
			}
			if (ch != '\n')
			{
				fout << ch;
			}
			else
			{
				i--;
			}
		}
		fout << endl;
		if (!fin)
		{
			break;
		}
	}

	fin.close();
	fout.close();

	return 0;
}
*/