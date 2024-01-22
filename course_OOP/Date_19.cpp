#include <iostream>
#include <vector>
#include <list>

using namespace std;

//template 함수 혹은 클래스를 만들기 전 특정 데이터타입에서 동작하는 함수와 클래스를 만든 뒤 template로 변환 시켜주는 것이 편함
//tempate<typename T>: datatype에 일반화된 함수/클래스 지원
//-class template의 method가 class외부에서 구현(정의)될 때,
//	tempalte<typename T>를 함수 윗주에 삽입, 범위지정 연산자 앞 <T>삽입
//	예)Point<T>::Point()

/*template함수
template <typename T, typename U> //Generic 함수(template 함수)
bool less_than(const T& x,const U& y) { return x < y; }

template<typename T>
T sum(const vector<T>& v)
{
	T result = 0;
	for (T elem : v)
	{
		result += elem;
	}
	return result;
}

int main()
{
	cout << less_than(2, 3) << endl;
	cout << less_than(2.1, 2.7) << endl;
	cout << less_than(2, 2.7) << endl; //<class T> 혹은 <typename T>만 적어주면 오류 -> <class U> 혹은 <typename U>추가 

	vector<int> v1 {1, 2, 3};
	vector<double> v2{ 1.1, 2.2, 3.3 };

	cout << sum(v1) << endl;
	cout << sum(v2) << endl;

	return 0;
}
*/




/*template class
template <typename T>
class Point
{
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX() const;
	T getY() const;
	void print() const;
};

int main()
{
	Point<int> pt1(1, 2); //template class는 <data type>을 적어주어여함
	//vector또한 template객체 -> vector<data type>을 작성해주었던 것임
	Point<double> pt2(1.1, 2.2);
	pt1.print();
	pt2.print();

	return 0;
}

template<typename T> //클래스의 구현부와 선언부를 나눌때 메소드또한 모두 generic함수이기에 template<typename T>를 명시해주어야함
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}//Point::Point가 아닌 Point<T>::Point로 함수명 앞에 명시해주어야 함

template<typename T>
void Point<T>::setXY(T _x, T _y)
{
	x = _x;
	y = _y;
}

template<typename T>
T Point<T>::getX() const
{
	return x;
}

template<typename T>
T Point<T>::getY() const
{
	return y;
}

template<typename T>
void Point<T>::print() const
{
	cout << x << ", " << y << endl;
}
*/

/*Pointer를 사용한 예제
int main()
{
	int ary[] = { 1, 2, 3 };
	int* begin = ary;
	int* end = ary + 3;

	for (auto curr = begin; curr != end; curr++)
	{
		cout << *curr << '\t';
	}
	cout << endl;

	return 0;
}
*/

/*
//iterator: pointer-like object이며, container의 위치값(주소값) 저장 (포인터랑 거의 동일하게 사용가능)
//	-주요 함수: begin(v), end(v)
//	-주요 연산자: iter++, iterr--, *iter, iter1 != iter2 (iter += 5같은 연산 불가)
//iterator를 사용한 예제(iterator는 객체, 모든 container는 begin(), end()함수 존재)
int main()
{
	vector<int> v{ 1, 2, 3 };
	vector<int>::iterator iter_begin = begin(v); //v.begin(); -> v.begin은 vector안 메소드
	auto iter_end = end(v); //v.end();, end(v)는 C++에서 제공하는 글로벌 함수
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;

	return 0;
}
*/

/*여러 활용
//	container-generic function: template를 사용해서 iterator를 입력받음
//	-begin(), end() 를 통한 container의 iterator들을 입력으로 받음
template<typename Iter>
void print(Iter iter_begin, Iter iter_end) //iterator는 가벼운 객체기 때문에 굳이 reference로 넘겨주지 않아도 됨
{
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;
}

template<typename Iter, typename T>
int count_value(Iter iter_begin, Iter iter_end, T key_value)
{
	int count = 0;
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		if (*iter == key_value)
		{
			count++;
		}
	}
	return count;
}

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x, int _y) : x(_x), y(_y) {}
	bool operator==(const Point& pt)
	{
		return (x == pt.x) && (y == pt.y);
	}
};

int main()
{
	vector<int> v{ 1, 2, 3, 2, 2, 2 };
	list<double> l{ 1.1, 2.2, 3.3, 1.1, 1.1 };
	int ary[] = { 10, 20, 30, 30 };

	print(begin(v), end(v)); //모든 container에 대해 generic하게 동작하는 함수
	print(begin(l), end(l));
	print(begin(ary), end(ary));
	//tempalte와 iterator를 이용하여 구현가능
	cout << endl;

	cout << count_value(begin(v), end(v), 2) << endl; //container안에 2라는 인스턴스가 몇개인지 확인하는 함수
	cout << count_value(begin(l), end(l), 1.1) << endl;
	cout << count_value(begin(ary), end(ary), 30) << endl;

	Point pts[] = { {1,2}, {2,3}, {3,4}, {1,2} };
	cout << count_value(begin(pts), end(pts), Point{ 1,2 }) << endl; 

	return 0;
}
*/
