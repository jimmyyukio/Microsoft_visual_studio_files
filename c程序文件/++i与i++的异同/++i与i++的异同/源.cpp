# include<stdio.h>
int main(void)
{
	printf("请输入任意一个值 i =");
	int i;
	int	k = 0;
	int	 b, j;
	scanf_s("%d", &i);
	k = i;
	printf("未运算之前的i与k ：  i = %d  k = %d\n", i, k);
	b = i++;
	j = ++k;

	printf("运算之后的四个函数值  ：k = %d i = %d\n b = %d j = %d",k,i, b, j);

	return 0;
}
/*
结论：未运算之前的i与k ：  i = 2  k = 2
      运算之后的四个函数值  ：k = 3 i = 3
                              b = 2 j = 3
							  
							  */