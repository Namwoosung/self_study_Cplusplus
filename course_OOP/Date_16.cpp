/*
#include <iostream>

using namespace std;

class Base
{
public:
	void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base //DerivedŬ������ BaseŬ������ ���(publicŰ�����)
{
public:
	void g() { cout << "Derived::g()" << endl; }
	//void f() {cout << "Base::f()" << endl;} <- �ڵ� �߰�
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