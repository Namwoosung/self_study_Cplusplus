#include "Heap.h"

int main()
{
	int arr[6] = { 1, 16, 13, 5, 3, 7 };

	MinHeap<int> A(arr, 6);
	
	cout << A << endl;

	return 0;
}