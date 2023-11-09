#include <iostream>
#include <ctime>
#include <algorithm>
#define size 50
using namespace std;

void swap(int& el1, int& el2) {
	int temp = el1;
	el1 = el2;
	el2 = temp;
}
int Sequential_search(int num, int ar[], int size_) {
	for (int i = 0; i < size_; i++)
	{
		if (ar[i] == num)
		{
			return i;
		}
	}
	return 0;
}
int Binary_search(int num, int ar[], int start, int end) {
	int e = end;
	int s = start;
	int half = (start + end) / 2;
	if (s > e) {
		return 0;
	}
	if (ar[half] == num) {
		return start;
	}
	else if (ar[half] > num) {
		return Binary_search(num, ar, s, half - 1);
	}
	else {
		return Binary_search(num, ar, half + 1, e);
	}
}

int main() {
	int arr[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		int rannum = rand() % 200 + 1;
		arr[i] = rannum;
	}
	cout << "[정렬 전 숫자 배열]" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	// bubble sort
	bool swapped;
	do {
		swapped = false;
		int sortcount = 0;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
				sortcount++;
			}
		}
		if (sortcount != 0) {
			swapped = true;
		}
	} while (swapped);

	cout << "[버블정렬 후 숫자 배열]" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;

	cout << Binary_search(25, arr, 0, size);

	// insertion sort
	int sortcount = 0;
	sortcount++;
	for (int i = 1; i < size; i++) {
		int unsortnum = arr[i];
		for (int j = i; j < size - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		int movecount = 0;
		for (int k = sortcount - 1; k >= 0; k--) {
			if (arr[k] > unsortnum) {
				movecount++;
				continue;
			}
			else {
				break;
			}
		}
		for (int l = size - 1; l > i - movecount; l--)
		{
			arr[l] = arr[l - 1];
		}
		arr[i - movecount] = unsortnum;
		sortcount++;
	}

	cout << "[인설트션정렬 후 숫자 배열]" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}

	// selection sort
	int numofel = 99;
	int sortcount = 0;
	int k;
	for (int i = 0; i < 99; i++) {
		int minnum = arr[i];
		for (int j = numofel; j > sortcount; j--) {
			minnum = min(minnum, arr[j]);
			if (minnum == arr[j]) {
				k = j;
			}
		}
		if (arr[i] != minnum) {
			swap(arr[i], arr[k]);
		}
		sortcount++;
	}
	cout << "[셀렉션정렬 후 숫자 배열]" << endl;
	for (int i = 0; i < 100; i++) {
		cout << arr[i] << ", ";
	}
	return 0;
}