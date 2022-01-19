#include "Person.h"

void Person::setFullname(std::string fn)
{
	fullName = fn;
}

void Person::setPassword(std::string ps)
{
	password = ps;
}

std::string Person::getFullname()
{
	return fullName;
}

std::string Person::getPassword()
{
	return password;
}