# include<stdio.h>
int main(void)
{
	int i;
	float sum = 0;
	for (i = 3;i <= 10; ++i)//++i�������i+1
	     sum = sum + 1/(float)(i);
	printf("sum = %f\n", sum);

	return 0;
}
//���ۣ�++i������i+1�����ۼ�ֵ��i�����޹�