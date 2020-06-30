/**************************************************************************
	*  @file	 : head.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/13 12:18
    *  @lastdate :
    *  @brief    : ͼ����Ϣ����ϵͳ
**************************************************************************/
#pragma once
# ifndef _TEST_
# define _TEST_
# include<stdio.h>

typedef struct//��
{
	char* bookname;//�洢ͼ����Ϣ
	int status;//��¼�����״̬
	char* describe;//�����Ϣ
	//struct BOOK* nextnode;//��ʽ�洢���洢��һ�����
}Book, * PBook;

typedef struct//�û��Ľṹ
{
    char* user;//�洢�û����˻���
    char* password;//�洢�û�������
    PBook bbook[10];//�洢�Ѿ����˵���
    int bbooknum;//�Ѿ��赽���������
}user,*Puser;

typedef struct book_stack//���
{
    PBook point;//���ڴ洢�����Ϣ
    struct book_stack* next;
}Stack,*PStack;

# endif