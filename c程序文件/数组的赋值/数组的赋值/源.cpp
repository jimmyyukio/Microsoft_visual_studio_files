# include<stdio.h>
int main(void)
{
	int a[5];
	int i;
	printf("请输入数组a[0]的值 a[0] = ");
	scanf_s("%d", &a[0]);
	printf("a[0] = %d\n", a[0]);

	printf("请输入数组a[3]的值 a[3] = ");
	scanf_s("%d", &a[3]);
	printf("a[3] = %d\n", a[3]);

	for (i = 0;i < 5; ++i)
		printf("%d\n", a[i]);

	return 0;
}