#pragma once
#include<iostream>
#include <string>
#include <windows.h>
#include<fstream>
#include <conio.h>
#include <iomanip>
#include<istream>
using namespace std;

class User
{
protected:
	std::string fullName;
	std::string login;
	std::string password;

public:
	User(std::string fn, std::string lg, std::string pw)
	{
		fullName = fn;
		login = lg;
		password = pw;
	}
	User()
	{
		fullName = "";
		login = "";
		password = "";
	}
};

