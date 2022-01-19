#pragma once
#include "Person.h"
#include <vector>
#include "Employee.h"
#include "Accountant.h"
#include <fstream>
#include <algorithm>

class Administrator :public Accountant
{
	//std::vector<Employee> vecEmployees;
	//shared_ptr<vector<Employee>> employee;

public:
	Administrator()
	{

	}
	Administrator(std::string fn, std::string ps)
	{
		setFullname(fn);
		setPassword(ps);
	}
	Administrator(std::string fn, std::string ps, std::vector<Employee> vEm)
	{
		setFullname(fn);
		setPassword(ps);
		vecEmployees = vEm;
	}

	void AddEmployee(Employee emp);
	//void Display();
	void DelEmployee(std::string fn);
	//Employee SearchEmployee(std::string fn);
	void ChangeEmployee(std::string fn);
	void SortEmployees();
	void ClearEmployees();
	//void WritingFile();
	//void ReadFile();
};

