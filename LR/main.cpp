#include <stdio.h>
#include "Stack.h"
#include "Employee.h"
//#include "FileIO.h"
#include "Administrator.h"

//int ent_int(std::istream& in, double min, double max) {
//	double i;
//	int flags;
//	do {
//		try {
//			flags = 0;
//			std::cout << "Enter the number... ";
//			in >> i;
//			if (!std::cin || std::cin.peek() != '\n') {
//				throw 1;
//			}
//			if (i < min || i > max) {
//				throw 'a';
//			}
//		}
//		catch (int) {
//			flags = 1;
//			std::cout << "It's not a (type) number!!!\n\n";
//			std::cin.clear(0);
//			rewind(stdin);
//		}
//		catch (char) {
//			flags = 1;
//			std::cout << "Out of range.\n\n";
//			std::cin.clear(0);
//			rewind(stdin);
//		}
//	} while (flags);
//	return i;
//}
//
//std::string enter_datea(std::istream& in) {
//	string i;
//	int flags;
//	do {
//		try {
//			flags = 0;
//			std::cout << "Enter date... ";
//			in >> i;
//			if (!std::cin || std::cin.peek() != '\n') {
//				throw 1;
//			}
//			//regex_search()
//			static std::regex rgx{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))" };
//			smatch res;
//			if (regex_search(i, res, rgx))
//			{
//				for (int j = 0; j < i.size(); j++) {
//					if (i[0] == '3' && i[1] == '1' && i[3] == '0' && i[4] == '2')
//					{
//						throw 1;
//
//
//					}
//					else if (i[0] == '3' && i[1] == '0' && i[3] == '0' && i[4] == '2')
//					{
//						throw 1;
//					}
//				}
//				return i;
//				/*d.day = std::stoi(res[1]);
//				d.month = std::stoi(res[2]);
//				d.year = std::stoi(res[3]);*/
//				//return true;
//			}
//			else {
//				throw 1;
//			}
//			//return false;
//			/*if (i < min || i > max) {
//				throw 'a';
//			}*/
//		}
//		catch (int) {
//			flags = 1;
//			std::cout << "It's not a (type) date!!!\n\n";
//			std::cin.clear(0);
//			rewind(stdin);
//		}
//		catch (char) {
//			flags = 1;
//			std::cout << "Out of range.\n\n";
//			std::cin.clear(0);
//			rewind(stdin);
//		}
//	} while (flags);
//	return i;
//}


//Stack<Employee> bt;

//void Add() { //добавление
//	//if (bt != NULL) {
//		//cout << "enter: \n";
//		Employee tmp = Employee();
//		cin >> tmp;
//		bt.push(tmp);
//	//}
//	/*else {
//		std::cout << "\nstack created\n";
//	}*/
//}

//void Clear() {// очистка
	//delete bt;
//}


int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 0;
	//File file("file.bin");

	/*FileIO file = FileIO("file.bin");*/


	//Stack<Employee>* bt;
	//bt = file.readFileToTree("stack.txt");
	int ch = 0;



	///////////new
	Administrator admin = Administrator();
	admin.AddEmployee();
	admin.AddEmployee();
	admin.ViewEmployees();
	admin.RemoveEmployee();
	admin.ViewEmployees();



	//do {
	//	cout << "1 - push \n2 - pop \n3 - search \n4 - sort inserts ascending \n5 - sort descending inserts \n6 - print \n7 - editing \n8 - save to file \n9 - read from file \n10 - exit and save\n";
	//	cout << "Enter choice: ";
	//	ch = ent_int(std::cin, 1, 10);
	//	int e=0;	
	//	string dt =" ";
	//	switch (ch) {
	//	case 1:
	//		cout << "enter elem\n";
	//		Add();
	//		break;
	//	case 2:
	//		bt.pop();
	//		cout << "del elem\n";
	//		/*if (b == NULL) {
	//			  cout << "not del elem\n";
	//		  }
	//		  else {
	//			  cout << "del elem\n";
	//		  }*/
	//		break;
	//	case 3:
	//		cout << "enter search elem (department number)\n";
	//		cin >> e;
	//		cout << "enter search elem (start date of work)\n";
	//		//enter_datea
	//		//cin >> dt;
	//		dt = enter_datea(std::cin);
	//		bt.search(e,dt);
	//		break;
	//	case 4:
	//		cout << "sort stack\n";

	//		bt.sortStack();
	//		break;
	//	case 5:
	//		cout << "sort stack\n";
	//		bt.sortStackB();
	//		break;
	//	case 6:
	//		bt.printStack();
	//		break;
	//	case 7:
	//		{
	//		string em;
	//		cout << "enter editing elem (full name)\n";
	//		cin >> em;
	//		bt.editing(em);
	//		}
	//		break;
	//	case 8:
	//	{//ofstream cls("file.bin", ios::binary);
	//		
	//		//char buf1[100];
	//		//for (int i = 0; i < file.file_name.size(); i++)
	//		//{
	//		//	buf1[i] = file.file_name[i];
	//		//}
	//		//remove(buf1);
	//		ofstream cls("file.bin", ios::binary | ios::app);
	//		file.write_record_in_file(bt);
	//		cls.close();
	//		cout << "Информация из стека записана в файл" << endl;
	//		//file.writeTreeToFile((*bt), "stack.txt");
	//		break;
	//	}
	//	case 9:
	//	{
	//		file.read_record_in_file(bt);
	//		cout << "Информация из файла записана в стек" << endl;
	//		break;
	//	}
	//	case 10:
	//		ofstream cls("file.bin", ios::binary | ios::out);
	//		file.write_record_in_file(bt);
	//		cls.close();
	//		break;
	//	}
	//} while (ch != 10);
	return 1;
}
