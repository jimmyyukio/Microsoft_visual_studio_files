# include<stdio.h>
int main(void)
{
	int i;
	int ch;
	printf("请输入i的值 i = ");
	scanf_s("%d", &i);
	printf("i = %d\n", i);

	while ((ch = getchar()) != '\n')
		continue;//对于非法字符输入的处理

	printf("请输入c的值 c = ");
	int c;
	scanf_s("%d", &c);
	printf("c = %d\n", c);

	return 0;
}