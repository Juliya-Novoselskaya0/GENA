#include "Employee.h"

void Employee::setDepartmentNumber(int dn) 
{
	departmentNumber = dn;
}

void Employee::setSalary(int sl)
{
	salary = sl;
}

int Employee::getDepartmentNumber()
{
	return departmentNumber;
}

int Employee::getSalary()
{
	return salary;
}

Employee Employee::getEmployee()
{
	return *this;
}

void Employee::print()
{
	std::cout << "\n" << "full name: " << getFullname() << " password: " << getPassword() 
		<< " department number: " << departmentNumber << " salary: " << salary << "\n";
}