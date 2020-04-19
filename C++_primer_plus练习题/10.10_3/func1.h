#pragma once

/**************************************************************************
	*  @file	 : func1.h
	*  @version  : C++ 11
    *  @author   : jimmy
    *  @date     : 2020/04/19 19:45
    *  @brief    : 对9.6_1程序的更改
**************************************************************************/
# ifndef _TEST_
# define _TEST_

class GOLF
{
    static const int Len = 40;/*  static const  定义作用域为类的常量*/
    char m_fullname[Len];
    int m_handicap;
public:
    GOLF(const char* name = "yukio" , const int handicap = 0);//带参数的构造函数
    //--2020/04/19 19:55--代替了原程序中C-风格的非交互式初始化和交互式初始化
    void Handicap(int);
    void showgolf();
};

# endif

