# include<stdio.h>
# include"head.h"
# include<stdlib.h>
# include<windows.h>
const int MAX_NUM = 10; //�ܹ��赽���������
const int MAX_NAMENUM = 20;//��������󳤶�
const int MAX_ACLEN = 15;//����˺ų���
const int MAX_PWLEN = 20;//������볤��
enum { YES = 1, NO = 0 };//���״̬
extern int MAX_DES;

Puser creatuser(void);//�����û�
PStack creatstack(void);//�������
void changepw(Puser);//������
int judgepw(char*, Puser);//�ж�����

Puser creatuser(void)//����һ���û�
{
	Puser one = (Puser)malloc(sizeof(user));//�����û�
	if (!one)
	{
		exit(-1);
	}
	one->user = (char*)malloc(MAX_ACLEN);//�û������15λ
	one->password = (char*)malloc(MAX_PWLEN);//�������20λ
	FILE* fp;
	fp = fopen("./ac_pw.txt", "rt");
	if (fp != NULL)//���ⲿ��ȡ����,����Ƿ�����ļ�
	{
		fscanf(fp, "%s", one->user);
		fscanf(fp, "%s", one->password);
	}
	else//��û�ж����ⲿ��Ϣ��ʹ��Ĭ�ϵ��û���������
	{
		//fclose(fp);
		fp = fopen("./ac_pw.txt", "at");//��Ϊ��һ���ļ������ڣ����Դ�ʧ���ˣ�����Ҫ�ȹر���
		one->user = "jimmy";
		one->password = "1425717639";
		//д��Ĭ�����뵽�ⲿ�ļ�
		fwrite(one->user, sizeof(char), strlen(one->user), fp);
		fputs(" ",fp);
		fwrite(one->password, sizeof(char), strlen(one->password), fp);
	}
	one->bbook[10] = (PBook)malloc(sizeof(Book) * MAX_NUM);//����һ�����ڴ洢�鼮������
	if (!(one->bbook))
	{
		exit(-1);
	}
	one->bbooknum = 0;//��ʼ�赽����Ϊ0
	fclose(fp);
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

void changepw(Puser consumer)
{
	printf("������ԭ���룺");
	char* lpw = (char*)malloc(MAX_PWLEN);
	if (!lpw)
	{
		exit(-1);
	}
	scanf("%s", lpw);
	int jd = judgepw(lpw, consumer);//����ģ�鷽��ݹ����
	if (jd == 0)
	{
		system("cls");
		printf("ȡ�������޸ģ�");
		Sleep(3*1000);
	}
	else
	{
		system("cls");
		printf("�����޸ĳɹ���");
		FILE* fp = fopen("./ac_pw.txt", "wt+");
		fwrite(consumer->user, sizeof(char), strlen(consumer->user), fp);//����д������
		fputs(" ", fp);
		fwrite(consumer->password, sizeof(char), strlen(consumer->password), fp);
		fclose(fp);
		Sleep(3*1000);
	}

}


int judgepw(char* lpw, Puser consumer)
{
	if (!strcmp(lpw, consumer->password))//�ж������Ƿ���ȷ,strcmp���ַ�����ͬ����0
	{
		char* onepw = (char*)malloc(MAX_PWLEN);
		printf("��������Ҫ�޸ĵ����루����q�˳�����");
		scanf("%s", onepw);
		if (onepw == "q")//����qֱ�ӷ���
		{
			return 0;
		}
		printf("���ٴ�ȷ������Ҫ�޸ĵ�����:");
		char* twopw = (char*)malloc(MAX_PWLEN);
		scanf("%s", twopw);
		if (strcmp(onepw, twopw))
		{
			printf("��������������������룡\n");
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
			consumer->password = twopw;//�޸�����
			return 1;
		}
	}
	else//��������
	{
		system("cls");
		printf("�������������������������\n");
		Sleep(2 * 1000);
		system("cls");
		printf("���������룺");
		scanf("%s", lpw);
		if (judgepw(lpw, consumer) == 0)//����ݹ鷵�ص�Ϊ0��ʾ�û�������qҪ�˳��޸�
		{
			return 0;
		}
		else//�����ص�Ϊ1���ʾ�޸ĳɹ���
		{
			return 1;
		}
	}
}