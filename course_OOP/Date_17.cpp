#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
// 1) Base type이 private: 상속타입과 상관없이 Derived에서 접근 불가
// 2) Base type이 protected: 상속 타입과 상관없이 Derived에서 private로 선언
// 3) Base type이 public: 상속타입 private/protected -> Derived에서 private
//						  상속타입 public -> Derived에서 public
//황금률: Base class의 private를 protected로 고치고, 상속타입은 public(편함)
//함수 overriding: 부모클래스 method를 자식클래스에 재정의 하는것
//			-핵심 키워드:(virtual, override)
//				-virtual: 부모클래스 method앞에 붙여줌 [ virtual void f() {} ]
//				-override: 자식클래스 method에 붙여줌 [ void f() override{} ]
//				가상함수는 정의를 하지 않는 순수가상함수와, 정의를 하는 일반가상함수로 나뉨
//				일반가상함수의 경우 이 함수가 자식클래스에서 오버라이딩되는 함수라는 것을 명시함
//				override키워드는 자식클래스에서 붙이며, 이 함수가 부모 클래스에 있는 함수를 오버라이딩한 함수라는 것을 명시함
//				virtual 키워드를 사용하는 이유는 객체의 포인터형 변수를 사용하여 접근할 때 원하는 접근이 이루어 질 수 있도록 함
//				++final키워드도 존재, final키워드는 override키워드와 동일하지만 마지막 오버라이드라는 것을 명시(더 이상 하위 클래스에서 이 함수를 오버라이드 하지 않음)
//				자식클래스에서 override키워드 대신 virtual키워드를 사용해서 오버라이드 할 수 있지만, override키워드를 사용할 시 개발자의 실수를 더 쉽게 방지할 수 있음
//				(override키워드는 부모 클래스에 해당 함수가 virtual로 존재하지 않을 시 컴파일에러 발생 but virtual키워드는 이 키워드가 부모클래스의 목적을 선언된 것인지, 상속받는 입자에서 선언된 것인지 판단을 못하기에 오류 발생x
//				final키워드도 마찬가지로 virtual이나 override를 사용할 수 있지만, final 사용시 하위 클래스에서 다시 오버라이드 할 경우 컴파일 에러 발생 -> 개발자의 실수 방지

class Base
{
public: //Base 타입
	virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base //상속타입
{
public:
	void g() { cout << "Derived::g()" << endl; }
	//void f()
	void f() override { cout << "specialized" << endl; } //overriding
};

int main()
{
	return 0;
}
*/

/*
class Text
{
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	virtual string get() const { return text; }
	virtual void append(string _t) { text = text + _t; }
};

class FancyText : public Text
{
private:
	string left_bracket;
	string right_bracket;
	string connector;

public:
	FancyText(string _t, string _left, string _right, string _conn) :
		Text(_t), left_bracket(_left), right_bracket(_right), connector(_conn) {} //initialization list의 특성 -> 생성자 호출하여 사용가능(상속에서 유리함)
	string get() const override { return left_bracket + Text::get() + right_bracket; }
	void append(string _t) override { Text::append(connector + _t); }
};

class FixedText : public Text
{
public:
	FixedText() : Text("FIXED") {}
	void append(string _s) override {}
};

//다형성: 부모클래스 포인터로 자식클래스 객체를 모두 사용 가능
int main()
{
	Text t1("plain");
	FancyText t2("Fancy", "<<", ">>", "***");
	FixedText t3;

	cout << t1.get() << endl;
	cout << t2.get() << endl;
	cout << t3.get() << endl << endl;

	t1.append("A");
	t2.append("A");
	t3.append("A");

	cout << t1.get() << endl;
	cout << t2.get() << endl;
	cout << t3.get() << endl << endl;

	t1 = t2; //assign은 자식클래스 객체를 부모클래스에게로만 가능(부모클래스를 자식클래스에 assign불가)
	// t2 = t1 : 불가능
	cout << t1.get() << endl;

	Text* pT;
	pT = &t1; //정적 바인딩: 자기자신 객체의 주소값을 포인터에 할당

	cout << pT->get() << endl;
	pT->append("B");
	cout << pT->get() << endl << endl;
	
	pT = &t2; //동적 바인딩: 부모클래스의 포인터로 자식클래스 주소를 저장
			  //			자식클래스의 overriding된 method를 사용
	cout << pT->get() << endl;
	pT->append("B");
	cout << pT->get() << endl << endl;

	//동적바인딩, 다형성읗 이용해 벡터 활용가능
	vector<Text*> texts{ new Text("Wow"), 
						 new FancyText("Whoa", "(", ")", "-"),
						 new FixedText };

	for (Text* elem : texts)
	{
		cout << elem->get() << endl;
	}

	return 0;
}
*/


//practice
//class Text {
//private:
//	string text;
//public:
//	Text(string _t): text(_t) {}
//	virtual string get() const { return this->text; }
//	virtual void append(string _t) { this->text += _t; }
//};
//
//class FancyText : public Text {
//private:
//	string left_bracket;
//	string right_bracket;
//	string connector;
//public:
//	FancyText(string _t, string _left, string _right, string _conn):
//		Text::Text(_t), left_bracket(_left), right_bracket(_right), connector(_conn) {}
//	string get() const override { return left_bracket + Text::get() + right_bracket; }
//	void append(string _t) override { Text::append(connector + _t); }
//};
//
//class FixedText : public Text {
//public:
//	FixedText(): Text::Text("Fixed") {}
//	void append(string _t) override {}
//};
//
//int main()
//{
//	Text t1("plain");
//	FancyText t2("Fancy", "<<", ">>", "***");
//	FixedText t3;
//
//	cout << t1.get() << endl;
//	cout << t2.get() << endl;
//	cout << t3.get() << endl << endl;
//
//	t1.append("A");
//	t2.append("A");
//	t3.append("A");
//
//	cout << t1.get() << endl;
//	cout << t2.get() << endl;
//	cout << t3.get() << endl << endl;
//
//	t1 = t2; //assign은 자식클래스 객체를 부모클래스에게로만 가능(부모클래스를 자식클래스에 assign불가) <- 자식은 부모의 멤버변수와 메소드를 모두 가지고 있지만, 부모는 그렇지 않음
//	// t2 = t1 : 불가능
//	cout << t1.get() << endl;
//
//	Text* pT;
//	pT = &t1; //정적 바인딩: 자기자신 객체의 주소값을 포인터에 할당
//
//	cout << pT->get() << endl;
//	pT->append("B");
//	cout << pT->get() << endl << endl;
//
//	pT = &t2; //동적 바인딩: 부모클래스의 포인터로 자식클래스 주소를 저장
//			  //			자식클래스의 overriding된 method를 사용
//			  //++만약 virtual과 override키워드를 사용하지 않으면 같은 이름의 메소드를 호출 시 부모클래스의 메소드를 호출함
//			  // => 바인딩 개념 -> 더 공부해 볼것
//	cout << pT->get() << endl;
//	pT->append("B");
//	cout << pT->get() << endl << endl;
//
//	//동적바인딩, 다형성을 이용해 벡터 활용가능(부모 객체의 포인터로 자식 객체를 가르키게하는 것이 가능함을 이용)
//	vector<Text*> texts{ new Text("Wow"),
//						 new FancyText("Whoa", "(", ")", "-"),
//						 new FixedText };
//
//	for (Text* elem : texts)
//	{
//		cout << elem->get() << endl;
//	}
//
//	return 0;
//}