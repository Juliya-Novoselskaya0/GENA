#pragma once
#include "Person.h"
#include <vector>
#include "Employee.h"
#include <fstream>

class Administrator :public Person
{
	std::vector<Employee> vecEmployees;
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
	void Display();
	void DelEmployee(std::string fn);
	void SearchEmployee(std::string fn);
	void ClearEmployees();
	void WritingFile();
	void ReadFile();
};

