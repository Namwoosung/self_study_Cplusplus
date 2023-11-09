#include "Student.h"


// Set student id from keyboard.
void Student::SetIDFromKeyBoard() {
	cout << "\tID: ";
	cin >> id_;
}

// Set student name from keyboard.
void Student::SetNameFromKeyBoard() {
	cout << "\tName: ";
	cin >> name_;
}

// Set student address from keyboard.
void Student::SetAddressFromKeyBoard() {
	cout << "\tAddress: ";
	std::cin.ignore(INT_MAX, '\n');
	getline(cin, address_, '\n');
}

// Set student record from keyboard.
void Student::SetRecordFromKeyBoard() {
	SetIDFromKeyBoard();
	SetNameFromKeyBoard();
	SetAddressFromKeyBoard();
}


// Read a record from  a file.
int Student::ReadDataFromFile(ifstream& fin) {
	fin >> id_;
	fin >> name_;
	getline(fin, address_);

	return 1;
}


// Write a record into file.
int Student::WriteDataFromFile(ofstream& fout) {
	fout << endl;
	fout << id_ << " ";
	fout << name_ << " ";
	fout << address_;

	return 1;
}