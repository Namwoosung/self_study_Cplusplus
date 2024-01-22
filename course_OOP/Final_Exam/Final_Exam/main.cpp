#include "SquareMatrix.h"
#include "DiagonalMatrix.h"

using namespace std;

int main()
{
	Matrix<int>* m1 = new SquareMatrix<int>;
	Matrix<double>* m2 = new DiagonalMatrix<double>;

	m1->set_matrix();
	cout << "name: " << m1->get_name() << endl;
	cout << "Length: " << m1->get_length() << endl;
	m1->print();
	cout << endl;

	m2->set_matrix();
	cout << "name: " << m2->get_name() << endl;
	cout << "Length: " << m2->get_length() << endl;
	m2->print();

	return 0;
}