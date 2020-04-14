# include<stdio.h>
# include<math.h>
int main(void)
{
	double a, b, c;
	double delta;
	double x1, x2;
	int off;
	do
	{


		
		{
			printf("请输入a ,b ,c 三个值\n");

			printf("a = ");
			scanf_s("%lf", &a);

			printf("b = ");
			scanf_s("%lf", &b);

			printf("c = ");
			scanf_s("%lf", &c);


			delta = b * b - 4 * a * c;

			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("此方程有两个不同的解\n  x1 = %lf\n x2 = %lf\n", x1, x2);

			}
			else if (delta == 0)
			{
				x1 = x2 = (-b) / (2 * a);
				printf("此方程有两个相同的解\n x1 = x2 = %lf\n", x1, x2);
			}
			else 
			{
				printf("此方程无解\n");
			}
			printf("如果想停止运行请输入off = 0,若想程序继续进行请输入 off = 1\n");
			printf("off = ");
			scanf_s("%d", &off);
		}
	} while ( off == 1);
	
	return 0;
}