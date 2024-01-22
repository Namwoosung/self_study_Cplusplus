#include <iostream>

using namespace std;

/*로컬 베리어블
// Local Variable: 함수 안에서만 선언/ 존재, 함수가 끝나면 사라짐
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

/*글로벌 베리어블
//Global Variable: 함수 외부에서 선언/ 전역게서 사용가능(공유)
//메모리 관점에서 굉장히 비효율적인 변수, 관리가 어려움 -> 주로 사용x
//유의사항: Local Variable > Global Variable
int gX;

void print()
{
	gX = 1000;
	cout << "gX in print(): " << gX << endl;
}

int main()
{
	//Varialbe Shawdowing: 전역변수와 지역변수가 동일하게 존재 -> 지역변수가 우선적으로 조사 됨
	int gX;

	gX = 10;
	cout << gX << endl;
	print();
	cout << gX << endl;
	return 0;
}
*/


/*재귀함수
//메모리 관점에서 비효율적
int factorial(int n)//재귀함수
{
	//termination condition(이상한 값이 들어가지 않도록 중간에 재귀를 끊어주는 역할)
	if (n <= 0)
	{
		return 1;
	}
	//base condition()
	return n * factorial(n - 1); //재귀형태
}

int main()
{
	int x = 5;
	cout << factorial(x) << endl;

	return 0;
}
*/

/*리퍼런스 베리어블로 값 복사
int main()
{
	int x = 10;
	int& r = x; //r은 x의 reference varialbe
	cout << x << '\t' << r << endl; 
	x = 1000;	//r도 바뀜
	cout << x << '\t' << r << endl;

	return 0;
}
*/

/* pass by value
//함수 입력 인자에 복사를 통해 값을 전달
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
	cout << x << '\t' << y << endl; //x, y 바뀌지 않음(swap함수가 pass by value로 넘겨준 파라미터를 사용)

	return 0;
}
*/

/* pass by reference
//함수 입력 인자에 참조를 통해 값을 전달(동기화)
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
	cout << x << '\t' << y << endl; //값 바뀜

	return 0;
}
*/