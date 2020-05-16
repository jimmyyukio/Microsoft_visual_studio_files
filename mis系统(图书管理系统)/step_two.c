# include<stdio.h>
# include"head.h"
# include<windows.h>

enum { YES = 1, NO = 0 };
extern int MAX_LEN;//�ⲿ����
const int MAX_DES = 100;//�����������

void putmenu_two(Puser, PStack);
void addbook(PStack);
void deletebook(PStack);
void printmune(void);
void findbook(PStack);
void lookbook(PStack);
extern void SetPosition(int x, int y);
void del(Puser , PStack);

void putmenu_two(Puser one , PStack two)//�����˵�
{
	//system("pause");
	static int status = 1;
	while (status)
	{
		printmune();
		printf("����������ѡ��");
		char choose;
		fflush(stdin);
		scanf("%c", &choose);
		switch (choose)
		{
		case '1'://���ͼ��
			system("cls");
			addbook(two);
			system("cls");
			break;
		case '2'://ɾ��ͼ��
			system("cls");
			deletebook(two);
			system("cls");
			break;
		case '3'://Ѱ��ͼ��
			system("cls");
			findbook(two);
			system("cls");
			break;
		case '4'://��������ͼ��
			system("cls");
			lookbook(two);
			system("cls");
			break;
		case '5'://����
			system("cls");
			//func5(one);
			printf("����δ��ɣ������ǰ4��ѡ��");
			Sleep(2*1000);
			system("cls");
			break;
		case '6'://����
			system("cls");
			//func6(one);
			printf("����δ��ɣ������ǰ4��ѡ��");
			Sleep(2*1000);
			system("cls");
			break;
		case '7'://�鿴�Ѿ����ĵ�ͼ��
			system("cls");
			//func7(one);
			printf("����δ��ɣ������ǰ4��ѡ��");
			Sleep(2*1000);
			system("cls");
			break;
		case '8'://��������
			system("cls");
			changepw(one);
			system("cls");
			break;
		case '9':
			system("cls");
			del(one,two);
			SetPosition(25,12);
			printf("��л����ʹ�ã������˳�����\n");
			Sleep(2*1000);
			status = 0;
			break;
		default:
			system("cls");
			printf("�Ƿ������룡\n");
			Sleep(2 * 1000);
			system("cls");
			putmenu_two(one, two);
			break;
		}
	}
}

void printmune(void)
{
	printf("***************************************************\n");
	printf("              --��ѡ��Ҫ���еĲ���--                  \n");
	printf("\n");
	printf("  (1)���һ��ͼ��\n");
	printf("\n");
	printf("  (2)ɾ��һ��ͼ��\n");
	printf("\n");
	printf("  (3)����һ��ͼ��\n");
	printf("\n");
	printf("  (4)����ͼ��Ļ�����Ϣ\n");
	printf("\n");
	printf("  (5)����\n");
	printf("\n");
	printf("  (6)����\n");
	printf("\n");
	printf("  (7)�鿴�ѽ��ĵ�ͼ��\n");
	printf("\n");	
	printf("  (8)��������\n");
	printf("\n");
	printf("  (9)�˳�����\n");
	printf("\n");
	printf("***************************************************\n");
}

void addbook(PStack two)
{
	PStack tem = two;
	printf("\n������Ҫ��ӵ�ͼ������");
	char* name = (char*)malloc(MAX_LEN);
	fflush(stdin);
	scanf("%s", name);
	PBook book = (PBook)malloc(sizeof(PBook));
	if (!book)
	{
		exit(-1);
	}
	book->bookname = name;
	printf("\n�������ͼ���������");
	char* describe = (char*)malloc(MAX_DES);
	fflush(stdin);
	scanf("%s", describe);
	book->describe = describe;
	book->status = NO;
	while (tem->next != NULL)//���������һ�����
		tem = tem->next;
	PStack node = (PStack)malloc(sizeof(Stack));//һ���µ����洢���
	if (!node)
	{
		exit(-1);
	}
	node->point = book;//�洢�鼮
	node->next = NULL;//��ʼ��ָ��
	tem->next = node;//����
	tem = tem->next;

	FILE* fp;
	fp = fopen("./book.txt", "at+");
	if (fp == NULL)
	{
		exit(-1);
	}
	if (two->next == tem);//������ǵ�һ����Ч�ڵ�
	else
		fputs(" ",fp);//��ǰ���鼮ǰ��һ���ո�
	fwrite(node->point->bookname, sizeof(char), strlen(node->point->bookname), fp);

	FILE* dp;
	dp = fopen("./describe.txt", "at+");
	if (dp == NULL)
	{
		exit(-1);
	}
	if (two->next == tem);//������ǵ�һ����Ч�ڵ�
	else
		fputs(" ", dp);//��ǰ���鼮ǰ��һ���ո�
	fwrite(node->point->describe, sizeof(char), strlen(node->point->describe), dp);

	printf("\n�����ɹ�\n");
	fclose(dp);
	fclose(fp);
	Sleep(2 * 1000);
	return;
}

void deletebook(PStack two)
{
	//PStack tem = two;
	PStack tem = two;
	PStack tem2 = two;
	printf("������Ҫɾ������ı��:");
	int num;
	fflush(stdin);
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		if (tem->next == NULL)//�Դ����������д���
		{
			printf("����ı�ţ�\n");
			Sleep(2 * 1000);
			return;
		}
		tem = tem->next;//tem�ƶ���Ҫɾ���Ľ���λ��
	}
	while (tem2->next != tem)//�ƶ���Ҫɾ���Ľ���ǰ��
	{
			tem2 = tem2->next;
	}
	if (tem->next == NULL)//��Ҫɾ�����ĺ���Ϊ��
	{
		tem2->next = NULL;//���ָ��
		//free(tem->point->bookname);
		//free(tem->point->describe);
		free(tem);//�ͷ���ռ�õĿռ�
	}
	//����д������
	FILE* fp = fopen("./book.txt", "wt");
	if (fp == NULL)
	{
		exit(-1);
	}
	tem = two;
	while (tem->next != NULL)
	{
		tem = tem->next;
		fwrite(tem->point->bookname, sizeof(char), strlen(tem->point->bookname), fp);
		fputs(" ", fp);
	}
	FILE* dp = fopen("./describe.txt", "wt");
	if (dp == NULL)
	{
		exit(-1);
	}
	tem = two;
	while (tem->next != NULL)
	{
		tem = tem->next;
		if (tem == two->next);
		else
			printf(" ");
		fwrite(tem->point->describe, sizeof(char), strlen(tem->point->describe), dp);
		
	}
	fclose(fp);
	fclose(dp);
	printf("\nɾ���ɹ���\n");
	Sleep(2 * 1000);
	return;
}

void findbook(PStack two)
{
	printf("��������Ҫ���ҵ��鼮�����֣�");
	char* name = (char*)malloc(MAX_LEN);
	fflush(stdin);
	scanf("%s", name);
	int position = 1;
	while (two->next != NULL)
	{
		two = two->next;
		if (!strcmp(name, two->point->bookname))
		{
			system("cls");
			printf("����ı��Ϊ��%d\n", position);
			printf("name : %s\n", two->point->bookname);
			printf("describe : %s\n", two->point->describe);
			if (two->point->status == NO)
				printf("status : ���˽���\n");
			else
				printf("status : �ѱ�����\n\n");
			break;
		}
		position++;
		if (two->next == NULL)//�Դ���������д���
		{
			system("cls");
			printf("\nû���ҵ����鼮���κ���Ϣ��\n\n");
		}
	}
	system("pause");
	return;
}

void lookbook(PStack two)
{
	PStack tem = two;
	int num = 1;
	if (tem->next == NULL)
		printf("\n��ǰ���Ϊ�գ�\n");
	while (tem->next != NULL)
	{
		tem = tem->next;

		printf("# %d :\n", num);
		printf("name : %s\n", tem->point->bookname);
		printf("describe : %s\n", tem->point->describe);
		if (tem->point->status == NO)
			printf("status : ���˽���\n");
		else
			printf("status : �ѱ�����\n");
		num++;
	}
	system("pause");
	return;
}

void del(Puser one , PStack two)//�ͷ����е��ڴ�
{
	//�ͷ����
	PStack tem = two;//��ʱָ��
	if(tem->next == NULL)//���Ϊ������
		free(two);//ֱ���ͷ�ͷ���
	else
	{
		tem = tem->next;
		free(two);//�Ե�һ��ͷ������⴦��
		while(tem != NULL)
		{
			two = tem;
			tem = tem->next;
			free(two->point->bookname);
			free(two->point->describe);
			free(two->point);
			free(two);
		}
	}
	//�ͷ��û�
	Puser tem2 = one;
	free(one->user);
	free(one->password);
	free(one);
	
	return;
}