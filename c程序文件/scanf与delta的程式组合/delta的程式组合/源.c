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
		printf("�˷��̰��������⣬x1 = %f,x2 = %f\n", x1, x2);
	}
	else if (delta == 0)
	{
		x1 = (-b) / (2 * a);
		x2 = x1;
		printf("�˷�����Ψһ�⣬x1 = x2 = %f\n", x1, x2);
	}
	else
		printf("�˷����޽�\n");


	return 0;
}