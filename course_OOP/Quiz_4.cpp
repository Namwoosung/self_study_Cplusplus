/*main.cpp
#include "ApplicationType.h"

using namespace std;

int main()
{
	ApplicationType appType;
	appType.run();
	return 0;
}
*/

/*Attacker.cpp
#include "ApplicationType.h"

using namespace std;

int main()
{
	ApplicationType appType;
	appType.run();
	return 0;
}
*/

/*Miner.cpp
#include "Miner.h"

Miner::Miner(int _type, string _name, int _price, int _mining_point) :
	Unit(_type, _name, _price), mining_point(_mining_point) {}

int Miner::action()
{
	return mining_point;
}

void Miner::print()
{
	cout << "[Miner] Name: " << get_name() << " (Mining point: " << mining_point << ", Price: " << get_price() << ")" << endl;
}

*/

/*ApplicationType.cpp
#include "ApplicationType.h"

ApplicationType::ApplicationType()
{
	unit_list_in_barracks = { new Attacker(1, "swordman", 300, 10),
							  new Attacker(1, "champion", 1200, 16),
							  new Miner(0, "farmer", 200, 20),
							  new Miner(0, "landlord", 500, 50) };
	curr_turn = 1;
	MAX_turn = 50;
	gold = 1000;
	enemy_hp = 500;
	flag_status = 0;
}

ApplicationType::~ApplicationType()
{
	for (unsigned i = 0; i < unit_list_in_barracks.size(); i++)
	{
		delete[] unit_list_in_barracks[i];
	}
	for (unsigned i = 0; i < unit_list.size(); i++)
	{
		delete[] unit_list[i];
	}
}

void ApplicationType::increase_turn()
{
	curr_turn++;
	if (curr_turn == MAX_turn)
	{
		flag_status = 1;
		cout << "You lose" << endl;
	}
}

void ApplicationType::print_unit_list_in_barracks()
{
	for (auto elem : unit_list_in_barracks)
	{
		elem->print();
	}
}

void ApplicationType::print_unit_list()
{
	for (auto elem : unit_list)
	{
		elem->print();
	}
	cout << endl;
}

void ApplicationType::ApplicationType::run()
{
	string sOption;
	while (flag_status == 0)
	{
		sOption = get_command();
		if (sOption == "1")			hire_unit();
		else if (sOption == "2")	attack_to_enemy();
		else if (sOption == "3")	gather_money();
		else if (sOption == "4")	print_unit_list();
		else if (sOption == "5")	break;
	}
	cout << "Exit the program..." << endl;
}

string ApplicationType::get_command()
{
	string com;
	cout << "Turn: " << curr_turn << "/" << MAX_turn << endl;
	cout << "Gold: " << gold << endl;
	cout << "Enemy HP: " << enemy_hp << endl << endl;
	cout << "1. Hire Unit" << endl;
	cout << "2. Attack to Enemy" << endl;
	cout << "3. Gather Money" << endl;
	cout << "4. print Units" << endl;
	cout << "Input>";
	cin >> com;
	return com;
}

bool ApplicationType::hire_unit()
{
	string unit_name;
	print_unit_list_in_barracks();
	cout << endl << "Please enter the name: ";
	cin >> unit_name;
	for (unsigned i = 0; i < unit_list_in_barracks.size(); i++)
	{
		if (unit_name == unit_list_in_barracks[i]->get_name())
		{
			if (gold >= unit_list_in_barracks[i]->get_price())
			{
				unit_list.push_back(unit_list_in_barracks[i]);
				gold -= unit_list_in_barracks[i]->get_price();
				cout << "Successfully hired" << endl << endl;
				increase_turn();
				return true;
			}
		}
	}
	cout << "Error: neither wrong name nor enough gold" << endl << endl;
	return false;
}

void ApplicationType::attack_to_enemy()
{
	cout << endl;
	int All_attack = 0;
	for (unsigned i = 0; i < unit_list.size(); i++)
	{
		if (unit_list[i]->get_type() == 1)
		{
			All_attack += unit_list[i]->action();
		}
	}
	enemy_hp -= All_attack;
	increase_turn();
	if (enemy_hp <= 0)
	{
		flag_status = 2;
		cout << "You win" << endl;
	}
}

void ApplicationType::gather_money()
{
	cout << endl;
	int All_mining = 0;
	for (unsigned i = 0; i < unit_list.size(); i++)
	{
		if (unit_list[i]->get_type() == 0)
		{
			All_mining += unit_list[i]->action();
		}
	}
	gold += All_mining;
	increase_turn();
}

*/

/*Attacker.h
#pragma once

#include <iostream>
#include "Unit.h"

using namespace std;

class Attacker : public Unit
{
protected:
	int attack_point;
public:
	Attacker(int _type, string _name, int _price, int _attack_point);
	int action() override;
	void print() override;
};
*/

/*Miner.h
#pragma once

#include <iostream>
#include <string>
#include "Unit.h"

using namespace std;

class Miner : public Unit
{
protected:
	int mining_point;
public:
	Miner(int _type, string _name, int _price, int _mining_point);
	int action() override;
	void print() override;
};

*/

/*ApplicationType.h
#pragma once

#include <string>
#include <vector>
#include "Unit.h"
#include "Attacker.h"
#include"Miner.h"

using namespace std;

class ApplicationType
{
private:
	vector<Unit*> unit_list_in_barracks;
	vector<Unit*> unit_list;
	int curr_turn;
	int MAX_turn;
	int gold;
	int enemy_hp;
	int flag_status;
public:
	ApplicationType();
	~ApplicationType();

	void increase_turn();
	void print_unit_list_in_barracks();
	void print_unit_list();

	void run();
	string get_command();
	bool hire_unit();
	void attack_to_enemy();
	void gather_money();
};
*/

/*Unity.h
#pragma once

#include <string>

using namespace std;

class Unit
{
protected:
	int type;
	string name;
	int price;
public:
	Unit(int _type, string _name, int _price) :
		type(_type), name(_name), price(_price) {}
	virtual int action() = 0;
	virtual void print() = 0;
	int get_type() { return type; }
	string get_name() { return name; }
	int get_price() { return price; }
};

*/