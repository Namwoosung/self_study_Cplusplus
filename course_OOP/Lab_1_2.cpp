//Date_1

//#include <iostream>

//using namespace std;

/*기초문제 1
int main()
{
	int x, y;
	x = 10;
	y = 20;
	cout << x << endl;
	cout << y << endl;
}
*/

/*기초문제 2
//sizeof(): 해당 변수의 메모리 크기를 바이트 단위로 반환해주는 함수
int main()
{
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
*/

/*기초문제 3
int main()
{
	cout << "( 7 == 5 ):" << (7 == 5) << endl;
	cout << "( 7 >= 5 ):" << (7 >= 5) << endl;
	cout << "( 7 != 5 ):" << (7 != 5) << endl;
	cout << "( 7 <= 5 ):" << (7 <= 5) << endl;
	cout << "( 7 >= 5 ? 100 : -100 ):" << (7 >= 5 ? 100 : -100) << endl;
}
*/

/*기초문제 4
int main()
{
	const double PI = 3.14;
	char ch1 = 65;
	char ch2 = ch1 + 32;
	cout << PI << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*기초문제 5
int main()
{
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = float(x) / y;
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
}
*/

/*
int main()
{
	cout << "My name is 남우성" << endl;
}
*/

/*응용문제 2
int main()
{
	int A, B;
	cout << "Please enter two integer values :";
	cin >> A >> B;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << float(A) / B << endl;
	cout << A << " % " << B << " = " << A % B << endl;
}
*/

/*응용문제 3
int main()
{
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;

	cout << i1 + (i2 * i3) << endl;
	cout << i1 * (i2 + i3) << endl;
	cout << i1 / (i2 + i3) << endl;
	cout << i1 / i2 + i3 << endl;
	cout << 3 + 4 + 5 / 3 << endl;
	cout << (3 + 4 + 5) / 3 << endl;
	cout << d1 + (d2 * d3) << endl;
	cout << d1 + d2 * d3 << endl;
	cout << d1 / d2 - d3 << endl;
	cout << d1 / (d2 -d3) << endl;
	cout << d1 + d2 + d3 / 3 << endl;
	cout << (d1 + d2 + d3) / 3 << endl;
}
*/

/*응용문제 4
int main()
{
	int A, B, temp;
	cout << "Please enter two integer values" << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;

	temp = A;
	A = B;
	B = temp;

	cout << "Value of A is : " << A << endl;
	cout << "Value of B is : " << B << endl;
}
*/

/*응용문제 5
int main()
{
	double T;
	cout << "Please enter Fahrenheit Value : ";
	cin  >> T;

	T = 5.0 / 9.0 * (T - 32);

	cout << "Celsius Value is : " << T << endl;
}
*/