# include<stdio.h>
int main(void)
{
	int i;
	float sum = 0;
	for (i = 3;i <= 10; ++i)//++i代表的是i+1
	     sum = sum + 1/(float)(i);
	printf("sum = %f\n", sum);

	return 0;
}
//结论：++i仅代表i+1，其累加值与i本身无关