# include<stdio.h>
# include<malloc.h>
int main(void)
{
	int a[5];
	int len;
	int* parr;
	int i;
	
	printf("������Ҫ�ڴ������д�ŵ�Ԫ�ظ���: ");
	scanf_s("%d", &len);
	parr = (int*)malloc(4 * len);

	printf("������Ҫ��ŵ�Ԫ�أ� \n");
	for(i = 0; i < len; ++i)
		scanf_s("%d", &parr[i]);
	printf("�������е�Ԫ����:");
	for (i = 0; i < len;++i)
		printf(" %d ", parr[i]);
	
	free(parr);
	return 0;
}