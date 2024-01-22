//Date_21

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

/*기초문제 1
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int, int), int x, int y)
{
	return f(x, y);
}

int main()
{
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;

	cout << evaluate([](int x, int y)-> int {return x + y; }, 20, 30) << endl;
	cout << evaluate([](int x, int y) {return x * y; }, 20, 30) << endl;

	[](int x, int y) {cout << x << ", " << y << endl; }(20, 30);

	auto f = [](int x, int y) {return x - y; };
	cout << f(1000, 2000) << endl;

	return 0;
}
*/

/*기초문제 2
int evaluate2(function<int(int, int)> f, int x, int y)
{
	return f(x, y);
}

int main()
{
	int a = 10, b = 20;

	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3) << endl;

	[&](int x) { a = 20; cout << a * x << endl; }(10);
	cout << "a: " << a << endl;
	return 0;
}
*/

/*기초문제 3
int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	for(int& elem : v1)
	{
		cout << elem << '\t';
	}
	cout << endl;

	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) { elem++; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem += a; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	copy(begin(v1) + 1, end(v1) - 1, begin(v2) + 2);
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;


	transform(begin(v1), end(v1), begin(v2), [](int elem) {return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	return 0;
}
*/

/*기초문제 4
int main()
{
	vector<int> v{ 1, 2, 3, 4 };

	int index;
	cin >> index;
	try {
		cout << v.at(index) << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		cout << "인덱스 에러" << endl;
	}

	cout << "[program is running]" << endl;
	return 0;
}
*/

/*기초문제 5
class FileNotFoundException : public exception
{
private:
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw()
	{
		return message.c_str();
	}
};

vector<int> load_vector(string filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		throw FileNotFoundException(filename);
	}

	vector<int> result;
	int num, value;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		fin >> value;
		result.push_back(value);
	}
	return result;
}

int main()
{
	try
	{
		vector<int> v = load_vector("values.dat");
		for (int elem : v)
		{
			cout << elem << ' ';
		}
		cout << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
*/

/*응용문제 1
int main()
{
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num;
	while (1)
	{
		cout << "출력 할 숫자의 수 : ";
		cin >> num;
		
		if (num < 0)
		{
			break;
		}

		try
		{
			for (int i = 0; i < num; i++)
			{
				cout << list.at(i) << ' ';
			}
			cout << endl;
		}
		catch (exception& e)
		{
			cout << endl;
			cout << "Index is out of range. P/lease try again." << endl;
		}
	}
	cout << "Program exit..." << endl;
	return 0;
}
*/

/*응용문제 2
int main()
{
	vector<int> list;

	srand((unsigned)time(NULL));

	int size = rand() % 100 + 1;
	for (int i = 0; i < size; i++)
	{
		list.push_back(i);
	}

	int cnt = -1;
	while (1)
	{
		cnt++;
		try
		{
			list.at(cnt);
		}
		catch (exception& e)
		{
			cout << "현재 list는 " << cnt << "의 크기를 가지고 있다." << endl;
			break;
		}
	}

	return 0;
}
*/

/*응용문제 3
class FileNotFoundException : public exception
{
	string message;
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}
	virtual const char* what() const throw()
	{
		return message.c_str();
	}
};

class CStudent
{
private:
	string m_Name;
	int m_Number;
	string m_Major;
public:
	CStudent() {}
	~CStudent() {}
	void setAll(string _name, int _num, string _maj)
	{
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
	}
	void Display()
	{
		cout << "이름: " << m_Name << endl;
		cout << "학번: " << m_Number << endl;
		cout << "전공: " << m_Major << endl << endl;
	}
};

vector<CStudent> read_file(string& filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		throw FileNotFoundException(filename);
	}

	vector<CStudent> result;
	int num, number;
	CStudent stu;
	string name, major;

	fin >> num;

	for (int i = 0; i < num; i++)
	{
		fin >> name >> number >> major;
		stu.setAll(name, number, major);
		result.push_back(stu);
	}

	return result;
}

int main()
{
	string str;

	cout << "파일 이름 : ";
	cin >> str;

	try
	{
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
		{
			value.Display();
		}
	}
	catch (std::exception & e)
	{
		cout << e.what() << '\n';
	}

	return 0;
}
*/

/*응용문제 4
class FileNotFoundException : public exception
{
private:
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw()
	{
		return message.c_str();
	}
};

int main()
{
	srand((unsigned)time(NULL));

	ofstream ofs;
	ofs.open("temp.txt");

	int number;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			number = rand() % 101;
			ofs << number << " ";
		}
		ofs << endl;
	}

	ofs.close();

	string f_name;

	cout << "파일 이름 : ";
	cin >> f_name;

	try
	{
		ifstream fin(f_name);

		if (!fin)
		{
			throw FileNotFoundException(f_name);
		}

		vector<vector<int>> vec;
		int number = 0;
		for (int i = 0; i < 10; i++)
		{
			vector<int> in_vec;
			for (int j = 0; j < 10; j++)
			{
				fin >> number;
				in_vec.push_back(number);
			}
			vec.push_back(in_vec);
		}

		fin.close();

		int row, col;
		cout << "출력할 행 크기:";
		cin >> row;
		cout << "출력할 열 크기: ";
		cin >> col;

		try
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << vec.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}
		catch (exception & e)
		{
			cout << e.what() << endl;
		}
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
*/