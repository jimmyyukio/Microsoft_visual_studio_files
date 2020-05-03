/**************************************************************************
	*  @file	 : head.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/02 19:53
    *  @lastdate :
    *  @brief    : brief
**************************************************************************/
#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

using namespace std;

class Port
{
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend ostream& operator<<(ostream& os, const Port& p);
};

class VintagePort : public Port
{
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort() { delete[] nickname; }
	VintagePort& operator=(const VintagePort& vp);
	virtual void Show() const;//设置为虚方法，编译器能够根据对象的类型来调用相应类中的方法
	friend ostream& operator<<(ostream& os, const VintagePort& vp);
};

# endif
