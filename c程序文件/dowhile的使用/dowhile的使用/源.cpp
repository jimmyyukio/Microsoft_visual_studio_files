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
			printf("������a ,b ,c ����ֵ\n");

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
				printf("�˷�����������ͬ�Ľ�\n  x1 = %lf\n x2 = %lf\n", x1, x2);

			}
			else if (delta == 0)
			{
				x1 = x2 = (-b) / (2 * a);
				printf("�˷�����������ͬ�Ľ�\n x1 = x2 = %lf\n", x1, x2);
			}
			else 
			{
				printf("�˷����޽�\n");
			}
			printf("�����ֹͣ����������off = 0,�������������������� off = 1\n");
			printf("off = ");
			scanf_s("%d", &off);
		}
	} while ( off == 1);
	
	return 0;
}