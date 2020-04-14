# include<stdio.h>
int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[7] = { 100, 23, 45, 67, 89, 010, 342 };
	int c[100] = { 11 , 22 , 33 , 44 , 55 };
	void f(int* Aprr, int len);
	f(a, 5);
	f(b, 7);
	f(c, 100);

	return 0;
}

void f(int* Aprr, int len)
{
	int i;
	for (i = 0;i < len;++i)
		printf("%d ", *(Aprr + i));
	printf("\n");
}