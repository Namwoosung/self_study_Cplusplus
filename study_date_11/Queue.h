#pragma once

#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyPointingIterator.h"

using namespace std;

template <typename T>
class DoublyLinkedList;
template <typename T>
struct Node;
template<typename T>
class DoublyPointingIterator;

template <typename T>
class Queue
{
private:
	DoublyLinkedList<T> line_;
	int length_;
public:
	Queue();
	Queue(const Queue& another);
	void Enqueue(T data);
	void Dequeue();
	T& Front();
	T& Back();
	bool IsEmpty();

	friend ostream& operator<<(ostream& os, const Queue<T>& one)
	{
		Queue<T> Queue_print = one;
		os << '[';
		while (true)
		{
			if (Queue_print.IsEmpty())
			{
				break;
			}
			T text = Queue_print.Back();
			os << text << ',';
			Queue_print.Dequeue();
		}
		os << ']' << endl;
		return os;
	}
};

template<typename T>
inline Queue<T>::Queue()
{
	DoublyLinkedList<T> list;
	line_ = list;
	length_ = 0;
}

template<typename T>
inline Queue<T>::Queue(const Queue& another)
{
	line_ = another.line_;
	length_ = another.length_;
}

template<typename T>
inline void Queue<T>::Enqueue(T data)
{
	line_.push_front(data);
	length_++;
	return;
}

template<typename T>
inline void Queue<T>::Dequeue()
{
	if (line_.tail_ == NULL)
	{
		cout << "이미 queue가 비어있습니다." << endl;
		return;
	}
	else
	{
		line_.pop_back();
		length_--;
		return;
	}
}

template<typename T>
inline T& Queue<T>::Front()
{
	if (line_.head_ == NULL)
	{
		cout << "Stack이 비어있습니다." << endl;
	}
	else
	{
		return line_.front();
	}
}

template<typename T>
inline T& Queue<T>::Back()
{
	if (line_.tail_ == NULL)
	{
		cout << "Stack이 비어있습니다." << endl;
	}
	else
	{
		return line_.back();
	}
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	if (line_.head_ == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
