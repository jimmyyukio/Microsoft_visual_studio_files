# include<stdio.h>
# include"head.h"
# include<windows.h>

enum { YES = 1, NO = 0 };
extern int MAX_LEN;//外部链接
const int MAX_DES = 100;//最大描述字数
// const int MAX_LEN = 30;//最大的密码长度

void putmenu_two(Puser, PStack);
void addbook(PStack);
void deletebook(PStack);
void printmune(void);
void findbook(PStack);
void lookbook(PStack);
void changepw(Puser);
extern void SetPosition(int x, int y);
void del(Puser , PStack);
void func5(Puser , PStack);
void func6(Puser, PStack);
void func7(Puser);

void putmenu_two(Puser one , PStack two)//二级菜单
{
	//system("pause");
	static int status = 1;
	while (status)
	{
		printmune();
		printf("请输入您的选择：");
		char choose;
		setbuf(stdin, NULL);//使默认缓冲流区转为无缓冲区，从未清空缓冲区中还未读入的输入
		scanf("%c", &choose);
		switch (choose)
		{
		case '1'://添加图书
			system("cls");
			addbook(two);
			system("cls");
			break;
		case '2'://删除图书
			system("cls");
			deletebook(two);
			system("cls");
			break;
		case '3'://寻找图书
			system("cls");
			findbook(two);
			system("cls");
			break;
		case '4'://遍历所有图书
			system("cls");
			lookbook(two);
			system("cls");
			break;
		case '5'://借书
			system("cls");
			func5(one,two);
			// printf("功能未完成！请测试前4个选项");
			Sleep(2*1000);
			system("cls");
			break;
		case '6'://还书
			system("cls");
			func6(one,two);
			//printf("功能未完成！请测试前4个选项");
			Sleep(1*1000);
			system("cls");
			break;
		case '7'://查看已经借阅的图书
			system("cls");
			func7(one);
			//printf("功能未完成！请测试前4个选项");
			// Sleep(1 * 1000);
			system("cls");
			break;
		case '8'://更改密码
			system("cls");
			changepw(one);
			system("cls");
			break;
		case '9':
			system("cls");
			del(one,two);
			SetPosition(25,12);
			printf("感谢您的使用，即将退出程序！\n");
			Sleep(1 * 1000);
			status = 0;
			break;
		default:
			system("cls");
			printf("非法的输入！\n");
			Sleep(1 * 1000);
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
	printf("  (8)更改密码\n");
	printf("\n");
	printf("  (9)退出程序\n");
	printf("\n");
	printf("***************************************************\n");
}

void addbook(PStack two)
{
	PStack tem = two;
	printf("\n请输入要添加的图书名：");
	char* name = (char*)malloc(MAX_LEN);
	fflush(stdin);
	scanf("%s", name);
	PBook book = (PBook)malloc(sizeof(PBook));
	if (!book)
	{
		exit(-1);
	}
	book->bookname = name;
	printf("\n请输入对图书的描述：");
	char* describe = (char*)malloc(MAX_DES);
	fflush(stdin);
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
	fflush(stdin);
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
	fflush(stdin);
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

void del(Puser one , PStack two)//释放所有的内存
{
	//释放书库
	PStack tem = two;//临时指针
	if(tem->next == NULL)//如果为空链表
		free(two);//直接释放头结点
	else
	{
		tem = tem->next;
		free(two);//对第一个头结点特殊处理
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
	//释放用户
	Puser tem2 = one;
	free(one->user);
	free(one->password);
	free(one);
	
	return;
}

void func5(Puser one, PStack two)//借书
{
	printf("请输入要借走的书的编号 ：");
	int num;
	scanf("%d",&num);
	PStack tem = two;
	for(int i = 0 ; i < num ; i ++)//移动到要借走的书的位置上
	{
		if(tem->next == NULL)//对输入的编号进行检查
		{
			printf("您的输入有误!\n");
			return;
		}
		tem = tem->next;
	}
	
	printf("\n请输入密码 : ");
	char* pw = (char*)malloc(sizeof(char) * MAX_LEN);//用于接收输入的密码
	scanf("%s",pw);//输入密码
	if( strcmp(pw,one->password))//两字符串相同返回0,判断输入的密码是否正确
	{
		printf("\n抱歉，您的输入错误！\n");
		return;
	}
	else
	{
		if (tem->point->status == YES)
		{
			printf("您已经借了这本书！\n");
			return;
		}
		one->bbook[one->bbooknum] = tem->point;//存储一份指向书的指针
		one->bbooknum++;//借到的书数量加一
		tem->point->status = YES;//书的状态改成被借走
		system("cls");
		printf("借书成功\n");
	}
}

void func6(Puser one , PStack two)//还书
{
	printf("请输入您要还的书的顺序编号 : ");
	int num;
	scanf("%d", &num);

	printf("\n请输入密码 : ");
	char* pw = (char*)malloc(sizeof(char) * MAX_LEN);//用于接收输入的密码
	scanf("%s", pw);//输入密码
	if (strcmp(pw, one->password))//两字符串相同返回0,判断输入的密码是否正确
	{
		printf("\n抱歉，您的输入错误！\n");
		return;
	}
	else
	{
		one->bbook[num - 1]->status = NO;//把书的状态还原
		if (one->bbooknum == 1)//只有一本书的时候
			one->bbook[0] = NULL;
		else
		{
			for (int i = 0; i < ((one->bbooknum) + 1 - num); i++)//按照删除位置往后还有的元素个数进行循环，将后面的所有元素向前移动
			{
				one->bbook[num - 1] = one->bbook[num];//向前移动，向前覆盖
			}
		}
		one->bbooknum--;//借到的书减一
		printf("书籍已归还\n");
	}
	return;
}

void func7(Puser one)//查看已经借到的书
{
	if (one->bbooknum == 0)
	{
		printf("您当前未借阅任何书籍！\n");
		system("pause");
		return;
	}
	for (int i = 0; i < one->bbooknum; i++)
	{
		printf("#%d : \n\n", i + 1);
		printf("%s\n\n", one->bbook[i]->bookname);
		printf("%s\n\n", one->bbook[i]->describe);
	}
	//printf("\n\n");
	//setbuf(stdin, NULL);
	system("pause");
	return;
}