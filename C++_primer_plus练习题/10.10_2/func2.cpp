/*
*ʱ��:2020��4��19��18:56:20
*
*����:
*
**/
# include<iostream>
# include<cstring>
# include"func1.h"

Person::Person(const std::string & ln, const char* fn )
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::show() const
{
	std::cout << "The person's lastname : " << lname << std::endl;
}

void Person::Formalshow() const
{
	std::cout << "Firstname is : " << fname << std::endl;
}