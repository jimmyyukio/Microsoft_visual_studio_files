#pragma once
/**************************************************************************
	*  @file	 : head.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/20 22:57
    *  @brief    : brief
	**************************************************************************/
# ifndef _TEST_
# define _TEST_
# include<iostream>

class list
{
	typedef struct//列表使用链表结构
	{
		double m_value;
		std::string m_name;
	}* PNODE , node;
	int nodenum;//记录当前列表中拥有的结点个数
	PNODE phead;//头结点
	PNODE lp;//指向尾指针
	node tem;//临时结点
public:
	list();//创建一个空链表
	bool is_empty();
	bool is_full();
	bool insert(node& , int fposition , int lposition);//插入一个结点
	node re_delete();//删除一个结点把删除掉的结点返回
};

# endif