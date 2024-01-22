/* 상속이용해서 도형class 만들기
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
	cout << "변의 길이가" << line1 << "인 정사각형 생성" << endl;
}
void Square::size()
{
	cout <<  "정사각형의 넓이:" << line1 * line1 << endl;
}

Rectangle::Rectangle(int line1, int line2)
{
	this->line1 = line1;
	this->line2 = line2;
	cout << "두변의 길이가" << line1 << ',' << line2 << "인 직사각형 생성" << endl;
}
void Rectangle::size()
{
	cout << "직사각형의 넓이:" << line1 * line2 << endl;
}

Circle::Circle(int line1)
{
	this->line1 = line1;
	cout << "반지름의 길이가" << line1 << "인 원 생성" << endl;
}
void Circle::size()
{
	cout << "원의 넓이:" << line1 * line1 * 3.14 << endl;
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
	cout << "세변의 길이가" << line1 << ',' << line2 << ',' << line3 << "인 직각삼각형 생성" << endl;
}
void r_aTriangle::size()
{
	cout << "직각삼각형의 넓이:" << line1 * line2 << endl;
}

RegularTriangle::RegularTriangle(int line1)
{
	this->line1 = line1;
	cout << "한변의 길이가" << line1 << "인 정삼각형 생성" << endl;
}
void RegularTriangle::size()
{
	cout << "정삼각형의 넓이:" << (sqrt(3) / 4) * line1 * line1 << endl;
}
*/

/*상속을 통해 TV관리
#include <iostream>
#include <string>

using namespace std;

class BaseTV
{ 
public:
	void virtual printTVInfo();
	void setBrandName(const char* Brandname); //상표이름 설정(strcpy이용)
	void setPrice(int Price); //가격 설정
	void setScreenSize(int ScreenSize); //화면크기 설정

protected:
	char mBrandName[100]; //상표
	int mPrice; //가격
	int mScreenSize; //화면크기
};
class DigitalTV
:public BaseTV
{
public:
	void setHangWall(bool hangwall); //벽결이 지원 여부 설정
	void setSmartTV(bool smarttv); //스마트 기능 지원 여부 설정
	void printTVInfo();
protected:
	bool mHangWall; //벽결이 가능 여부
	bool mSmartTV; //스마트 기능 지원 여부
};
class AnalogTV
:public BaseTV
{
public:
	void setDigitalSupport(bool digitalsupport); //디지털 방송 수신 여부 설정
	void printTVInfo();
protected:
	bool mDigitalSupport; //디지털 방송 수신 여부
};
class LcdTV
:public DigitalTV
{
public:
	void setLED(bool led); // LED기능 지원 여부 설정
	void set3DTV(bool tdtv); //3D TV기능 지원 여부 설정
	void printTVInfo();
protected:
	bool mIsLED; //LED 백라이트 여부
	bool mIs3DTV; // 3D TV기능 지원 여부
};
class PdpTV
:public DigitalTV
{
public:
	void setAcPDP(bool acpdp); // AC PDP, DC PDP 여부 설정
	void printTVInfo();
protected:
	bool mAcPDP; //AC PDP, DC PDP 여부
};
class CrtTV
:public AnalogTV
{
public:
	void setFlat(bool flat); // 완전평면 여부 설정
	void printTVInfo();
protected:
	bool mIsFlat; //완전평면 여부
};
class ProjectionTV
:public AnalogTV
{
public:
	void setProjectionMethod(int pMethod); //프로젝션 방식 설정
	void printTVInfo();
protected:
	int mProjectionMethod; //프로젝션방식 0(LDP), 1(LCD), 2(CRT)
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
	cout << "상표: " << this->mBrandName << endl;
	cout << "가격: " << this->mPrice << "원" << endl;
	cout << "화면크기: " << this->mScreenSize << "Inch" << endl;
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
		cout << "스마트TV기능 지원" << endl;
	}
	else
	{
		cout << "스마트 TV기능 미지원" << endl;
	}
	if (this->mHangWall == true)
	{
		cout << "벽결이 기능 지원" << endl;
	}
	else
	{
		cout << "벽결이 기능 미지원" << endl;
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
		cout << "디지털 방송 수신 가능" << endl;
	}
	else
	{
		cout << "디지털 방송 수신 불가" << endl;
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
		cout << "3D TV 기능 지원" << endl;
	}
	else
	{
		cout << "3D TV 기능 미지원" << endl;
	}
	if (this->mIsLED == true)
	{
		cout << "LED 백라이트 기능 지원" << endl << endl;
	}
	else
	{
		cout << "LED 백라이트 기능 미지원" << endl << endl;
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
		cout << "완전평면 아날로그 TV" << endl << endl;
	}
	else
	{
		cout << "완전평면이 아닌 아날로그 TV" << endl << endl;
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
		cout << "DLP프로젝션 방식" << endl << endl;
	}
	else if (this->mProjectionMethod == 1)
	{
		cout << "LCD프로젝션 방식" << endl << endl;
	}
	else
	{
		cout << "CRT프로젝션 방식" << endl << endl;
	}
}
*/