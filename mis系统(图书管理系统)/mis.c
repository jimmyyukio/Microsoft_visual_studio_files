# include<stdio.h>
# include"head.h"
# include<stdlib.h>

Puser creatuser();
PStack creatstack();
void putmenu_one(Puser);
void putmenu_two(Puser , PStack);

int main(void)
{
	Puser one = creatuser();//创建用户对象
	PStack two = creatstack();//创建书库

	putmenu_one(one);//第一步登录
	putmenu_two(one,two);//第二步选择执行操作

	return 0;
}