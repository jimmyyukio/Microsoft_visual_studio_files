#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>
# include<cstring>
using namespace std;

class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") { strcpy(fab, s); }
	virtual void tell() { cout << fab; }//声明为虚函数，以便正确的调用函数
};

class Gloam
{
private:
	int glip;
	Frabjous fb;
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);//用对象作为参数，初始化Gloam对象
	void tell();
};

# endif
