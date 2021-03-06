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

Employee Administrator::SearchEmployee(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{
			it->print();
			return it->getEmployee();
		}
	}
	return it->getEmployee();
}

void Administrator::ChangeEmployee(std::string fn)
{
	std::vector<Employee>::iterator it;
	for (it = vecEmployees.begin(); it != vecEmployees.end(); ++it)
	{
		if (it->getFullname() == fn)
		{
			int choice = 0; 
			do
			{
				std::cout << "                ------------------------------------------" << std::endl;
				std::cout << "                --------1.Full name.-----------" << std::endl;
				std::cout << "                --------2.Password.-----------" << std::endl;
				std::cout << "                --------3.Department number.-----------" << std::endl;
				std::cout << "                --------4.Salary.-----------" << std::endl;
				std::cout << "                --------5.Nothing - > exit.-----------" << std::endl;
				std::cout << "\n             Choice:";
				std::cin >> choice;
				switch (choice)
				{
				case 1:
				{
					std::string name;
					std::cout << "Enter new name - ";
					std::cin >> name;
					it->setFullname(name);
				}
					break;
				case 2:
				{
					std::string pass;
					std::cout << "Enter new password - ";
					std::cin >> pass;
					it->setPassword(pass);
				}
				break;
				case 3:
				{
					int depN;
					std::cout << "Enter new department number - ";
					std::cin >> depN;
					it->setDepartmentNumber(depN);
				}
				break;
				case 4:
				{
					int Sal;
					std::cout << "Enter new salary - ";
					std::cin >> Sal;
					it->setSalary(Sal);
				}
				break;
				}
			} 			
			while (choice != 5);
		}
	}
}

void Administrator::ClearEmployees()
{
	vecEmployees.clear();
}


bool comparator(Employee & book1, Employee & book2)
{
	if (book1.getSalary() < book2.getSalary())
	{
			return book1.getSalary() < book2.getSalary();
	}
	else
		return book2.getSalary() < book2.getSalary();
}
void Administrator::SortEmployees()
{
	std::sort(vecEmployees.begin(), vecEmployees.end(), comparator);
}

void Administrator::WritingFile()
{
	std::ofstream out("employees.txt", std::ios_base::trunc);
	out.clear();
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
	std::string fullN;
	std::string pas;
	int depNum, Sal;
	std::ifstream in("employees.txt"); 
	if (in.is_open())
	{
		while (in >> fullN >> pas >> depNum>>Sal)
		{
			vecEmployees.push_back(Employee(fullN,pas,depNum,Sal));
		}
	}
	in.close();
}