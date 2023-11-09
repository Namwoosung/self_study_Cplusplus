#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"
#include "Student.h"

#define FILE_NAME_SIZE 1024

/**
*    application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor
	*/
	Application() {
		command_ = 0;
	}

	/**
	*    destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Delete requested record in the list.
	*	@pre	list should be initialized.
	*	@post	Selected record is deleted from the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItem();

	/**
	*	@brief	Replace requested record in the list.
	*	@pre	list should be initialized.
	*	@post	Selected record is replaced with parameter data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceItem();

	/**
	*	@brief	Display requested record in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DisplayItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();


private:
	ifstream fin_;    ///< input file descriptor
	ofstream fout_;   ///< output file descriptor
	ArrayList<Student> list_;     ///< item list.
	int command_;        ///< current command number
};

