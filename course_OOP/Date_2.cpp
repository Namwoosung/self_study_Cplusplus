#include <iostream> // cin, cout
#include <cmath>
using namespace std;

/* �Լ��� ����, ����, ȣ��
//1����(prototyping)
int square(int a);

int main()
{
	int x = 10;

	cout << square(x) << endl; //3)ȣ��(calling)
	cout << square(100) << endl;

	return 0;
}
//2)����(����)
int square(int a)
{
	return a * a;
}
*/

/*cmath���̺귯���� ���ԵǾ��ִ� �Լ� ���
int main()
{
	double x;
	cin >> x;

	//cmath ���̺귯�� �ȿ� ���ԵǾ� �ִ� �Լ����� ȣ��
	cout << sqrt(x) << endl; //���� ������ ��ȯ �Լ�
	cout << log(x) << endl; //lnX�� �� ��ȯ
	cout << log10(x) << endl; //log10�� �� ��ȯ �Լ�
	cout << cos(x) << endl; // cos�� ��ȯ�Լ�
	cout << pow(2, x) << endl; //2�� x���� �� ��ȯ�Լ�

	return 0;
}
*/

/*����
int get_data();
int sum(int a, int b);
float idiv(int a, int b);

int main()
{
	int x, y;
	x = get_data();
	y = get_data();

	cout << x << '\t' << y << '\n';
	cout << sum(x, y) << endl;
	cout << idiv(x, y) << endl;

	return 0;
}

int get_data()
{
	int a;
	cout << "Enter a number: ";
	cin >> a;
	return a;
}

int sum(int a, int b)
{
	return a + b;
}

float idiv(int a, int b)
{
	return float(a) / b;
}
*/

/*Defauly Argumants(**�߿�**)
//Default Argument�� ���Ǻΰ� �ƴ� ����ο� ���������� ��
void point(int a = 1, int b = 2)
{
	cout << a << '\t' << b << endl;
}
int main()
{
	point(1000, 2000);
	point();
	point(1000); //�׻� ���ʺ��� ���� ä����
	//point(, 2000); �Ұ��� -> ������ ������ ä��� ��� ���� X
	//���� �ٲ��� �ϴ� ���� �Ű������ۼ� �� ���ʿ� �ۼ�
	return 0;
}
*/