# include<stdio.h>
# include"head.h"
# include<stdlib.h>
# include<windows.h>
const int MAX_NUM = 3; //能够借到的最大数量
const int MAX_NAMENUM = 20;//书名的最大长度
const int MAX_ACLEN = 15;//最大账号长度
const int MAX_PWLEN = 20;//最大密码长度
enum { YES = 1, NO = 0 };//书的状态
extern int MAX_DES;

Puser creatuser(void);//创建用户
PStack creatstack(void);//创建书库
void changepw(Puser);//改密码
int judgepw(char*, Puser);//判断密码

Puser creatuser(void)//创建一个用户
{
	Puser one = (Puser)malloc(sizeof(user));//创建用户
	if (!one)
	{
		exit(-1);
	}
	one->user = (char*)malloc(MAX_ACLEN);//用户名最多15位
	one->password = (char*)malloc(MAX_PWLEN);//密码最多20位
	FILE* fp;
	fp = fopen("./ac_pw.txt", "rt");
	if (fp != NULL)//从外部读取密码,检查是否打开了文件
	{
		fscanf(fp, "%s", one->user);
		fscanf(fp, "%s", one->password);
	}
	else//若没有读到外部信息则使用默认的用户名和密码
	{
		//fclose(fp);
		fp = fopen("./ac_pw.txt", "at");//因为上一次文件不存在，所以打开失败了，不需要先关闭流
		one->user = "jimmy";
		one->password = "1425717639";
		//写入默认密码到外部文件
		fwrite(one->user, sizeof(char), strlen(one->user), fp);
		fputs(" ",fp);
		fwrite(one->password, sizeof(char), strlen(one->password), fp);
	}
	one->bbook = (PBook)malloc(sizeof(Book) * MAX_NUM);//创建一个字符串数组
	if (!(one->bbook))
	{
		exit(-1);
	}
	one->bbooknum = 0;
	fclose(fp);
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

void changepw(Puser consumer)
{
	printf("请输入原密码：");
	char* lpw = (char*)malloc(MAX_PWLEN);
	if (!lpw)
	{
		exit(-1);
	}
	scanf("%s", lpw);
	int jd = judgepw(lpw, consumer);//做成模块方便递归调用
	if (jd == 0)
	{
		system("cls");
		printf("取消密码修改！");
		Sleep(3*1000);
	}
	else
	{
		system("cls");
		printf("密码修改成功！");
		FILE* fp = fopen("./ac_pw.txt", "wt+");
		fwrite(consumer->user, sizeof(char), strlen(consumer->user), fp);//重新写入数据
		fputs(" ", fp);
		fwrite(consumer->password, sizeof(char), strlen(consumer->password), fp);
		fclose(fp);
		Sleep(3*1000);
	}

}


int judgepw(char* lpw, Puser consumer)
{
	if (!strcmp(lpw, consumer->password))//判断密码是否正确,strcmp两字符串相同返回0
	{
		char* onepw = (char*)malloc(MAX_PWLEN);
		printf("请输入您要修改的密码（输入q退出）：");
		scanf("%s", onepw);
		if (onepw == "q")//输入q直接返回
		{
			return 0;
		}
		printf("请再次确认您所要修改的密码:");
		char* twopw = (char*)malloc(MAX_PWLEN);
		scanf("%s", twopw);
		if (strcmp(onepw, twopw))
		{
			printf("您的输入错误！请重新输入！\n");
			Sleep(2 * 1000);
			system("cls");
			if (judgepw(lpw, consumer) == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			consumer->password = twopw;//修改密码
			return 1;
		}
	}
	else//重新输入
	{
		system("cls");
		printf("您输入的密码有误！请重新输入\n");
		Sleep(2 * 1000);
		system("cls");
		printf("请输入密码：");
		scanf("%s", lpw);
		if (judgepw(lpw, consumer) == 0)//如果递归返回的为0表示用户输入了q要退出修改
		{
			return 0;
		}
		else//若返回的为1则表示修改成功了
		{
			return 1;
		}
	}
}