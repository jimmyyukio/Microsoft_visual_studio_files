/*
*时间:2020年4月19日18:56:20
*
*描述:
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