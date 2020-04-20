#pragma once
/**************************************************************************
	*  @file	 : head.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/20 22:39
    *  @brief    : brief
**************************************************************************/
# ifndef _TEST_
# define _TEST_
# include<cstring>

class plorg
{
	char m_name[19];
	int m_CI;
public:
	plorg(const char* name = "Plorga", const int CI = 50);
	void recomposeCI(const int CI);
	void showplorg();
};

# endif