# include<stdio.h>
# include"head.h"
# include<windows.h>

const int MAX_LEN = 15;

void SetPosition(int x, int y);
void verify(char* username, char* psw, Puser one);
void SetPosition(int x, int y);
void putmenu_one(Puser one);

void SetPosition(int x, int y)//设置光标的位置
{
	HANDLE winHandle;//获取窗口句柄
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);
}

void putmenu_one(Puser one)//一级菜单
{
	printf("***************************************************\n");
	printf("                    --请登录!--                     \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("***************************************************\n");
	printf("[提示：用户名为 jimmy 密码为 1425717639\n");
	printf("[可以故意错误的输入进行测试]\n");
	SetPosition(4, 4);
	printf("请输入账号：");
	char* username = (char*)malloc(sizeof(MAX_LEN));
	scanf("%s", username);
	SetPosition(4, 7);
	printf("请输入密码：");
	char* psw = (char*)malloc(sizeof(MAX_LEN));
	scanf("%s", psw);
	verify(username , psw , one);
	SetPosition(4, 15);
	printf("登录成功！即将进入二级菜单！\n");
	printf("         3...\n");
	Sleep(1000);
	printf("         2...\n");
	Sleep(1000);
	printf("         1...\n");
	Sleep(1000);
}

void verify(char* username , char* psw , Puser one)//验证
{
	if (strcmp(username, one->user))
	{
		SetPosition(54, 5);
		printf("您输入的账号有误！请重新输入");
		Sleep(2 * 1000);
		system("cls");
		putmenu_one(one);//调用
		return ;
	}
	if (strcmp(psw, one->password))
	{
		SetPosition(54, 5);
		printf("您输入的密码有误！请重新输入");
		Sleep(2 * 1000);
		system("cls");
		putmenu_one(one);//调用
		return ;
	}
	
	return ;
}