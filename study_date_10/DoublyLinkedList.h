#pragma once

#include <iostream>
#include "DoublyPointingIterator.h"

using namespace std;

template <typename T>
struct Node
{
	T data_;
	Node* next_node_;
	Node* befo_node_;
};
template<typename T>
class DoublyPointingIterator;

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

	DoublyPointingIterator<T> begin();
	DoublyPointingIterator<T> end();
	DoublyPointingIterator<T> Insert(DoublyPointingIterator<T> pos, T value);
	DoublyPointingIterator<T> Erase(DoublyPointingIterator<T> pos);
	DoublyPointingIterator<T> GetIterator(const T& Item);

	friend class DoublyPointingIterator<T>;
	typedef DoublyPointingIterator<T> Iterator;
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
	new_node->data_ = data;
	new_node->next_node_ = NULL;

	Node<T>* judge = head_;
	Node<T>* now_point;

	if (head_ == NULL)
	{
		new_node->befo_node_ = NULL;
		head_ = new_node;
		tail_ = new_node;
	}
	else
	{
		while (judge)
		{
			now_point = judge;
			judge = judge->next_node_;
			if (judge == NULL)
			{

				new_node->befo_node_ = now_point;
				tail_ = new_node;
				now_point->next_node_ = new_node;
			}
		}
	}

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

template<typename T>
inline DoublyPointingIterator<T> DoublyLinkedList<T>::begin()
{
	DoublyPointingIterator<T> test(*this, this->head_);
	return test;
}

template<typename T>
inline DoublyPointingIterator<T> DoublyLinkedList<T>::end()
{
	if (this->tail_ == NULL)
	{
		DoublyPointingIterator<T> test(*this, this->tail_);
		return test;
	}
	else
	{
		DoublyPointingIterator<T> test(*this, this->tail_->next_node_);
		return test;
	}
}

template<typename T>
DoublyPointingIterator<T> DoublyLinkedList<T>::Insert(DoublyPointingIterator<T> pos, T value)
{
	Node<T>* new_node = new Node<T>;

	length_++;

	new_node->data_ = value;
	new_node->befo_node_ = pos.current_node_->befo_node_;
	new_node->next_node_ = pos.current_node_;

	pos.current_node_->befo_node_->next_node_ = new_node;

	pos.current_node_->befo_node_ = new_node;

	DoublyPointingIterator<T> test(pos.list_, new_node);
	return test;
}

template<typename T>
inline DoublyPointingIterator<T> DoublyLinkedList<T>::Erase(DoublyPointingIterator<T> pos)
{
	DoublyPointingIterator<T> test(pos.list_, pos.current_node_->next_node_);
	if (pos.current_node_->befo_node_ == NULL)
	{
		pos.current_node_->next_node_->befo_node_ = NULL;
	}
	else if (pos.current_node_->next_node_ == NULL)
	{
		pos.current_node_->befo_node_->next_node_ = NULL;
	}
	else
	{
		pos.current_node_->befo_node_->next_node_ = pos.current_node_->next_node_;
		pos.current_node_->next_node_->befo_node_ = pos.current_node_->befo_node_;
	}

	length_--;
	delete pos.current_node_;

	return test;
}

template<typename T>
inline DoublyPointingIterator<T> DoublyLinkedList<T>::GetIterator(const T& Item)
{
	DoublyPointingIterator<T> test(*this, this->head_);
	while (test.current_node_)
	{
		++test;
		if (test.current_node_->data_ == Item)
		{
			return test;
		}
	}
}
