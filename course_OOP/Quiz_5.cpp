#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
class Point
{
public:
	T x;
	T y;
	Point(T _x, T _y);
	bool operator==(const Point& pt);
};

void get_command(string& com);

template<typename T, typename Iter>
void count_val(Iter iter_begin, Iter iter_end);

int main()
{
	Point<int> myPoints[] = { {1,2}, {-1,5}, {3,7}, {2,4},{1,10},{1,2} };
	string command;

	while (1)
	{
		get_command(command);
		if (command == "1")			for_each(begin(myPoints), end(myPoints), [](Point<int> pt) {cout << "(" << pt.x << ", " << pt.y << ")" << endl; });
		else if (command == "2")	count_val<int>(begin(myPoints), end(myPoints));
		else if (command == "0")	break;
	}
	cout << "EXIT program.." << endl;

	return 0;
}

template<typename T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<typename T>
bool Point<T>::operator==(const Point& pt)
{
	if (this->x == pt.x)
	{
		if (this->y == pt.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void get_command(string& com)
{
	do
	{
		cout << "1. Print" << endl;
		cout << "2. Find Points" << endl;
		cout << "0.EXIT" << endl;
		cout << "Input>>";
		cin >> com;
	} while (!(com == "1" || com == "2" || com == "0"));
}


template<typename T, typename Iter>
void count_val(Iter iter_begin, Iter iter_end)
{
	T x, y;
	int count = 0;

	cout << "Enter (x, y): ";
	cin >> x >> y;

	Point<T> test_pt(x, y);

	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		if (test_pt == *iter)
		{
			count++;
		}
	}

	cout << "Number of matching elements: " << count << endl << endl;
}