# include<stdio.h>
# include"head.h"
# include<windows.h>

const int MAX_LEN = 15;

void SetPosition(int x, int y);
void verify(char* username, char* psw, Puser one);
void SetPosition(int x, int y);
void putmenu_one(Puser one);

void SetPosition(int x, int y)//���ù���λ��
{
	HANDLE winHandle;//��ȡ���ھ��
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ�� 
	SetConsoleCursorPosition(winHandle, pos);
}

void putmenu_one(Puser one)//һ���˵�
{
	printf("***************************************************\n");
	printf("                    --���¼!--                     \n");
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
	printf("[��ʾ���û���Ϊ jimmy ����Ϊ 1425717639\n");
	printf("[���Թ�������������в���]\n");
	SetPosition(4, 4);
	printf("�������˺ţ�");
	char* username = (char*)malloc(sizeof(MAX_LEN));
	scanf("%s", username);
	SetPosition(4, 7);
	printf("���������룺");
	char* psw = (char*)malloc(sizeof(MAX_LEN));
	scanf("%s", psw);
	verify(username , psw , one);
	SetPosition(4, 15);
	printf("��¼�ɹ���������������˵���\n");
	printf("         3...\n");
	Sleep(1000);
	printf("         2...\n");
	Sleep(1000);
	printf("         1...\n");
	Sleep(1000);
}

void verify(char* username , char* psw , Puser one)//��֤
{
	if (strcmp(username, one->user))
	{
		SetPosition(54, 5);
		printf("��������˺���������������");
		Sleep(2 * 1000);
		system("cls");
		putmenu_one(one);//����
		return ;
	}
	if (strcmp(psw, one->password))
	{
		SetPosition(54, 5);
		printf("�������������������������");
		Sleep(2 * 1000);
		system("cls");
		putmenu_one(one);//����
		return ;
	}
	
	return ;
}