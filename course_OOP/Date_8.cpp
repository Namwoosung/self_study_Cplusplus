#include <iostream>

using namespace std;

/*������
//&x: x�� �ּҰ��� ��ȯ
//int* px: px�� ������������ �ּҰ��� �����ϴ� ������������ ����
//*px: px�� ����� �ּҰ����� jump in
int main()
{
	int x = 10;
	int* px = &x; //x�� �ּҰ��� px��� int�������� ���� px�� ����
	//&x�� �ڷ����� �˼��ϸ� int* => &x�� x������ �޸� �ּҰ��� �ǹ��ϰ�, type�� int*�� ����
	//x���� ��ȯ�ϸ� *px���� ��ȯ, *px���� ��ȯ �ϸ� x���� ��ȯ

	*px = 15;

	cout << x << '\t' <<&x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;

	int* y, * z; //int* �� ���� ���� ����


	return 0;
}
*/

/*pass by address
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 10, y = 1000;
	cout << x << '\t' << y << endl;
	swap(&x, &y);
	cout << x << '\t' << y << endl;

	return 0;
}
*/