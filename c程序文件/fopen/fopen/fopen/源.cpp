# include<stdio.h>
#define DIR "D:\\����ļ�\\c�ļ�\\fopen\\test.txt"
int main(void)
{
	int i;
	i = 20;
	char M[3] = { 'H','E','L' };
	FILE* A = NULL;
	A = fopen(DIR, "w");
	if (A = NULL)
	{
		return -1;
	}
	fwrite(&M, sizeof(int), 1, A);

	fclose(A);
	A = NULL;
	return 0;
}