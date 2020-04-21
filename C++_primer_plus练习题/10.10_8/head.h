#pragma once
/**************************************************************************
	*  @file	 : head.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/20 22:57
    *  @lastdate : 2020��4��21��15:59:29
    *  @brief    : brief
	**************************************************************************/
# ifndef _TEST_
# define _TEST_
# include<iostream>

class list
{
	typedef struct Node//�б�ʹ������ṹ
	{
		double m_value;
		std::string m_name;
		struct Node* next;
	}* PNODE , node;
	int nodenum;//��¼��ǰ�б���ӵ�еĽ�����
	PNODE phead;//ͷ���
	PNODE lp;//ָ��βָ��
	node temnode;//��ʱ���
public:
	list();//����һ��������
	bool creatnode(const std::string name = "noname", const double value = 0);//�����µĽڵ�
	bool is_empty();
	void showlist();
	bool insert(int fposition);//����һ�����
	node re_delete(const int position);//ɾ��һ������ɾ�����Ľ�㷵��
	void changename(const int position , const std::string name);
	void changevalue(const int position , const double value);
};

# endif