/* ����̿��ؼ� ����class �����
#include <iostream>

using namespace std;

class Figure
{
public:
	void virtual size() = 0;
};

class Square
:public Figure
{
public:
	Square(int line1);
	void virtual size();
protected:
	int line1;
};

class Rectangle
:public Figure
{
public:
	Rectangle(int line1, int line2);
	void virtual size();
protected:
	int line1;
	int line2;
};

class Circle
:public Figure
{
public:
	Circle(int line1);
	void virtual size();
protected:
	int line1;
};

class r_aTriangle
:public Figure
{
public:
	r_aTriangle(int line1, int line2, int line3);
	void virtual size();
protected:
	int line1;
	int line2;
	int line3;
};

class RegularTriangle
:public Figure
{
public:
	RegularTriangle(int line1);
	void virtual size();
protected:
	int line1;
};

int main()
{
	Square figure1(5);
	figure1.size();

	Rectangle figure2(3, 5);
	figure2.size();

	Circle figure3(4);
	figure3.size();

	r_aTriangle figure4(3, 5, 4);
	figure4.size();

	RegularTriangle figure5(4);
	figure5.size();

	return 0;
}

Square::Square(int line1)
{
	this->line1 = line1;
	cout << "���� ���̰�" << line1 << "�� ���簢�� ����" << endl;
}
void Square::size()
{
	cout <<  "���簢���� ����:" << line1 * line1 << endl;
}

Rectangle::Rectangle(int line1, int line2)
{
	this->line1 = line1;
	this->line2 = line2;
	cout << "�κ��� ���̰�" << line1 << ',' << line2 << "�� ���簢�� ����" << endl;
}
void Rectangle::size()
{
	cout << "���簢���� ����:" << line1 * line2 << endl;
}

Circle::Circle(int line1)
{
	this->line1 = line1;
	cout << "�������� ���̰�" << line1 << "�� �� ����" << endl;
}
void Circle::size()
{
	cout << "���� ����:" << line1 * line1 * 3.14 << endl;
}

r_aTriangle::r_aTriangle(int line1, int line2, int line3)
{
	if (line1 > line2 && line1 > line3)
	{
		this->line1 = line3;
		this->line2 = line2;
		this->line3 = line1;
	}
	else if (line2 > line1 && line2 > line3)
	{
		this->line1 = line1;
		this->line2 = line3;
		this->line3 = line2;
	}
	else
	{
		this->line1 = line1;
		this->line2 = line2;
		this->line3 = line3;
	}
	cout << "������ ���̰�" << line1 << ',' << line2 << ',' << line3 << "�� �����ﰢ�� ����" << endl;
}
void r_aTriangle::size()
{
	cout << "�����ﰢ���� ����:" << line1 * line2 << endl;
}

RegularTriangle::RegularTriangle(int line1)
{
	this->line1 = line1;
	cout << "�Ѻ��� ���̰�" << line1 << "�� ���ﰢ�� ����" << endl;
}
void RegularTriangle::size()
{
	cout << "���ﰢ���� ����:" << (sqrt(3) / 4) * line1 * line1 << endl;
}
*/

/*����� ���� TV����
#include <iostream>
#include <string>

using namespace std;

class BaseTV
{ 
public:
	void virtual printTVInfo();
	void setBrandName(const char* Brandname); //��ǥ�̸� ����(strcpy�̿�)
	void setPrice(int Price); //���� ����
	void setScreenSize(int ScreenSize); //ȭ��ũ�� ����

protected:
	char mBrandName[100]; //��ǥ
	int mPrice; //����
	int mScreenSize; //ȭ��ũ��
};
class DigitalTV
:public BaseTV
{
public:
	void setHangWall(bool hangwall); //������ ���� ���� ����
	void setSmartTV(bool smarttv); //����Ʈ ��� ���� ���� ����
	void printTVInfo();
protected:
	bool mHangWall; //������ ���� ����
	bool mSmartTV; //����Ʈ ��� ���� ����
};
class AnalogTV
:public BaseTV
{
public:
	void setDigitalSupport(bool digitalsupport); //������ ��� ���� ���� ����
	void printTVInfo();
protected:
	bool mDigitalSupport; //������ ��� ���� ����
};
class LcdTV
:public DigitalTV
{
public:
	void setLED(bool led); // LED��� ���� ���� ����
	void set3DTV(bool tdtv); //3D TV��� ���� ���� ����
	void printTVInfo();
protected:
	bool mIsLED; //LED �����Ʈ ����
	bool mIs3DTV; // 3D TV��� ���� ����
};
class PdpTV
:public DigitalTV
{
public:
	void setAcPDP(bool acpdp); // AC PDP, DC PDP ���� ����
	void printTVInfo();
protected:
	bool mAcPDP; //AC PDP, DC PDP ����
};
class CrtTV
:public AnalogTV
{
public:
	void setFlat(bool flat); // ������� ���� ����
	void printTVInfo();
protected:
	bool mIsFlat; //������� ����
};
class ProjectionTV
:public AnalogTV
{
public:
	void setProjectionMethod(int pMethod); //�������� ��� ����
	void printTVInfo();
protected:
	int mProjectionMethod; //�������ǹ�� 0(LDP), 1(LCD), 2(CRT)
};

int main()
{
	BaseTV* myTVs[4];

	LcdTV lcdTV;
	lcdTV.setBrandName("LG");
	lcdTV.setPrice(1000000);
	lcdTV.setScreenSize(60);
	lcdTV.setHangWall(true);
	lcdTV.setSmartTV(false);
	lcdTV.set3DTV(false);
	myTVs[0] = &lcdTV;

	PdpTV pdpTV;
	pdpTV.setBrandName("Samsung");
	pdpTV.setPrice(500000);
	pdpTV.setScreenSize(42);
	pdpTV.setHangWall(false);
	pdpTV.setSmartTV(true);
	pdpTV.setAcPDP(false);
	myTVs[1] = &pdpTV;

	CrtTV crtTV;
	crtTV.setBrandName("sony");
	crtTV.setPrice(100000);
	crtTV.setScreenSize(21);
	crtTV.setDigitalSupport(true);
	crtTV.setFlat(true);
	myTVs[2] = &crtTV;

	ProjectionTV prjTV;
	prjTV.setBrandName("Sharp");
	prjTV.setPrice(200000);
	prjTV.setScreenSize(54);
	prjTV.setDigitalSupport(false);
	prjTV.setProjectionMethod(0);
	myTVs[3] = &prjTV;

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		myTVs[i]->printTVInfo();
		cout << endl;
	}
	return 0;
}

void BaseTV::printTVInfo() 
{
	cout << "��ǥ: " << this->mBrandName << endl;
	cout << "����: " << this->mPrice << "��" << endl;
	cout << "ȭ��ũ��: " << this->mScreenSize << "Inch" << endl;
}
void BaseTV::setBrandName(const char* Brandname)
{
	strcpy_s(this->mBrandName,100,Brandname);
}
void BaseTV::setPrice(int Price) 
{
	this->mPrice = Price;
}
void BaseTV::setScreenSize(int ScreenSize) 
{
	this->mScreenSize = ScreenSize;
}
void DigitalTV::setHangWall(bool hangwall) 
{
	this->mHangWall = hangwall;
}
void DigitalTV::setSmartTV(bool smarttv) 
{
	this->mSmartTV = smarttv;
}
void DigitalTV::printTVInfo() 
{
	BaseTV::printTVInfo();
	if (this->mSmartTV == true)
	{
		cout << "����ƮTV��� ����" << endl;
	}
	else
	{
		cout << "����Ʈ TV��� ������" << endl;
	}
	if (this->mHangWall == true)
	{
		cout << "������ ��� ����" << endl;
	}
	else
	{
		cout << "������ ��� ������" << endl;
	}
}
void AnalogTV::setDigitalSupport(bool digitalsupport) 
{
	this->mDigitalSupport = digitalsupport;
}
void AnalogTV::printTVInfo()
{
	BaseTV::printTVInfo();
	if (this->mDigitalSupport == true)
	{
		cout << "������ ��� ���� ����" << endl;
	}
	else
	{
		cout << "������ ��� ���� �Ұ�" << endl;
	}
}
void LcdTV::setLED(bool led) 
{
	this->mIsLED = led;
}
void LcdTV::set3DTV(bool tdtv)
{
	this->mIs3DTV = tdtv;
}
void LcdTV::printTVInfo() 
{
	cout << "LCD TV" << endl;

	DigitalTV::printTVInfo();

	if (this->mIs3DTV == true)
	{
		cout << "3D TV ��� ����" << endl;
	}
	else
	{
		cout << "3D TV ��� ������" << endl;
	}
	if (this->mIsLED == true)
	{
		cout << "LED �����Ʈ ��� ����" << endl << endl;
	}
	else
	{
		cout << "LED �����Ʈ ��� ������" << endl << endl;
	}
}
void PdpTV::setAcPDP(bool acpdp) 
{
	this->mAcPDP = acpdp;
}
void PdpTV::printTVInfo() 
{
	cout << "PDP TV" << endl;

	DigitalTV::printTVInfo();

	if (this->mAcPDP == true)
	{
		cout << "AC PDP TV" << endl << endl;
	}
	else
	{
		cout << "DC PDP TV" << endl << endl;
	}
}
void CrtTV::setFlat(bool flat)
{
	this->mIsFlat = flat;
}
void CrtTV::printTVInfo() 
{
	cout << "CRT TV" << endl;

	AnalogTV::printTVInfo();

	if (this->mIsFlat == true)
	{
		cout << "������� �Ƴ��α� TV" << endl << endl;
	}
	else
	{
		cout << "��������� �ƴ� �Ƴ��α� TV" << endl << endl;
	}
}
void ProjectionTV::setProjectionMethod(int pMethod) 
{
	this->mProjectionMethod = pMethod;
}
void ProjectionTV::printTVInfo() 
{
	cout << "Projection TV" << endl;

	AnalogTV::printTVInfo();
	
	if (this->mProjectionMethod == 0)
	{
		cout << "DLP�������� ���" << endl << endl;
	}
	else if (this->mProjectionMethod == 1)
	{
		cout << "LCD�������� ���" << endl << endl;
	}
	else
	{
		cout << "CRT�������� ���" << endl << endl;
	}
}
*/