# include<stdio.h>
# include"head.h"
# include<stdlib.h>

Puser creatuser();
PStack creatstack();
void putmenu_one(Puser);
void putmenu_two(Puser , PStack);

int main(void)
{
	Puser one = creatuser();//�����û�����
	PStack two = creatstack();//�������

	putmenu_one(one);//��һ����¼
	putmenu_two(one,two);//�ڶ���ѡ��ִ�в���

	return 0;
}