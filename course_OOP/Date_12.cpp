//#include <iostream>
//
//using namespace std;

/*class
//private: class내 사용사능/ class외부에서 접근 불가 (data)
//public: class 내/외에서 모두 사용가능 (function = method)
//getter: private멤버 변수를 외부로 반환
//setter: private멤버 변수를 수정
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
	//pt1.X = 10; <- 컴파일 오류
	//pt1.Y = 20; <- 컴파일 오류
	//Point 객체 속 x,y 멤버 변수는 private 이므로 직접 접근 불가능 -> 메소드를 통해 접근

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