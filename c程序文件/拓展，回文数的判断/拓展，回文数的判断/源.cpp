# include<stdio.h>
int main(void)
{
	int m, val;
	int sum = 0;
	printf("������һ���������ж����Ƿ�Ϊ������  val =");
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
			printf("�ǻ�����!\n");
		else
			printf("���ǻ�����!\n");
	return 0;
}