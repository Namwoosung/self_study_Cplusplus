#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* string �ڷ���
int main()
{
	string s1 = "fred";
	cout << s1 << endl;
	cout << s1.size() << endl << endl; //size() == length()

	cout << s1.empty() << endl; // empty() -> ��������� true(1), ������������� false(0) ��ȯ
	s1.clear(); // s1 = "";
	cout << s1.empty() << endl << endl;

	s1 = "Good";
	s1 = s1 + "-bye"; // s1 = "Good-bye"
	cout << s1[4] << ", " << s1.at(4) << endl; // s1[4] == s1.at(4), at(): string����� �ִ� �޼ҵ� -> �ӵ��� �������� ����ó���� �־� ������ �߻��� �� ����(������)
	cout << s1.substr(5, 3) << endl; //substr(a,b) -> a��° �ε������� b���� ���ڸ� ��ȯ
	cout << s1.find("od") << endl; //find() -> ���ڿ� ������ �Ű������� ������ ������ �ε����� ��ȯ(������ ���ڰ� �ִٸ� �� �տ� �ִ� �ε����� ��ȯ)
	cout << (s1.find("od", 5) == string::npos) << endl; //5�� �ǹ̴� 5��° �ε������� �˻縦 �϶�� �ǹ�(���� ã�� ���ϸ� �����Ⱚ ��ȯ), (������ �� == string::npos)

	//Good-bye-od
	s1 += "-od";
	int index = s1.find("od");
	cout << s1.find("od", index + 2) << endl; //�ش� ���ڿ��� �ι�° �ε����� ��ȯ�ް� ���� �� ����ϴ� ��ų

	return 0;
}
*/

////���� ����
////���� ��ü ����: 1)open(), 2)close()
////ofstream fout: fout << s1 (���ڿ��� ����)
////				 fout.put(����)
////ifstream fin: fin >> ���ڿ� (����, �ٹٲ����� ����)
////				fin.get(����)
////				getline(fin,���ڿ�) // �ٹٲ����� line ����
//// fin == false: 1)������ ������ �� �о��� ��, 2) ������ ���� ���Ҷ�
//int main()
//{
//	ofstream fout;
//	fout.open("example.txt"); //�����(���� ������ ����� ���� �ۼ�)
//	//fout.open("example.txt", ios::app); //�̾��(���� �ʱ�ȭx)
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
//	/*�������� �ʴ� ������ �ҷ����� ����� ����ó��
//	fin.open("example.txt2");
//	if (!fin)
//	{
//		cout << "Erroe: no such file exists" << endl;
//		exit(100); // ���α׷� ���� ����
//	}
//	*/
//	/*�� ���ڿ��� �޾� ����ϴ� �ڵ�
//	while(true)
//	{
//		fin >> s1; //�����̽� Ȥ�� ���� �Է±����� ���ڿ��� �ҷ��� ����
//		if (!fin)
//		{
//			break;
//		}
//		cout << s1 << endl;
//	}
//	*/
//	/*���� �ϳ��ϳ��� �޾� ����ϴ� �ڵ�
//	while (true)
//	{
//		fin.get(ch); //���� �ϳ��� ��ȯ����(�����̽�, �ٹٲ޹��� ��� �޾Ƽ� ��ȯ)
//		if (!fin)
//		{
//			break;
//		}
//		cout << ch;
//	}
//	*/
//	/*������ �� �پ� �޾� ����ϴ� �ڵ�
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