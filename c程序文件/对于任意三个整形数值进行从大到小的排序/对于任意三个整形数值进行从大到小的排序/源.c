# include<stdio.h>
# include<stdlib.h>
int main(void)
{
	printf("请输入三个数值，中间使用空格分开\n");
	int a, b, c;
	int t;//暂时使用的暂存函数，用于数值交换
	scanf_s("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		t = a;//将a的数值暂时赋值给t
		a = b;
		b = t;//将a的暂存值赋值给b
	}
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}