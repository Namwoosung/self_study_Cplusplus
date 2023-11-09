/* 쇼핑카트 관리 class
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

	cout << "카트 프로그램 시행" << endl;
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
		cout << "추가불가! 카트에 빈 공간이 없습니다." << endl;
	}
	else
	{
		cout << pID << "품목을 카트에 추가합니다." << endl;
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
			cout << pID << "품목을 제거합니다." << endl;
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
		cout << "제거불가! 카트에 ID에 해당하는 품목이 존재하지 않습니다." << endl;
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

/* 분수 계산기 ver2
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

/* class 이용해 은행 계좌 관리
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct TRANSACTION
{
	int change_money; //변동금액
	string memo; //메모
};

class BankAccount
{
	static const int MAX_HISTORY_SIZE = 20;

private:
	int m_nAccountNO; //계좌번호(5글자)
	int m_nBalance; //예금잔액
	TRANSACTION m_stHistory[MAX_HISTORY_SIZE]; //20개의 거래내역 기록
	static int nTotalBankBalace; //은행잔고
	int m_nHistoryCount; //최근거래내역
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
	A.Deposit(100000, "용돈");
	A.Withdraw(21000, "도서구입");
	A.Withdraw(15000, "동아리회비");
	A.PrintAccount();

	BankAccount B(10000);
	B.Withdraw(5700, "커피");
	B.Withdraw(4900, "교통비");
	B.Deposit(600000, "장학금");
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
	m_stHistory[0].memo = "계좌생성";
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
	cout << "계좌 잔액" << m_nBalance << endl;
	cout << "거래내역" << endl;
	for (int i = 0; i < m_nHistoryCount; i++)
	{
		cout << i << ':' << m_stHistory[i].change_money << "     " << m_stHistory[i].memo << endl;
	}
}
void BankAccount::Deposit(int nAmount, string str_Memo)
{
	if (m_nHistoryCount == MAX_HISTORY_SIZE)
	{
		cout << "에러!! 거래 내역이 초과되었습니다." << endl;
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
		cout << "에러!! 거래 내역이 초과되었습니다." << endl;
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
	cout << "==============" << endl << "은행잔고" << endl;
	cout << nTotalBankBalace << endl;
}
*/