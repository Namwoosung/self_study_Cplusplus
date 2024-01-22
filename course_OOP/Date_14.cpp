//#include <iostream>
//
//using namespace std;
//class, 포인터, 연산자 오버로딩
/*class point 
{
private:
	int x;
	int y;
public:
	point() : x(0), y(0) {}
	point(int _x, int _y) : x(_x), y(_y) {}
	void setxy(int _x, int _y);
	int getx() const; //const method를 선언함으로써 해당 메소드에서 멤버변수가 변할 수 없음을 명시 + 협업시 코드의 고장 방지
	int gety() const; //++ const method내에서 멤버변수를 수정하거나, const method가 아닌 다른 method를 재 호출시 컴파일 에러가 발생
	// => get함수와 같이 멤버변수에 대한 수정을 필요로 하지 않는 메소드는 const를 붙여 명시해주는 것이 좋음
	point operator+(const point& pt); //pt2 + pt3 -> pt2.+(pt3)
	point operator=(const point& pt);
	//parameter로 point class를 넘겨주고 싶은데, pt는 객체이므로 pass by value로 넘겨주면 새로운 객체 생성 -> 메모리 비효율적
	//=> pass by reference로 넘겨주어서 주소를 가르키게 함
	//++pass by reference이므로 pt의 값이 변경될 여지가 있음 => const를 붙여 메소드 내에서 pt의 값이 변경되지 않도록 설정
};

void point::setxy(int _x, int _y)
{
	this->x = _x; // this포인터: 현재 객체의 주소값을 가지고 있는 포인터 -> 변수 이름이 겹치는 경우 명확히 해줄 수 있음
	this->y = _y;
}
int point::getx() const { return this->x; }
int point::gety() const { return this->y; }
point point::operator+(const point& pt) //pt2 + pt3 -> pt2.+(pt3)
{
	point result(this->x + pt.getx(), this->y + pt.gety());
	return result;
}
point point::operator=(const point& pt)
{
	this->x = pt.getx(); // this포인터: 현재 객체의 주소값을 가지고 있는 포인터 -> 변수 이름이 겹치는 경우 명확히 해줄 수 있음
	this->y = pt.gety();
	return (*this);
}

// pass by reference: 객체를 함수의 인자로 전달할 때 pass by ref 사용 권장
// const: 함수 내부에 객체의 멤버변수가 바뀌지 않을 경우 const 삽입
//		   -> 이때, 객체의 const method만 사용 가능(method이름 const {})
void print_pt(const point& pt) 
{
	cout << pt.getx() << ", " << pt.gety() << endl;
}

//연산자 오버로딩: +, -, *, /, ==, >= 등을 객체에 대해 재정의
//	1)class 외부: operator+(좌측 피연산자, 우측 피연산자)
//	2)class 내부: operator+(우측 피연산자) -----> pt2 + pt3 -> pt2.+(pt3)
point operator+(const point& pt1, const point& pt2)
{
	point result(pt1.getx() + pt2.getx(), pt1.gety() + pt2.gety());
	return result;
}

// cout << pt1 ----> <<(cout, pt1)
// cout << pt1 << pt2
ostream& operator<<(ostream& cout, const point& pt)
{
	cout << pt.getx() << ", " << pt.gety() ;
	return cout;
}

int main()
{
	point pt1(1, 2);
	print_pt(pt1);

	//객체 pointer 단순화 문법: (*ppt).  --->   ppt->
	point* ppt = &pt1;
	cout << (*ppt).getx() << ", " << (*ppt).gety() << endl;
	cout << ppt->getx() << ", " << ppt->gety() << endl; //위와 아래는 완전히 동일한 방식으로 동작함
	cout << endl;

	point* list = new point[5];

	for (int i = 0; i < 5; i++)
	{
		cout << list[i].getx() << ", " << list[i].gety() << endl;
	}
	cout << endl;

	delete[] list;

	point pt2(10, 20);
	point pt3(100, 200);
	//pt1 = pt2 + pt3; -> 컴파일 오류 but 오버로딩을 통해 객체에 대해 함수를 재정의 해주면 시행 가능
	pt1 = pt2 + pt3;
	
	//cout << pt1 << endl; -> 컴파일 오류 but 오버로딩을 통해 객체에 대해 함수를 재정의 해주면 시행 가능
	cout << pt1 << endl;
	cout << pt2 << endl;
	cout << pt3 << endl;
	cout << endl;
	return 0;
}
*/


//practice
//#include <iostream>
//
//using namespace std;
//
//class point {
//private:
//	int x;
//	int y;
//public:
//	point(): x(0), y(0) {}
//	point(int _x, int _y): x(_x), y(_y) {}
//	void set_xy(int _x, int _y);
//	int get_x() const;
//	int get_y() const;
//	point operator+(const point& pt);
//	point operator=(const point& pt);
//};
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
//	point result(this->x += pt.get_x(), this->y += pt.get_y());
//	return result;
//}
//
//point point::operator=(const point& pt)
//{
//	this->x = pt.get_x();
//	this->y = pt.get_y();
//	return *this;
//}
//
//ostream& operator<<(ostream& cout, const point& pt) {
//	cout << pt.get_x() << ", " << pt.get_y() << endl;
//	return cout;
//}
//
//int main() {
//	point pt1;
//	point pt2(10, 20);
//
//	cout << pt2;
//	pt1.set_xy(1, 2);
//	point pt3;
//	pt3 = pt1 + pt2;
//	cout << pt3;
//
//	return 0;
//}