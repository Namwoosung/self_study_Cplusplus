//#include <iostream> //C++�� ���̺귯�� ���� (����� �Լ����� ���ԵǾ� ����, cout, cin....)

//using namespace std; //���ӽ����̽��� std��� -> �浹���� & ��Ȯȯ ���ӽ����̽� ����

/*���� ����, ����, ���
int main() { //���� �Լ��� ������Ʈ�� ������ �� �� ����, ������Ʈ ����� �ҷ����� �Լ�
	int x;  //��������
	x = 10; // �Ҵ�, x��� ������ 10�̶�� �� ����

	cout << x << endl; //x��� ���� ���
	//cout ȭ�鿡 ������ ����ϴ� �Լ�
	//endl �ٹٲ�(����)�� �ϴ� ����
*/

/*�������� ��� �ڷ���
int main()
{
	short int sx; //2����Ʈ ũ�� (�� 3��) int ������ ��
	int x; //4����Ʈ ũ�� (�� 20��)
	long int lx; //4����Ʈ ũ�� (�� 20��) int ������ �� ++int�� long�� ���̴� int�� �ü���� ���� �޶��� ex 64bit OS������ 8byte, 16bit OS������ 2byte but long�� 4byte�� ����
	long long int llx; // 8����Ʈ ũ�� () int ������ ��

	//���� �տ� unsigned�� ���̸� ����� ��� -> ���������� 2�谡 ��

	cout << sizeof(sx) << endl; //sizeof�Լ�: �ش纯���� �޸�ũ�⸦ ����Ʈ ������ ������ִ� �Լ�
	cout << sizeof(x) << endl;
	cout << sizeof(lx) << endl;
	cout << sizeof(llx) << endl;
}
*/

/*ĳ���� �ڷ����� �ƽ�Ű �ڵ�
int main()
{
	char ch1 = 'A';
	char ch2 = 65;// A�� �ƽ�Ű �ڵ�
	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*���ȭ(const)
int main()
{
	const double PI = 3.14;
	//PI = 44.5; ������ ����(PI������ const�� �����Ͽ� ���ȭ�߱� ������ �����ǰ� �Ұ���)
}
*/

/* cin + ��Ģ������
int main()
{
	int x, y, sum, mod;
	float div;
	cin >> x >> y; // ����ڿ��� ���� �Է¹޾� x�� y�� ���� ����

	sum = x + y;
	mod = x % y;
	div = float(x) / y;

	x += y; // x = x + y;
	x %= y; // x = x % y;


	++x; //�������� ������(x�� 1�� ���ϰ� ���� ���� x�� ��ȯ)
	x++; //�������� ������(���� x�� ���� ��ȯ�ϰ� x�� 1�� ����)
	--x;
	x--;

	cout << x << '\t' << y << endl;
	cout << sum << endl;
	cout << mod << endl;
	cout << div << endl;
}
*/

/*�񱳿�����(false = 0, true = 1)
int main()
{
	cout << (7 == 5) << endl;
	cout << (7 == 7) << endl;
}
*/


/*����ų� ���۷����� -> �� ���� ��ȯ ��� ���� ���ϴ� ���� ��ȯ, [ ? (���� �� ��ȯ��) : (������ �� ��ȯ ��)]���� ���
int main()
{
	cout << (7 >= 5 ? 1000 : -100) << endl;
}
*/