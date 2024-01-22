//Date_14 & Date_15

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*기초문제 1
class Point
{
private:
	int x;
	int y;
	static int numCreatedObjects;
	//	ifstream fin;
	//	int * ary;
public:
	Point() : x(0), y(0)
	{
		numCreatedObjects++;
		//	fin.open("test.txt");
		//	ary = new int[100]
	}
	Point(int _x, int _y);

	~Point()
	{
		//	fin.close()
		//	delete[] ary;
		cout << "Destructed..." << endl;
	}

	static int getNumCreatedObject() { return numCreatedObjects; }

	void setXY(int _x, int _y)
	{
		this->x = x;
		this->y = y;
	}
	int getX() const;
	int getY() const;

	Point operator=(const Point& pt)
	{
		this->x = pt.getX(); // this포인터: 현재 객체의 주소값을 가지고 있는 포인터 -> 변수 이름이 겹치는 경우 명확히 해줄 수 있음
		this->y = pt.getY();
		return (*this);
	}
	Point operator+(const Point& pt2) //pt2 + pt3 -> pt2.+(pt3)
	{
		Point result(this->x + pt2.getX(), this->y + pt2.getY());
		return result;
	}
	friend ostream& operator <<(ostream& cout, Point& pt);
	friend void print(const Point& pt);
	friend class SpyPoint;
};

int Point::numCreatedObjects = 0;

Point::Point(int _x, int _y): x(_x), y(_y)
{
	numCreatedObjects++;
}

int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;
}

//Point operator+(Point& pt1, Point& pt2){
//	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
//	return result;
//}

void print(const Point& pt)
{
	cout << pt.x << ", " << pt.y << endl << endl;
}

ostream& operator<<(ostream& cout, Point& pt)
{
	cout << pt.x << ", " << pt.y;
	return cout;
}

class SpyPoint
{
public:
	void hack_all_info(const Point& pt)
	{
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "numCreatedObj: " << pt.getNumCreatedObject << endl << endl;
	}

	//freind class Point;
};

int main()
{
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);

	Point* pPt1 = &pt1;
	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl << endl;

	Point* pPt2 = new Point(10, 20);
	cout << "pt2: ";
	cout << pPt2->getX() << ", " << pPt2->getY() << endl << endl;

	int a = 3 + 5;
	Point pt2(10, 20), pt3(30, 40);

	Point pt4 = pt2 + pt3;

	cout << "pt2: " << pt2 << endl;
	cout << "pt3: " << pt3 << endl;
	cout << "pt4: " << pt4 << endl;

	cout << "pt1 NumCreatedObject: " << pt1.getNumCreatedObject() << endl << endl;

	Point* ptAry = new Point[5];
	cout << "pt2 NumCreatedObject: " << pt2.getNumCreatedObject() << endl << endl;
	delete[] ptAry;

	SpyPoint spy;
	cout << endl << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);

	return 0;
}
*/

/*응용문제 1
class User
{
private:
	string id;
	string password;
public:
	User() : id(" "), password(" ") {};
	User(string _id, string _password) : id(_id), password(_password) {};
	void set_info(string _id, string _password);
	string get_id() { return this->id; }
	string get_password() { return this->password; }
};

int main()
{
	User user[3];
	string id, password, searchld, searchPassword;
	for (int i = 0; i < 3; i++)
	{
		cout << "============" << i + 1 << "============" << endl;
		cout << "ID : ";
		cin >> id;
		for (int j = 0; j < i; j++)
		{
			if (user[j].get_id() == id)
			{
				cout << "이미 존재하는 ID입니다." << endl << "종료합니다." << endl;
				exit(100);
			}
		}
		cout << "password : ";
		cin >> password;
		user[i].set_info(id, password);
		cout << "=============================" << endl << endl;
	}
	while (1)
	{
		cout << "============ Login ============" << endl << endl;
		cout << "ID : ";
		cin >> searchld;
		if (searchld == "종료")
		{
			cout << "종료하겠습니다." << endl;
			exit(100);
		}

		cout << "password : ";
		cin >> searchPassword;

		for (int i = 0; i < 3; i++)
		{
			if (searchld == user[i].get_id() && searchPassword == user[i].get_password())
			{
				cout << "로그인 되셨습니다." << endl;
				cout << "=============================" << endl << endl;
				break;
			}
			
			if (i == 2)
			{
				cout << "잘못된 ID거나 PASSWORD 입니다." << endl;
				cout << "=============================" << endl << endl;
			}
		}
	}
}

void User::set_info(string _id, string _password)
{
	id = _id;
	password = _password;
}
*/

/*응용문제 2
class Point
{
private:
	int x;
	int y;
public:
	Point(int _x, int _y) :
		x(_x), y(_y) {}
	Point() :
		x(0), y(0) {}
	void setPoint(int _x, int _y);
	Point operator-(const Point& pt);
	Point operator*(const Point& pt);
	Point& operator=(const Point& pt);
	int getx() const;
	int gety() const;
};

int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
	cin >> x1 >> y1;
	cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); //x,y가 0으로 초기화

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "두 좌표 사이의 길이는 " << sqrt(pP3->getx() + pP3->gety()) << "입니다." << endl;

	return 0;
}

void Point::setPoint(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}

Point Point::operator-(const Point& pt)
{
	Point result(this->x - pt.getx(), this->y - pt.gety());
	return result;
}

Point Point::operator*(const Point& pt)
{
	Point result(this->x * pt.getx(), this->y * pt.gety());
	return result;
}

Point& Point::operator=(const Point& pt)
{
	this->x = pt.getx();
	this->y = pt.gety();
	return (*this);
}

int Point::getx() const
{
	return this->x;
}

int Point::gety() const
{
	return this->y;
}
*/

/*응용문제 3
class Account
{
private:
	string name;
	string id;
	int balance;
public:
	Account(string _name, string _id, int _balance):
		name(_name), id(_id), balance(_balance) {}
	string getId() const { return this->id; }
	string getName() const { return this->name; }
	int getBalance() const { return this->balance; }
	Account operator+(const Account& ac);
	Account operator-(const Account& ac);
	Account& operator=(const Account& ac);

};

void give_balance(Account& ac1, Account& ac2);

ostream& operator<<(ostream& cout, const Account& ac)
{
	cout << "학번 : " << ac.getId() << ", 이름: " << ac.getName() << ", 잔액: " << ac.getBalance();
	return cout;
}

int main()
{
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000)
	};

	string give_id, recieve_id;

	while (true)
	{
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> give_id;

		if (give_id == "종료")
		{
			cout << "종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << acnt[i] << endl;
			}
			exit(100);
		}

		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> recieve_id;

		int g_id = 10, r_id = 10;

		for (int i = 0; i < 3; i++)
		{
			if (acnt[i].getId() == give_id)
			{
				g_id = i;
			}
			if (acnt[i].getId() == recieve_id)
			{
				r_id = i;
			}
		}

		if (g_id == 10 || r_id == 10)
		{
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else if (g_id == r_id)
		{
			cout << "보내는 학생과 받는 학생이 동일합니다. 다시 입력해주세요." << endl;
			continue;
		}
		else if (acnt[g_id].getBalance() == 0)
		{
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		else
		{
			give_balance(acnt[g_id], acnt[r_id]);
			cout << "보낸 학생의 잔액 => " << acnt[g_id] << endl;
			cout << "받은 학생의 잔액 => " << acnt[r_id] << endl;
		}
	}
}

void give_balance(Account& ac1, Account& ac2)
{
	ac2 = ac2 + ac1;
	ac1 = ac1 - ac1;
}

Account Account::operator+(const Account& ac)
{
	Account result(this->name, this->getId(), this->balance + ac.getBalance());
	return result;
}

Account Account::operator-(const Account& ac)
{
	Account result(this->name, this->getId(), this->balance - ac.getBalance());
	return result;
}

Account& Account::operator=(const Account& ac)
{
	this->balance = ac.getBalance();
	return (*this);
}
*/

/*응용문제 4
class Account
{
private:
	string id;
	string name;
	int balance;
	static int All_balance;
public:
	Account():
		id(""), name(""), balance(0) {}
	~Account()
	{
		All_balance += this->balance;
	}
	void set_Info(string _id, string _name, int _balance);
	string get_id() { return this->id; }
	static int get_allBalance();
};


int Account::All_balance = 0;

int main()
{
	int number;
	cout << "총 학생 수 입력: ";
	cin >> number;

	string id, name;
	int balance;

	Account* student_ary = new Account[number];

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "번째 학생 계좌 입력 : 학번 : ";
		cin >> id;
		cout << endl << "이름 : ";
		cin >> name;
		cout << endl << "잔액 : ";
		cin >> balance;
		cout << "======================" << endl << endl;

		for (int j = 0; j < i; j++)
		{
			if (student_ary[j].get_id() == student_ary[i].get_id())
			{
				cout << "학번이 동일합니다." << endl;
				exit(100);
			}
		}

		student_ary[i].set_Info(id, name, balance);
	}

	delete[] student_ary;

	cout << "회수된 금액 : " << student_ary->get_allBalance() << endl;

	return 0;
}

void Account::set_Info(string _id, string _name, int _balance)
{
	this->id = _id;
	this->name = _name;
	this->balance = _balance;
}

int Account::get_allBalance()
{
	return All_balance;
}
*/