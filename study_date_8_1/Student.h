#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


/**
*    Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

/**
*   item information class.
*/
class Student
{
public:
	/**
	*    default contructor.
	*/
	Student() {
		id_ = -1;
		name_ = "";
		address_ = "";
	}

	/**
	*    destructor.
	*/
	~Student() {}

	/**
	*    @brief  Get student id.
	*    @pre    student id is set.
	*    @post   none.
	*    @return student id.
	*/
	int GetId() {
		return id_;
	}

	/**
	*    @brief  Get Names.
	*    @pre    student name is set.
	*    @post   none.
	*    @return student name.
	*/
	string GetName() {
		return name_;
	}

	/**
	*    @brief  Get student address.
	*    @pre    student address is set.
	*    @post   none.
	*    @return student address.
	*/
	string GetAddress() {
		return address_;
	}

	/**
	*    @brief  Set student id.
	*    @pre    none.
	*    @post   student id is set.
	*    @param  inId    student id.
	*/
	void SetId(int inId) {
		id_ = inId;
	}

	/**
	*    @brief  Set student name.
	*    @pre    none.
	*    @post   student name is set.
	*    @param  inName  student name.
	*/
	void SetName(string inName) {
		name_ = inName;
	}

	/**
	*    @brief  Set student address.
	*    @pre    none.
	*    @post   student name is set.
	*    @param  inAddress  student address.
	*/
	void SetAddress(string inAddress) {
		address_ = inAddress;
	}

	/**
	*    @brief  Set student record.
	*    @pre    none.
	*    @post   student record is set.
	*    @param  inId       student id.
	*    @param  inName     student name.
	*    @param  inAddress  student address.
	*/
	void SetRecord(int inId, string inName, string inAddress) {
		SetId(inId);
		SetName(inName);
		SetAddress(inAddress);
	}

	/**
	*    @brief  Display student id on screen.
	*    @pre    student id is set.
	*    @post   student id is on screen.
	*/
	void DisplayIdOnScreen() {
		cout << "\tID: " << id_ << endl;
	};

	/**
	*    @brief  Display student name on screen.
	*    @pre    student name is set.
	*    @post   student name is on screen.
	*/
	void DisplayNameOnScreen() {
		cout << "\tName: " << name_ << endl;
	};

	/**
	*    @brief  Display student address on screen.
	*    @pre    student address is set.
	*    @post   student address is on screen.
	*/
	void DisplayAddressOnScreen() {
		cout << "\tAddress: " << address_ << endl;
	};

	/**
	*    @brief  Display student record on screen.
	*    @pre    student record is set.
	*    @post   student record is on screen.
	*/
	void DisplayRecordOnScreen() {
		cout << setw(20) << id_;
		cout << setw(20) << name_;
		cout << setw(30) << address_ << endl;
	};

	/**
	*    @brief    Set student id from keyboard.
	*    @pre      none.
	*    @post     student id is set.
	*/
	void SetIDFromKeyBoard();

	/**
	*    @brief    Set student name from keyboard.
	*    @pre      none.
	*    @post     student name is set.
	*/
	void SetNameFromKeyBoard();

	/**
	*    @brief    Set student address from keyboard.
	*    @pre      none.
	*    @post     student address is set.
	*/
	void SetAddressFromKeyBoard();

	/**
	*    @brief    Set student record from keyboard.
	*    @pre      none.
	*    @post     student record is set.
	*/
	void SetRecordFromKeyBoard();

	/**
	*    @brief  Read a record from file.
	*    @pre    the target file is opened.
	*    @post   student record is set.
	*    @param  fin file descriptor.
	*    @return return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataFromFile(ofstream& fout);

	// ==연산자로 비교 (id가 같으면 같은 학생으로 판단)
	bool operator==(Student& another)
	{
		return (this->GetId() == another.GetId());
	}

protected:
	int id_;            ///< student ID.
	string name_;      ///< student name.
	string address_;    ///< student address.
};
