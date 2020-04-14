# include<stdio.h>
# include<malloc.h>
int main(void)
{
	void f(int** q);
	int* p;
	f(&p);
	printf("%d\n", *p);

	return 0;
}

void f(int** q)
{
	*q = (int*)malloc(sizeof(int));
	**q = 5;
	
}