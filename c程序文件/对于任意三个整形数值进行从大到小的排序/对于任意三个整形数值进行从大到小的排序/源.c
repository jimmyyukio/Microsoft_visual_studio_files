# include<stdio.h>
# include<stdlib.h>
int main(void)
{
	printf("������������ֵ���м�ʹ�ÿո�ֿ�\n");
	int a, b, c;
	int t;//��ʱʹ�õ��ݴ溯����������ֵ����
	scanf_s("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		t = a;//��a����ֵ��ʱ��ֵ��t
		a = b;
		b = t;//��a���ݴ�ֵ��ֵ��b
	}
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}