//Review
//���������: 1) open() 2)close()
//ofstream fout: fout << ���ڿ�, fout.put(����)
//ifstream fin: fin >> ���ڿ� //���� �Ǵ� �ٹٲ� ���ڷ� ���ڿ� ����
//				fin.get(����) //
//				getline(fin, ���ڿ�) //�ٹٲ� ���ڷ� ����
//(!fin == true: 1) -> 1) ������ ����� ���� ���� �� 2)������ ���� ���� 

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*cout �Լ�
int main()
{
	double a = 12.347;

	cout.width(15); //��ĭ����
	cout.precision(4); //�����ڸ���
	cout.fill('-'); //��ĭ�� ���ڷ� ä���
	cout << a << endl;
	cout.fill(' '); //���Ŀ� ä�� ���ڸ� ����ϱ⸦ ������ �ʴ´ٸ� �ٽ� ��ĭ���� ������ �־����

	char ch; //ch�Է½� �����̽��ٸ� �Է½� ���� ���x
	cin.unsetf(ios::skipws); //C++������ �ʱ�ȭ -> �����̽��� ���� Ư�����ڷ� ���
	cin >> ch;
	cout << '(' << ch << ')' << endl;
	cin.setf(ios::skipws); //�ٽ� ������ Ȱ��ȭ

	return 0;
}
*/



//bool readstu(ifstream& fin, int& id, int& score1, int& score2, int& score3);
//void calcgrade(int score1, int score2, int score3, int& avg, char& grade);
//void writestu(ofstream& fout, int id, int avg, char grade);
////ifstream, ofstream�� �Ű������� �������� �׻� pass by reference�� ��������� �׷��� ������ ������ ����
//
//int main()
//{
//	//�ݺ�: ��� �л��� ������ �о ó���� �� ����
//		//1)ch7stufl.dat���� �Ѹ��� �л������� �о�´�(id, s1, s2 ,s3)
//		//2)(s1, s2, s3)�� �̿��Ͽ� ���(avg)�� ���(grade)�� ���Ѵ�
//		//3)grade.txt�� �Ѹ� �л��� id, avg, grade�� �����Ѵ�
//
//	ifstream fin("ch7stufl.dat"); //fin.open()
//	ofstream fout("grade.txt"); //fout.open()
//
//	if (!fin || !fout) //����ó�� ***�߿�***, ������� ���� ó�� �ʼ�
//	{
//		cout << "���Ͽ��� ����" << endl;
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
//	cout << "���α׷� ����" << endl;
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