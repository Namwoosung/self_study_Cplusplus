#include <iostream>
#include <functional>
#include <algorithm> //for_each, copy, transform
#include <vector>

using namespace std;

/*lambda �Լ�: ��ȸ�� �Լ�
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }

int evaluate(int(*f)(int, int), int x, int y)
{
	return f(x, y);
}

int main()
{
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;

	// lambda �Լ�: [](�Էº���)->����Ÿ�� {����}
	//sum: [](int x,int y)->int { return x + y; }

	cout << evaluate([](int x, int y)->int {return x + y; }, 20, 30) << endl;

	//simplified labda �Լ� ǥ��: [](�Էº���) {����}
	//mult: [](int x, int y) {return x * y; }
	
	cout << evaluate([](int x, int y) {return x * y; }, 20, 30) << endl;

	//������ ȣ���� ���ÿ�: �����Լ�(�Է°�)
	[](int x, int y) {cout << x << ", " << y << endl; }(20, 30);

	//�����Լ��� �Լ������Ϳ� ���� -> ��� ����� �� ����
	int (*f)(int, int) = [](int x, int y) {return x - y; }; //auto f = [](int x, int y){return x - y;}; ǥ���� ����
	cout << f(1000, 2000) << endl;
	int f(int x, int y)
	{
		return x - y;
	}

	return 0;
}
*/

/*lambda�Լ��� closure
int evaluate2(function<int(int, int)> f, int x, int y)
{
	return f(x, y);
}

int main()
{
	int a = 10, b = 20;
	[&a](int x) {a = 20; cout << a * x << endl; }(10); //[]�κ�(closure �κ�): �ܺκ����� lambda�Լ� ���η� ����
	cout << "a: " << a << endl;						   //[a]: ���� a�� call by value�� lambda�Լ��� ����
													   //[&a]: ���� a�� call by reference�� ����
													   //[=]: ��� �ܺ� ������ call by value�� ����
													   //[&]: ��� �ܺ� ������ call by ref�� ����
													   // -���� ������ ��: closure�� ����� ��� function��ü�� assign���� ��

	//���� int evaluate2(int(*f)(int, int), int x, int y)�� �Լ��� ���� �Ǿ��� ��� �Ʒ��ڵ� ������ ����
	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3) << endl; //lambda�Լ��� �Լ������Ϳ��� ����� �� closure�κ� ��� �Ұ�

	return 0;
}
*/

/*algorithm ��ǥ�Լ�
int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	for (int elem : v1)
	{
		cout << elem << '\t';
	}
	cout << endl;

	//for_each(������ġ(iter), ����ġ(iter), �����Լ�)
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) { elem++; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem += a; }); //closure�κе� ��밡��
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	//copy: container1(source) �� element�� container2(destination)�� ����
	//copy(src������ġ, src����ġ, dst������ġ)
	//v1: {1, 2, 3, 4}
	//v2: {0, 0, 2, 3}


	copy(begin(v1) + 1, end(v1) - 1, begin(v2) + 2); //iterator ��ü�� +�� ����� �� �ִ� ����: 
														//vector��� container�� �����̱⿡ element�� ���������� �Ҵ��ϱ� ������ ����
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	//transform: container1�� element�� �����Ѵ���(�����Լ�) container2�� ����(for_each�� copy�� ��ģ ���)
	//transform(src������ġ, src����ġ dst������ġ, �����Լ�)
	transform(begin(v1), end(v1), begin(v2),
		[](int elem) {return elem * elem; }
	);
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	return 0;
}
*/