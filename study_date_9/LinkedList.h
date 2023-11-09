#pragma once

#include <iostream>

using namespace std;

/* 단일 연결 리스트
template <typename T>
struct Node
{
	T data_;
	Node* next_node_;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head_;
	int length_;
public:
	LinkedList();
	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void remove(T data);
	T& front();
	T& back();
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head_ = NULL;
	length_ = 0;
}

template<typename T>
inline void LinkedList<T>::push_front(T data)
{
	Node<T>* new_node = new Node<T>;

	new_node->data_ = data;
	new_node->next_node_ = head_;

	head_ = new_node;

	length_++;
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	Node<T>* temp = head_->next_node_;
	delete head_;
	head_ = temp;
	length_--;
}

template<typename T>
inline void LinkedList<T>::push_back(T data)
{
	Node<T>* new_node;
	new_node = new Node<T>;

	Node<T>* judge = head_;
	Node<T>* now_point;
	while (judge)
	{
		now_point = judge;
		judge = judge->next_node_;
		if (judge == NULL)
		{
			now_point->next_node_ = new_node;
		}
	}

	new_node->data_ = data;
	new_node->next_node_ = NULL;

	length_++;
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	Node<T>* judge = head_;
	Node<T>* now_point = head_;
	Node<T>* befo_point = head_;
	while (judge)
	{
		befo_point = now_point;
		now_point = judge;
		judge = (*judge).next_node_;
		if (judge == NULL)
		{
			befo_point->next_node_ = NULL;
			delete now_point;
		}
	}
	return;
}

template<typename t>
inline void LinkedList<t>::remove(t data)
{
	bool test = true;
	Node<t>* judge = head_;
	Node<t>* now_point = head_;
	Node<t>* befo_point = head_;
	while (judge)
	{
		befo_point = now_point;
		now_point = judge;
		judge = judge->next_node_;
		if (now_point->data_ == data)
		{
			if (befo_point == now_point)
			{
				head_ = judge;
			}
			befo_point->next_node_ = judge;
			delete now_point;
			test = false;
		}
	}
	if (test)
	{
		cout << "해당 데이터에 해당하는 요소가 없습니다." << endl;
	}
	return;
}

template<typename T>
inline T& LinkedList<T>::front()
{
	return head_->data_;
}

template<typename T>
inline T& LinkedList<T>::back()
{
	Node<T>* judge = head_;
	Node<T>* now_point;
	while (judge)
	{
		now_point = judge;
		judge = judge->next_node_;
		if (judge == NULL)
		{
			return now_point->data_;
		}
	}
}
*/

/*이중 연결 리스트
template <typename T>
struct Node
{
	T data_;
	Node* next_node_;
	Node* befo_node_;
};

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* head_;
	Node<T>* tail_;
	int length_;
public:
	DoublyLinkedList();
	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void remove(T data);
	T& front();
	T& back();
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	length_ = 0;
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(T data)
{
	Node<T>* new_node = new Node<T>;

	new_node->data_ = data;
	new_node->next_node_ = head_;
	new_node->befo_node_ = NULL;

	head_ = new_node;

	if (head_->next_node_ != NULL)
	{
		head_->next_node_->befo_node_ = new_node;
	}
	else
	{
		tail_ = head_;
	}

	length_++;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{
	Node<T>* temp = head_->next_node_;
	delete head_;
	head_ = temp;

	if (head_ != NULL)
	{
		head_->befo_node_ = NULL;
	}

	length_--;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(T data)
{
	Node<T>* new_node;
	new_node = new Node<T>;

	Node<T>* judge = head_;
	Node<T>* now_point;
	while (judge)
	{
		now_point = judge;
		judge = judge->next_node_;
		if (judge == NULL)
		{
			tail_ = new_node;
			now_point->next_node_ = new_node;
			new_node->befo_node_ = now_point;
		}
	}

	new_node->data_ = data;
	new_node->next_node_ = NULL;

	length_++;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{
	Node<T>* judge = head_;
	Node<T>* now_point = head_;
	Node<T>* befo_point = head_;
	while (judge)
	{
		befo_point = now_point;
		now_point = judge;
		judge = (*judge).next_node_;
		if (judge == NULL)
		{
			befo_point->next_node_ = NULL;
			delete now_point;
			tail_ = befo_point;
		}
	}
	return;
}

template<typename t>
inline void DoublyLinkedList<t>::remove(t data)
{
	bool test = true;
	Node<t>* judge = head_;
	Node<t>* now_point = head_;
	Node<t>* befo_point = head_;
	while (judge)
	{
		befo_point = now_point;
		now_point = judge;
		judge = judge->next_node_;
		if (now_point->data_ == data)
		{
			if (befo_point == now_point)
			{
				head_ = judge;
				judge->befo_node_ = NULL;
			}
			else if (judge == NULL)
			{
				tail_ = befo_point;
				befo_point->next_node_ = NULL;
			}
			else
			{
				befo_point->next_node_ = judge;
				judge->befo_node_ = befo_point;
			}
			delete now_point;
			test = false;
			length_--;
		}
	}
	if (test)
	{
		cout << "해당 데이터에 해당하는 요소가 없습니다." << endl;
	}
	return;
}

template<typename T>
inline T& DoublyLinkedList<T>::front()
{
	return head_->data_;
}

template<typename T>
inline T& DoublyLinkedList<T>::back()
{
	return tail_->data_;
}
*/
