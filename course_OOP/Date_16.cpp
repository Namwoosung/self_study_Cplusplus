/*
#include <iostream>

using namespace std;

class Base
{
public:
	void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base //Derived클래스가 Base클래스를 상속(public키워드로)
{
public:
	void g() { cout << "Derived::g()" << endl; }
	//void f() {cout << "Base::f()" << endl;} <- 자동 추가
};

int main()
{
	Base myB;
	Derived myD;
	myB.f();
	myD.g();
	myD.f();

	return 0;
}
*/