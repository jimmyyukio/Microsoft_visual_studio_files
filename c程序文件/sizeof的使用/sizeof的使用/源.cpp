# include<stdio.h>
int main(void)
{
	char ch = 'A';
	int i = 10;
	double x = 16.6;
	char* p = &ch;
	int* q = &i;
	double* k = &x;
	printf("%d %d %d\n", sizeof(p), sizeof(q), sizeof(k));
	printf("%d %d %d\n", sizeof(ch), sizeof(i), sizeof(x));

	return 0;
}