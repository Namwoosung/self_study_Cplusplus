#pragma once

#include <iostream>
#include "Iterator.h"

using namespace std;

template <typename T>
class Iterator;

template <typename T>
struct Node
{
	T val_;
	Node* left_;
	Node* right_;
};

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root_;
	int length_;
public:
	BinarySearchTree();
	void Insert(T val);
	int GetLength();
	bool IsEmpty();
	void Remove(T val);
//	iterator Search(T val);
	void Print_all();
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	root_ = NULL;
	length_ = 0;
}

template<typename T>
inline void BinarySearchTree<T>::Insert(T val)
{
	Node<T>* new_node = new Node<T>;

	new_node->left_ = NULL;
	new_node->right_ = NULL;
	new_node->val_ = val;

	Node<T>* now_root;
	now_root = root_;

	if (root_ == NULL)
	{
		root_ = new_node;

		length_++;
		return;
	}
	else
	{
		while (true)
		{
			if (val > now_root->val_)
			{
				if (now_root->right_ == NULL)
				{
					now_root->right_ = new_node;
					length_++;
					return;
				}
				else
				{
					now_root = now_root->right_;
				}
			}
			else if (val < now_root->val_)
			{
				if (now_root->left_ == NULL)
				{
					now_root->left_ = new_node;
					length_++;
					return;
				}
				else
				{
					now_root = now_root->left_;
				}
			}
			else
			{
				return;
			}
		}
	}
}

template<typename T>
inline int BinarySearchTree<T>::GetLength()
{
	return length_;
}

template<typename T>
inline bool BinarySearchTree<T>::IsEmpty()
{
	if (root_ == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void BinarySearchTree<T>::Remove(T val)
{
	Node<T>* now_point;
	now_point = root_;

	Node<T>* temp = NULL;
	Node<T>* del_point = NULL;
	Node<T>* renew_point = NULL;
	Node<T>* renew_befo_point = NULL;
	bool judge = true;

	if (val == root_->val_)
	{
		del_point = now_point;

		if (now_point->right_ != NULL)
		{
			now_point = now_point->right_;
			if (now_point->left_== NULL)
			{
				renew_point = now_point;
				renew_befo_point = del_point;
			}
			else
			{
				while (judge)
				{
					if (now_point->left_ == NULL)
					{
						renew_point = now_point;
						judge = false;
					}
					else if (now_point->left_->left_ == NULL)
					{
						renew_befo_point = now_point;
					}
					now_point = now_point->left_;
				}
				temp = renew_point->right_;
				renew_point->right_ = del_point->right_;
				renew_befo_point->left_ = temp;
			}
			renew_point->left_ = del_point->left_;
			root_ = renew_point;

			delete del_point;

			length_--;

			return;
		}
		else
		{
			root_ = del_point->left_;
			delete del_point;
			length_--;
			return;
		}
	}

	Node<T>* befo_point = NULL;

	while (true)
	{
		if (val > now_point->val_)
		{
			if (now_point->right_ == NULL)
			{
				cout << "해당 데이터가 트리안에 존재하지 않습니다!" << endl;
				return;
			}
			else
			{
				if (now_point->right_->val_ == val)
				{
					befo_point = now_point;
				}
				now_point = now_point->right_;
				if (val == now_point->val_)
				{
					del_point = now_point;

					if (now_point->right_ != NULL)
					{
						now_point = now_point->right_;
						if (now_point->left_ == NULL)
						{
							renew_point = now_point;
							renew_point->left_ = del_point->left_;

							befo_point->right_ = renew_point;

							delete del_point;

							length_--;

							return;
						}
						else
						{
							while (judge)
							{
								if (now_point->left_ == NULL)
								{
									renew_point = now_point;
									judge = false;
								}
								else if (now_point->left_->left_ == NULL)
								{
									renew_befo_point = now_point;
								}
								now_point = now_point->left_;
							}
							renew_point->left_ = del_point->left_;
							renew_point->right_ = del_point->right_;

							befo_point->right_ = renew_point;

							renew_befo_point->left_ = NULL;

							delete del_point;

							length_--;

							return;
						}
					}
					else
					{
						befo_point->right_ = del_point->left_;
						delete  del_point;

						length_--;

						return;
					}
				}
			}
		}
		else if (val < now_point->val_)
		{
			if (now_point->left_ == NULL)
			{
				cout << "해당 데이터가 트리안에 존재하지 않습니다!" << endl;
				return;
			}
			else
			{
				if (now_point->left_->val_ == val)
				{
					befo_point = now_point;
				}
				now_point = now_point->left_;
				if (val == now_point->val_)
				{
					del_point = now_point;

					if (now_point->right_ != NULL)
					{
						now_point = now_point->right_;
						if (now_point->left_ == NULL)
						{
							renew_point = now_point;
							renew_point->left_ = del_point->left_;

							befo_point->left_ = renew_point;

							delete del_point;

							length_--;

							return;
						}
						else
						{
							while (judge)
							{
								if (now_point->left_ == NULL)
								{
									renew_point = now_point;
									judge = false;
								}
								else if (now_point->left_->left_ == NULL)
								{
									renew_befo_point = now_point;
								}
								now_point = now_point->left_;
							}
							renew_point->left_ = del_point->left_;
							renew_point->right_ = del_point->right_;

							befo_point->right_ = renew_point;

							renew_befo_point->left_ = NULL;

							delete del_point;

							length_--;

							return;
						}
					}
					else
					{
						befo_point->left_ = del_point->left_;
						delete  del_point;
						length_--;
						return;
					}
				}
			}
		}
	}
}

/*template<typename T>
inline iterator BinarySearchTree<T>::Search(T val)
{
	return iterator();
}
*/
/*
template<typename T>
inline void BinarySearchTree<T>::Print_all()
{
}
*/