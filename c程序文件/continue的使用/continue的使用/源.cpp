# include<stdio.h>
int main(void)
{
	int i;
	int ch;
	printf("������i��ֵ i = ");
	scanf_s("%d", &i);
	printf("i = %d\n", i);

	while ((ch = getchar()) != '\n')
		continue;//���ڷǷ��ַ�����Ĵ���

	printf("������c��ֵ c = ");
	int c;
	scanf_s("%d", &c);
	printf("c = %d\n", c);

	return 0;
}