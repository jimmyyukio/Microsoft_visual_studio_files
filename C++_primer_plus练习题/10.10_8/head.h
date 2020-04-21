#pragma once
/**************************************************************************
	*  @file	 : head.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/20 22:57
    *  @lastdate : 2020年4月21日15:59:29
    *  @brief    : brief
	**************************************************************************/
# ifndef _TEST_
# define _TEST_
# include<iostream>

class list
{
	typedef struct Node//列表使用链表结构
	{
		double m_value;
		std::string m_name;
		struct Node* next;
	}* PNODE , node;
	int nodenum;//记录当前列表中拥有的结点个数
	PNODE phead;//头结点
	PNODE lp;//指向尾指针
	node temnode;//临时结点
public:
	list();//创建一个空链表
	bool creatnode(const std::string name = "noname", const double value = 0);//创建新的节点
	bool is_empty();
	void showlist();
	bool insert(int fposition);//插入一个结点
	node re_delete(const int position);//删除一个结点把删除掉的结点返回
	void changename(const int position , const std::string name);
	void changevalue(const int position , const double value);
};

# endif