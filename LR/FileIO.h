#pragma once
#include "Stack.h"
#include "Employee.h"

#include <fstream>
#include <iostream>
using namespace std;


class FileIO {

	//char file_name[30];
public:
	string file_name;
	fstream file_stream;
public:
	//bool open_file_in();
	//bool open_file_out();
	FileIO(string file_name);
	void Remoute();
	void write_record_in_file(Stack<Employee>& object);
	void read_record_in_file(Stack<Employee>& object);
	bool R_end_file();
	//Stack<Employee>* readFileToTree(string);
	//void writeTreeToFile(Stack<Employee>, string);
};

FileIO::FileIO(string file_name)
{
	this->file_name = file_name;
}
void FileIO::write_record_in_file(Stack<Employee>& object)
{
	object.PrintInFail(file_name);
	//file_stream << object;
}

void FileIO::read_record_in_file(Stack<Employee>& object)
{
	object.clearStack();
	ifstream fin;
	int k = 0;
	fin.open(file_name, ios::binary);
	while (fin) {
		Employee A;
		A.inputFromFile(file_name, fin);
		object.push(A);
		k++;
	}
	//object.Del(k);
	fin.close();
}
/*Stack<Employee>* FileIO::readFileToTree(string fileName) {
	ifstream fileObj;
	fileObj.open(fileName, ios::in);
	Stack<Employee>* result = new Stack<Employee>();
	if (fileObj.peek() == std::ifstream::traits_type::eof()) {
		return result;
	}
	Employee temp;
	string fullName, position, startDateOfWork, fn;
	int departmentNumber;

	while (!fileObj.eof()) {

		fileObj >> fullName;
		fileObj >> position;
		fileObj >> departmentNumber;
		fileObj >> startDateOfWork;
		if (fileObj.eof()) {
			break;
		}
		temp = Employee(fullName, departmentNumber, position, startDateOfWork);
		result->push(temp);
	}

	fileObj.close();

	return result;
}

void FileIO::writeTreeToFile(Stack<Employee> stack, string fileName) {
	ofstream fileObj;
	fileObj.open(fileName, ios::trunc);
	Employee* arr = new Employee();
	int* count = new int[1];
	count[0] = 0;

	Employee temp;
	string name, position, startDay;
	int depNum;


	for (int i = stack.top - 1; i >= 0; i--) {
		temp = stack.getPtr()[i];

		name = temp.getFullName();
		depNum = temp.getDepNum();
		position = temp.getPosition();
		startDay = temp.getStartDateOfWork();

		fileObj << name << endl;
		fileObj << position << endl;
		fileObj << depNum << endl;
		fileObj << startDay << endl;
		if (i == 0) {
			break;
		}
	
	}

	fileObj.close();
}
*/