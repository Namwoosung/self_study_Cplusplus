#include <iostream>
#include <vector> //vector�� stack�� �ڷᱸ��
using namespace std;

/*Review
int main()
{
	int x = 100;
	int* px = &x;

	cout << x << '\t' << &x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;

	return 0;
}
*/

/*function pointer
int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*f)(int, int), int a, int b)
{
	return f(a, b);
}

int main()
{
	int(*func)(int, int); //int�� �ǹ�: ��ȯ���� int�� �Լ��� ������, func: ������ ���� �̸�, (int, int): �Ķ���ͷ� int�� ���� 2���� ���� �Լ��� ������

	func = &sum;
	cout << func(10, 20) << endl;

	func = &mult;
	cout << func(10, 20) << endl;

	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}
*/


/*vector
//��ü�� �׻� pass by reference�� -> �� ���������ʰ� �ּҸ� ����Ű���� -> �������� �����ͼս��� �ٿ���
//�Լ� �ȿ��� ��ü�� data�� �ٲ��� ���� �� const�� ���� ��
void print(const vector<int>& v) //value�� ���� �Ѱ��ָ� vector��� element�� ���� -> ��ȿ����, reference�� ���� �Ѱ��ָ� �ذ� but �Լ��������� ���� ���� �� ���� -> const�� ���ȭ �����ָ� ��
{
	for (unsigned int i = 0; i < v.size(); i++) //size()�� ��ȯ���� unsigned int�̹Ƿ� �����ֱ� ���� �Ȱ����ڷ��� ���(int����ص� �Ǳ���)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
}


int main()
{
	vector<int> vec{ 10, 20, 30, 40 }; //<int>: vector�� ��� element���� ������ ������ �ǹ�
	vector<int> vec_2(10); // 10���� �ε����� ����� 0���� ä��
	vector<int> vec_3(10, 8); //10���� �ε����� ����� 8�� ä��

	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;
	print(vec);

	vec.push_back(50);
	print(vec);
	vec.pop_back();
	print(vec);
	//stack�� �ڷᱸ���̱� ������ �߰� Ȥ�� ���Ŵ� �� �� element���� �̷����

	//int& elem = vec[0] -> body
	//int& elem = vec[1] -> body
	//.....
	//�� for�� ���۽� elem�� vec�� �ε����� ����ȭ ������ �� for���� body�� ����
	//�Ʒ� �ڵ�� vec�� element���� ��� �Է°����� �ٲ���
	for (int& elem : vec)
	{
		cin >> elem;
	}
	//int elem = vec[0] -> body
	//int elem = vec[1] -> body
	//.....
	for (int elem : vec)
	{
		cout << elem << '\t';
	}
	cout << endl;


	return 0;
}
*/