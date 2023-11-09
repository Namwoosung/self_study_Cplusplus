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
class Stack
{
private:
	DoublyLinkedList<T> line_;
	int length_;
public:
	Stack();
	Stack(const Stack& another);
	void push(T data);
	void pop();
	T& top();
	bool IsEmpty();

	friend ostream& operator<<(ostream& os, const Stack<T>& one)
	{
		Stack<T> Stack_print = one;
		os << '[';
		while (true)
		{
			if (Stack_print.IsEmpty())
			{
				break;
			}
			T text = Stack_print.top();
			os << text << ',';
			Stack_print.pop();
		}
		os << ']' << endl;
		return os;
	}
};

template<typename T>
inline Stack<T>::Stack()
{
	DoublyLinkedList<T> list;
	line_ = list;
	length_ = 0;
}

template<typename T>
inline Stack<T>::Stack(const Stack& another)
{
	line_ = another.line_;
	length_ = another.length_;
}

template<typename T>
inline void Stack<T>::push(T data)
{
	line_.push_front(data);
	length_++;
	return;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (line_.head_ == NULL)
	{
		cout << "이미 stack이 비어있습니다." << endl;
		return;
	}
	else
	{
		line_.pop_front();
		length_--;
		return;
	}
}

template<typename T>
inline T& Stack<T>::top()
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
inline bool Stack<T>::IsEmpty()
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
