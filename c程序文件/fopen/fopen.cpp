# include<stdio.h>
int main(void)
{
	int i;
	i = 20;
	char M[3] = {'H','E','L'};
	FILE* A = NULL;
	A = fopen("D:\����ļ�\c�ļ�\fopen\test.txt","w");
	if(NULL = A)
	{
		return -1��
	}
	fwrite(&M,"%d",1,A);
	
	fclose(A);
	getchar();
	
	return 0;
}