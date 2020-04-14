# include<stdio.h>

void huhuan(int * p,int *q)
{
	int t;
	    t = *p;
		* p = *q;
		*q = t;	
}

int main(void)
{
	int a = 4;
	int b = 8;
	huhuan(&a, &b);
	printf("a = %d b = %d\n", a, b);
	return 0;
}