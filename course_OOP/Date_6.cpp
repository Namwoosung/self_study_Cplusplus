#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* string 자료형
int main()
{
	string s1 = "fred";
	cout << s1 << endl;
	cout << s1.size() << endl << endl; //size() == length()

	cout << s1.empty() << endl; // empty() -> 비어있으면 true(1), 비어있지않으면 false(0) 반환
	s1.clear(); // s1 = "";
	cout << s1.empty() << endl << endl;

	s1 = "Good";
	s1 = s1 + "-bye"; // s1 = "Good-bye"
	cout << s1[4] << ", " << s1.at(4) << endl; // s1[4] == s1.at(4), at(): string멤버에 있는 메소드 -> 속도는 느리지만 예외처리가 있어 오류가 발생할 일 적음(안정성)
	cout << s1.substr(5, 3) << endl; //substr(a,b) -> a번째 인덱스부터 b개의 문자를 반환
	cout << s1.find("od") << endl; //find() -> 문자열 내에서 매개변수와 동일한 문자의 인덱스를 반환(동일한 문자가 있다면 더 앞에 있는 인덱스를 반환)
	cout << (s1.find("od", 5) == string::npos) << endl; //5의 의미는 5번째 인덱스부터 검사를 하라는 의미(만약 찾지 못하면 쓰레기값 반환), (쓰레기 값 == string::npos)

	//Good-bye-od
	s1 += "-od";
	int index = s1.find("od");
	cout << s1.find("od", index + 2) << endl; //해당 문자열의 두번째 인덱스를 반환받고 싶을 때 사용하는 스킬

	return 0;
}
*/

////파일 관리
////파일 객체 사용법: 1)open(), 2)close()
////ofstream fout: fout << s1 (문자열을 저장)
////				 fout.put(문자)
////ifstream fin: fin >> 문자열 (띄어쓰기, 줄바꿈으로 구분)
////				fin.get(문자)
////				getline(fin,문자열) // 줄바꿈으로 line 구분
//// fin == false: 1)파일의 끝까지 다 읽었을 때, 2) 파일을 열지 못할때
//int main()
//{
//	ofstream fout;
//	fout.open("example.txt"); //덮어쓰기(현재 파일을 지우고 새로 작성)
//	//fout.open("example.txt", ios::app); //이어쓰기(파일 초기화x)
//
//	string s1 = "Objective Oriented Programming";
//	fout << s1 << endl;
//	fout << "Random variable" << endl;
//	fout << "Linear Algebra" << endl;
//
//	fout.close();
//
//	ifstream fin;
//	char ch;
//	fin.open("example.txt");
//	/*존재하지 않는 파일을 불러왔을 경우의 예외처리
//	fin.open("example.txt2");
//	if (!fin)
//	{
//		cout << "Erroe: no such file exists" << endl;
//		exit(100); // 포로그램 강제 종료
//	}
//	*/
//	/*한 문자열을 받아 출력하는 코드
//	while(true)
//	{
//		fin >> s1; //스페이스 혹은 엔터 입력까지의 문자열을 불러와 저장
//		if (!fin)
//		{
//			break;
//		}
//		cout << s1 << endl;
//	}
//	*/
//	/*문자 하나하나를 받아 출력하는 코드
//	while (true)
//	{
//		fin.get(ch); //문자 하나를 반환받음(스페이스, 줄바꿈문자 모두 받아서 반환)
//		if (!fin)
//		{
//			break;
//		}
//		cout << ch;
//	}
//	*/
//	/*파일의 한 줄씩 받아 출력하는 코드
//	while (getline(fin, s1))
//	{
//		cout << s1 << endl;
//	}
//	*/
//
//	fin.close();
//
//	return 0;
//}