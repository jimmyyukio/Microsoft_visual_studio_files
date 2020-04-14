# include<stdio.h>
# include<malloc.h>
struct A
{
	int i ;
	int j ;

};
int main(void)
{
	struct A* p = (struct A*)malloc(sizeof(struct A));//1   p存储了该块动态内存空间的地址。
	struct A* c = (struct A*)malloc(sizeof(struct A));//2   c........
	printf("请输入p中i的值 ：");
	scanf_s("%d", &(*p).i, 3);
	printf("i = %d\n", (*p).i);
	printf("请输入c中i的值 ：");
	scanf("%d", &(*c).i);
	printf("i = %d\n", (*c).i);
	free(p);
	free(c);
}
/*
2019.12.6  19：24
    结论：动态内存的分配和java一样1和2是在堆中分配了两块不同的空间，相互独立。
*/