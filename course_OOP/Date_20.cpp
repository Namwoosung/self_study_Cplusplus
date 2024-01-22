#include <iostream>
#include <functional>
#include <algorithm> //for_each, copy, transform
#include <vector>

using namespace std;

/*lambda 함수: 일회성 함수
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

	// lambda 함수: [](입력변수)->리턴타입 {본문}
	//sum: [](int x,int y)->int { return x + y; }

	cout << evaluate([](int x, int y)->int {return x + y; }, 20, 30) << endl;

	//simplified labda 함수 표현: [](입력변수) {본문}
	//mult: [](int x, int y) {return x * y; }
	
	cout << evaluate([](int x, int y) {return x * y; }, 20, 30) << endl;

	//생성과 호출을 동시에: 람다함수(입력값)
	[](int x, int y) {cout << x << ", " << y << endl; }(20, 30);

	//람다함수를 함수포인터에 대입 -> 계속 사용할 수 있음
	int (*f)(int, int) = [](int x, int y) {return x - y; }; //auto f = [](int x, int y){return x - y;}; 표현도 가능
	cout << f(1000, 2000) << endl;
	int f(int x, int y)
	{
		return x - y;
	}

	return 0;
}
*/

/*lambda함수의 closure
int evaluate2(function<int(int, int)> f, int x, int y)
{
	return f(x, y);
}

int main()
{
	int a = 10, b = 20;
	[&a](int x) {a = 20; cout << a * x << endl; }(10); //[]부분(closure 부분): 외부변수를 lambda함수 내부로 전달
	cout << "a: " << a << endl;						   //[a]: 변수 a를 call by value로 lambda함수에 전달
													   //[&a]: 변수 a를 call by reference로 전달
													   //[=]: 모든 외부 변수를 call by value로 전달
													   //[&]: 모든 외부 변수를 call by ref로 전달
													   // -사용시 주의할 점: closure를 사용할 경우 function객체로 assign받을 것

	//만약 int evaluate2(int(*f)(int, int), int x, int y)로 함수가 선언 되었을 경우 아래코드 컴파일 에러
	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3) << endl; //lambda함수를 함수포인터에서 사용할 때 closure부분 사용 불가

	return 0;
}
*/

/*algorithm 대표함수
int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	for (int elem : v1)
	{
		cout << elem << '\t';
	}
	cout << endl;

	//for_each(시작위치(iter), 끝위치(iter), 람다함수)
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) { elem++; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem += a; }); //closure부분도 사용가능
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	//copy: container1(source) 의 element를 container2(destination)로 복사
	//copy(src시작위치, src끝위치, dst시작위치)
	//v1: {1, 2, 3, 4}
	//v2: {0, 0, 2, 3}


	copy(begin(v1) + 1, end(v1) - 1, begin(v2) + 2); //iterator 객체에 +를 사용할 수 있는 이유: 
														//vector라는 container는 동적이기에 element를 연속적으로 할당하기 때문에 가능
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	//transform: container1의 element를 변형한다음(람다함수) container2에 복사(for_each와 copy를 합친 기능)
	//transform(src시작위치, src끝위치 dst시작위치, 람다함수)
	transform(begin(v1), end(v1), begin(v2),
		[](int elem) {return elem * elem; }
	);
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	return 0;
}
*/