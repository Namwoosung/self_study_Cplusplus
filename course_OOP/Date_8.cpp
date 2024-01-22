#include <iostream>

using namespace std;

/*포인터
//&x: x의 주소값을 반환
//int* px: px는 정수형변수의 주소값을 저장하는 정수형포인터 변수
//*px: px에 저장된 주소값으로 jump in
int main()
{
	int x = 10;
	int* px = &x; //x의 주소값을 px라는 int포인터형 변수 px에 저장
	//&x의 자료형을 검서하면 int* => &x는 x변수의 메모리 주소값을 의미하고, type은 int*와 같음
	//x값를 변환하면 *px값도 변환, *px값을 변환 하면 x값도 변환

	*px = 15;

	cout << x << '\t' <<&x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;

	int* y, * z; //int* 형 변수 동시 선언


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