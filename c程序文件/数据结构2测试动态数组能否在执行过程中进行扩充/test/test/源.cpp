# include<stdio.h>
# include<malloc.h>

struct A
{
	int* P;//用于存储数组的第一个元素的地址
	int len;//用于表示数组的长度（当前所分配的内存大小）
	int cnt;//用于表示当前有效元素的个数
};


int main(void)
{
	void B(int);
	printf("请输入数组的长度：");
	int len;
	int i;
	//struct A arr;
	scanf("%d", &len);
	void B(int len);
	for (i = 0;i < len;++i)
	{
		printf(" %d ", A[i]);
	}
	
	getchar();

	return 0;
}

void B(int len)
{
	int* A = (int*)malloc(sizeof(int) * len);
}