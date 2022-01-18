#include "Employee.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <istream>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <regex>
#include <iomanip>
//#include <string>

using namespace std;
 // ��� setw
std::string enter_date(std::istream& in) {
	string i;
	int flags;
	do {
		try {
			flags = 0;
			std::cout << "Enter date... ";
			in >> i;
			if (!std::cin || std::cin.peek() != '\n') {
				throw 1;
			}
			//regex_search()
			static std::regex rgx{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))" };
			smatch res;
			if (regex_search(i, res, rgx))
			{
				for (int j = 0; j < i.size(); j++) {
					if (i[0] == '3' && i[1] == '1' && i[3] == '0' && i[4] == '2')
					{
						throw 1;


					}
					else if (i[0] == '3' && i[1] == '0' && i[3] == '0' && i[4] == '2')
					{
						throw 1;
					}
				}
				return i;
				/*d.day = std::stoi(res[1]);
				d.month = std::stoi(res[2]);
				d.year = std::stoi(res[3]);*/
				//return true;
			}
			else {
				throw 1;
			}
			//return false;
			/*if (i < min || i > max) {
				throw 'a';
			}*/
		}
		catch (int) {
			flags = 1;
			std::cout << "It's not a (type) date!!!\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
		catch (char) {
			flags = 1;
			std::cout << "Out of range.\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
	} while (flags);
	return i;
}


int enter_int(std::istream& in, double min, double max) {
	double i;
	int flags;
	do {
		try {
			flags = 0;
			std::cout << "Enter the number... ";
			in >> i;
			if (!std::cin || std::cin.peek() != '\n') {
				throw 1;
			}
			if (i < min || i > max) {
				throw 'a';
			}
		}
		catch (int) {
			flags = 1;
			std::cout << "It's not a (type) number!!!\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
		catch (char) {
			flags = 1;
			std::cout << "Out of range.\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
	} while (flags);
	return i;
}

std::string enter_char(std::istream& in) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);
	////////

	std::string s;
	int flags;
	std::string letters = "��������������������������������";
	do {
		try {
			flags = 0;
			rewind(stdin);
			std::cout << "Enter the letters... ";
			getline(in, s);
			//std::transform(s.begin(), s.end(), s.begin(), tolower);
			//in >> s;			
			for (int i = 0; i < s.length(); i++)
			{
				for (int il = 0; il < letters.length(); il++)
				{
					if (s[i] != letters[il])
					{
						if (il == letters.length() - 1)
						{
							if (!isalpha(s[i]) && s[i] != ' ' && s[i]!='-')
								throw 1; break; break;
						}
					}
					else break;
				}
			}
		}
		catch (int) {
			flags = 1;
			std::cout << "It's not a letters!!!\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
	} while (flags);
	return s;
}

int Employee::getDepNum()
{
	int rez = departmentNumber;
	return rez;
}

int Employee::getDepNum(Employee& ob)
{
	int rez = ob.departmentNumber;
	return rez;
}



std::string Employee::getFullName()
{
	return fullName;
}

std::string Employee::getPosition()
{
	return position;
}

std::string Employee::getStartDateOfWork()
{
	return startDateOfWork;
}


// I / O operator overloading

std::istream& operator>>(std::istream& in, Employee& ob)
{
	std::cout << "Enter full name" << endl;
	ob.fullName = enter_char(std::cin);
	std::cout << "Enter department number" << endl;
	ob.departmentNumber = enter_int(std::cin, 1, 1000);
	std::cout << "Enter position" << endl;
	ob.position = enter_char(std::cin);
	std::cout << "Enter start date of work" << endl;
	ob.startDateOfWork = enter_date(std::cin);
	/*in.read(const_cast<char*> (ob.fullName.c_str()), sizeof(ob.fullName));
	in.read(reinterpret_cast<char*> (ob.departmentNumber), sizeof(ob.departmentNumber));
	in.read(const_cast<char*> (ob.position.c_str()), sizeof(ob.position));
	in.read(const_cast<char*> (ob.startDateOfWork.c_str()), sizeof(ob.startDateOfWork));*/
	return in;
}

std::ostream& operator<<(std::ostream& out, Employee& ob)
{
	out << std::setw(20) << ob.fullName << std::setw(20) << ob.departmentNumber << std::setw(20) << ob.position <<
		std::setw(20) << ob.startDateOfWork << endl;
	/*out.write(ob.fullName.c_str(), sizeof(ob.fullName));
	out.write(reinterpret_cast<char*> (ob.departmentNumber), sizeof(ob.departmentNumber));
	out.write(ob.position.c_str(), sizeof(ob.position));
	out.write(ob.startDateOfWork.c_str(), sizeof(ob.startDateOfWork));*/
	return out;
}