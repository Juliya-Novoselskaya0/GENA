// GenadiyPavlovsky.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>
#include <vector>
#include <memory>
#include "Administrator.h"

using namespace std;
int main()
{
	Administrator addmin("juliya", "nova");
	addmin.ReadFile();
	int choice = 0; //选择操作选项
	while (true)
	{

		cout << "                ***********Personnel management system************\n" << endl;

		cout << "                ------------------------------------------" << endl;

		cout << "                --------1.Displayed information.-----------" << endl;

		cout << "                --------2.Add Information.-----------" << endl;

		cout << "                --------3.Find information.-----------" << endl;

		cout << "                --------4.Delete Information.-----------" << endl;

		cout << "                --------5.Change information.-----------" << endl;

		cout << "\n             Choice:";

		cin >> choice;
		switch (choice)
		{
		case 1:
			addmin.Display();
			addmin.WritingFile();
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
			addmin.AddEmployee(emp);
			break;
		}

		case 3:
		{
			string na;
			cout << "Please enter the name of the employee you are looking for：";
			cin >> na;
			addmin.SearchEmployee(na);
		}

		case 4:
		{
			string na;
			cout << "Please enter the name of the employee you want to delete：";
			cin >> na;
			addmin.DelEmployee(na);
		}


		default:
			break;
		}
	}

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
