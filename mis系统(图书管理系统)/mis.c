# include<stdio.h>
# include"head.h"
# include<stdlib.h>

int main(void)
{
	Puser one = creatuser();//创建用户对象
	PStack two = creatstack();//创建书库

	putmenu_one(one);//第一步登录
	putmenu_two(one,two);//第二步选择执行操作

	return 0;
}

//测试
//PStack test = two;
//while (test->next != NULL)
//{
//	test = test->next;
//	printf("%s\n", (test->point->bookname));
//}