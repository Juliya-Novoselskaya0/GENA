#pragma once
#include "Person.h"
#include <vector>
#include "Employee.h"
#include <fstream>
#include <algorithm>

class Accountant : public Person
{
	std::vector<Employee> vecEmployees;
public:
	Accountant()
	{

	}
	Accountant(std::string fn, std::string ps)
	{
		setFullname(fn);
		setPassword(ps);
	}
	Accountant(std::string fn, std::string ps, std::vector<Employee> vEm)
	{
		setFullname(fn);
		setPassword(ps);
		vecEmployees = vEm;
	}

	//void AddEmployee(Employee emp);
	void Display();
	//void DelEmployee(std::string fn);
	Employee SearchEmployee(std::string fn);
	void ChangeEmployee_Salary(std::string fn);
	void SortEmployees();
	//void ClearEmployees();
	void WritingFile();
	void ReadFile();
};
