# include<stdio.h>
int main(void)
{
	int i = 5;
	int j = 10;
	int* p = &i;
	int* q = &j;
	int c;
	int a[5] = {1,2,3,4,5};
	 p = &a[1];
	 q = &a[4];
	 c = q - p;
	 printf("�������%d���ַ�"��c);
 

	return 0;
}
