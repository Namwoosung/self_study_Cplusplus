/* ����īƮ ���� class
#include <iostream>
#include <string>

using namespace std;

struct Product
{
	int pID;
	int Price;
};

class Cart
{
public:
	Cart();
	Cart(const Cart& ca);
	void add(int pId);
	void remove(int pID);
	void print();
	void print(Product produckPriceAry[]);

private:
	int PruductID[10];
	int nProduct;
};

int main()
{
	struct Product productPriceAry[10] = { {1001, 1000}, {2001, 5000}, {2002, 7500}, {3001, 5000}, {3002,10000}, {3003, 3000} };

	cout << "īƮ ���α׷� ����" << endl;
	Cart ca1;
	ca1.add(1001);
	ca1.add(2001);
	ca1.print();

	Cart ca2(ca1);
	ca1.remove(1001);
	ca1.add(2002);
	ca1.print(productPriceAry);

	ca1.remove(2001);
	ca1.remove(2002);
	ca1.print();

	ca1.remove(1001);

	Cart ca3;
	ca3.add(1001);
	ca3.add(2001);
	ca3.add(2001);
	ca3.add(2001);
	ca3.add(2002);
	ca3.add(2002);
	ca3.add(3001);
	ca3.add(3001);
	ca3.add(2002);
	ca3.add(3003);
	ca3.add(3002);

	return 0;

}

Cart::Cart()
{
	PruductID[10] = { 0, };
	nProduct = 0;
}
Cart::Cart(const Cart& ca)
{
	for (int i = 0; i < 10; i++)
	{
		PruductID[i] = ca.PruductID[i];
	}
	nProduct = ca.nProduct;
}
void Cart::add(int pID)
{
	if (this->nProduct >= 10)
	{
		cout << "�߰��Ұ�! īƮ�� �� ������ �����ϴ�." << endl;
	}
	else
	{
		cout << pID << "ǰ���� īƮ�� �߰��մϴ�." << endl;
		this->PruductID[this->nProduct] = pID;
		this->nProduct += 1;
	}
}
void Cart::remove(int pID)
{
	bool judge = true;
	for (int i = 0; i < this->nProduct; i++)
	{
		if (this->PruductID[i] == pID)
		{
			cout << pID << "ǰ���� �����մϴ�." << endl;
			this->nProduct -= 1;
			this->PruductID[i] = 0;
			judge = false;
			for (int j = i; j < 10; j++)
			{
				if (j == 9)
				{
					this->PruductID[j] = 0;
				}
				else
				{
					this->PruductID[j] = this->PruductID[j + 1];
				}
			}
		}
	}
	if (judge == true)
	{
		cout << "���źҰ�! īƮ�� ID�� �ش��ϴ� ǰ���� �������� �ʽ��ϴ�." << endl;
	}
}
void Cart::print()
{
	cout << "PID" << endl << "--------" << endl;
	for (int i = 0; i < this->nProduct; i++)
	{
		cout << this->PruductID[i] << endl;
	}
}
void Cart::print(Product productPriceAry[])
{
	cout << "PID" << '\t' << "PRICE" << endl << "---------------" << endl;
	for (int i = 0; i < this->nProduct; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (this->PruductID[i] == productPriceAry[j].pID)
			{
				cout << productPriceAry[j].pID << '\t' << productPriceAry[j].Price << endl;
			}
		}
	}
}
*/

/* �м� ���� ver2
#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction(int number_1, int number_2);
	Fraction();

private:
	int number_1;
	int number_2;

public:
	int GCD(int given_number_1, int given_number_2);
	Fraction operator+(Fraction another);
	Fraction operator-(Fraction another);
	Fraction operator*(Fraction another);
	Fraction operator/(Fraction another);
	Fraction& operator=(const Fraction& another);
	friend ostream& operator<<(ostream& os, const Fraction& one);
};

int main()
{
	Fraction fr1(3, 5);
	Fraction fr2(7, 10);
	Fraction fr3;

	fr3 = fr1 + fr2;
	cout << "value of fr1 + fr2" << endl;
	cout << fr3 << endl;
	cout << endl;

	fr3 = fr1 - fr2;
	cout << "value of fr1 - fr2" << endl;
	cout << fr3 << endl;
	cout << endl;

	fr3 = fr1 * fr2;
	cout << "value of fr1 * fr2" << endl;
	cout << fr3 << endl;
	cout << endl;

	fr3 = fr1 / fr2;
	cout << "value of fr1 / fr2" << endl;
	cout << fr3 << endl;
	cout << endl;

	return 0;
}

Fraction::Fraction(int number_1, int number_2)
{
	this->number_1 = number_1;
	this->number_2 = number_2;
}
Fraction::Fraction()
{
	number_1 = 0;
	number_2 = 0;
}
int Fraction::GCD(int given_number_1, int given_number_2)
{
	int left_number;

	bool judge = true;
	while (judge)
	{
		if (given_number_1 > given_number_2)
		{
			left_number = given_number_1 % given_number_2;
			if (left_number == 0)
			{
				judge = false;
				return given_number_2;
			}
			else
			{
				given_number_1 = left_number;
			}
		}
		else if (given_number_1 < given_number_2)
		{
			left_number = given_number_2 % given_number_1;
			if (left_number == 0)
			{
				judge = false;
				return given_number_1;
			}
			else
			{
				given_number_2 = left_number;
			}
		}
		else
		{
			judge = false;
			return given_number_1;
		}
	}
}
Fraction Fraction::operator+(Fraction another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_2 + number_2 * another.number_1;
	int GCD_number = GCD(num_down, num_up);

	int test_1;
	int test_2;
		
	test_1 = num_up / GCD_number;
	test_2 = num_down / GCD_number;
	return Fraction(test_1, test_2);
}
Fraction Fraction::operator-(Fraction another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_2 - number_2 * another.number_1;
	int GCD_number = GCD(num_down, num_up);

	int test_1;
	int test_2;

	test_1 = num_up / GCD_number;
	test_2 = num_down / GCD_number;
	return Fraction(test_1, test_2);
}
Fraction Fraction::operator*(Fraction another)
{
	int num_down = number_2 * another.number_2;
	int num_up = number_1 * another.number_1;
	int GCD_number = GCD(num_down, num_up);

	int test_1;
	int test_2;

	test_1 = num_up / GCD_number;
	test_2 = num_down / GCD_number;
	return Fraction(test_1, test_2);
}
Fraction Fraction::operator/(Fraction another)
{
	int num_down = number_2 * another.number_1;
	int num_up = number_1 * another.number_2;
	int GCD_number = GCD(num_down, num_up);

	int test_1;
	int test_2;

	test_1 = num_up / GCD_number;
	test_2 = num_down / GCD_number;
	return Fraction(test_1, test_2);
}

Fraction& Fraction::operator=(const Fraction& another)
{
	Fraction fr4;
	number_1 = another.number_1;
	number_2 = another.number_2;

	fr4.number_1 = number_1;
	fr4.number_2 = number_2;
	return fr4;
}

ostream& operator<<(ostream& os, const Fraction& one)
{
	os << one.number_1 << '/' << one.number_2 << endl;
	return os;
}
*/

/* class �̿��� ���� ���� ����
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct TRANSACTION
{
	int change_money; //�����ݾ�
	string memo; //�޸�
};

class BankAccount
{
	static const int MAX_HISTORY_SIZE = 20;

private:
	int m_nAccountNO; //���¹�ȣ(5����)
	int m_nBalance; //�����ܾ�
	TRANSACTION m_stHistory[MAX_HISTORY_SIZE]; //20���� �ŷ����� ���
	static int nTotalBankBalace; //�����ܰ�
	int m_nHistoryCount; //�ֱٰŷ�����
public:
	BankAccount()
	{
		srand(time(NULL));
		m_nAccountNO = rand() % 100000;
		m_nBalance = 0;
		m_nHistoryCount = 0;
		for (int i = 0; i < 20; i++)
		{
			m_stHistory[i] = { 0," " };
		}
	}
	BankAccount(int number);
	void PrintAccount();
	static void PrintBank();
	void Deposit(int nAmount, string str_Memo);
	void Withdraw(int nAmount, string str_Memo);
};

int main()
{
	BankAccount A(50000);
	A.Deposit(100000, "�뵷");
	A.Withdraw(21000, "��������");
	A.Withdraw(15000, "���Ƹ�ȸ��");
	A.PrintAccount();

	BankAccount B(10000);
	B.Withdraw(5700, "Ŀ��");
	B.Withdraw(4900, "�����");
	B.Deposit(600000, "���б�");
	B.PrintAccount();

	BankAccount::PrintBank();

	return 0;
}

int BankAccount::nTotalBankBalace = 0;
BankAccount::BankAccount(int number)
{
	srand(time(NULL));
	m_nAccountNO = rand() % 100000;
	m_nBalance = number;
	m_stHistory[0].change_money = number;
	m_stHistory[0].memo = "���»���";
	m_nHistoryCount = 1;
	for (int i = 1; i < 20; i++)
	{
		m_stHistory[i] = { 0," " };
	}

}
void BankAccount::PrintAccount()
{
	cout << "==================" << endl;
	cout << "Account NO." << m_nAccountNO << endl;
	cout << "���� �ܾ�" << m_nBalance << endl;
	cout << "�ŷ�����" << endl;
	for (int i = 0; i < m_nHistoryCount; i++)
	{
		cout << i << ':' << m_stHistory[i].change_money << "     " << m_stHistory[i].memo << endl;
	}
}
void BankAccount::Deposit(int nAmount, string str_Memo)
{
	if (m_nHistoryCount == MAX_HISTORY_SIZE)
	{
		cout << "����!! �ŷ� ������ �ʰ��Ǿ����ϴ�." << endl;
		return;
	}
	nTotalBankBalace += nAmount;
	m_nBalance += nAmount;
	m_stHistory[m_nHistoryCount].change_money = nAmount;
	m_stHistory[m_nHistoryCount].memo = str_Memo;
	m_nHistoryCount++;

}
void BankAccount::Withdraw(int nAmount, string str_Memo)
{
	if (m_nHistoryCount == MAX_HISTORY_SIZE)
	{
		cout << "����!! �ŷ� ������ �ʰ��Ǿ����ϴ�." << endl;
		return;
	}
	nTotalBankBalace -= nAmount;
	m_nBalance -= nAmount;
	m_stHistory[m_nHistoryCount].change_money = -nAmount;
	m_stHistory[m_nHistoryCount].memo = str_Memo;
	m_nHistoryCount++;
}
void BankAccount::PrintBank()
{
	cout << "==============" << endl << "�����ܰ�" << endl;
	cout << nTotalBankBalace << endl;
}
*/