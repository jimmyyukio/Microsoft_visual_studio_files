/**************************************************************************
	*  @file	 : head.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/13 12:18
    *  @lastdate :
    *  @brief    : 图书信息管理系统
**************************************************************************/
#pragma once
# ifndef _TEST_
# define _TEST_
# include<stdio.h>

typedef struct//书
{
	char* bookname;//存储图书信息
	int status;//记录该书的状态
	char* describe;//书的信息
	//struct BOOK* nextnode;//链式存储，存储下一个结点
}Book, * PBook;

typedef struct//用户的结构
{
    char* user;//存储用户的账户名
    char* password;//存储用户的密码
    PBook bbook;//存储已经借了的书
    int bbooknum;//已经借到的书的数量
}user,*Puser;

typedef struct book_stack//书库
{
    PBook point;//用于存储书的信息
    struct book_stack* next;
}Stack,*PStack;

# endif