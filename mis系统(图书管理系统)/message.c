# include<stdio.h>
# include"head.h"
# include<stdlib.h>
const int MAX_NUM = 3; //能够借到的最大数量
const int MAX_NAMENUM = 20;
enum { YES = 1, NO = 0 };//书的状态
extern int MAX_DES;

Puser creatuser(void);
PStack creatstack(void);

Puser creatuser(void)//创建一个用户
{
	Puser one = (Puser)malloc(sizeof(user));//创建用户
	if (!one)
	{
		exit(-1);
	}
	one->user = "jimmy";
	one->password = "1425717639";
	one->bbook = (PBook)malloc(sizeof(Book) * MAX_NUM);//创建一个字符串数组
	if (!(one->bbook))
	{
		exit(-1);
	}
	one->bbooknum = 0;

	return one;
}

PStack creatstack(void)//创建一个书库
{
	PStack phead = (PStack)malloc(sizeof(Stack));//头结点
	if (!phead)
	{
		exit(-1);
	}
	PStack Pnode = phead;//指向头结点
	phead->next = NULL;
	phead->point = NULL;
	FILE* fp;//打开名字文件
	fp = fopen("./book.txt", "at+");
	//if (!feof(fp))
	//	printf("文件已打开");
	if (fp == NULL)
	{
		exit(-1);
	}
	FILE* dp;//打开描述文件
	dp = fopen("./describe.txt", "at+");
	if (dp == NULL)
	{
		exit(-1);
	}

	//测试
	//fseek(fp, SEEK_SET, 0);//从定位到文件头
	//char name[20] = {0};
	//fread(name,sizeof(char),20,fp);

	fseek(fp, SEEK_SET, 0);//从定位到文件头
	int test;
	while((test = getc(fp)) != EOF)//若不到结束一直从数据库中读取数据
	{
		ungetc(test, fp);
		char* bookname = (char*)malloc(MAX_NAMENUM);//记录书名
		if (!bookname)
		{
			exit(-1);
		}
		fscanf(fp, "%s" , bookname);

		PBook bk = (PBook)malloc(sizeof(Book));//创建一本书的实体
		bk->status = NO;
		bk->bookname = bookname;//给实体书一个名字存进去
		bk->describe = (char*)malloc(MAX_DES);//分配内存
		if (feof(dp))
			bk->describe = "NULL";
		else
			fscanf(dp, "%s", bk->describe);//写入描述

		Pnode->next = (PStack)malloc(sizeof(Stack));//在书库中创建一个新的结点用于存储书
		if (!Pnode->next)
		{
			exit(-1);
		}
		Pnode->next->point = bk;//指向书，也就是将生产的实体书放入
		Pnode = Pnode->next;//游标指针指向最后一个结点
		Pnode->next = NULL;//将指针域初始化
	}
	fclose(fp);
	fclose(dp);

	return phead;
}