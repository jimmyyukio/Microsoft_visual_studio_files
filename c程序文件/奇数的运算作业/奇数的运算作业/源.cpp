# include<stdio.h>
int main(void)
{   //第一个
	int i;
	int sum = 0;
	for (i = 0;i <= 100; i+=2)
		sum = sum + i;
	printf("sum = %d\n", sum);

	//第二个
	int num = 0;
	
	for (i = 1;i <= 100;i += 2)
		num = num + 1;
	printf("sum = %d\n", num);
	
	//第三个
	float average;
	
	average = sum / num;
	printf("average = %f", average);
	
	
	
	return 0;
}

