#include <iostream>
#include <string>
#include <vector>
#include "Date_18_CFancyText.h"
#include "Date_18_CFixedText.h"

using namespace std;

/*���� ���ε�
class Base
{
public:
	void f() { cout << "Base::f()" << endl; }
	virtual void vf() { cout << "Base::vf()" << endl; }
};

class Derived : public Base
{
public:
	void f() { cout << "Derived::f()" << endl; }
	void vf() override { cout << "Derived::vf()" << endl; }
};


int main()
{
	Base* pBase = new Derived;

	pBase->f(); //�������ε�: ���� method�� compole�� ������ (Base::f()�� ����)
	pBase->vf(); //�������ε�: ���� method�� run-time(������) ������ (Derived::vf()�� ����)
	//									-�ٽ� Ű����: virtual(�θ�), override(�ڽ�)

	//Derived test;
	//test.f(); -> Derived::f()����
	//test.vf(); ->Derived::vf() ����
	
	return 0;
}
*/



/*�߻�Ŭ����, ���� �����Լ�
//�߻�Ŭ����(abstract class): ���������Լ��� ��� �ϳ� ������ �ִ� Ŭ����
//						-main()���� ��ü�� ������ �� ����
//						-���������� interface(Base class pointer)�� ����
class Base
{
public:
	void f() { cout << "Base::f()" << endl; }
	virtual void vf() = 0; //���� �����Լ�: ��ɾ��� interface�� ����
	//							�ݵ�� �ڽ�Ŭ�������� (override)������ �ؾ���(����� = 0 �� �ϴ� ���� ���������Լ� ����)
};

class Derived : public Base
{
public:
	void f() { cout << "Derived::f()" << endl; }
	void vf() override { cout << "Derived::vf()" << endl; }
};


int main()
{
	Base* pBase = new Derived;

	pBase->f();
	pBase->vf();

	//Base base -> �Ұ�

	return 0;
}
*/




/*�߻�Ŭ����, ���,cpp ������
//Ŭ���� ���� h���ϰ� cpp���� ������, h���Ͽ��� ����, cpp���Ͽ��� ���� => main.cpp������ Ŭ�������� ������ϵ��� include�ؼ� ���
void print(Text* pText) //�������� �̿��Ͽ� �ϳ��� print�Լ������� ��� �θ�,�ڽ�Ŭ������ print �Լ��� ��������(��û ������ ��) <- �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ������ �� ������
{
	cout << pText->get() << endl;
}

int main()
{
	FancyText t1("fancy", "<<", ">>", "**");
	FixedText t2;
	print(&t1);
	print(&t2);

	vector<Text*> texts{ new FancyText("AAA", "&", "&", "--"),
						new FixedText,
						new FancyText("BBB", "^", "^", "--") };

	for (Text* elem : texts)
	{
		elem->append("XXX");
	}

	for (auto elem : texts)
	{
		print(elem);
	}

	for (auto elem : texts)
	{
		delete elem;
	}

	return 0;
}
*/