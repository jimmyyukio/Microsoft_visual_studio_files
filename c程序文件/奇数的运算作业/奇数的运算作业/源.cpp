# include<stdio.h>
int main(void)
{   //��һ��
	int i;
	int sum = 0;
	for (i = 0;i <= 100; i+=2)
		sum = sum + i;
	printf("sum = %d\n", sum);

	//�ڶ���
	int num = 0;
	
	for (i = 1;i <= 100;i += 2)
		num = num + 1;
	printf("sum = %d\n", num);
	
	//������
	float average;
	
	average = sum / num;
	printf("average = %f", average);
	
	
	
	return 0;
}

