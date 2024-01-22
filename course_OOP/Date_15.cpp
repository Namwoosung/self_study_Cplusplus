
#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
	static int cntObj; // static 멤버 변수는 객체 안 or main함수 안에서 초기화하면 X 
	//static 멤버 변수는 객체들이 같이 공유(마치 method를 공유하는 것고 같이), 모든 객체가 static멤버 변수에 대한 동일한 주소값을 공유
	//static멤버변수를 객체안에서 혹은 생성자에서 초기화할시 객체 생성시마다 초기화 되기 때문에 사용할 수 없음 => 전역범위에서 초기화 해주어야 함
	//모든 객체들이 동일하게 공유해야 할 변수를 선언할 때 사용(ex 현재 객체가 생성되어있는 갯수)
	//클래스 내에서 선언할 때는 메모리 할당이 되어있지않지만, 전역에서 변수를 정의해주면 메모리가 할당 됨 -> 객체 생성이전에도 print로 접근하면 접근 가능
	//static변수는 cpp파일에서 선인 및 정의를 해줘야 함, 만약 h파일에서 할 경우 다른 파일에도 여러번 include한다면 여러번 정의 및 선언되는 것과 같기 때문
	//static 변수는 private이지만 전역에서 정의해 주어야하기 때문에 전역범위에서 접근이 가능함
	//const static변수는 객체안에서 선언 및 정의가 가능하고, h파일에서 정의하는 것 또한 가능(const 값의 경우 컴파일 시점에 값이 할당되고 고정되기 때문)
	//=> 모든 객체가 공유해야하고, 값의 변경이 필요없는 변수의 경우 const statice으로 선언

	// int* list;
	// ofstream fout;
public:
	Point() : x(0), y(0)
	{
		// list = new int[100];
		// fout.open("example.txt")
		cntObj++;
	}
	Point(int _x, int _y) : x(_x), y(_y) { cntObj++; } // 함수 오버로딩: 같은 함수 이름 사용, 매개변수가 다른경우 다르게 동작하게 함(함수 이름 동일, 파라미터 개수 혹은 파라미터의 자료형 다름, return자료형 같아도 되고 달라도 됨)
	//<-> 오버라이딩: 상속받은 자식 객체에서 부모 객체와 동일한 메소드를 선언하고, 부모 메소드와 동작이 다른 함수를 선언하는 것(함수 이름, 파라미터 개수, 자료형, return의 자료형 동일, 함수 동작 다름 )
	~Point()//소멸자는 기본적으로 내장되어 있고, 객체가 지워져야 할 때 호출됨
	//개발자가 직접 소멸자를 정의하는 상황은 객체 내에서 동적으로 선언된 배열이 있거나, 파일을 닫아야 할 경우
	{
		// delete[] list; : 소멸자 사용 이유 1
		// fout.close(); : 소멸자 사용 이유 2
		cout << "Destructed.." << endl; //소멸자가 호출되었음을 cout을 통해 명시하는 예제
	}
	void setXY(int _x, int _y);
	int getX() const { return this->x; } // const메소드로 바꾸기
	int getY() const { return this->y; }
	static int getCntObj() { return cntObj; }
	Point operator+(const Point& pt);
	Point& operator=(const Point& pt);
	//객체 내에서 friend로 함수 혹은 클래스를 선언할 경우 선언된 함수와 클래스에서는 해당 객체의 private혹은 protected로 선언된 것들에 대한 접근이 가능 
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint; // friend class라 Point꺼 쓸 수 있음 but, Point는 friend꺼 못 씀
};

// pass by reference: 객체를 함수의 인자로 전달하 떄 pass by ref. 사용 권장
// const: 함수 내부의 객체의 멤버 변수가 바뀌지 않을 경우 const 삽입
//      -> 이때, 객체의 const method만 사용 가능( method이름 const { })
void print_pt(const Point& pt)
{
	cout << pt.getX() << ", " << pt.getY() << endl;
}

// 연산자 오버로딩: +, -, *, ==, >= 등을 객체에 대해 재정의
//      1) class 외부: operator+(좌측 피연산자, 우측 피연산자)
//      2) class 내부: operator+(우측 피연산자) 

// 연산자 오버로딩 1)
// pt1 + pt2 --> +(pt1, pt2)
//Point operator+(const Point pt1, const Point pt2) 
//{
//   Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY()); // result 라는 함수를 만든거
//   return result;
//}

// cout << pt1 --> <<(cout, pt1) -> return cout
// cout << pt1 << pt2; : 계속 이러질려면 <<가 cout을 return 할 필요가 있음
// └> (cout << pt1) -> cout << pt2
//ostream& operator<<(ostream& cout, const Point& pt)
//{
//   cout << pt.getX() << ", " << pt.getY();
//   return cout;
//}
ostream& operator<<(ostream& cout, const Point& pt)
{
	cout << pt.x << ", " << pt.y; // friend 함수라 Point꺼 쓸 수 있음 but, Point는 friend꺼 못 씀 (class도 마찬가지)
	return cout;
}

class SpyPoint
{
public:
	void hacking(const Point& pt)
	{
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "cntObj: " << pt.cntObj << endl << endl;
	}
};

int main()
{

	//Point pt1(1, 2);
	//print_pt(pt1);

	//// 객체 pointer 단순화 문법: (*pPt). --> pPt->
	//Point* pPt = &pt1; // 객체가 아님, 변수 일 뿐
	//cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	//cout << pPt->getX() << ", " << pPt->getY() << endl; // 단순화된 포인터 사용 방법
	//cout << endl;

	//Point* list = new Point[5];
	//for (int i = 0; i < 5; i++)
	//   cout << list[i].getX() << ", " << list[i].getY() << endl;
	//cout << endl;
	//delete[] list;

	//// a = b + c; -> a = +(b, c): +는 함수
	//Point pt2(10, 20);
	//Point pt3(100, 200);
	//pt1 = pt2 + pt3;
	//cout << pt1 << endl;
	//cout << pt2 << endl;
	//cout << pt3 << endl;
	//cout << endl;


	// -------------------------------------------------

	Point pt1(1, 2);
	cout << "cntObj: " << pt1.getCntObj() << endl;

	Point* pPt = &pt1;
	cout << "cntObj: " << pt1.getCntObj() << endl;

	Point* list = new Point[5];
	cout << "cntObj: " << list[0].getCntObj() << endl;
	cout << "Before delete[]" << endl;
	delete[] list;
	cout << "After delete[]" << endl;

	Point pt2(10, 20);
	Point pt3(100, 200);
	pt1 = pt2 + pt3; // operator+에서 result 객체가 생성되면서 하나 더 늘어남
	cout << "cntObj: " << pt1.getCntObj() << endl;

	SpyPoint spy;
	spy.hacking(pt1);
	spy.hacking(pt2);
	spy.hacking(pt3);

	cout << "Exit program" << endl;
	return 0;
}

int Point::cntObj = 0;

void Point::setXY(int _x, int _y)
{
	x = _x;
	y = _y;
}

// 연산자 오버로딩 2)
// pt2 + pt3 -> pt2.+(pt3)
Point Point::operator+(const Point& pt)
{
	Point result(this->x + pt.getX(), this->y + pt.getY());
	return result;
}

// pt1 = pt2 = pt3
Point& Point::operator=(const Point& pt) // &: return by ref로 pt1, pt2 다 동기화 돼서 다 값이 같아짐
{
	this->x = pt.getX();
	this->y = pt.getY();
	return (*this);
}



//practice
//#include <iostream>
//
//using namespace std;
//
//class point {
//private:
//	int x;
//	int y;
//	static int cntobj;
//public:
//	point() : x(0), y(0) { cntobj++; }
//	point(int _x, int _y) : x(_x), y(_y) { cntobj++; }
//	void set_xy(int _x, int _y);
//	int get_x() const;
//	int get_y() const;
//	point operator+(const point& pt);
//	point operator=(const point& pt);
//};
//
//int point::cntobj = 0;
//
//void point::set_xy(int _x, int _y)
//{
//	this->x = _x;
//	this->y = _y;
//}
//
//int point::get_x() const
//{
//	return this->x;
//}
//
//int point::get_y() const
//{
//	return this->y;
//}
//
//point point::operator+(const point& pt)
//{
//	point result(this->x + pt.get_x(), this->y + pt.get_x());
//	return result;
//}
//
//point point::operator=(const point& pt)
//{
//	this->x = pt.get_x();
//	this->y = pt.get_y();
//	return *this;
//}
