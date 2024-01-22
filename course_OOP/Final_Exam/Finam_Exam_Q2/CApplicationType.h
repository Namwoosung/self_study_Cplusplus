#pragma once

#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include <vector>

using namespace std;

template<typename T>
class ApplicationType
{
private:
	vector<Matrix<T>*> vList;
public:
	void clear();
	~ApplicationType() { clear(); }
	string get_command();
	void run();
	void add_matrix();
	void find_matrix();
	void display_matrix();
	void save_matrix();
	void load_matrix();
};

template<typename T>
inline void ApplicationType<T>::clear()
{
	vList.clear();
}

template<typename T>
inline string ApplicationType<T>::get_command()
{
	string com;

	cout << "1. Add matrix" << endl;
	cout << "2. Find matrix" << endl;
	cout << "3. Dispay all matrices" << endl;
	cout << "4. Save matrix" << endl;
	cout << "5. Load matrix" << endl;
	cout << "0. Quit" << endl;

	cout << "Input>";
	cin >> com;
	return  com;
}

template<typename T>
inline void ApplicationType<T>::run()
{
	string command;
	while (1)
	{
		command = get_command();
		if (command == "1")			add_matrix();
		else if (command == "2")	find_matrix();
		else if (command == "3")	display_matrix();
		else if (command == "4")	save_matrix();
		else if (command == "5")	load_matrix();
		else if (command == "0")	break;
	}
}

template<typename T>
inline void ApplicationType<T>::add_matrix()
{
	int type_num;
	cout << "Enter matrix type(1: square, 2: diagonal): ";
	cin >> type_num;
	if (type_num == 1)
	{
		Matrix<T>* temp = new SquareMatrix<T>;
		temp->set_matrix();
		vList.push_back(temp);
		cout << "Addition Success" << endl;
	}
	else if (type_num == 2)
	{
		Matrix<T>* temp = new DiagonalMatrix<T>;
		temp->set_matrix();
		vList.push_back(temp);
		cout << "Addition Success" << endl;
	}
}

template<typename T>
inline void ApplicationType<T>::find_matrix()
{
	string find_name;
	cout << "Find Matrix: ";
	cin >> find_name;
	for (unsigned i = 0; i < this->vList.size(); i++)
	{
		if (vList[i]->get_name() == find_name)
		{
			vList[i]->print();
			break;
		}
	}
}

template<typename T>
inline void ApplicationType<T>::display_matrix()
{
	for (unsigned i = 0; i < this->vList.size(); i++)
	{
		vList[i]->print();
	}
}

template<typename T>
inline void ApplicationType<T>::save_matrix()
{
	string f_name;

	cout << "Enter the filename: ";
	cin >> f_name;

	ofstream fout;
	fout.open(f_name);

	for (unsigned i = 0; i < this->vList.size(); i++)
	{
		vList[i]->save_matrix(fout);
	}

	fout.close();

	cout << "Save Success" << endl;
}

template<typename T>
inline void ApplicationType<T>::load_matrix()
{
}

class FileNotFoundException : public exception
{
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not Found: " + _m) {}

	virtual const char* what() const throw()
	{
		return message.c_str();
	}
};