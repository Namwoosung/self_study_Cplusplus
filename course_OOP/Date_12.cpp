//#include <iostream>
//
//using namespace std;

/*class
//private: class�� �����/ class�ܺο��� ���� �Ұ� (data)
//public: class ��/�ܿ��� ��� ��밡�� (function = method)
//getter: private��� ������ �ܺη� ��ȯ
//setter: private��� ������ ����
class Point
{
private: //data
	int x;
	int y;
public: //function
	void setXY(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
};

int main()
{
	Point pt1, pt2;
	//pt1.X = 10; <- ������ ����
	//pt1.Y = 20; <- ������ ����
	//Point ��ü �� x,y ��� ������ private �̹Ƿ� ���� ���� �Ұ��� -> �޼ҵ带 ���� ����

	pt1.setXY(10, 20);

	cout << pt1.getX() << ", " << pt1.getY() << endl;

	return 0;
}
*/

/* practice
#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	void set_XY(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int get_X() {
		return x;
	}
	int get_Y() {
		return y;
	}
};

int main() {
	Point p1, p2;
	p1.set_XY(10, 20);
	p2.set_XY(1, 2);

	cout << p1.get_X() << '\t' << p1.get_Y() << endl;
	cout << p2.get_X() << '\t' << p2.get_Y() << endl;

	return 0;
}
*/