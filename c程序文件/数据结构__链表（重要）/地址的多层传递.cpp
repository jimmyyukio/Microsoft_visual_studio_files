# include<stdio.h>
# include<malloc.h>

void test1(int *);
void test2(int *);
//��һ��
int* test(void)
{
	int* a = (int *)malloc(sizeof(int));
	*a = 3;
	return a;//���ر���a�ĵ�һ���ֽڵĵ�ַ
	
} 
//�ڶ���
int main(void)
{
	int * P = NULL;
	P = test();//��a�ĵ�ַ��ֵ��ָ��P
	
	test1(P);//��a�ĵ�ַ����������test1
	
	
	getchar();
	return 0;
}
//������
void test1(int * p)
{
	test2(p);
}
//���Ĵ�
void test2(int * P)
{
	printf("%d",*P);
}