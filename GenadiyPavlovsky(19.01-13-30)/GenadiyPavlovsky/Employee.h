#pragma once
#include "Person.h"
class Employee : public Person
{
	int departmentNumber;
	int salary;

public:
	Employee()
	{
		departmentNumber = 0;;
		salary = 0;
	}
	Employee(int dn, int sl)
	{
		departmentNumber = dn;
		salary = sl;
	}
	Employee(std::string fn, std::string ps)
	{
		setFullname(fn);
		setPassword(ps);
	}
	Employee(std::string fn, std::string ps, int dn, int sl)
	{
		setFullname(fn);
		setPassword(ps);
		departmentNumber = dn;
		salary = sl;
	}
	void setDepartmentNumber(int dn);
	void setSalary(int sl);
	int getDepartmentNumber();
	int getSalary();
	Employee getEmployee();
	void print();
};

