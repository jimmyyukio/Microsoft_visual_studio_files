# include<stdio.h>

int a = 0;
int f(int m, int n)
{
	int i;
	int j;
	
	for (i = 0;i <= m;++i)
	{
		if (m % i == 0)
			for(j = 0;j <= n; ++j)
				if (n % j == 0 && i == j)
				{
					a = i;
					printf("i = %d j = %d", i, j);
				}
	}
	return a;
}

int main(void)
{
	int h(int m, int n);
	int maxcd, mincm;
	int m;
	int n;
	printf("������������m,n������ǵ���С�����������Լ��\n");

	printf("m = ");
	scanf_s("%d", &m,3);
	printf("n = ");
	scanf_s("%d", &n,3);
	
	maxcd = f(m, n);
	printf("���Լ�� = %d", maxcd);

	return 0;
}