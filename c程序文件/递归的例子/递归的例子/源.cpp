# include<stdio.h>
int main(void)
{
	int age(int i);
	int n;
	printf("�������n��ͬѧ����� n = ");
	scanf_s("%d", &n);
	printf("������ͬѧ������Ϊ��%d\n", age(n));

	return 0;
}

int age(int i)
{
	int c;
	if (i == 1)
	{
		c = 10;
		return c;
	}
	else
	{
		c = age(i - 1) + 2;
		return c;
	}

}