#include "Application.h"

// Program driver
void Application::Run()
{
	while (1) {
		command_ = GetCommand();

		switch (command_) {
		case 1:    // read a record and add to list.
			AddItem();
			break;
		case 2:    // read a record and delete from list.
			DeleteItem();
			break;
		case 3:    // read a record and replace record from list.
			ReplaceItem();
			break;
		case 4:    // read a record id and display that record.
			DisplayItem();
			break;
		case 5:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 6:		// make empty list.
			list_.MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand() {
	int command;

	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Display item" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddItem() {
	// ���ο� �л� ������ �Է� �ް� ����Ʈ�� �߰�
	Student stu;
	stu.SetIDFromKeyBoard();
	stu.SetNameFromKeyBoard();
	stu.SetAddressFromKeyBoard();
	list_.Append(stu);
	return 0;
}

// Delete requested record in the list.
int Application::DeleteItem() {
	// ������ �л� id�� �Է� �ް� ����Ʈ���� ����
	Student stu;
	stu.SetIDFromKeyBoard();
	list_.Remove(stu);
	return 0;
}

// Replace requested record in the list.
int Application::ReplaceItem() {
	// ��ü�� �л� id�� �Է� �ް� �ش� �л� ������ ���� �Է��� �л� ������ ��ü
	Student stu;
	stu.SetIDFromKeyBoard();
	stu.SetNameFromKeyBoard();
	stu.SetAddressFromKeyBoard();
	list_.SetItem(list_.Index(stu), stu);
	return 0;
}

// Display requested record in the list on screen
int Application::DisplayItem() {
	// ǥ���� �л��� id�� �Է� �ް� �ش� �л� ������ ���
	Student stu;
	stu.SetIDFromKeyBoard();
	int number = (list_.Index(stu));
	Student* Address = list_.GetItemAddress(number);
	Address->DisplayRecordOnScreen();
	return 0;
}

// Display all records in the list on screen.
void Application::DisplayAllItem() {
	// ����Ʈ�� ��� �л� ������ ���
	for (int i = 0; i < list_.GetLength(); i++)
	{
		Student* Address = list_.GetItemAddress(i);
		Address->DisplayRecordOnScreen();
	}
	return;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
	fin_.open(fileName);    // file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!fin_) {
		return 0;
	}
	else {
		return 1;
	}
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName) {
	fout_.open(fileName);    // file open for writing

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����
	if (!fout_) {
		return 0;
	}
	else {
		return 1;
	}
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {
	int index = 0;
	Student data;    // �б�� �ӽ� ����

	char filename[FILE_NAME_SIZE];
	cout << "\n\tEnter input file name: ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename)) {
		return 0;
	}

	// ������ ��� ������ �о� list�� �߰�
	while (!fin_.eof()) {
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(fin_);
		list_.Append(data);
	}

	fin_.close();    // file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {
	Student data;

	char filename[FILE_NAME_SIZE];
	cout << "\n\tEnter output file name: ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename)) {
		return 0;
	}

	// list �����͸� �ʱ�ȭ
	list_.ResetIterator();


	Student* iter;
	list_.ResetIterator();
	while ((iter = list_.GetNextItemAddress()) != NULL) {
		iter->WriteDataFromFile(fout_);
	}

	fout_.close();    // file close

	return 1;
}