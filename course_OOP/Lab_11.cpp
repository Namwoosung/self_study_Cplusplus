//Date_14 & Date_15

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*���ʹ��� 1
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
		this->x = pt.getX(); // this������: ���� ��ü�� �ּҰ��� ������ �ִ� ������ -> ���� �̸��� ��ġ�� ��� ��Ȯ�� ���� �� ����
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

/*���빮�� 1
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
				cout << "�̹� �����ϴ� ID�Դϴ�." << endl << "�����մϴ�." << endl;
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
		if (searchld == "����")
		{
			cout << "�����ϰڽ��ϴ�." << endl;
			exit(100);
		}

		cout << "password : ";
		cin >> searchPassword;

		for (int i = 0; i < 3; i++)
		{
			if (searchld == user[i].get_id() && searchPassword == user[i].get_password())
			{
				cout << "�α��� �Ǽ̽��ϴ�." << endl;
				cout << "=============================" << endl << endl;
				break;
			}
			
			if (i == 2)
			{
				cout << "�߸��� ID�ų� PASSWORD �Դϴ�." << endl;
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

/*���빮�� 2
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

	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;
	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); //x,y�� 0���� �ʱ�ȭ

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "�� ��ǥ ������ ���̴� " << sqrt(pP3->getx() + pP3->gety()) << "�Դϴ�." << endl;

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

/*���빮�� 3
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
	cout << "�й� : " << ac.getId() << ", �̸�: " << ac.getName() << ", �ܾ�: " << ac.getBalance();
	return cout;
}

int main()
{
	Account acnt[3] = {
		Account("����ȣ", "2014", 10000),
		Account("������", "2019", 0),
		Account("������", "2013", 5000)
	};

	string give_id, recieve_id;

	while (true)
	{
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> give_id;

		if (give_id == "����")
		{
			cout << "�����մϴ�." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << acnt[i] << endl;
			}
			exit(100);
		}

		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
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
			cout << "������ �л� Ȥ�� ���� �л��� �й��� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		else if (g_id == r_id)
		{
			cout << "������ �л��� �޴� �л��� �����մϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		else if (acnt[g_id].getBalance() == 0)
		{
			cout << "������ �л��� �ܾ��� �����մϴ�." << endl;
			continue;
		}
		else
		{
			give_balance(acnt[g_id], acnt[r_id]);
			cout << "���� �л��� �ܾ� => " << acnt[g_id] << endl;
			cout << "���� �л��� �ܾ� => " << acnt[r_id] << endl;
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

/*���빮�� 4
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
	cout << "�� �л� �� �Է�: ";
	cin >> number;

	string id, name;
	int balance;

	Account* student_ary = new Account[number];

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "��° �л� ���� �Է� : �й� : ";
		cin >> id;
		cout << endl << "�̸� : ";
		cin >> name;
		cout << endl << "�ܾ� : ";
		cin >> balance;
		cout << "======================" << endl << endl;

		for (int j = 0; j < i; j++)
		{
			if (student_ary[j].get_id() == student_ary[i].get_id())
			{
				cout << "�й��� �����մϴ�." << endl;
				exit(100);
			}
		}

		student_ary[i].set_Info(id, name, balance);
	}

	delete[] student_ary;

	cout << "ȸ���� �ݾ� : " << student_ary->get_allBalance() << endl;

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