/*
ʱ�䣺2019.12.19   21:49
*/
# include<stdio.h>

int main(void)
{
	int A[5] = {1,2,3,4,5,};
	int i;
	for(i = 0;i < 5;++i)
	{
		printf(" %d ",A[i]);
		
	}
	
	int A[8] = {};//�����޷��ڶ���һ������֮����ִ�й������޸ĸ����������
	
	for(i = 0;i < 8;++i)
	{
		printf(" %d ",A[i]);
		
	}
	
	getchar();
	return 0;
}