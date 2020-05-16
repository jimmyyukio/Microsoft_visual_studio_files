# include<stdlib.h>
# include<stdio.h>
# include<windows.h>

# define MAX_LEN 20//最大名字长度

typedef struct MyNode
{
	int ID;//车子的编号
	char Name[40];//车子的名字
	int price;//车子的价格
	int ByYear;//购买的时间
	int weight;//重量
	struct MyNode* next;
}CAR, * PCAR;

PCAR initdata(void);//初始化对象
void mainmune(PCAR);//功能菜单
void printmenu(void);//打印菜单
void ReadFronmFile(PCAR);//从外部读入数据
void WriteToFile(PCAR);//数据同步
void Display(PCAR);//显示所有的数据
void InputRecord(PCAR);//写入数据
void DeleteRecord(PCAR);//删除指定数据
void Finddata(PCAR);//搜索数据
void changedata(PCAR);//更改数据
void printmenu2(void);//二级菜单
void displaymassage(PCAR);
PCAR position(PCAR);

int main(void)
{
	PCAR phead = initdata();
	mainmune(phead);//进入主菜单
	//system("pause");
	return 0;
}

void mainmune(PCAR phead)
{
	static int status = 1;
	while (status)
	{
		printmenu();
		printf("请输入您的选择：");
		char choose;
		fflush(stdin);
		scanf("%c", &choose);
		switch (choose)
		{
		case '1'://读入数据
			system("cls");
			ReadFronmFile(phead);
			system("cls");
			break;
		case '2'://同步数据
			system("cls");
			WriteToFile(phead);
			system("cls");
			break;
		case '3'://显示所有数据
			system("cls");
			Display(phead);
			system("cls");
			break;
		case '4'://添加数据
			system("cls");
			InputRecord(phead);
			system("cls");
			break;
		case '5'://删除数据
			system("cls");
			DeleteRecord(phead);
			system("cls");
			break;
		case '6'://查找数据
			system("cls");
			Finddata(phead);
			system("cls");
			break;
		case '7'://改写数据
			system("cls");
			changedata(phead);
			system("cls");
			break;
		case '8':
			system("cls");
			printf("感谢您的使用，即将退出程序！\n");
			Sleep(2 * 1000);
			status = 0;
			break;
		default:
			system("cls");
			printf("非法的输入！\n");
			Sleep(1 * 1000);
			system("cls");
			//printmenu();
			break;
		}
	}
}

void printmenu()
{
	printf("***************************************************\n");
	printf("                     --请选择--                     \n");
	printf("\n");
	printf("		（1）读入数据\n");
	printf("\n");
	printf("		（2）同步数据\n");
	printf("\n");
	printf("		（3）显示当前库中所有的数据\n");
	printf("\n");
	printf("		（4）添加数据\n");
	printf("\n");
	printf("		（5）删除数据\n");
	printf("\n");
	printf("		（6）查找数据\n");
	printf("\n");
	printf("		（7）改写数据\n");
	printf("\n");
	printf("		（8）退出程序\n");
	printf("\n");
	printf("***************************************************\n");
}


PCAR initdata()//启动时对程序的初始化
{
	PCAR phead = (PCAR)malloc(sizeof(CAR));
	phead->next = NULL;
	return phead;
}

void ReadFronmFile(PCAR phead)//从外部读取数据
{
	PCAR lp = phead;//定义一个临时指针
	while (lp->next != NULL)//如读取时库中数据不为空，这将临时指针移动到最后一个结点的位置
	{
		lp = lp->next;
	}
	FILE* fp = fopen("./message.txt", "rt");
	if (fp == NULL)//若外部文件不存在
	{
		printf("外部文件不存在！");
		Sleep(1 * 1000);
		return;
	}
	if (feof(fp))//若文件为空
	{
		printf("外部文件为空文件！");
		Sleep(1 * 1000);
		return;
	}
	else//若文件不为空
	{
		while (!feof(fp))
		{
			PCAR node = (PCAR)malloc(sizeof(CAR));//创建一个新的结点
			node->next = NULL;//初始化指针
			if (node == NULL)
			{
				exit(-1);
			}

			fscanf(fp, "%d %s %d %d %d", &(node->ID), node->Name, &(node->price), &(node->ByYear), &(node->weight));
			lp->next = node;
			lp = lp->next;
			node = NULL;
		}
		fclose(fp);
		system("cls");
		printf("数据读取成功！");
		Sleep(1 * 1000);
	}
	return;
}

void WriteToFile(PCAR phead)
{
	if (phead->next == NULL)//对空库进行处理
	{
		printf("当前库中无任何信息！");
		Sleep(1 * 1000);
		return;
	}
	FILE* fp = fopen("./message.txt", "wt+");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	PCAR tem = phead;
	while (tem->next != NULL)
	{
		tem = tem->next;
		if (tem != phead->next)//第一个数据不加空格
			fputs(" ", fp);
		fprintf(fp, "%d",tem->ID);
		fputs(" ", fp);
		fprintf(fp, "%s", tem->Name);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->price);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->ByYear);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->weight);
	}
	fclose(fp);
	printf("数据同步成功！");
	Sleep(1 * 1000);
	return;

}

void Display(PCAR phead)
{
	PCAR tem = phead;//临时指针
	if (tem->next == NULL)
	{
		printf("当前仓库为空！\n");
		Sleep(1 * 1000);
	}
	else
	{
		int num = 1;
		while (tem->next != NULL)
		{
			tem = tem->next;
			printf("#%d : \n", num);
			printf("ID: %d\n", tem->ID);
			printf("Name: %s\n", tem->Name);
			printf("Price: %d\n", tem->price);
			printf("ByYear: %d\n", tem->ByYear);
			printf("Weight: %d\n\n", tem->weight);
			num++;
		}
	}
	system("pause");
	return;
}

void InputRecord(PCAR phead)
{
	PCAR tem = phead;
	while (tem->next != NULL)
	{
		tem = tem->next;//移动到最后一个结点
	}
	PCAR node = (PCAR)malloc(sizeof(CAR));
	if (node == NULL)
	{
		exit(-1);
	}
	printf("ID:");
	scanf("%d", &(node->ID));
	printf("Name:");
	scanf("%s", node->Name);	
	printf("Price:");
	scanf("%d", &(node->price));	
	printf("ByYear:");
	scanf("%d", &(node->ByYear));	
	printf("weight:");
	scanf("%d", &(node->weight));
	node->next = NULL;
	tem->next = node;
	Sleep(1 * 1000);
	system("cls");
	printf("信息录入成功！\n");
	Sleep(1 * 1000);
	return;
}

void DeleteRecord(PCAR phead)
{
	PCAR tem = phead;//临时指针1
	PCAR tem2 = phead;//临时指针2
	printf("请输入要删的信息在库中的排序位置(输入-1退出)：");
	int num;
	scanf("%d", &num);
	if (num == -1)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		if (tem->next == NULL)//对错误的输入进行处理
		{
			printf("错误的编号！\n");
			Sleep(1 * 1000);
			return;
		}
		tem = tem->next;//tem指针指向到要删除的结点的位置
	}
	while (tem2->next != tem)//tem2移动到要删除的结点的前面
	{
		tem2 = tem2->next;
	}
	if (tem->next == NULL)//若要删除结点的后面为空
	{
		tem2->next = NULL;//直接清空清空指针
		free(tem);//释放所占用的空间
	}
	else 
	{
		tem2->next = tem->next;
		free(tem);
	}
	printf("\n删除成功！\n");
	Sleep(1 * 1000);
	return;
}

void Finddata(PCAR phead)
{
	PCAR tem = phead;
	printf("请输入要查找的零件名字（输入q退出）：");
	char* name = (char*)malloc(MAX_LEN);
	scanf("%s", name);
	if (name == "q")
	{
		exit(-1);
	}
	int position = 1;
	while (tem->next != NULL)
	{
		tem = tem->next;
		if (!strcmp(name, tem->Name))
		{
			system("cls");
			printf("该零件在库中的排序位置为：%d\n", position);
			printf("ID：%d\n", tem->ID);
			printf("name : %s\n", tem->Name);
			printf("price: %d\n",tem->price);
			printf("ByYear: %d\n", tem->ByYear);
			printf("Weight: %d\n", tem->weight);
			system("pause");
			break;
		}
		position++;
		if (tem->next == NULL)//对错误输入进行处理
		{
			system("cls");
			printf("\n没有找零件的任何信息！\n\n");
		}
	}
	return;
}

void changedata(PCAR phead)
{
	printmenu2();
	printf("请输入您的选择：");
	char choose;
	fflush(stdin);
	scanf("%c", &choose);
	PCAR tem;
	int test;
	switch (choose)
	{
	case '1'://修改ID
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("请输入您要修改的ID值：");
		scanf("%d", &test);
		tem->ID = test;
		printf("修改成功！");
		Sleep(1 * 1000);
		system("cls");
		break;
	case '2'://修改价格
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("请输入您要修改的价格：");
		scanf("%d", &test);
		tem->price = test;
		printf("修改成功！");
		Sleep(1 * 1000);
		system("cls");
		break;
	case '3'://修改购买的日期
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("请输入您要修改的购买年份：");
		scanf("%d", &test);
		tem->ByYear = test;
		printf("修改成功！");
		Sleep(1 * 1000);
		system("cls");
		system("cls");
		break;
	case '4'://修改零件的重量
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("请输入您要修改的重量：");
		scanf("%d", &test);
		tem->weight = test;
		printf("修改成功！");
		Sleep(1 * 1000);
		system("cls");
		system("cls");
		break;
	case '5'://退出
		system("cls");
		break;
	default:
		system("cls");
		printf("非法的输入！\n");
		Sleep(1 * 1000);
		system("cls");
		//printmenu();
		break;
	}
	return;
}

void printmenu2()
{
	printf("***************************************************\n");
	printf("              --请选择要进行的操作--                  \n");
	printf("\n");
	printf("  (1)修改ID\n");
	// printf("\n");
	// printf("  (2)修改名字\n");
	printf("\n");
	printf("  (2)修改价格\n");
	printf("\n");
	printf("  (3)修改购买的日期\n");
	printf("\n");
	printf("  (4)修改零件的重量\n");
	printf("\n");
	printf("  (5)退出\n");
	printf("\n");
	printf("***************************************************\n");
}

void displaymassage(PCAR tem)
{
	printf("ID：%d\n", tem->ID);
	printf("name : %s\n", tem->Name);
	printf("price: %d\n", tem->price);
	printf("ByYear: %d\n", tem->ByYear);
	printf("Weight: %d\n", tem->weight);
}

PCAR position(PCAR phead)
{
	PCAR tem = phead;
	printf("请输入要修改的零件在库存中排序的位置：");
	int num;
	scanf("%d", &num);
	int i;
	for (i = 0; i < num; i++)
	{
		if (tem->next == NULL)
		{
			printf("错误的输入！");
			break;
		}
		tem = tem->next;//移动到要修改的位置
	}
	return tem;
}
