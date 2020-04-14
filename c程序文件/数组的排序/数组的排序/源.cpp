# include<stdio.h>
int main(void)
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int t;
	int x,y;

	x = 0;
	y = 5;

	while (x < y)
	{
		t = a[x];
		a[x] = a[y];
		a[y] = t;
		x++;
		--y;
	}
	
	for (x = 0; x < 6;++x)
		printf("%d\n", a[x]);

	return 0;
}