#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class ArrayList
{
private:
	T* data_;
	int length_;
	int size_;
	int iter_;
public:
	ArrayList();
	ArrayList(int size);
	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	bool Append(T item);
	bool Insert(T item, int index);
	int Index(T item);
	T* GetItemAddress(int index);
	bool Remove(T item);
	bool Delete(int index);
	bool SetItem(int index, T item);
	bool Reverse();
	void ResetIterator();
	T* GetNextItemAddress();
	friend ostream& operator<<(ostream& os, const ArrayList<T>& one)
	{
		os << '[';
		for (int i = 0; i < one.length_; i++)
		{
			os << one.data_[i] << ", ";
		}
		os << ']' << endl;

		return os;
	}
};

template<typename T>
inline ArrayList<T>::ArrayList()
{
	size_ = 20;
	data_ = new T[size_];
	length_ = 0;
}

template<typename T>
inline ArrayList<T>::ArrayList(int size)
{
	size_ = size;
	data_ = new T[size_];
	length_ = 0;
}

template<typename T>
inline void ArrayList<T>::MakeEmpty()
{
	length_ = 0;
}

template<typename T>
inline int ArrayList<T>::GetLength()
{
	return length_;
}

template<typename T>
inline bool ArrayList<T>::IsFull()
{
	if (this->length_ == this->size_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool ArrayList<T>::IsEmpty()
{
	if (length_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool ArrayList<T>::Append(T item)
{
	if (!IsFull())
	{
		data_[length_] = item;
		length_ += 1;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool ArrayList<T>::Insert(T item, int index)
{
	if (!IsFull() && index < length_)
	{
		for (int i = length_; i > index; i--)
		{
			data_[i] = data_[i - 1];
		}
		data_[index] = item;
		length_ += 1;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline int ArrayList<T>::Index(T item)
{
	for (int i = 0; i < length_; i++)
	{
		if (data_[i] == item)
		{
			return i;
		}
	}

	cout << "아이템에 해당하는 요소가 리스트 없습니다." << endl;
}

template<typename T>
inline T* ArrayList<T>::GetItemAddress(int index)
{
	return &data_[index];
}

template<typename T>
inline bool ArrayList<T>::Remove(T item)
{
	for (int i = 0; i < length_; i++)
	{
		if (data_[i] == item)
		{
			for (int j = i; j < length_ - 1; j++)
			{
				data_[j] = data_[j + 1];
			}
			length_ -= 1;
			return true;
		}
	}
}

template<typename T>
inline bool ArrayList<T>::Delete(int index)
{
	if (index < length_)
	{
		for (int j = index; j < length_ - 1; j++)
		{
			data_[j] = data_[j + 1];
		}
		length_ -= 1;
		return true;
	}
}

template<typename T>
inline bool ArrayList<T>::SetItem(int index, T item)
{
	if (0 < index && index <= length_)
	{
		data_[index] = item;
		return true;
	}
}

template<typename T>
inline bool ArrayList<T>::Reverse()
{
	for (int i = 0; i < length_ / 2; i++)
	{
		T temp;
		temp = data_[i];
		data_[i] = data_[length_ - (1 + i)];
		data_[length_ - (1 + i)] = temp;
	}
	return true;
}

template<typename T>
inline void ArrayList<T>::ResetIterator()
{
	iter_ = -1;
}

template<typename T>
inline T* ArrayList<T>::GetNextItemAddress()
{
	iter_++;
	if (iter_ >= length_)
	{
		return NULL;
	}
	return &data_[iter_];
}