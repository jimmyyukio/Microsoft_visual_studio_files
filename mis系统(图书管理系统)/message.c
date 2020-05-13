# include<stdio.h>
# include"head.h"
# include<stdlib.h>
const int MAX_NUM = 3; //�ܹ��赽���������
const int MAX_NAMENUM = 20;
enum { YES = 1, NO = 0 };//���״̬
extern int MAX_DES;

Puser creatuser(void);
PStack creatstack(void);

Puser creatuser(void)//����һ���û�
{
	Puser one = (Puser)malloc(sizeof(user));//�����û�
	if (!one)
	{
		exit(-1);
	}
	one->user = "jimmy";
	one->password = "1425717639";
	one->bbook = (PBook)malloc(sizeof(Book) * MAX_NUM);//����һ���ַ�������
	if (!(one->bbook))
	{
		exit(-1);
	}
	one->bbooknum = 0;

	return one;
}

PStack creatstack(void)//����һ�����
{
	PStack phead = (PStack)malloc(sizeof(Stack));//ͷ���
	if (!phead)
	{
		exit(-1);
	}
	PStack Pnode = phead;//ָ��ͷ���
	phead->next = NULL;
	phead->point = NULL;
	FILE* fp;//�������ļ�
	fp = fopen("./book.txt", "at+");
	//if (!feof(fp))
	//	printf("�ļ��Ѵ�");
	if (fp == NULL)
	{
		exit(-1);
	}
	FILE* dp;//�������ļ�
	dp = fopen("./describe.txt", "at+");
	if (dp == NULL)
	{
		exit(-1);
	}

	//����
	//fseek(fp, SEEK_SET, 0);//�Ӷ�λ���ļ�ͷ
	//char name[20] = {0};
	//fread(name,sizeof(char),20,fp);

	fseek(fp, SEEK_SET, 0);//�Ӷ�λ���ļ�ͷ
	int test;
	while((test = getc(fp)) != EOF)//����������һֱ�����ݿ��ж�ȡ����
	{
		ungetc(test, fp);
		char* bookname = (char*)malloc(MAX_NAMENUM);//��¼����
		if (!bookname)
		{
			exit(-1);
		}
		fscanf(fp, "%s" , bookname);

		PBook bk = (PBook)malloc(sizeof(Book));//����һ�����ʵ��
		bk->status = NO;
		bk->bookname = bookname;//��ʵ����һ�����ִ��ȥ
		bk->describe = (char*)malloc(MAX_DES);//�����ڴ�
		if (feof(dp))
			bk->describe = "NULL";
		else
			fscanf(dp, "%s", bk->describe);//д������

		Pnode->next = (PStack)malloc(sizeof(Stack));//������д���һ���µĽ�����ڴ洢��
		if (!Pnode->next)
		{
			exit(-1);
		}
		Pnode->next->point = bk;//ָ���飬Ҳ���ǽ�������ʵ�������
		Pnode = Pnode->next;//�α�ָ��ָ�����һ�����
		Pnode->next = NULL;//��ָ�����ʼ��
	}
	fclose(fp);
	fclose(dp);

	return phead;
}