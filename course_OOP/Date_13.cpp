//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;

//생성자 (constructor): 객체 선언시에 1회 호출 - 멤버	변수 초기화
//						1) 함수명이 클래스 이름과 동일, return type이 없음
//						2) 생성자를 만들지 않으면 default 생성자 자동생성
//						   default constructor: Account(){}
//						3) 생성자를 만들면 default 생성자 생성되지 않음
//						4) initialization list 사용 권장(상속, 다형성때 필수)

/* 은행 계좌 관리
class Account
{
private: //data: 클래스 내부에서만 접근 가능
	string name;
	string id;
	double balance;

public: //method: 클래스 내/외부에서 모두 접근 가능
	//Account() {} //default 생성자 (만약 작성자가 생성자를 만들지 않을 시 프로그램 내에서 자동적으로 생성)
	Account(string _name, string _id, double _bal) :
		name(_name), id(_id), balance(_bal) {
		if (balance < 0)
		{
			balance = 0;
		}
	}

	//생성자를 여러개 만들 수 있음(함수 오버로딩)
	Account() : name("XXX"), id("0000"), balance(0) {} //Initialization list로 객체를 초기화 시키는 방법 -> 이 방법을 추쳔함

	//그냥 생성자
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
	Account Acc2("홍길동", "1002", 5000);
	
	Acc1.print();
	Acc2.print();

	Acc1.deposit(10000);
	Acc1.print();

	if ( !Acc1.withdraw(20000) )
	{
		cout << "잔액이 부족합니다." << endl;
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
//	Account acc2("남우성", "1234", 10000);
//
//	acc1.Print();
//	acc2.Print();
//
//	acc1.deposit(5000);
//	acc1.Print();
//
//	if (!(acc1.withdraw(10000))) {
//		cout << "잔액이 부족합니다." << endl;
//	}
//
//	acc2.withdraw(9000);
//	acc2.Print();
//
//	return 0;
//}

