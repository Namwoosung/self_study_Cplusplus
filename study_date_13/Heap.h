#pragma once

#include <iostream>

using namespace std;

template<typename T>
class HeapBase
{
protected:
	int Max_size_;
	int length_;
	T* list_;
public:
	HeapBase();
	HeapBase(int max_size);
	HeapBase(T list[], int length);
	HeapBase(int max_size, T list[], int length);
	int Parent(int index);
	int Right(int index);
	int Left(int index);
	T GetdRoot();
	T virtual Pop() = 0;
	void virtual Push(T item) = 0;

};

template<typename T>
inline HeapBase<T>::HeapBase()
{
	Max_size_ = 20;
	length_ = 0;
	list_ = new T[Max_size_];
}

template<typename T>
inline HeapBase<T>::HeapBase(int max_size)
{
	Max_size_ = max_size;
	length_ = 0;
	list_ = new T[Max_size_];
}

template<typename T>
inline HeapBase<T>::HeapBase(T list[], int length)
{
	Max_size_ = 20;
	length_ = length;
	list_ = new T[Max_size_];
	for (int i = 0; i < length; i++)
	{
		list_[i] = list[i];
	}
}

template<typename T>
inline HeapBase<T>::HeapBase(int max_size, T list[], int length)
{
	Max_size_ = max_size;
	list_ = new T[Max_size_];
	for (int i = 0; i < length; i++)
	{
		list_[i] = list[i];
	}
	length_ = length;
}

template<typename T>
inline int HeapBase<T>::Parent(int index)
{
	return (index - 1) / 2;
}

template<typename T>
inline int HeapBase<T>::Right(int index)
{
	return (2 * index) + 2;
}

template<typename T>
inline int HeapBase<T>::Left(int index)
{
	return (2 * index) + 1;
}

template<typename T>
inline T HeapBase<T>::GetdRoot()
{
	if (length_ == 0)
	{
		cout << "리스트가 비어있습니다." << endl;
	}
	else
	{
		return list_[0];
	}
}

template<typename T>
class MinHeap : public HeapBase<T>
{
public:
	T virtual Pop();
	void virtual Push(T item);

	MinHeap(int max_size);
	MinHeap(T list[], int length);
	MinHeap(int max_size, T list[], int length);
	MinHeap(const MinHeap& another);

	using HeapBase<T>::length_;
	using HeapBase<T>::list_;
	using HeapBase<T>::Max_size_;
	using HeapBase<T>::Parent;
	using HeapBase<T>::Left;
	using HeapBase<T>::Right;

	friend ostream& operator<<(ostream& os, const MinHeap<T>& one)
	{
		MinHeap<T> print_heap = one;
		T data;
		os << '[';
		for (int i = 0; i < one.length_; i++)
		{
			data = print_heap.Pop();
			os << data << ',';
		}
		os << ']' << endl;
		return os;
	}
};

template<typename T>
inline void MinHeap<T>::Push(T item)
{
	int test_point = length_;
	int now_point = length_;
	T temp = 0;

	if (length_ >= Max_size_)
	{
		cout << "사이즈 초과! 아이템을 추가할 수 없습니다!" << endl;
		return;
	}
	else
	{
		list_[length_] = item;
		if (length_ == 0)
		{
			length_++;
			return;
		}
		else
		{
			while (true)
			{
				now_point = test_point;
				test_point = Parent(test_point);
				if (item < list_[test_point])
				{
					temp = list_[test_point];
					list_[test_point] = item;
					list_[now_point] = temp;
				}
				else
				{
					length_++;
					return;
				}
			}
		}
	}
}

template<typename T>
inline MinHeap<T>::MinHeap(int max_size)
{
	Max_size_ = 20;
	length_ = 0;
	list_ = new T[Max_size_];
}

template<typename T>
inline MinHeap<T>::MinHeap(T list[], int length)
{
	Max_size_ = 20;
	length_ = length;
	list_ = new T[Max_size_];
	for (int i = 0; i < length; i++)
	{
		list_[i] = list[i];
	}
	MinHeap<T> print_heap = *this;
	T data;
	for (int i = 0; i < this->length_; i++)
	{
		data = print_heap.Pop();
		this->list_[i] = data;
	}
}

template<typename T>
inline MinHeap<T>::MinHeap(int max_size, T list[], int length)
{
	Max_size_ = max_size;
	list_ = new T[Max_size_];
	for (int i = 0; i < length; i++)
	{
		list_[i] = list[i];
	}
	length_ = length;
	MinHeap<T> print_heap = *this;
	T data;
	for (int i = 0; i < this->length_; i++)
	{
		data = print_heap.Pop();
		this->list_[i] = data;
	}
}

template<typename T>
inline MinHeap<T>::MinHeap(const MinHeap& another)
{
	Max_size_ = another.Max_size_;
	length_ = another.length_;
	list_ = new T[Max_size_];
	for (int i = 0; i < length_; i++)
	{
		list_[i] = another.list_[i];
	}
}

template<typename T>
inline T MinHeap<T>::Pop()
{
	int test_point = 0;
	int now_point = 0;
	T temp = 0;
	T re_value = 0;

	if (length_ == 0)
	{
		cout << "이미 리스트가 비어있습니다!" << endl;
	}
	else if (length_ == 1)
	{
		length_--;
		return list_[length_];
	}
	else
	{
		length_--;
		temp = list_[0];
		re_value = temp;
		list_[0] = list_[length_];
		while (true)
		{
			if (Left(now_point) > length_ && Right(now_point) > length_)
			{
				return re_value;
			}
			else if (Right(now_point) > length_)
			{
				if (list_[now_point] > list_[Left(now_point)])
				{
					test_point = Left(now_point);
					temp = list_[test_point];
					list_[test_point] = list_[now_point];
					list_[now_point] = temp;
					now_point = test_point;
				}
				else
				{
					return re_value;
				}
			}
			else
			{
				if (list_[now_point] > list_[Left(now_point)] || list_[now_point] > list_[Right(now_point)])
				{
					if (list_[Left(now_point)] < list_[Right(now_point)])
					{
						test_point = Left(now_point);
						temp = list_[test_point];
						list_[test_point] = list_[now_point];
						list_[now_point] = temp;
						now_point = test_point;
					}
					else
					{
						test_point = Right(now_point);
						temp = list_[test_point];
						list_[test_point] = list_[now_point];
						list_[now_point] = temp;
						now_point = test_point;
					}
				}
				else
				{
					return re_value;
				}
			}
		}
	}
}