#include <iostream>
#include <vector>
#include <list>

using namespace std;

//template �Լ� Ȥ�� Ŭ������ ����� �� Ư�� ������Ÿ�Կ��� �����ϴ� �Լ��� Ŭ������ ���� �� template�� ��ȯ �����ִ� ���� ����
//tempate<typename T>: datatype�� �Ϲ�ȭ�� �Լ�/Ŭ���� ����
//-class template�� method�� class�ܺο��� ����(����)�� ��,
//	tempalte<typename T>�� �Լ� ���ֿ� ����, �������� ������ �� <T>����
//	��)Point<T>::Point()

/*template�Լ�
template <typename T, typename U> //Generic �Լ�(template �Լ�)
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
	cout << less_than(2, 2.7) << endl; //<class T> Ȥ�� <typename T>�� �����ָ� ���� -> <class U> Ȥ�� <typename U>�߰� 

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
	Point<int> pt1(1, 2); //template class�� <data type>�� �����־��
	//vector���� template��ü -> vector<data type>�� �ۼ����־��� ����
	Point<double> pt2(1.1, 2.2);
	pt1.print();
	pt2.print();

	return 0;
}

template<typename T> //Ŭ������ �����ο� ����θ� ������ �޼ҵ���� ��� generic�Լ��̱⿡ template<typename T>�� ������־����
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}//Point::Point�� �ƴ� Point<T>::Point�� �Լ��� �տ� ������־�� ��

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

/*Pointer�� ����� ����
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
//iterator: pointer-like object�̸�, container�� ��ġ��(�ּҰ�) ���� (�����Ͷ� ���� �����ϰ� ��밡��)
//	-�ֿ� �Լ�: begin(v), end(v)
//	-�ֿ� ������: iter++, iterr--, *iter, iter1 != iter2 (iter += 5���� ���� �Ұ�)
//iterator�� ����� ����(iterator�� ��ü, ��� container�� begin(), end()�Լ� ����)
int main()
{
	vector<int> v{ 1, 2, 3 };
	vector<int>::iterator iter_begin = begin(v); //v.begin(); -> v.begin�� vector�� �޼ҵ�
	auto iter_end = end(v); //v.end();, end(v)�� C++���� �����ϴ� �۷ι� �Լ�
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;

	return 0;
}
*/

/*���� Ȱ��
//	container-generic function: template�� ����ؼ� iterator�� �Է¹���
//	-begin(), end() �� ���� container�� iterator���� �Է����� ����
template<typename Iter>
void print(Iter iter_begin, Iter iter_end) //iterator�� ������ ��ü�� ������ ���� reference�� �Ѱ����� �ʾƵ� ��
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

	print(begin(v), end(v)); //��� container�� ���� generic�ϰ� �����ϴ� �Լ�
	print(begin(l), end(l));
	print(begin(ary), end(ary));
	//tempalte�� iterator�� �̿��Ͽ� ��������
	cout << endl;

	cout << count_value(begin(v), end(v), 2) << endl; //container�ȿ� 2��� �ν��Ͻ��� ����� Ȯ���ϴ� �Լ�
	cout << count_value(begin(l), end(l), 1.1) << endl;
	cout << count_value(begin(ary), end(ary), 30) << endl;

	Point pts[] = { {1,2}, {2,3}, {3,4}, {1,2} };
	cout << count_value(begin(pts), end(pts), Point{ 1,2 }) << endl; 

	return 0;
}
*/
