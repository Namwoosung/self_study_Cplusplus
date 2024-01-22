//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;

//������ (constructor): ��ü ����ÿ� 1ȸ ȣ�� - ���	���� �ʱ�ȭ
//						1) �Լ����� Ŭ���� �̸��� ����, return type�� ����
//						2) �����ڸ� ������ ������ default ������ �ڵ�����
//						   default constructor: Account(){}
//						3) �����ڸ� ����� default ������ �������� ����
//						4) initialization list ��� ����(���, �������� �ʼ�)

/* ���� ���� ����
class Account
{
private: //data: Ŭ���� ���ο����� ���� ����
	string name;
	string id;
	double balance;

public: //method: Ŭ���� ��/�ܺο��� ��� ���� ����
	//Account() {} //default ������ (���� �ۼ��ڰ� �����ڸ� ������ ���� �� ���α׷� ������ �ڵ������� ����)
	Account(string _name, string _id, double _bal) :
		name(_name), id(_id), balance(_bal) {
		if (balance < 0)
		{
			balance = 0;
		}
	}

	//�����ڸ� ������ ���� �� ����(�Լ� �����ε�)
	Account() : name("XXX"), id("0000"), balance(0) {} //Initialization list�� ��ü�� �ʱ�ȭ ��Ű�� ��� -> �� ����� ������

	//�׳� ������
	//Account()
	//{
	//	name = "XXX";
	//	id = "0000";
	//	balance = 0;
	//} 
	void deposit(double _amt)
	{
		balance += _amt;
	}
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
		cout << name << '\t' << id << '\t' << balance << endl;
	}
};

int main()
{
	Account Acc1;
	Account Acc2("ȫ�浿", "1002", 5000);
	
	Acc1.print();
	Acc2.print();

	Acc1.deposit(10000);
	Acc1.print();

	if ( !Acc1.withdraw(20000) )
	{
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	Acc1.print();

	Acc1.withdraw(5400);
	Acc1.print();

	auto a = 10;
	auto b = 10.1;
	auto c = 'z';

	vector<Account> vec;

	vec.push_back(Acc1);
	vec.push_back(Acc2);

	for (Account elem : vec)
	{
		elem.print();
	}

	return 0;
}
*/


//practice
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Account {
//private:
//	string name;
//	string id;
//	double balance;
//public:
//	Account(string _name, string _id, double _balance) :
//		name(_name), id(_id), balance(_balance) {
//		if (balance < 0) {
//			balance = 0;
//		}
//	}
//
//	Account(): name("xxx"), id("0000"), balance(0) {}
//
//	void deposit(double _amt) {
//		balance += _amt;
//	}
//	bool withdraw(double _amt) {
//		if (balance - _amt < 0) {
//			return false;
//		}
//		balance -= _amt;
//		return true;
//	}
//	void Print() {
//		cout << name << '\t' << id << '\t' << balance << endl;
//	}
//
//};
//
//int main() {
//	Account acc1;
//	Account acc2("���켺", "1234", 10000);
//
//	acc1.Print();
//	acc2.Print();
//
//	acc1.deposit(5000);
//	acc1.Print();
//
//	if (!(acc1.withdraw(10000))) {
//		cout << "�ܾ��� �����մϴ�." << endl;
//	}
//
//	acc2.withdraw(9000);
//	acc2.Print();
//
//	return 0;
//}

