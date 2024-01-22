#include <iostream> // cin, cout
#include <cmath>
using namespace std;

/* 함수의 선언, 정의, 호출
//1선언(prototyping)
int square(int a);

int main()
{
	int x = 10;

	cout << square(x) << endl; //3)호출(calling)
	cout << square(100) << endl;

	return 0;
}
//2)정의(구현)
int square(int a)
{
	return a * a;
}
*/

/*cmath라이브러리에 포함되어있는 함수 사용
int main()
{
	double x;
	cin >> x;

	//cmath 라이브러리 안에 포함되어 있는 함수들을 호출
	cout << sqrt(x) << endl; //양의 제곱근 반환 함수
	cout << log(x) << endl; //lnX의 값 반환
	cout << log10(x) << endl; //log10의 값 반환 함수
	cout << cos(x) << endl; // cos값 반환함수
	cout << pow(2, x) << endl; //2의 x제곱 값 반환함수

	return 0;
}
*/

/*계산기
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

/*Defauly Argumants(**중요**)
//Default Argument는 정의부가 아닌 선언부에 적용시켜줘야 함
void point(int a = 1, int b = 2)
{
	cout << a << '\t' << b << endl;
}
int main()
{
	point(1000, 2000);
	point();
	point(1000); //항상 왼쪽부터 값이 채워짐
	//point(, 2000); 불가능 -> 오른쪽 값부터 채우는 방법 존재 X
	//자주 바뀌어야 하는 값을 매개변수작성 시 왼쪽에 작성
	return 0;
}
*/