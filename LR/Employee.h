#pragma once
#include "User.h"

#include<iostream>
#include <string>
#include <windows.h>
#include<fstream>
#include <conio.h>
#include <iomanip>
#include<istream>
using namespace std;

class Employee: public User
{
	//std::string fullName;
	int departmentNumber;
	std::string position;
	std::string startDateOfWork;
public:
	Employee(int dn, std::string pos, std::string stDW)
	{
	//	fullName = fn;
		departmentNumber = dn;
		position = pos;
		startDateOfWork = stDW;
	}
	Employee()
	{
		//fullName = "";
		departmentNumber = 0;
		position = "";
		startDateOfWork = "";
	}
	std::string getFullName();
	int getDepNum();
	int getDepNum(Employee& ob);
	int inputFromFile(std::string file_name, std::ifstream& fin)
	{
		size_t size;

		size = 0;
		fin.read(reinterpret_cast<char*>(&size), sizeof(size));
		fullName.resize(size);
		fin.read(&fullName[0], size);
		fin.read(reinterpret_cast<char*>(&departmentNumber), sizeof(departmentNumber));
		size = 0;
		fin.read(reinterpret_cast<char*>(&size), sizeof(size));
		position.resize(size);
		fin.read(&position[0], size);
		size = 0;
		fin.read(reinterpret_cast<char*>(&size), sizeof(size));
		startDateOfWork.resize(size);
		fin.read(&startDateOfWork[0], size);
		std::string s;
		fin.read(&s[0], sizeof("\n"));
		return 0;
	}

	void fillFile(std::string file_name) {
		std::ofstream fout;
		size_t size;
		fout.open(file_name, ios::binary | ios::app);
		//fout.open(file_name, ios::binary | ios::out);
		size = fullName.size();
		fout.write(reinterpret_cast<char*>(&size), sizeof(size));
		fout.write(&fullName[0], size);

		fout.write(reinterpret_cast<char*>(&departmentNumber), sizeof(departmentNumber));

		size = position.size();
		fout.write(reinterpret_cast<char*>(&size), sizeof(size));
		fout.write(&position[0], size);

		size = startDateOfWork.size();
		fout.write(reinterpret_cast<char*>(&size), sizeof(size));
		fout.write(&startDateOfWork[0], size);

		fout.write("\n", sizeof("\n"));
		fout.close();
	}
	void updateFullName(std::string name)
	{
		this->fullName = name;
	}
	void updateDepartmentNumber(int depNember)
	{
		this->departmentNumber = depNember;
	}
	void updatePosition(std::string pos)
	{
		this->position = pos;
	}
	void updatestartDateOfWork(std::string date)
	{
		this->startDateOfWork = date;
	}
	std::string getPosition();
	std::string getStartDateOfWork();
	friend std::ostream& operator<<(std::ostream& out, Employee& ob);
	friend std::istream& operator>>(std::istream& in, Employee& ob);

};

