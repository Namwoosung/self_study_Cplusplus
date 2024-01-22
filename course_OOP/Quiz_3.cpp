/*
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student
{
private:
	string name;
	string id;
	string code[100];
	int numCourseTaken;
public:
	Student() :
		name(" "), id(" "), numCourseTaken(0) {}
	Student(string _name, string _id) :
		name(_name), id(_id), numCourseTaken(0) {}
	void addCourse(string _code)
	{
		this->code[numCourseTaken] = _code;
		numCourseTaken++;
	}
	void setName(string _name) { this->name = _name; }
	void setId(string _id) { this->id = _id; }
	string getId() const { return this->id; }
	string getName() const { return this->name; }
	string getCode(int num) const { return this->code[num]; }
	friend class KHUIS;
	friend ostream& operator<<(ostream& cout, const Student& stu);
};

ostream& operator<<(ostream& cout, const Student& stu)
{
	cout << "ID: " << stu.id << '\t' << "Name: " << stu.name << '\t' << "Course(taking): ";
	for (int i = 0; i < stu.numCourseTaken; i++)
	{
		cout << stu.code[i] << " ";
	}
	return cout;
}

class Course
{
private:
	string name;
	string code;
public:
	void setName(string _name) { this->name = _name; }
	void setCode(string _code) { this->code = _code; }
	string getCode() const { return this->code; }
	string getName() const { return this->name; }
	friend class KHUIS;
	friend ostream& operator<<(ostream& cout, const Course& cs);
};


ostream& operator<<(ostream& cout, const Course& cs)
{
	cout << "Code: " << cs.code << '\t' << "Name: " << cs.name;
	return cout;
}

class KHUIS
{
public:
	void printInfo(Student& _stu, Course* _course, int numCourse);
};

int main()
{
	int numTotalCourse = 3;
	Course* pCourse = new Course[numTotalCourse];
	pCourse[0].setName("°´Ã¼ÁöÇâÇÁ·Î±×·¡¹Ö");
	pCourse[0].setCode("CSE100");
	pCourse[1].setName("¿µ»óÃ³¸®");
	pCourse[1].setCode("CSE200");
	pCourse[2].setName("¸Ó½Å·¯´×");
	pCourse[2].setCode("CSE300");

	cout << pCourse[0].getCode() << '\t' << pCourse->getName() << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	cout << pCourse[0] << endl;
	cout << pCourse[1] << endl;
	cout << pCourse[2] << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	Student stu1("È«±æµ¿", "20181004"), stu2;
	stu1.addCourse("CSE100");
	stu1.addCourse("CSE200");

	stu2.setName("±è¿µÈñ");
	stu2.setId("20182000");
	stu2.addCourse("CSE100");
	stu2.addCourse("CSE300");

	cout << stu1.getId() << '\t' << stu1.getName() << '\t' << stu1.getCode(0) << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	cout << stu1 << endl;
	cout << stu2 << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	KHUIS khuis;
	khuis.printInfo(stu1, pCourse, numTotalCourse);
	khuis.printInfo(stu2, pCourse, numTotalCourse);

	delete[] pCourse;

	return 0;
}

void KHUIS::printInfo(Student& _stu, Course* _course, int numCourse)
{
	cout << "[Student and Course Information]" << endl;
	cout << "ID: " << _stu.id << '\t' << "Name: " << _stu.name << '\t' << "Course(taking): ";
	for (int i = 0; i < _stu.numCourseTaken; i++)
	{
		cout << _stu.code[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < numCourse; i++)
	{
		for (int j = 0; j < _stu.numCourseTaken; j++)
		{
			if (_course[i].code == _stu.code[j])
			{
				cout << "Code: " << _course[i].code << '\t' << "Name: " << _course[i].name << endl;
			}
		}
	}

	cout << endl << endl;
}
*/