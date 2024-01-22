#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> A;

	A.Insert(13);
	A.Insert(24);
	A.Insert(35);
	A.Insert(1);
	A.Insert(20);
	A.Insert(7);
	A.Insert(18);
	A.Insert(22);
	A.Insert(45);

	int number = A.GetLength();
	cout << number << endl;

	A.Remove(24);
	A.Remove(1);
	A.Remove(22);
	A.Remove(7);
	A.Remove(13);
	A.Remove(35);
	A.Remove(20);
	A.Remove(18);
	A.Remove(45);

	if (!A.IsEmpty())
	{
		number = A.GetLength();
		cout << number << endl;
		cout << "ÇìÇì" << endl;
	}

	return 0;
}