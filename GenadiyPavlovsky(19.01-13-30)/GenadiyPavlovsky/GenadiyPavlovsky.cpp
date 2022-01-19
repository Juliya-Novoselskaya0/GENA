// GenadiyPavlovsky.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>
#include <vector>
#include <memory>
#include "Administrator.h"


using namespace std;


const std::string adminPAS = "gena";
const std::string adminNAME = "gena";

void menuAdmin(Administrator add)
{
	//Administrator addmin("gena", "gena");
	//addmin.ReadFile();
	int choice = 0;
	do
	{

		cout << "                ***********Personnel management system (ADMIN)************\n" << endl;

		cout << "                ------------------------------------------" << endl;

		cout << "                --------1.Displayed employees.-----------" << endl;

		cout << "                --------2.Add employee.-----------" << endl;

		cout << "                --------3.Find employee.-----------" << endl;

		cout << "                --------4.Delete employee.-----------" << endl;

		cout << "                --------5.Change employee.-----------" << endl;
		cout << "                --------6.Sort employees (by salary).-----------" << endl;

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
			break;
		}

		case 3:
		{
			string na;
			cout << "Please enter the name of the employee you are looking for: ";
			cin >> na;
			add.SearchEmployee(na);
		}

		case 4:
		{
			string na;
			cout << "Please enter the name of the employee you want to delete: ";
			cin >> na;
			add.DelEmployee(na);
		}
		case 5:
		{
			string na;
			cout << "Please enter the name of the employee you want to change:";
			cin >> na;
			add.ChangeEmployee(na);
		}
		case 6:
		{
			add.SortEmployees();
		}

		default:
			break;
		}
	} while (choice != 7);
}

//void menuEmployee(std::string name, std::string pas, Administrator admin)
void menuEmployee(Employee employee, Administrator admin)
{
	//Employee employee = Employee(name, pas);
	//admin.ReadFile();
	int ch = 0;
	do{

		cout << "                ***********Personnel management system (EMPLOYEE)************\n" << endl;
		cout << "                ------------------------------------------" << endl;
		cout << "                --------1.Displayed data.-----------" << endl;
		cout << "                --------2.Change data.-----------" << endl;
		cout << "                --------3.Exit.-----------" << endl;
		cout << "\n             Choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			employee.print();
			break;
		case 2:
		{
			admin.ChangeEmployee(employee.getFullname());
			admin.WritingFile();
		}
		case 3:
			break;
		}
	} while (ch != 3);
}
int main()
{
	Administrator addmin("gena", "gena");
	addmin.ReadFile();

	std::string name, pas;
	int i = 0;
	do {
		cout << "\nSIGN IN \n";
		cout << "Enter name and password\n";
		cin >> name >> pas;
		if (pas == addmin.SearchEmployee(name).getPassword()) {		
			menuEmployee(addmin.SearchEmployee(name),addmin);
			i = 1;
		}
		else
		{
			if (pas == adminPAS && name == adminNAME)
			{
				i = 1;
				menuAdmin(addmin);
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
