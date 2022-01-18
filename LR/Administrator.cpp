#include "Administrator.h"

#include <stdio.h>

using namespace std;

void Administrator::AddEmployee()
{
	cout << "enter new employee\n";
	Employee tmp = Employee();
	cin >> tmp;
	stackEmp.push(tmp);
}

void Administrator::RemoveEmployee()
{
	stackEmp.pop();
	cout << "del employee\n";
}

void Administrator::ViewEmployees()
{
	stackEmp.printStack();
}