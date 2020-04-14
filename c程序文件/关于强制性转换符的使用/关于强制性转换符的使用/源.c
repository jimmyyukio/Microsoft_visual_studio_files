# include<stdio.h>
int main(void)
{
	int i;//这里不能够使用float进行声明变量，因为float的值是一个近似值，在有些数字进行存储时会产生误差
	float sum = 0;
	if (i = 1 ; i <= 100; ++i)
	{
		sum = sum + 1 / (float)(i);//将i的值强制转换为浮点型
	}
	printf("sum = %f\n", sum);

	return 0;
}