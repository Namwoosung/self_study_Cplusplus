#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "DoublyPointingIterator.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
	/* ���� ť �˻��ڵ�
	Stack<int> stack1;
	stack1.push(5);
	stack1.push(6);
	int number = stack1.top();
	cout << number << endl;
	stack1.pop();
	int number2 = stack1.top();
	cout << number2 << endl;
	bool judge = stack1.IsEmpty();
	if (!judge)
	{
		cout << "�˻�Ϸ�" << endl << "stack�� ���" << endl;
		cout << stack1 << endl;
	}
	stack1.pop();
	stack1.top();
	

	Queue<int> queue1;
	queue1.Enqueue(5);
	queue1.Enqueue(6);
	queue1.Enqueue(7);
	int number3 = queue1.Front();
	cout << number3 << endl;
	int number4 = queue1.Back();
	cout << number4 << endl;
	queue1.Dequeue();
	int number5 = queue1.Back();
	cout << number5 << endl;

	if (!queue1.IsEmpty())
	{
		cout << "�˻�Ϸ�" << endl << "queue�� ���" << endl;
		cout << queue1 << endl;
	}
	queue1.Dequeue();
	queue1.Dequeue();
	queue1.Front();
	queue1.Back();
	*/
	
	/*��ȣ���ڿ� �˻�(�����̿�)
	Stack<char> result;
	cout << "��ȣ ���ڿ� ���̸� �Է��Ͻʽÿ�." << endl;
	int number;
	cin >> number;
	cout << "�˻��� ��ȣ ���ڿ��� �ϳ��� �Է��Ͻʽÿ�." << endl;
	string sign;
	cin >> sign;
	bool judge = true;

	for (int i = 0; i < number; i++)
	{
		result.push(sign[i]);
	}

	int standard = 0;
	while (!result.IsEmpty())
	{
		char test;
		test = result.top();

		if (test == ')')
		{
			standard++;
		}
		else if (test == '(')
		{
			standard--;
		}
		result.pop();

		if (standard < 0)
		{
			cout << "NO" << endl;
			judge = false;
			break;
		}
	}
	if (judge)
	{
		if (standard == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	*/

	Queue<string> order;

}