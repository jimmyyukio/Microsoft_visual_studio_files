# include<stdio.h>
//# include<malloc.h>
# include<stdlib.h>

typedef struct node
{
	int data;
	//int score;
}*PNODE,NODE;//����һ����������

int main(void)
{
	
	//printf("test\n");
	NODE a;//����һ������a
	a.data = 2;
	//printf("hello\n");
	printf("a.data = %d\n",a.data);
	
	NODE c;
	c.data = 60;
	//ָ��1
	PNODE B;
	printf("%d\n",B);//16
	B = &c;
	//ָ��2
	PNODE P = NULL;//ָ������
	printf("%d\n",P);//0
	P = &a;
	P->data = 10;
	printf("%d\n",P->data);//10
	
	
	/*
	PNODE b ;
	b->data = 2;//����PNODE b ��һ��struct node ���͵�ָ��
	*/
	
	P = B;
	printf("%d",P->data);//60,����ָ��֮�丳ֵ
	
	printf("\n\n\n\n\n\n");
	
	//test2
	
	//int Hu = (int)malloc(5);//error
	//int Hu = (int*)malloc(5);//error
	int* Hu = (int*)malloc(5);
	printf("%d",sizeof(Hu));
	
	
	
	
	getchar();
	return 0;
	
}