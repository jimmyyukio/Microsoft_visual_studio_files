# include<stdio.h>
int main(void)
{
	int i;
	int sum = 0;
	for (i = 1 ;i <= 100; i += 2)//�ȼ���i= i+2
	{
		sum = sum + i;
	}
	printf("sum = %d\n", sum);
	printf("i = %d\n", i);

	return 0;
}