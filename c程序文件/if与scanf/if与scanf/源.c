# include <stdio.h>

int main(void)
{
	int i;
		scanf("%d", &i);
	
		double delta = i;

		if (delta > 6)
			printf("有两个不同的解\n");
		else if (delta == 6)
		printf("有两个相同的解\n");
		else
			printf("无解\n");

	return 0;
}