# include<stdio.h>
//# include<malloc.h>
# include<stdlib.h>

typedef struct node
{
	int data;
	//int score;
}*PNODE,NODE;//这是一个变量类型

int main(void)
{
	
	//printf("test\n");
	NODE a;//生成一个变量a
	a.data = 2;
	//printf("hello\n");
	printf("a.data = %d\n",a.data);
	
	NODE c;
	c.data = 60;
	//指针1
	PNODE B;
	printf("%d\n",B);//16
	B = &c;
	//指针2
	PNODE P = NULL;//指针清零
	printf("%d\n",P);//0
	P = &a;
	P->data = 10;
	printf("%d\n",P->data);//10
	
	
	/*
	PNODE b ;
	b->data = 2;//错误PNODE b 是一个struct node 类型的指针
	*/
	
	P = B;
	printf("%d",P->data);//60,两个指针之间赋值
	
	printf("\n\n\n\n\n\n");
	
	//test2
	
	//int Hu = (int)malloc(5);//error
	//int Hu = (int*)malloc(5);//error
	int* Hu = (int*)malloc(5);
	printf("%d",sizeof(Hu));
	
	
	
	
	getchar();
	return 0;
	
}