/*
时间：2019.12.19   21:49
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
	
	int A[8] = {};//错误，无法在定义一个数组之后在执行过程中修改该数组的容量
	
	for(i = 0;i < 8;++i)
	{
		printf(" %d ",A[i]);
		
	}
	
	getchar();
	return 0;
}