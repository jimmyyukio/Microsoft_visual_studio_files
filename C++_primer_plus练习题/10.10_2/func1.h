#pragma once
/*
*@时间:2020年4月19日18:28:42
*
*@描述:
*
**/
# ifndef _TEST_
# define _TEST_
# include<iostream>

class Person
{
private:
	static const int LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = "jimmy" ; fname[0] = '\0' ; }/*内联函数*/
	Person(const std::string & ln, const char* fn = "Heyyou");/*构造函数,带默认值*/
	void show() const;
	void Formalshow() const;
	/*在函数后面加上const 的声明或者定义表示其为const成员函数 */
};

# endif