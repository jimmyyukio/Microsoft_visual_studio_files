# include<stdio.h>
# include<malloc.h>

void test1(int *);
void test2(int *);
//第一次
int* test(void)
{
	int* a = (int *)malloc(sizeof(int));
	*a = 3;
	return a;//返回变量a的第一个字节的地址
	
} 
//第二次
int main(void)
{
	int * P = NULL;
	P = test();//将a的地址赋值给指针P
	
	test1(P);//将a的地址发送至函数test1
	
	
	getchar();
	return 0;
}
//第三次
void test1(int * p)
{
	test2(p);
}
//第四次
void test2(int * P)
{
	printf("%d",*P);
}