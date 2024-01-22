#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
// 1) Base type�� private: ���Ÿ�԰� ������� Derived���� ���� �Ұ�
// 2) Base type�� protected: ��� Ÿ�԰� ������� Derived���� private�� ����
// 3) Base type�� public: ���Ÿ�� private/protected -> Derived���� private
//						  ���Ÿ�� public -> Derived���� public
//Ȳ�ݷ�: Base class�� private�� protected�� ��ġ��, ���Ÿ���� public(����)
//�Լ� overriding: �θ�Ŭ���� method�� �ڽ�Ŭ������ ������ �ϴ°�
//			-�ٽ� Ű����:(virtual, override)
//				-virtual: �θ�Ŭ���� method�տ� �ٿ��� [ virtual void f() {} ]
//				-override: �ڽ�Ŭ���� method�� �ٿ��� [ void f() override{} ]
//				�����Լ��� ���Ǹ� ���� �ʴ� ���������Լ���, ���Ǹ� �ϴ� �Ϲݰ����Լ��� ����
//				�Ϲݰ����Լ��� ��� �� �Լ��� �ڽ�Ŭ�������� �������̵��Ǵ� �Լ���� ���� �����
//				overrideŰ����� �ڽ�Ŭ�������� ���̸�, �� �Լ��� �θ� Ŭ������ �ִ� �Լ��� �������̵��� �Լ���� ���� �����
//				virtual Ű���带 ����ϴ� ������ ��ü�� �������� ������ ����Ͽ� ������ �� ���ϴ� ������ �̷�� �� �� �ֵ��� ��
//				++finalŰ���嵵 ����, finalŰ����� overrideŰ����� ���������� ������ �������̵��� ���� ���(�� �̻� ���� Ŭ�������� �� �Լ��� �������̵� ���� ����)
//				�ڽ�Ŭ�������� overrideŰ���� ��� virtualŰ���带 ����ؼ� �������̵� �� �� ������, overrideŰ���带 ����� �� �������� �Ǽ��� �� ���� ������ �� ����
//				(overrideŰ����� �θ� Ŭ������ �ش� �Լ��� virtual�� �������� ���� �� �����Ͽ��� �߻� but virtualŰ����� �� Ű���尡 �θ�Ŭ������ ������ ����� ������, ��ӹ޴� ���ڿ��� ����� ������ �Ǵ��� ���ϱ⿡ ���� �߻�x
//				finalŰ���嵵 ���������� virtual�̳� override�� ����� �� ������, final ���� ���� Ŭ�������� �ٽ� �������̵� �� ��� ������ ���� �߻� -> �������� �Ǽ� ����

class Base
{
public: //Base Ÿ��
	virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base //���Ÿ��
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
		Text(_t), left_bracket(_left), right_bracket(_right), connector(_conn) {} //initialization list�� Ư�� -> ������ ȣ���Ͽ� ��밡��(��ӿ��� ������)
	string get() const override { return left_bracket + Text::get() + right_bracket; }
	void append(string _t) override { Text::append(connector + _t); }
};

class FixedText : public Text
{
public:
	FixedText() : Text("FIXED") {}
	void append(string _s) override {}
};

//������: �θ�Ŭ���� �����ͷ� �ڽ�Ŭ���� ��ü�� ��� ��� ����
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

	t1 = t2; //assign�� �ڽ�Ŭ���� ��ü�� �θ�Ŭ�������Էθ� ����(�θ�Ŭ������ �ڽ�Ŭ������ assign�Ұ�)
	// t2 = t1 : �Ұ���
	cout << t1.get() << endl;

	Text* pT;
	pT = &t1; //���� ���ε�: �ڱ��ڽ� ��ü�� �ּҰ��� �����Ϳ� �Ҵ�

	cout << pT->get() << endl;
	pT->append("B");
	cout << pT->get() << endl << endl;
	
	pT = &t2; //���� ���ε�: �θ�Ŭ������ �����ͷ� �ڽ�Ŭ���� �ּҸ� ����
			  //			�ڽ�Ŭ������ overriding�� method�� ���
	cout << pT->get() << endl;
	pT->append("B");
	cout << pT->get() << endl << endl;

	//�������ε�, �������� �̿��� ���� Ȱ�밡��
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
//	t1 = t2; //assign�� �ڽ�Ŭ���� ��ü�� �θ�Ŭ�������Էθ� ����(�θ�Ŭ������ �ڽ�Ŭ������ assign�Ұ�) <- �ڽ��� �θ��� ��������� �޼ҵ带 ��� ������ ������, �θ�� �׷��� ����
//	// t2 = t1 : �Ұ���
//	cout << t1.get() << endl;
//
//	Text* pT;
//	pT = &t1; //���� ���ε�: �ڱ��ڽ� ��ü�� �ּҰ��� �����Ϳ� �Ҵ�
//
//	cout << pT->get() << endl;
//	pT->append("B");
//	cout << pT->get() << endl << endl;
//
//	pT = &t2; //���� ���ε�: �θ�Ŭ������ �����ͷ� �ڽ�Ŭ���� �ּҸ� ����
//			  //			�ڽ�Ŭ������ overriding�� method�� ���
//			  //++���� virtual�� overrideŰ���带 ������� ������ ���� �̸��� �޼ҵ带 ȣ�� �� �θ�Ŭ������ �޼ҵ带 ȣ����
//			  // => ���ε� ���� -> �� ������ ����
//	cout << pT->get() << endl;
//	pT->append("B");
//	cout << pT->get() << endl << endl;
//
//	//�������ε�, �������� �̿��� ���� Ȱ�밡��(�θ� ��ü�� �����ͷ� �ڽ� ��ü�� ����Ű���ϴ� ���� �������� �̿�)
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