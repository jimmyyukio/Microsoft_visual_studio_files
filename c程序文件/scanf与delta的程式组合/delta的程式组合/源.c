# include<stdio.h>
# include<math.h>
int main(void)
{
	int a ;
	int b ;
	int c ;
	scanf("%d %d %d", &a,&b,&c);
	float delta;
	float x1;
	float x2;
	delta = b * b - 4 * a * c;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		printf("此方程包含两个解，x1 = %f,x2 = %f\n", x1, x2);
	}
	else if (delta == 0)
	{
		x1 = (-b) / (2 * a);
		x2 = x1;
		printf("此方程有唯一解，x1 = x2 = %f\n", x1, x2);
	}
	else
		printf("此方程无解\n");


	return 0;
}