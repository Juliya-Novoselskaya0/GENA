#include "Administrator.h"
void Administrator::AddEmployee(Employee emp)
{
	vecEmployees.push_back(emp);
}

void Administrator::Display()
{
	for (int i = 0; i < vecEmployees.size(); i++)
		vecEmployees[i].print();
}

void Administrator::DelEmployee(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{
			vecEmployees.erase(it);
			return;
		}
	}
}

void Administrator::SearchEmployee(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{
			it->print();
		}
	}
}