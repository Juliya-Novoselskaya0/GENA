#include "Accountant.h"

void Accountant::Display()
{
	for (int i = 0; i < vecEmployees.size(); i++)
		vecEmployees[i].print();
}

Employee Accountant::SearchEmployee(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{
			//it->print();
			return it->getEmployee();
		}
	}
	Employee emp = Employee();
	return emp;
}

void Accountant::ChangeEmployee_Salary(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{				
					int Sal;
					std::cout << "Enter new salary - ";
					std::cin >> Sal;
					it->setSalary(Sal);				
		}
	}
}

bool comparators(Employee& book1, Employee& book2)
{
	if (book1.getSalary() < book2.getSalary())
	{
		return book1.getSalary() < book2.getSalary();
	}
	else
		return book2.getSalary() < book2.getSalary();
}
void Accountant::SortEmployees()
{
	std::sort(vecEmployees.begin(), vecEmployees.end(), comparators);
}

void Accountant::WritingFile()
{
	std::ofstream out("employees.txt", std::ios_base::trunc);
	out.clear();
	if (out.is_open())
	{
		for (int i = 0; i < vecEmployees.size(); i++)
		{
			out << vecEmployees[i].getFullname() << " " << vecEmployees[i].getPassword() << " "
				<< vecEmployees[i].getDepartmentNumber() << " " << vecEmployees[i].getSalary() << std::endl;
		}
	}
	out.close();
}

void Accountant::ReadFile()
{
	std::string fullN;
	std::string pas;
	int depNum, Sal;
	std::ifstream in("employees.txt");
	if (in.is_open())
	{
		while (in >> fullN >> pas >> depNum >> Sal)
		{
			vecEmployees.push_back(Employee(fullN, pas, depNum, Sal));
		}
	}
	in.close();
}