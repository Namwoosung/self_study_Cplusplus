//Date_12 & Date_13

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*기초문제 1
class Point
{
private:
	int x;
	int y;

public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void setXY(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void print()
	{
		cout << x << ", " << y << endl;
	}
};
int main()
{
	Point pt1(1, 2), pt2(3, 4);
	pt1.setXY(10, 20);
	pt1.print();
	pt2.print();
	
	cout << pt1.getX() << endl;
	cout << pt2.getY() << endl;

	return 0;
}
*/

/*기초문제 2
class Account
{
private:
	string name;
	string id;
	double balance;
public:
	Account() : 
		name(""), id(""), balance(0) {}
	Account(string _name, string _id) :
		name(_name), id(_id), balance(0) {}
	Account(string _name, string _id, double _balance) :
		name(_name), id(_id), balance(_balance) {
		if (balance < 0)
		{
			balance = 0;
		}
	}
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt)
	{
		if (balance - _amt < 0)
		{
			return false;
		}
		balance -= _amt;
		return true;
	}
	void print()
	{
		cout << name << ", " << id << ", " << balance << endl;
	}
};

int main()
{
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();

	int depo;
	cout << "예금할 금액을 입력하세요: ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();

	int wdrw;
	cout << "출금할 금액을 입력하세요: ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
	{
		cout << "잔액이 부족합니다." << endl;
	}
	ac1.print();
	return 0;
}
*/

/*응용문제 1
class CStudent
{
private:
	int id;
	string name;
	string major;
public:
	CStudent() : id(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	CStudent(int _id, string _name, string _major) :
		id(_id), name(_name), major(_major) {}
	void setNumber(int _id) { id = _id; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }
	int getNumber() { return id; }
	string getName() { return name; }
	string getMajor() { return major; }
	void Display()
	{
		cout << "학번 :" << id << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl <<endl;
	}
};

int main()
{
	CStudent s1;
	s1.Display();

	CStudent s2(1999000000, "공지철", "연극영화과");
	s2.Display();

	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;

	return 0;
}
*/

/*응용문제 2
class CStudent
{
private:
	int id;
	string name;
	string major;
public:
	CStudent() : id(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	CStudent(int _id, string _name, string _major) :
		id(_id), name(_name), major(_major) {}
	void setNumber(int _id) { id = _id; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }
	int getNumber() { return id; }
	string getName() { return name; }
	string getMajor() { return major; }
	void Display()
	{
		cout << "학번 :" << id << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl << endl;
	}
};

int main()
{
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1)
	{
		bool IsCrush = false;


		cout << length + 1<< " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;

		for (int i = 0; i < length; i++)
		{
			if (inputNumber == s[i].getNumber())
			{
				IsCrush = true;
			}
		}

		if (!IsCrush)
		{
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			cout << "※입력 완료" << endl << endl;
			length++;
		}
		else
		{
			cout << "※중복된 학번이 존재합니다" << endl << endl;
		}

		if (length == 3)
		{
			cout << "---모든입력이 완료되었습니다---" << endl;
			cout << "1학생정보" << endl;
			s[0].Display();
			cout << "2학생정보" << endl;
			s[1].Display();
			cout << "3학생정보" << endl;
			s[2].Display();
			break;
		}
	}
}
*/

/*응용문제 3
class Student
{
private:
	string name;
	int id;
	string dpt;
	vector<string> subject;
	vector<char> grade;
public:
	Student(string _name, int _id, string _dpt) :
		name(_name), id(_id), dpt(_dpt) {}
	Student() :
		name("default"), id(0), dpt("depart") {}
	void setName(string _name) { name = _name; }
	void setID(int _id) { id = _id; }
	void setDpt(string _dpt) { dpt = _dpt; }
	void print()
	{
		cout << name << " " << id << " " << dpt << endl;
	}
	void addGrade(string _sub, char _grade)
	{
		subject.push_back(_sub);
		grade.push_back(_grade);
	}
	void PrintGrades()
	{
		for (unsigned i = 0; i < subject.size(); i++)
		{
			cout << subject[i] << " " << grade[i] << endl;
		}
		cout << "GPA : " << getGPA() << endl;
	}
	float getGPA()
	{
		int number = 0;
		for (unsigned i = 0; i < grade.size(); i++)
		{
			switch (grade[i])
			{
			case 'A':
				number += 4;
				break;
			case 'B':
				number += 3;
				break;
			case 'C':
				number += 2;
				break;
			case 'D':
				number += 1;
				break;
			case 'F':
				number += 0;
				break;
			}
		}
		return float(number) / grade.size();
	}
	void getYear(int year)
	{
		int s_number = id / 1000000;
		int g_number = year - s_number;
		if (g_number >= 4)
		{
			cout << "About to graduate(" << g_number << "학년)" << endl;
		}
		else
		{
			switch (g_number)
			{
			case 3:
				cout << "Senior(4학년)" << endl;
				break;
			case 2:
				cout << "Junior(3학년)" << endl;
				break;
			case 1:
				cout << "Sophomore(2학년)" << endl;
				break;
			case 0:
				cout << "Freshman(1학년)" << endl;
				break;
			}
		}
	}
};

int main()
{
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.PrintGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << '\n';
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.PrintGrades();
	cout << "\n\n";

	return 0;
}
*/