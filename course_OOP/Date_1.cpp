//#include <iostream> //C++의 라이브러리 파일 (입출력 함수들이 포함되어 있음, cout, cin....)

//using namespace std; //네임스페이스로 std사용 -> 충돌방지 & 명확환 네임스페이스 제공

/*변수 선언, 대입, 출력
int main() { //메인 함수는 프로젝트에 무조건 한 개 존재, 프로젝트 실행시 불려지는 함수
	int x;  //변수선언
	x = 10; // 할당, x라는 변수에 10이라는 값 대입

	cout << x << endl; //x라는 변수 출력
	//cout 화면에 변수를 출력하는 함수
	//endl 줄바꿈(개행)을 하는 문자
*/

/*여러가지 상수 자료형
int main()
{
	short int sx; //2바이트 크기 (약 3만) int 지워도 됨
	int x; //4바이트 크기 (약 20억)
	long int lx; //4바이트 크기 (약 20억) int 지워도 됨 ++int와 long의 차이는 int는 운영체제에 따라 달라짐 ex 64bit OS에서는 8byte, 16bit OS에서는 2byte but long은 4byte로 고정
	long long int llx; // 8바이트 크기 () int 지워도 됨

	//변수 앞에 unsigned를 붙이면 양수만 취급 -> 변수범위가 2배가 됨

	cout << sizeof(sx) << endl; //sizeof함수: 해당변수의 메모리크기를 바이트 단위로 출력해주는 함수
	cout << sizeof(x) << endl;
	cout << sizeof(lx) << endl;
	cout << sizeof(llx) << endl;
}
*/

/*캐릭터 자료형과 아스키 코드
int main()
{
	char ch1 = 'A';
	char ch2 = 65;// A의 아스키 코드
	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*상수화(const)
int main()
{
	const double PI = 3.14;
	//PI = 44.5; 컴파일 오류(PI번수는 const로 지정하여 상수화했기 때문에 재정의가 불가함)
}
*/

/* cin + 사칙연산자
int main()
{
	int x, y, sum, mod;
	float div;
	cin >> x >> y; // 사용자에게 값을 입력받아 x와 y에 각각 대입

	sum = x + y;
	mod = x % y;
	div = float(x) / y;

	x += y; // x = x + y;
	x %= y; // x = x % y;


	++x; //전위증가 연산자(x의 1을 더하고 더한 값의 x를 반환)
	x++; //후위증가 연산자(현재 x의 값을 반환하고 x에 1을 더함)
	--x;
	x--;

	cout << x << '\t' << y << endl;
	cout << sum << endl;
	cout << mod << endl;
	cout << div << endl;
}
*/

/*비교연산자(false = 0, true = 1)
int main()
{
	cout << (7 == 5) << endl;
	cout << (7 == 7) << endl;
}
*/


/*컨디셔널 오퍼레이터 -> 참 거짓 반환 대신 내가 원하는 값을 반환, [ ? (참일 때 반환값) : (거짓일 때 반환 값)]으로 사용
int main()
{
	cout << (7 >= 5 ? 1000 : -100) << endl;
}
*/