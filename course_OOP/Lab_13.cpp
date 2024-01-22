//Date_19 & Date_20

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <ctime>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

/*기초문제 1
template<typename T, typename U>
bool less_than(const T& a,const U& b) { return a < b; }

template<typename T>
T sum(const vector<T>& v)
{
	T result = 0;
	for (auto elem : v)
	{
		result += elem;
	}
	return result;
}

int main()
{
	cout << less_than(2, 3) << endl;
	cout << less_than(2.1, 2.9) << endl;
	cout << less_than(2, 2.5) << endl;

	vector<int> v1{ 1, 2, 3, 4 };
	vector<double> v2{ 10.1, 20.2, 30.3, 40.4 };
	cout << sum(v1) << endl;
	cout << sum(v2) << endl;

	return 0;
}
*/

/*기초문제 2
template<typename T>
class Point
{
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX();
	T getY();
	void print();
};

template<typename T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<typename T>
void Point<T>::setXY(T _x, T _y)
{
	x = _x;
	y = _y;
}

template<typename T>
T Point<T>::getX()
{
	return x;
}

template<typename T>
T Point<T>::getY()
{
	return y;
}

template<typename T>
void Point<T>::print()
{
	cout << x << ", " << y << endl;
}

int main()
{
	Point<int> pt(1, 2);
	Point<double> pt2(1.1, 2.2);
	pt.print();
	pt2.print();

	return 0;
}
*/

/*기초문제 3
int main()
{
	list<int> myList{ 1,2,3,4 };
	char command;
	int inputVal;
	bool finished = false;
	while (!finished)
	{
		cout << "I)nput, P)rint, L)ength, E)mpth, Q)uit>>";
		cin >> command;

		switch (command)
		{
		case 'I':
		case 'i':
			cin >> inputVal;
			myList.push_back(inputVal);
			break;
		case 'P':
		case 'p':
			for (int elem : myList)
			{
				cout << elem << '\t';
			}
			cout << endl;
			break;
		case 'L':
		case 'l':
			cout << "Number of items: " << myList.size() << endl;
			break;
		case 'E':
		case 'e':
			myList.clear();
			break;
		case 'Q':
		case 'q':
			finished = true;
			cout << "Exit the program" << endl;
			break;
		default:
			cout << "Wrong command" << endl;
			break;
		}
	}
	return 0;
}
*/

/*기초문제 4
int main()
{
	int ary[] = { 1, 2 ,3, 4 };
	int* pBegin, * pEnd;
	pBegin = ary;
	pEnd = ary + 4;
	for (int* pIter = pBegin; pIter != pEnd; pIter++)
	{
		cout << *pIter << '\t';
	}
	cout << endl;

	vector<int> v{ 10, 20, 30, 40 };
	auto iter_begin = begin(v);
	auto iter_end = end(v);

	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;


	return 0;
}
*/

/*기초문제 5
template<typename Iter>
void print(const Iter& iter_begin, const Iter& iter_end)
{
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;
}

template<typename Iter>
void print_reverse(const Iter& iter_begin, const Iter& iter_end)
{
	Iter iter = iter_end;
	iter--;
	while (iter != iter_begin)
	{
		cout << *iter << '\t';
		iter--;
	}
	cout << *iter << '\t';
	cout << endl;
}

int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	list<double> l{ 1.1, 2.2, 3.3 };
	int ary[] = { 100, 200, 300, 400 };

	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(ary), end(ary));

	print_reverse(begin(v), end(v));
	print_reverse(begin(l), end(l));
	print_reverse(begin(ary), end(ary));

	return 0;
}
*/

/*응용문제 1
template<typename T>
class CList
{
private:
	T m_Array[5];
	int m_Length;
public:
	CList();

	bool IsEmpty();
	bool IsFull();

	void Add(T data);
	void Delete(T data);
	void Print();
};

int command()
{
	int num;

	cout << "\n\t---- manu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
	cin >> num;
	return num;
}

int main()
{
	CList<int> list;
	int input;
	int com;
	while (1)
	{
		com = command();
		switch (com)
		{
		case 1:
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n삭제할 데이터 : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t프로그램을 종료합니다.\n";
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

template<typename T>
CList<T>::CList()
{
	m_Length = 0;
}

template<typename T>
bool CList<T>::IsEmpty()
{
	if (m_Length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool CList<T>::IsFull()
{
	if (m_Length == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void CList<T>::Add(T data)
{
	if (IsFull())
	{
		cout << "\tList is full" << endl;
	}
	else
	{
		if (IsEmpty())
		{
			m_Array[m_Length] = data;
			m_Length++;
		}
		else
		{
			for (int i = 0; i < m_Length; i++)
			{
				if (m_Array[i] == data)
				{
					cout << " 중복된 데이터가 존재합니다." << endl;
					return;
				}
			}

			m_Array[m_Length] = data;
			for (int i = m_Length; i > 0; i--)
			{
				if (m_Array[i - 1] < data)
				{
					break;
				}
				else
				{
					T temp = m_Array[i - 1];
					m_Array[i - 1] = m_Array[i];
					m_Array[i] = temp;
				}
			}
			m_Length++;
		}
	}

}

template<typename T>
void CList<T>::Delete(T data)
{
	if (IsEmpty())
	{
		cout << "\tList is empty." << endl;
	}
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] == data)
			{
				for (int j = i; j < m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;
			}
		}
	}
}

template<typename T>
void CList<T>::Print()
{
	cout << " @@ Current List" << endl;
	for (int i = 0; i < m_Length; i++)
	{
		cout << " " << m_Array[i];
	}
	cout << endl;
}
*/

/*응용문제 2
int main()
{
	int vec1_max = 0, vec1_min = 100, vec2_max = 0, vec2_min = 100;
	vector<int> vector1(10);
	vector<int> vector2(10);

	srand((unsigned)time(NULL));

	for_each(begin(vector1), end(vector1), [](int& elem) {elem = rand() % 11; });
	for_each(begin(vector2), end(vector2), [](int& elem) {elem = rand() % 21; });

	vector<int>::iterator vec1_start = begin(vector1);
	vector<int>::iterator vec1_end = end(vector1);
	vector<int>::iterator vec2_start = begin(vector2);
	vector<int>::iterator vec2_end = end(vector2);

	cout << "<vector 1>" << endl;

	for (auto Iter = vec1_start; Iter != vec1_end; Iter++)
	{
		if (vec1_max < *Iter)
		{
			vec1_max = *Iter;
		}
		if (vec1_min > *Iter)
		{
			vec1_min = *Iter;
		}
		cout << *Iter << " ";
	}
	cout << endl << "<vector 2>" << endl;
	for (auto Iter = vec2_start; Iter != vec2_end; Iter++)
	{
		if (vec2_max < *Iter)
		{
			vec2_max = *Iter;
		}
		if (vec2_min > * Iter)
		{
			vec2_min = *Iter;
		}
		cout << *Iter << " ";
	}
	cout << endl << endl << "최댓값 = " << vec1_max * vec2_max << endl << "최솟값 = " << vec1_min * vec2_min << endl;

}
*/

/*응용문제 3
int main()
{
	string text;
	string x_text;
	while (1)
	{
		cout << "문자열 하나를 입력해주세요(EXIT입력시 프로그램 종료) : ";
		cin >> text;
		x_text.clear();

		if (text == "EXIT")
		{
			break;
		}

		cout << "입력하신 문자열의 역순 : ";
		for (int i = text.size() - 1; i >= 0; i--)
		{
			cout << text.at(i);
			x_text += text.at(i);
		}
		cout << endl;

		[](string text, string x_text) {if (text == x_text) cout << "이 문자는 회문입니다." << endl; else cout << "이 문자는 회문이 아닙니다." << endl; }(text, x_text);
		cout << endl;
	}
}
*/

/*응용문제 4
int main()
{
	int number = 0;
	cout << "홀수 숫자를 하나 입력해 주세요 : ";
	cin >> number;

	int row = number, col = number;
	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;
		}
	}

	int n_row = 0, n_col = number / 2, n_value = 1;
	int pre_row = n_row, pre_col = n_col;

	for (int i = 0; i < row * col; i++)
	{
		pre_row = n_row;
		pre_col = n_col;
		mat[n_row][n_col] = n_value;
		n_value++;
		pre_row--;
		pre_col++;
		if (pre_row < 0)
		{
			pre_row = number - 1;
		}
		if (pre_col >= number)
		{
			pre_col = 0;
		}
		if (mat[pre_row][pre_col] > 0)
		{
			n_row++;
			if (n_row < 0)
			{
				n_row = number - 1;
			}
		}
		else
		{
			n_row = pre_row;
			n_col = pre_col;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) <<mat[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;

	return 0;
}
*/

/*응용문제 5
template<typename T>
class Queue
{
private:
	T* p_list;
	int size;
	int MAX_SIZE;
public:
	Queue();
	~Queue();
	int find_index(T _item);
	void Enqueue(T _item);
	T Dequeue();
	void print() const;
	int get_size();
	T get_item(int _index);
};

int main()
{
	Queue<int> int_queue;
	Queue<float> float_queue;
	Queue<char> char_queue;

	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);

	float_queue.Enqueue(4.3);
	float_queue.Enqueue(2.5);
	float_queue.Enqueue(3.7);
	float_queue.Enqueue(3.7);

	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');

	cout << "<Before Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();

	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();

	cout << "<After Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();

	return 0;

}

template<typename T>
Queue<T>::Queue()
{
	MAX_SIZE = 1000;
	p_list = new T[MAX_SIZE];
	size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] p_list;
}

template<typename T>
int Queue<T>::find_index(T _item)
{
	T* begin = p_list;
	T* end = p_list + size;
	int n_index = 0;
	for (T* curr = begin; curr != end; curr++)
	{
		if (*curr == _item)
		{
			return n_index;
		}
		n_index++;
	}
	return -1;
}

template<typename T>
void Queue<T>::Enqueue(T _item)
{
	if (find_index(_item) == -1)
	{
		if (size < MAX_SIZE)
		{
			p_list[size] = _item;
			size++;
		}
		else
		{
			cout << "Error: out of mamory" << endl;
		}
	}
}

template<typename T>
T Queue<T>::Dequeue()
{
	if (size == 0)
	{
		cout << "Error: No item exists in the list" << endl;
	}
	else
	{
		T value = p_list[0];
		for (int i = 0; i < size - 1; i++)
		{
			T temp = p_list[i];
			p_list[i] = p_list[i + 1];
			p_list[i + 1] = p_list[i];
		}
		size--;
		return value;
	}
}

template<typename T>
void Queue<T>::print() const
{
	T* begin = p_list;
	T* end = p_list + size;

	cout << "items in the list : ";
	for (T* curr = begin; curr != end; curr++)
	{
		cout << *curr << ", ";
	}
	cout << endl;
}

template<typename T>
int Queue<T>::get_size()
{
	return size;
}

template<typename T>
T Queue<T>::get_item(int _index)
{
	return p_list[3];
}
*/