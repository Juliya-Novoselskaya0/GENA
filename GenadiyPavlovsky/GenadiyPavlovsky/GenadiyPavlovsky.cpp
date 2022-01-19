// GenadiyPavlovsky.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>
#include <vector>
#include <memory>
#include "Administrator.h"
#include "Accountant.h"

using namespace std;

const std::string adminPAS = "gena";
const std::string adminNAME = "gena";

const std::string accPAS = "accountant";
const std::string accNAME = "accountant";
extern int i = 0;

void menuAdmin(Administrator add)
{
	int choice = 0;
	do
	{
		cout << "\n                ***********Personnel management system (ADMIN)************\n" << endl;
		cout << "                --------1.Displayed employees.------------------------------" << endl;
		cout << "                --------2.Add employee.-------------------------------------" << endl;
		cout << "                --------3.Find employee.------------------------------------" << endl;
		cout << "                --------4.Delete employee.----------------------------------" << endl;
		cout << "                --------5.Change employee.----------------------------------" << endl;
		cout << "                --------6.Sort employees (by salary).-----------------------" << endl;
		cout << "                --------7.Exit->--------------------------------------------" << endl;

		cout << "\n             Choice:";

		cin >> choice;
		switch (choice)
		{
		case 1:
			add.Display();
			add.WritingFile();
			break;
		case 2:
		{
			Employee emp;
			cout << "Enter info \n";
			std::string fullN, pass;
			int sl, dn;
			cin >> fullN >> pass >> dn >> sl;
			emp.setFullname(fullN);
			emp.setPassword(pass);
			emp.setDepartmentNumber(dn);
			emp.setSalary(sl);
			add.AddEmployee(emp);
			add.WritingFile();
			break;
		}
		case 3:
		{
			string na;
			cout << "Please enter the name of the employee you are looking for: ";
			cin >> na;
			add.SearchEmployee(na).print();
		}
		case 4:
		{
			string na;
			cout << "Please enter the name of the employee you want to delete: ";
			cin >> na;
			add.DelEmployee(na);
			add.WritingFile();
		}
		case 5:
		{
			string na;
			cout << "Please enter the name of the employee you want to change:";
			cin >> na;
			add.ChangeEmployee(na);
			add.WritingFile();
		}
		case 6:
		{
			add.SortEmployees();
			add.WritingFile();
		}
		}
	} while (choice != 7); i = 0;
}

void menuAccountant(Accountant acc)
{
	int choi = 0;
	acc.ReadFile();
	do
	{
		cout << "\n                ***********ACCOUNTANT'S PERSONAL ACCOUNT************\n" << endl;
		cout << "                --------1.Displayed employees------------------------" << endl;
		cout << "                --------2.Find employee.-----------------------------" << endl;
		cout << "                --------3.Change employee's salary.------------------" << endl;
		cout << "                --------4.Sort employees (by salary).----------------" << endl;
		cout << "                --------5.Exit->.------------------------------------" << endl;

		cout << "\n             Choice:";

		cin >> choi;
		switch (choi)
		{
		case 1:
			acc.Display();
			acc.WritingFile();
			break;
		case 2:
		{
			string na;
			cout << "Please enter the name of the employee you are looking for: ";
			cin >> na;
			acc.SearchEmployee(na).print();
		}
		case 3:
		{
			string na;
			cout << "Please enter the name of the employee you want to change:";
			cin >> na;
			acc.ChangeEmployee_Salary(na);
			acc.WritingFile();
		}
		case 4:
		{
			acc.SortEmployees();
			acc.WritingFile();
		}
		}
	} while (choi != 5); i = 0;
}

void menuEmployee(Employee employee, Administrator admin)
{
	int ch = 0;
	do{

		cout << "\n                ***********EMPLOYEE'S PERSONAL ACCOUNT************\n" << endl;
		cout << "                --------1.Displayed data.-------------------------" << endl;
		cout << "                --------2.Change data.----------------------------" << endl;
		cout << "                --------3.Exit.-----------------------------------" << endl;
		cout << "\n             Choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			employee.print();
			break;
		case 2:
		{
			admin.ReadFile();
			admin.ChangeEmployee(employee.getFullname());
			admin.WritingFile();
		}
		case 3:
			break;
		}
	} while (ch != 3); i=0;
}
int main()
{
	Administrator addmin("gena", "gena");
	Accountant acc("accountant", "accountant");
	addmin.ReadFile();

	std::string name, pas;
	
	do {
		cout << "\n--------------------SIGN IN------------------\n";
		cout << "Enter name: \n";
		cin >> name;
		cout << "\nEnter password: \n";
		cin >> pas;
		if (pas == addmin.SearchEmployee(name).getPassword()) 
		{		
			menuEmployee(addmin.SearchEmployee(name),addmin);
			i = 0;
		}
		else
		{
			if (pas == adminPAS && name == adminNAME)
			{	
				menuAdmin(addmin);
				i = 0;
			}
			else if (pas == accPAS && name == accNAME)
			{
				menuAccountant(acc);
				i = 0;
			}
			else i = 0;
		}
	} while (i != 1);
	system("pause");
}

 //Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
 //Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

 //Советы по началу работы 
 //  1. В окне обозревателя решений можно добавлять файлы и управлять ими.
 //  2. В окне Team Explorer можно подключиться к системе управления версиями.
 //  3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
 //  4. В окне "Список ошибок" можно просматривать ошибки.
 //  5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
 //  6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
