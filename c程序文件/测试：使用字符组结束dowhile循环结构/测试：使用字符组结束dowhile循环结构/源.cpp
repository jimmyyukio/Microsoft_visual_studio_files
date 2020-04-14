# include<stdio.h>
# include<string.h>

int main(void)
{
	int i;
	char str1[3] = { 'y','e','s' };
	char str2[3];
	scanf_s("%c %c %c",str2[0],str2[1],str2[2]);
	if (strcmp(str1, str2) == 0)
		printf("h");
	else
		printf("b");
	


	
	return 0;
}

