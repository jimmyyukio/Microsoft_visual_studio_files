# include<stdio.h>
int main(void)
{
	int i;
	float sum = 0;
	
	for ( i = 2  ; i <= 100 ;++i)
		sum = sum + 1 / (float)(i);
	printf("i = %f\n", sum);

	return 0;
 }