#include "DoublyLinkedList.h"
#include "DoublyPointingIterator.h"

int main()
{
	DoublyLinkedList<int> list;
	
	list.push_back(5);
	list.push_front(6);
	list.push_front(62);
	list.push_front(61);

	DoublyPointingIterator<int> iter = list.begin();
	++iter;
	list.Insert(iter, 3);

	DoublyPointingIterator<int> iter2 = list.GetIterator(6);
	list.Insert(iter2, 33);

	for (DoublyLinkedList<int>::Iterator iter = list.begin();
		iter != list.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}