# include<stdio.h>
# include"head.h"
# include<windows.h>

enum { YES = 1, NO = 0 };
extern int MAX_LEN;//外部链接
const int MAX_DES = 100;//最大描述字数

void putmenu_two(Puser, PStack);
void addbook(PStack);
void deletebook(PStack);
void printmune(void);
void findbook(PStack);
void lookbook(PStack);
extern void SetPosition(int x, int y);

void putmenu_two(Puser one , PStack two)//二级菜单
{
	//system("pause");
	static int status = 1;
	while (status)
	{
		printmune();
		printf("请输入您的选择：");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			addbook(two);
			system("cls");
			break;
		case 2:
			system("cls");
			deletebook(two);
			system("cls");
			break;
		case 3:
			system("cls");
			findbook(two);
			system("cls");
			break;
		case 4:
			system("cls");
			lookbook(two);
			system("cls");
			break;
		case 5:
			system("cls");
			//func5();
			printf("功能未完成！请测试前4个选项");
			Sleep(2*1000);
			system("cls");
			break;
		case 6:
			system("cls");
			//func6();
			printf("功能未完成！请测试前4个选项");
			Sleep(2*1000);
			system("cls");
			break;
		case 7:
			system("cls");
			//func7();
			printf("功能未完成！请测试前4个选项");
			Sleep(2*1000);
			system("cls");
			break;
		case 8:
			system("cls");
			SetPosition(25,12);
			printf("感谢您的使用，即将退出程序！\n");
			Sleep(2*1000);
			status = 0;
			break;
		default:
			system("cls");
			printf("非法的输入！\n");
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
	printf("              --请选择要进行的操作--                  \n");
	printf("\n");
	printf("  (1)添加一本图书\n");
	printf("\n");
	printf("  (2)删除一本图书\n");
	printf("\n");
	printf("  (3)查找一本图书\n");
	printf("\n");
	printf("  (4)游览图书的基本信息\n");
	printf("\n");
	printf("  (5)借书\n");
	printf("\n");
	printf("  (6)还书\n");
	printf("\n");
	printf("  (7)查看已借阅的图书\n");
	printf("\n");
	printf("  (8)退出程序\n");
	printf("\n");
	printf("***************************************************\n");
}

void addbook(PStack two)
{
	PStack tem = two;
	printf("\n请输入要添加的图书名：");
	char* name = (char*)malloc(MAX_LEN);
	scanf("%s", name);
	PBook book = (PBook)malloc(sizeof(PBook));
	if (!book)
	{
		exit(-1);
	}
	book->bookname = name;
	printf("\n请输入对图书的描述：");
	char* describe = (char*)malloc(MAX_DES);
	scanf("%s", describe);
	book->describe = describe;
	book->status = NO;
	while (tem->next != NULL)//遍历到最后一个结点
		tem = tem->next;
	PStack node = (PStack)malloc(sizeof(Stack));//一个新的书库存储结点
	if (!node)
	{
		exit(-1);
	}
	node->point = book;//存储书籍
	node->next = NULL;//初始化指针
	tem->next = node;//接上
	tem = tem->next;

	FILE* fp;
	fp = fopen("./book.txt", "at+");
	if (fp == NULL)
	{
		exit(-1);
	}
	if (two->next == tem);//如果这是第一个有效节点
	else
		fputs(" ",fp);//在前面书籍前加一个空格
	fwrite(node->point->bookname, sizeof(char), strlen(node->point->bookname), fp);

	FILE* dp;
	dp = fopen("./describe.txt", "at+");
	if (dp == NULL)
	{
		exit(-1);
	}
	if (two->next == tem);//如果这是第一个有效节点
	else
		fputs(" ", dp);//在前面书籍前加一个空格
	fwrite(node->point->describe, sizeof(char), strlen(node->point->describe), dp);

	printf("\n操作成功\n");
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
	printf("请输入要删除的书的编号:");
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		if (tem->next == NULL)//对错误的输入进行处理
		{
			printf("错误的编号！\n");
			Sleep(2 * 1000);
			return;
		}
		tem = tem->next;//tem移动到要删除的结点的位置
	}
	while (tem2->next != tem)//移动到要删除的结点的前面
	{
			tem2 = tem2->next;
	}
	if (tem->next == NULL)//若要删除结点的后面为空
	{
		tem2->next = NULL;//清空指针
		//free(tem->point->bookname);
		//free(tem->point->describe);
		free(tem);//释放所占用的空间
	}
	//重新写入数据
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
	printf("\n删除成功！\n");
	Sleep(2 * 1000);
	return;
}

void findbook(PStack two)
{
	printf("请输入您要查找的书籍的名字：");
	char* name = (char*)malloc(MAX_LEN);
	scanf("%s", name);
	int position = 1;
	while (two->next != NULL)
	{
		two = two->next;
		if (!strcmp(name, two->point->bookname))
		{
			system("cls");
			printf("该书的编号为：%d\n", position);
			printf("name : %s\n", two->point->bookname);
			printf("describe : %s\n", two->point->describe);
			if (two->point->status == NO)
				printf("status : 无人借走\n");
			else
				printf("status : 已被借走\n\n");
			break;
		}
		position++;
		if (two->next == NULL)//对错误输入进行处理
		{
			system("cls");
			printf("\n没有找到该书籍的任何信息！\n\n");
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
		printf("\n当前书库为空！\n");
	while (tem->next != NULL)
	{
		tem = tem->next;

		printf("# %d :\n", num);
		printf("name : %s\n", tem->point->bookname);
		printf("describe : %s\n", tem->point->describe);
		if (tem->point->status == NO)
			printf("status : 无人借走\n");
		else
			printf("status : 已被借走\n");
		num++;
	}
	system("pause");
	return;
}