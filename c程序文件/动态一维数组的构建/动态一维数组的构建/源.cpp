# include<stdio.h>
# include<malloc.h>
int main(void)
{
	int a[5];
	int len;
	int* parr;
	int i;
	
	printf("请输入要在此数组中存放的元素个数: ");
	scanf_s("%d", &len);
	parr = (int*)malloc(4 * len);

	printf("请输入要存放的元素： \n");
	for(i = 0; i < len; ++i)
		scanf_s("%d", &parr[i]);
	printf("该数组中的元素有:");
	for (i = 0; i < len;++i)
		printf(" %d ", parr[i]);
	
	free(parr);
	return 0;
}