#include <iostream>

using namespace std;

/*���� �������
// Local Variable: �Լ� �ȿ����� ����/ ����, �Լ��� ������ �����
void increase(int x)
{
	x++;
	cout << "x: " << x << endl;
}

int main()
{
	int x = 10;
	cout << x << endl;
	increase(x);
	cout << x << endl;
	return 0;
}
*/

/*�۷ι� �������
//Global Variable: �Լ� �ܺο��� ����/ �����Լ� ��밡��(����)
//�޸� �������� ������ ��ȿ������ ����, ������ ����� -> �ַ� ���x
//���ǻ���: Local Variable > Global Variable
int gX;

void print()
{
	gX = 1000;
	cout << "gX in print(): " << gX << endl;
}

int main()
{
	//Varialbe Shawdowing: ���������� ���������� �����ϰ� ���� -> ���������� �켱������ ���� ��
	int gX;

	gX = 10;
	cout << gX << endl;
	print();
	cout << gX << endl;
	return 0;
}
*/


/*����Լ�
//�޸� �������� ��ȿ����
int factorial(int n)//����Լ�
{
	//termination condition(�̻��� ���� ���� �ʵ��� �߰��� ��͸� �����ִ� ����)
	if (n <= 0)
	{
		return 1;
	}
	//base condition()
	return n * factorial(n - 1); //�������
}

int main()
{
	int x = 5;
	cout << factorial(x) << endl;

	return 0;
}
*/

/*���۷��� �������� �� ����
int main()
{
	int x = 10;
	int& r = x; //r�� x�� reference varialbe
	cout << x << '\t' << r << endl; 
	x = 1000;	//r�� �ٲ�
	cout << x << '\t' << r << endl;

	return 0;
}
*/

/* pass by value
//�Լ� �Է� ���ڿ� ���縦 ���� ���� ����
void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x = 10, y = 1000;
	cout << x << '\t' << y << endl;
	swap(x, y);
	cout << x << '\t' << y << endl; //x, y �ٲ��� ����(swap�Լ��� pass by value�� �Ѱ��� �Ķ���͸� ���)

	return 0;
}
*/

/* pass by reference
//�Լ� �Է� ���ڿ� ������ ���� ���� ����(����ȭ)
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x = 10, y = 1000;
	cout << x << '\t' << y << endl;
	swap(x, y);
	cout << x << '\t' << y << endl; //�� �ٲ�

	return 0;
}
*/