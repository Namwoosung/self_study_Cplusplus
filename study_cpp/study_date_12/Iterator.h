#pragma once

#include <iostream>
#include "binarysearchtree.h"

using namespace std;

template <typename T>
struct node;
template <typename T>
class binarysearchtree;

template <typename T>
class iterator
{
private:
	const binarysearchtree<T>& tree_;
	node<T>* current_node_;
public:
	iterator(const binarysearchtree<T>& tree) : tree_(tree), current_node_(tree.root_)
	{
	}
	iterator(const binarysearchtree<T>& tree, node<T>* current_node) : tree_(tree), current_node_(current_node)
	{
	}
}; 