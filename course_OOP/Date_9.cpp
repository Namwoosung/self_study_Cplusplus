#include <iostream>
#include <vector> //vector는 stack형 자료구조
using namespace std;

/*Review
int main()
{
	int x = 100;
	int* px = &x;

	cout << x << '\t' << &x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;

	return 0;
}
*/

/*function pointer
int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*f)(int, int), int a, int b)
{
	return f(a, b);
}

int main()
{
	int(*func)(int, int); //int의 의미: 반환값이 int인 함수의 포인터, func: 포인터 변수 이름, (int, int): 파라미터로 int형 변수 2개를 갖는 함수의 포인터

	func = &sum;
	cout << func(10, 20) << endl;

	func = &mult;
	cout << func(10, 20) << endl;

	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}
*/


/*vector
//객체는 항상 pass by reference로 -> 값 복사하지않고 주소를 가리키게함 -> 쓸데없는 데이터손실을 줄여줌
//함수 안에서 객체의 data가 바뀌지 않을 때 const를 써줄 것
void print(const vector<int>& v) //value로 값을 넘겨주면 vector모든 element를 복사 -> 비효울적, reference로 값을 넘겨주면 해결 but 함수내에서도 값이 변할 수 있음 -> const로 상수화 시켜주면 됨
{
	for (unsigned int i = 0; i < v.size(); i++) //size()의 반환값이 unsigned int이므로 맞춰주기 위해 똑같은자료형 사용(int사용해도 되긴함)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
}


int main()
{
	vector<int> vec{ 10, 20, 30, 40 }; //<int>: vector속 모든 element들은 정수형 값임을 의미
	vector<int> vec_2(10); // 10개의 인덱스를 만들고 0으로 채움
	vector<int> vec_3(10, 8); //10개의 인덱스를 만들고 8로 채움

	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;
	print(vec);

	vec.push_back(50);
	print(vec);
	vec.pop_back();
	print(vec);
	//stack형 자료구조이기 때문에 추가 혹은 제거는 맨 뒤 element에서 이루어짐

	//int& elem = vec[0] -> body
	//int& elem = vec[1] -> body
	//.....
	//즉 for문 시작시 elem과 vec의 인덱스를 동기화 시켜준 뒤 for문의 body를 실행
	//아래 코드는 vec의 element들을 모두 입력값으로 바꿔줌
	for (int& elem : vec)
	{
		cin >> elem;
	}
	//int elem = vec[0] -> body
	//int elem = vec[1] -> body
	//.....
	for (int elem : vec)
	{
		cout << elem << '\t';
	}
	cout << endl;


	return 0;
}
*/