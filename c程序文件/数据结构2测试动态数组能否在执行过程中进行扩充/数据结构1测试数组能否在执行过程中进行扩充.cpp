# include<stdio.h>
# include<malloc.h>

/*struct A
{
	int* P;//���ڴ洢����ĵ�һ��Ԫ�صĵ�ַ
	int len;//���ڱ�ʾ����ĳ��ȣ���ǰ��������ڴ��С��
	int cnt;//���ڱ�ʾ��ǰ��ЧԪ�صĸ���
};*/


int main(void)
{
	int len;
	int i;
	//struct A arr;
	scanf("%d",&len);
	int* A = ��int *��malloc(sizeof(int) * len);
	for(i = 0;i < len;++i)
	{
	      printf("%d",A[i]);
	}

	getchar();

	return 0;
}