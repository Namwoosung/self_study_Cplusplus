#include "Application.h"

/**
*    program main function
*/
int main()
{
	Application app;
	app.Run();
	return 0;
}

//#include "ArrayList.h"
//
///**
//*    program main function
//*/
//int main()
//{
//	ArrayList<int> list;
//	ArrayList<double> list2;
//	ArrayList<string> list3;
//	int index_to_set;
//
//	// int list
//	list.Append(1);
//	list.Append(2);
//	list.Append(3);
//	list.Append(4);
//	list.Append(5);
//	list.Append(6);
//
//	index_to_set = list.Index(5);
//	list.SetItem(index_to_set, 500);
//	list.Insert(10, 0);
//	list.Remove(3);
//	list.Delete(1);
//
//	cout << "list length: " << list.GetLength() << endl;
//	cout << "list: " << list << endl;
//	cout << "list[2]: " << *(list.GetItemAddress(2)) << endl;
//	list.Reverse();
//	cout << "list reverse: " << list << endl;
//	list.ResetIterator();
//	int* iter;
//	while ((iter = list.GetNextItemAddress()) != NULL) {
//		cout << *iter << endl;
//	}
//	cout << endl;
//
//	// double list2
//	list2.Append(1.1);
//	list2.Append(2.22);
//	list2.Append(3.333);
//	list2.Append(4.4444);
//	list2.Append(5.55555);
//	list2.Append(6.66666);
//
//	index_to_set = list2.Index(5.55555);
//	list2.SetItem(index_to_set, 500.1234);
//	list2.Insert(10.123, 0);
//	list2.Remove(3.333);
//	list2.Delete(1);
//
//	cout << "list2 length: " << list2.GetLength() << endl;
//	cout << "list2: " << list2 << endl;
//	cout << "list2[2]: " << *(list2.GetItemAddress(2)) << endl;
//	list2.Reverse();
//	cout << "list2 reverse: " << list2 << endl;
//	list2.ResetIterator();
//	double* iter2;
//	while ((iter2 = list2.GetNextItemAddress()) != NULL) {
//		cout << *iter2 << endl;
//	}
//	cout << endl;
//
//	// string list3
//	list3.Append("1A");
//	list3.Append("2B");
//	list3.Append("3C");
//	list3.Append("4D");
//	list3.Append("5E");
//	list3.Append("6F");
//
//	index_to_set = list3.Index("5E");
//	list3.SetItem(index_to_set, "5EEEEE");
//	list3.Insert("100AAAA", 0);
//	list3.Remove("3C");
//	list3.Delete(1);
//
//	cout << "list3 length: " << list3.GetLength() << endl;
//	cout << "list3: " << list3 << endl;
//	cout << "list3[2]: " << *(list3.GetItemAddress(2)) << endl;
//	list3.Reverse();
//	cout << "list3 reverse: " << list3 << endl;
//	list3.ResetIterator();
//	string* iter3;
//	while ((iter3 = list3.GetNextItemAddress()) != NULL) {
//		cout << *iter3 << endl;
//	}
//	cout << endl;
//
//	return 0;
//}