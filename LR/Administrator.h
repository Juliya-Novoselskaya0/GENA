#pragma once
#include "User.h"
#include <stdio.h>
#include "Stack.h"
#include "Employee.h"
//#include "FileIO.h"

class Administrator : public User
{
	Stack<Employee> stackEmp;
public:
	Administrator(Stack<Employee> bp)
	{
		stackEmp = bp;
	}
	Administrator()
	{
		
	}
	void AddEmployee();
	void RemoveEmployee();
	void ViewEmployees();
};

