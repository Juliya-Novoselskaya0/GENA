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

void Administrator::ClearEmployees()
{
	vecEmployees.clear();
}

void Administrator::WritingFile()
{
	std::ofstream out("employees.txt");

	if (out.is_open())
	{
		for (int i = 0; i < vecEmployees.size(); i++)
		{
			out << vecEmployees[i].getFullname() << " " << vecEmployees[i].getPassword() <<" "
				<< vecEmployees[i].getDepartmentNumber()<<" "<<vecEmployees[i].getSalary() << std::endl;
		}
	}
	out.close();
}

void Administrator::ReadFile()
{
	//std::vector<Employee> new_operations;
	std::string fullN;
	std::string pas;
	int depNum, Sal;
	std::ifstream in("employees.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (in >> fullN >> pas >> depNum>>Sal)
		{
			vecEmployees.push_back(Employee(fullN,pas,depNum,Sal));
		}
	}
	in.close();
}