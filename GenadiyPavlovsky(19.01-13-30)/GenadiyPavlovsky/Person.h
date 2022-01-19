#pragma once
#include <iostream>
class Person
{
	std::string fullName;
	std::string password;
public:
	Person()
	{
		fullName = "";
		password = "";
	}
	Person(std::string fn, std::string ps)
	{
		fullName = fn;
		password = ps;
	}
	void setFullname(std::string fn);
	void setPassword(std::string ps);
	std::string getFullname();
	std::string getPassword();
};

