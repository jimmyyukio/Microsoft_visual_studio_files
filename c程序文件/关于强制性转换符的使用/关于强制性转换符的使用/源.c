# include<stdio.h>
int main(void)
{
	int i;//���ﲻ�ܹ�ʹ��float����������������Ϊfloat��ֵ��һ������ֵ������Щ���ֽ��д洢ʱ��������
	float sum = 0;
	if (i = 1 ; i <= 100; ++i)
	{
		sum = sum + 1 / (float)(i);//��i��ֵǿ��ת��Ϊ������
	}
	printf("sum = %f\n", sum);

	return 0;
}