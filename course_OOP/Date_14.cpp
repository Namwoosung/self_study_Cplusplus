//#include <iostream>
//
//using namespace std;
//class, ������, ������ �����ε�
/*class point 
{
private:
	int x;
	int y;
public:
	point() : x(0), y(0) {}
	point(int _x, int _y) : x(_x), y(_y) {}
	void setxy(int _x, int _y);
	int getx() const; //const method�� ���������ν� �ش� �޼ҵ忡�� ��������� ���� �� ������ ��� + ������ �ڵ��� ���� ����
	int gety() const; //++ const method������ ��������� �����ϰų�, const method�� �ƴ� �ٸ� method�� �� ȣ��� ������ ������ �߻�
	// => get�Լ��� ���� ��������� ���� ������ �ʿ�� ���� �ʴ� �޼ҵ�� const�� �ٿ� ������ִ� ���� ����
	point operator+(const point& pt); //pt2 + pt3 -> pt2.+(pt3)
	point operator=(const point& pt);
	//parameter�� point class�� �Ѱ��ְ� ������, pt�� ��ü�̹Ƿ� pass by value�� �Ѱ��ָ� ���ο� ��ü ���� -> �޸� ��ȿ����
	//=> pass by reference�� �Ѱ��־ �ּҸ� ����Ű�� ��
	//++pass by reference�̹Ƿ� pt�� ���� ����� ������ ���� => const�� �ٿ� �޼ҵ� ������ pt�� ���� ������� �ʵ��� ����
};

void point::setxy(int _x, int _y)
{
	this->x = _x; // this������: ���� ��ü�� �ּҰ��� ������ �ִ� ������ -> ���� �̸��� ��ġ�� ��� ��Ȯ�� ���� �� ����
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
	this->x = pt.getx(); // this������: ���� ��ü�� �ּҰ��� ������ �ִ� ������ -> ���� �̸��� ��ġ�� ��� ��Ȯ�� ���� �� ����
	this->y = pt.gety();
	return (*this);
}

// pass by reference: ��ü�� �Լ��� ���ڷ� ������ �� pass by ref ��� ����
// const: �Լ� ���ο� ��ü�� ��������� �ٲ��� ���� ��� const ����
//		   -> �̶�, ��ü�� const method�� ��� ����(method�̸� const {})
void print_pt(const point& pt) 
{
	cout << pt.getx() << ", " << pt.gety() << endl;
}

//������ �����ε�: +, -, *, /, ==, >= ���� ��ü�� ���� ������
//	1)class �ܺ�: operator+(���� �ǿ�����, ���� �ǿ�����)
//	2)class ����: operator+(���� �ǿ�����) -----> pt2 + pt3 -> pt2.+(pt3)
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

	//��ü pointer �ܼ�ȭ ����: (*ppt).  --->   ppt->
	point* ppt = &pt1;
	cout << (*ppt).getx() << ", " << (*ppt).gety() << endl;
	cout << ppt->getx() << ", " << ppt->gety() << endl; //���� �Ʒ��� ������ ������ ������� ������
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
	//pt1 = pt2 + pt3; -> ������ ���� but �����ε��� ���� ��ü�� ���� �Լ��� ������ ���ָ� ���� ����
	pt1 = pt2 + pt3;
	
	//cout << pt1 << endl; -> ������ ���� but �����ε��� ���� ��ü�� ���� �Լ��� ������ ���ָ� ���� ����
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