#include <iostream>
#include <vector>

using namespace std;

/*문제 1
class Complex
{
	double re, im;
public:
	Complex(double r, double i) { re = r; im = i; }
	Complex() { re = 0; im = 0; }

	Complex operator+(Complex other)
	{
		return Complex(other.im + this->im, other.re + this->re);
	}
	Complex operator+(double other)
	{
		return Complex(this->im + other, this->re);
	}
	Complex operator-(Complex other)
	{
		return Complex(this->im - other.im, this->re - other.re);
	}
	Complex operator-(double other)
	{
		return Complex(this->im - other, this->re);
	}

	void print()
	{
		cout << re << " + i" << im << endl;
	}
};

int main()
{
	Complex a(.3, 8.4), b(4.5, 5.2), c(2.0, 7.7);

	Complex sum, dif;
	sum = a + b + 3.0;
	cout << "a + b + 3.0 = ";
	sum.print();

	dif = a - b - 2.0;
	cout << "a - b - 2.0 = ";
	dif.print();

	sum = a + b + 5 - c - 8;
	cout << "a + b + 5 - c - 9 = ";
	sum.print();
	return 0;
}
*/

/*문제 2
class VectorList
{
	vector<double*> vItem;
	vector<int> vLength;
public:
	void append(double* _pArray, int _length) { vItem.push_back(_pArray); vLength.push_back(_length); }
	int findVector(double* _pArray, int _length)
	{
		int Correct_num = 0;
		for (unsigned i = 0; i < vLength.size(); i++)
		{
			Correct_num = 0;
			for (int j = 0; j < _length; j++)
			{
				if ((*this->vItem[i] + j) != _pArray[j])
				{
					break;
				}
				else
				{
					Correct_num++;
				}

				if (Correct_num == _length)
				{
					return i;
				}
			}
		}
		return -1;
	}
	void print_single_vector(int dx)
	{
		if (dx < 0)
		{
			cout << "[Wrong index]" << endl;
		}
		else
		{
			cout << dx << "-th vector:\t";
			for (int i = 0; i < vLength[dx]; i++)
			{
				cout << *(vItem[dx] + i) << "\t";
			}
			cout << endl;
		}
	}
	void print_all_vectors()
	{
		for (unsigned i = 0; i < vLength.size(); i++)
		{
			cout << i << "-th vector:\t";
			for (int j = 0; j < vLength[i]; j++)
			{
				cout << *(vItem[i] + j) << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
	VectorList vectorList;
	double* pTemp = new double[3]{ 1.1, 2.2, 3.3 };
	vectorList.append(pTemp, 3);

	pTemp = new double[5]{ 10.1, 10.2, 10.3, 10.4, 10.5 };
	vectorList.append(pTemp, 5);

	pTemp = new double[2]{ 4.5, 5.5 };
	vectorList.append(pTemp, 2);

	vectorList.print_single_vector(-1);
	vectorList.print_single_vector(0);
	cout << endl;

	vectorList.print_all_vectors();
	cout << endl;

	double* pTemp1 = new double[2]{ 4.5, 5.5 };
	double* pTemp2 = new double[4]{ 1.1, 2.2, 5.5, 4.4 };
	cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 5.5, 4.4} :" << vectorList.findVector(pTemp2, 4) << endl;

	delete[] pTemp;
	delete[] pTemp1;
	delete[] pTemp2;

	return 0;
}
*/