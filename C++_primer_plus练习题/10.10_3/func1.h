#pragma once

/**************************************************************************
	*  @file	 : func1.h
	*  @version  : C++ 11
    *  @author   : jimmy
    *  @date     : 2020/04/19 19:45
    *  @brief    : ��9.6_1����ĸ���
**************************************************************************/
# ifndef _TEST_
# define _TEST_

class GOLF
{
    static const int Len = 40;/*  static const  ����������Ϊ��ĳ���*/
    char m_fullname[Len];
    int m_handicap;
public:
    GOLF(const char* name = "yukio" , const int handicap = 0);//�������Ĺ��캯��
    //--2020/04/19 19:55--������ԭ������C-���ķǽ���ʽ��ʼ���ͽ���ʽ��ʼ��
    void Handicap(int);
    void showgolf();
};

# endif

