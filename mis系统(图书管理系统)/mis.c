# include<stdio.h>
# include"head.h"
# include<stdlib.h>

int main(void)
{
	Puser one = creatuser();//�����û�����
	PStack two = creatstack();//�������

	putmenu_one(one);//��һ����¼
	putmenu_two(one,two);//�ڶ���ѡ��ִ�в���

	return 0;
}

//����
//PStack test = two;
//while (test->next != NULL)
//{
//	test = test->next;
//	printf("%s\n", (test->point->bookname));
//}