# include<stdio.h>
# include<malloc.h>
struct A
{
	int i ;
	int j ;

};
int main(void)
{
	struct A* p = (struct A*)malloc(sizeof(struct A));//1   p�洢�˸ÿ鶯̬�ڴ�ռ�ĵ�ַ��
	struct A* c = (struct A*)malloc(sizeof(struct A));//2   c........
	printf("������p��i��ֵ ��");
	scanf_s("%d", &(*p).i, 3);
	printf("i = %d\n", (*p).i);
	printf("������c��i��ֵ ��");
	scanf("%d", &(*c).i);
	printf("i = %d\n", (*c).i);
	free(p);
	free(c);
}
/*
2019.12.6  19��24
    ���ۣ���̬�ڴ�ķ����javaһ��1��2���ڶ��з��������鲻ͬ�Ŀռ䣬�໥������
*/