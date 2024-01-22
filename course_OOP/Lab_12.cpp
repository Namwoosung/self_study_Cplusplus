//Date_16 & Date_17 & Date_18

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*기초문제1
class Base
{
protected:
	void print_Base() { cout << "Base" << endl; }
};

class Derived : private Base
{
public:
	void print_derived()
	{
		print_Base();
		cout << "Derived" << endl;
	}
};

int main()
{
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}
*/

/*기초문제 2
class Text
{
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	virtual string get() const { return text; }
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text
{
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() const override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { Text::append(connector + _extra); }
};

class FixedText : public Text
{
public:
	FixedText() : Text::Text("FIXED") {}
	void append(string _extra) override {};
};

int main()
{
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2;
	//t2 = t1;

	return 0;
}
*/

/*응용문제1&2 class
class Polygon
{
protected:
	int mPoint;
	double mLength;
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point, mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() 
	{ 
		cout << "Perimeter: empty" << endl;
	}
	virtual void calcArea()
	{
		cout << "Area: empty" << endl;
	}
};

class Rectangle : public Polygon
{
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength << endl; }
};

class Triangle : public Polygon
{
public:
	Triangle() {}
	Triangle(int point, float length) : Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength * sqrt(3) / 4 << endl; }
};

class Circle : public Polygon
{
public:
	Circle() {}
	Circle(int point, float length) : Polygon(point, length) {}
	~Circle() {}
	void calcPerimeter() override { cout << "Perimeter: " << 3.14 * 2 * mLength << endl; }
	void calcArea() override { cout << "Area: " << 3.14 * mLength * mLength << endl; }
};
*/

/*응용문제1
int main()
{
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	return 0;
}
*/

/*응용문제2
int main()
{
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}
*/

/*응용문제3
class Train
{
protected:
	int mPeople;
public:
	Train() {}
	Train(int people) { mPeople = people; }
	~Train() {}
	virtual int station(int takeOff, int takeOn) 
	{
		mPeople = mPeople - takeOff + takeOn;
		return mPeople;
	}
};

class Ktx : public Train
{
public:
	Ktx() : Train(0) {}
	Ktx(int people) : Train(people) {}
	~Ktx() {}
	int station (int takeOff, int takeOn) override 
	{
		mPeople = mPeople - takeOff + takeOn;
		return mPeople;
	}
	int getPeople() { return mPeople; }
};

int main()
{
	Ktx k;
	int off_num = 0, on_num = 0, max_people = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "번역: ";
		cin >> off_num >> on_num;
		k.station(off_num, on_num);
		if (k.getPeople() > 300)
		{
			cout << "정원초과입니다." << endl;
			break;
		}
		else if (k.getPeople() < 0)
		{
			cout << "정원미달입니다." << endl;
			break;
		}

		if (max_people <= k.getPeople())
		{
			max_people = k.getPeople();
		}
		if (i == 4)
		{
			cout << "가장 많은 사람이 탑승 했을 때의 사람 수: " << max_people << endl;
		}
	}

	return 0;
}
*/

/*응용문제4
class Avengers
{
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
public:
	Avengers()
	{
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	virtual int attack() { return 0; }
	virtual void defense(int _attack_point) {}
	virtual void print_info() {}
};

class Character : public Avengers
{
public:
	void set(string _name, int _attack, int _defense, int _health) override
	{
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	int attack() override { return attack_point; }
	void defense(int _attack_point) override { health -= _attack_point - defense_point; }
	void print_info() override 
	{
		cout << "Name: " << this->name << endl;
		cout << "Attack_Point: " << this->attack_point << endl;
		cout << "Defense_Point: " << this->defense_point << endl;
		cout << "Health: " << this->health << endl;
	}
	int get_health() { return health; }
};

int main()
{
	Character my_char;
	Character enemy_char;

	srand(time(NULL));

	string my_pick;
	string enemy_pick;

	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> my_pick;

	switch (rand() % 3)
	{
	case 0:
		enemy_pick = "IronMan";
		break;
	case 1:
		enemy_pick = "CaptainAmerica";
		break;
	case 2:
		enemy_pick = "Thor";
		break;
	}

	if (my_pick == "IronMan")
	{
		my_char.set("IronMan", 70, 40, 100);
	}
	else if (my_pick == "CaptainAmerica")
	{
		my_char.set("CaptainAmerica", 60, 50, 100);
	}
	else if (my_pick == "Thor")
	{
		my_char.set("Thor", 80, 30, 100);
	}

	if (enemy_pick == "IronMan")
	{
		enemy_char.set("IronMan", 70, 40, 100);
	}
	else if (enemy_pick == "CaptainAmerica")
	{
		enemy_char.set("CaptainAmerica", 60, 50, 100);
	}
	else if (enemy_pick == "Thor")
	{
		enemy_char.set("Thor", 80, 30, 100);
	}

	cout << "--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << '\t'
		<< "Enemy Life: " << enemy_char.get_health() << endl;

	while (1)
	{
		enemy_char.defense(my_char.attack());
		cout << "My Life: " << my_char.get_health() << '\t'
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0)
		{
			cout << "you win!" << endl;
			break;
		}
		my_char.defense(enemy_char.attack());
		cout << "My Life: " << my_char.get_health() << '\t'
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0)
		{
			cout << "you Lose!" << endl;
			break;
		}
	}

	return 0;
}
*/