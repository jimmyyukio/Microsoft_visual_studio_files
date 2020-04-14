# include<stdio.h>
int main(void)
{
	int age(int i);
	int n;
	printf("请输入第n名同学的序号 n = ");
	scanf_s("%d", &n);
	printf("第五名同学的年龄为：%d\n", age(n));

	return 0;
}

int age(int i)
{
	int c;
	if (i == 1)
	{
		c = 10;
		return c;
	}
	else
	{
		c = age(i - 1) + 2;
		return c;
	}

}