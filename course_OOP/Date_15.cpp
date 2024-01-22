
#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
	static int cntObj; // static ��� ������ ��ü �� or main�Լ� �ȿ��� �ʱ�ȭ�ϸ� X 
	//static ��� ������ ��ü���� ���� ����(��ġ method�� �����ϴ� �Ͱ� ����), ��� ��ü�� static��� ������ ���� ������ �ּҰ��� ����
	//static��������� ��ü�ȿ��� Ȥ�� �����ڿ��� �ʱ�ȭ�ҽ� ��ü �����ø��� �ʱ�ȭ �Ǳ� ������ ����� �� ���� => ������������ �ʱ�ȭ ���־�� ��
	//��� ��ü���� �����ϰ� �����ؾ� �� ������ ������ �� ���(ex ���� ��ü�� �����Ǿ��ִ� ����)
	//Ŭ���� ������ ������ ���� �޸� �Ҵ��� �Ǿ�����������, �������� ������ �������ָ� �޸𸮰� �Ҵ� �� -> ��ü ������������ print�� �����ϸ� ���� ����
	//static������ cpp���Ͽ��� ���� �� ���Ǹ� ����� ��, ���� h���Ͽ��� �� ��� �ٸ� ���Ͽ��� ������ include�Ѵٸ� ������ ���� �� ����Ǵ� �Ͱ� ���� ����
	//static ������ private������ �������� ������ �־���ϱ� ������ ������������ ������ ������
	//const static������ ��ü�ȿ��� ���� �� ���ǰ� �����ϰ�, h���Ͽ��� �����ϴ� �� ���� ����(const ���� ��� ������ ������ ���� �Ҵ�ǰ� �����Ǳ� ����)
	//=> ��� ��ü�� �����ؾ��ϰ�, ���� ������ �ʿ���� ������ ��� const statice���� ����

	// int* list;
	// ofstream fout;
public:
	Point() : x(0), y(0)
	{
		// list = new int[100];
		// fout.open("example.txt")
		cntObj++;
	}
	Point(int _x, int _y) : x(_x), y(_y) { cntObj++; } // �Լ� �����ε�: ���� �Լ� �̸� ���, �Ű������� �ٸ���� �ٸ��� �����ϰ� ��(�Լ� �̸� ����, �Ķ���� ���� Ȥ�� �Ķ������ �ڷ��� �ٸ�, return�ڷ��� ���Ƶ� �ǰ� �޶� ��)
	//<-> �������̵�: ��ӹ��� �ڽ� ��ü���� �θ� ��ü�� ������ �޼ҵ带 �����ϰ�, �θ� �޼ҵ�� ������ �ٸ� �Լ��� �����ϴ� ��(�Լ� �̸�, �Ķ���� ����, �ڷ���, return�� �ڷ��� ����, �Լ� ���� �ٸ� )
	~Point()//�Ҹ��ڴ� �⺻������ ����Ǿ� �ְ�, ��ü�� �������� �� �� ȣ���
	//�����ڰ� ���� �Ҹ��ڸ� �����ϴ� ��Ȳ�� ��ü ������ �������� ����� �迭�� �ְų�, ������ �ݾƾ� �� ���
	{
		// delete[] list; : �Ҹ��� ��� ���� 1
		// fout.close(); : �Ҹ��� ��� ���� 2
		cout << "Destructed.." << endl; //�Ҹ��ڰ� ȣ��Ǿ����� cout�� ���� ����ϴ� ����
	}
	void setXY(int _x, int _y);
	int getX() const { return this->x; } // const�޼ҵ�� �ٲٱ�
	int getY() const { return this->y; }
	static int getCntObj() { return cntObj; }
	Point operator+(const Point& pt);
	Point& operator=(const Point& pt);
	//��ü ������ friend�� �Լ� Ȥ�� Ŭ������ ������ ��� ����� �Լ��� Ŭ���������� �ش� ��ü�� privateȤ�� protected�� ����� �͵鿡 ���� ������ ���� 
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint; // friend class�� Point�� �� �� ���� but, Point�� friend�� �� ��
};

// pass by reference: ��ü�� �Լ��� ���ڷ� ������ �� pass by ref. ��� ����
// const: �Լ� ������ ��ü�� ��� ������ �ٲ��� ���� ��� const ����
//      -> �̶�, ��ü�� const method�� ��� ����( method�̸� const { })
void print_pt(const Point& pt)
{
	cout << pt.getX() << ", " << pt.getY() << endl;
}

// ������ �����ε�: +, -, *, ==, >= ���� ��ü�� ���� ������
//      1) class �ܺ�: operator+(���� �ǿ�����, ���� �ǿ�����)
//      2) class ����: operator+(���� �ǿ�����) 

// ������ �����ε� 1)
// pt1 + pt2 --> +(pt1, pt2)
//Point operator+(const Point pt1, const Point pt2) 
//{
//   Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY()); // result ��� �Լ��� �����
//   return result;
//}

// cout << pt1 --> <<(cout, pt1) -> return cout
// cout << pt1 << pt2; : ��� �̷������� <<�� cout�� return �� �ʿ䰡 ����
// ��> (cout << pt1) -> cout << pt2
//ostream& operator<<(ostream& cout, const Point& pt)
//{
//   cout << pt.getX() << ", " << pt.getY();
//   return cout;
//}
ostream& operator<<(ostream& cout, const Point& pt)
{
	cout << pt.x << ", " << pt.y; // friend �Լ��� Point�� �� �� ���� but, Point�� friend�� �� �� (class�� ��������)
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

	//// ��ü pointer �ܼ�ȭ ����: (*pPt). --> pPt->
	//Point* pPt = &pt1; // ��ü�� �ƴ�, ���� �� ��
	//cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	//cout << pPt->getX() << ", " << pPt->getY() << endl; // �ܼ�ȭ�� ������ ��� ���
	//cout << endl;

	//Point* list = new Point[5];
	//for (int i = 0; i < 5; i++)
	//   cout << list[i].getX() << ", " << list[i].getY() << endl;
	//cout << endl;
	//delete[] list;

	//// a = b + c; -> a = +(b, c): +�� �Լ�
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
	pt1 = pt2 + pt3; // operator+���� result ��ü�� �����Ǹ鼭 �ϳ� �� �þ
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

// ������ �����ε� 2)
// pt2 + pt3 -> pt2.+(pt3)
Point Point::operator+(const Point& pt)
{
	Point result(this->x + pt.getX(), this->y + pt.getY());
	return result;
}

// pt1 = pt2 = pt3
Point& Point::operator=(const Point& pt) // &: return by ref�� pt1, pt2 �� ����ȭ �ż� �� ���� ������
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
