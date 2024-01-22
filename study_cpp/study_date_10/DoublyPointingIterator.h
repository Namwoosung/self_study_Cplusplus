#pragma once

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <typename T>
class DoublyLinkedList;
template <typename T>
struct Node;

template <typename T>
class DoublyPointingIterator
{
private:
	const DoublyLinkedList<T>& list_;
	Node<T>* current_node_;

public:
	DoublyPointingIterator(const DoublyLinkedList<T>& list) : list_(list), current_node_(list.head_)
	{
	}
	DoublyPointingIterator(const DoublyLinkedList<T>& list, Node<T>* current_node) : list_(list), current_node_(current_node)
	{
	}
	DoublyPointingIterator<T>& operator++()
	{
		current_node_ = current_node_->next_node_;
		return *this;
	}
	DoublyPointingIterator<T>& operator--()
	{
		current_node_ = current_node_->befo_node_;
		return *this;
	}
	bool operator!=(const DoublyPointingIterator& another)
	{
		if (this->current_node_ == another.current_node_)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	DoublyPointingIterator<T>& operator=(const DoublyPointingIterator<T>& another)
	{
		DoublyPointingIterator<T> test(another.list_, another.current_node_);
		return test;
	}
	T& operator*()
	{
		return this->current_node_->data_;
	}

	friend class DoublyLinkedList<T>;
};