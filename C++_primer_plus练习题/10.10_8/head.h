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
	typedef struct//�б�ʹ������ṹ
	{
		double m_value;
		std::string m_name;
	}* PNODE , node;
	int nodenum;//��¼��ǰ�б���ӵ�еĽ�����
	PNODE phead;//ͷ���
	PNODE lp;//ָ��βָ��
	node tem;//��ʱ���
public:
	list();//����һ��������
	bool is_empty();
	bool is_full();
	bool insert(node& , int fposition , int lposition);//����һ�����
	node re_delete();//ɾ��һ������ɾ�����Ľ�㷵��
};

# endif