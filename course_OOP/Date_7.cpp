//Review
//파일입출력: 1) open() 2)close()
//ofstream fout: fout << 문자열, fout.put(문자)
//ifstream fin: fin >> 문자열 //띄어쓰기 또는 줄바꿈 문자로 문자열 구분
//				fin.get(문자) //
//				getline(fin, 문자열) //줄바꿈 문자로 구분
//(!fin == true: 1) -> 1) 파일을 제대로 열지 못할 때 2)파일의 끝에 도달 

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*cout 함수
int main()
{
	double a = 12.347;

	cout.width(15); //빈칸생성
	cout.precision(4); //숫자자르기
	cout.fill('-'); //빈칸을 문자로 채우기
	cout << a << endl;
	cout.fill(' '); //이후에 채운 문자를 사용하기를 원하지 않는다면 다시 빈칸으로 설정해 주어야함

	char ch; //ch입력시 스페이스바를 입력시 문자 취급x
	cin.unsetf(ios::skipws); //C++설정을 초기화 -> 스페이스바 또한 특수문자로 취급
	cin >> ch;
	cout << '(' << ch << ')' << endl;
	cin.setf(ios::skipws); //다시 설정을 활성화

	return 0;
}
*/



//bool readstu(ifstream& fin, int& id, int& score1, int& score2, int& score3);
//void calcgrade(int score1, int score2, int score3, int& avg, char& grade);
//void writestu(ofstream& fout, int id, int avg, char grade);
////ifstream, ofstream을 매개변수로 보낼때는 항상 pass by reference로 보내줘야함 그렇지 않으면 컴파일 오류
//
//int main()
//{
//	//반복: 모든 학생의 정보를 읽어서 처리할 때 까지
//		//1)ch7stufl.dat에서 한명의 학생정보를 읽어온다(id, s1, s2 ,s3)
//		//2)(s1, s2, s3)를 이용하여 평균(avg)와 등급(grade)를 구한다
//		//3)grade.txt에 한명 학생의 id, avg, grade를 저장한다
//
//	ifstream fin("ch7stufl.dat"); //fin.open()
//	ofstream fout("grade.txt"); //fout.open()
//
//	if (!fin || !fout) //예외처리 ***중요***, 퀴즈볼때도 예외 처리 필수
//	{
//		cout << "파일열기 오류" << endl;
//		exit(100);
//	}
//
//	int id, score1, score2, score3, avg;
//	char grade;
//
//	while (readstu(fin, id, score1, score2, score3)) //1)
//	{
//		calcgrade(score1, score2, score3, avg, grade); //2)
//		writestu(fout, id, avg, grade);
//	}
//	cout << "프로그램 종료" << endl;
//
//	fin.close();
//	fout.close();
//
//	return 0;
//}
//
//bool readstu(ifstream& fin, int& id, int& score1, int& score2, int& score3)
//{
//	fin >> id >> score1 >> score2 >> score3;
//	if (!fin)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//void calcgrade(int score1, int score2, int score3, int& avg, char& grade)
//{
//	avg = (score1 + score2 + score3) / 3;
//	if (avg >= 90)
//	{
//		grade = 'a';
//	}
//	else if (avg >= 80)
//	{
//		grade = 'b';
//	}
//	else if (avg >= 70)
//	{
//		grade = 'c';
//	}
//	else if (avg >= 60)
//	{
//		grade = 'd';
//	}
//	else
//	{
//		grade = 'f';
//	}
//}
//
//void writestu(ofstream& fout, int id, int avg, char grade)
//{
//	fout.fill('0');
//	fout << setw(4) << id;
//	fout.fill(' ');
//	fout << setw(3) << avg;
//	fout << setw(2) << grade << endl;
//}