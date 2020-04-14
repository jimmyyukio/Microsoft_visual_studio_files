# include<stdio.h>
int main(void)
{
	int m, val;
	int sum = 0;
	printf("请输入一个数字来判断其是否为回文数  val =");
	scanf_s("%d", &val);
	m = val;
		while (m)
		{
			sum = sum * 10 + m % 10;
			printf(" sum = %d\n", sum);
				m /= 10;
				
		}
		printf("sum = %d    val = %d\n", sum, val);
		if (sum == val)
			printf("是回文数!\n");
		else
			printf("不是回文数!\n");
	return 0;
}