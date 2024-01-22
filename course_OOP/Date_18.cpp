#include <iostream>
#include <string>
#include <vector>
#include "Date_18_CFancyText.h"
#include "Date_18_CFixedText.h"

using namespace std;

/*동적 바인딩
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

	pBase->f(); //정적바인딩: 사용될 method가 compole시 결정됨 (Base::f()가 실행)
	pBase->vf(); //동적바인딩: 사용될 method가 run-time(동작중) 결정됨 (Derived::vf()가 실행)
	//									-핵심 키워드: virtual(부모), override(자식)

	//Derived test;
	//test.f(); -> Derived::f()실행
	//test.vf(); ->Derived::vf() 실행
	
	return 0;
}
*/



/*추상클래스, 순수 가상함수
//추상클래스(abstract class): 순수가상함수를 적어도 하나 가지고 있는 클래스
//						-main()에서 객체로 선언할 수 없음
//						-다형성에서 interface(Base class pointer)만 제공
class Base
{
public:
	void f() { cout << "Base::f()" << endl; }
	virtual void vf() = 0; //순수 가상함수: 기능없고 interface만 제공
	//							반드시 자식클래스에서 (override)재정의 해야함(선언시 = 0 을 하는 것이 순수가상함수 문법)
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

	//Base base -> 불가

	return 0;
}
*/




/*추상클래스, 헤더,cpp 나누기
//클래스 별로 h파일과 cpp파일 생성후, h파일에는 선언, cpp파일에는 정의 => main.cpp에서는 클래스들의 헤더파일들을 include해서 사용
void print(Text* pText) //다형성을 이용하여 하나의 print함수만으로 모든 부모,자식클래스의 print 함수를 생성가능(엄청 유용할 듯) <- 부모 클래스의 포인터로 자식 클래스에 접근할 수 있으니
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