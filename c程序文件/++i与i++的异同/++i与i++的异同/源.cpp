# include<stdio.h>
int main(void)
{
	printf("����������һ��ֵ i =");
	int i;
	int	k = 0;
	int	 b, j;
	scanf_s("%d", &i);
	k = i;
	printf("δ����֮ǰ��i��k ��  i = %d  k = %d\n", i, k);
	b = i++;
	j = ++k;

	printf("����֮����ĸ�����ֵ  ��k = %d i = %d\n b = %d j = %d",k,i, b, j);

	return 0;
}
/*
���ۣ�δ����֮ǰ��i��k ��  i = 2  k = 2
      ����֮����ĸ�����ֵ  ��k = 3 i = 3
                              b = 2 j = 3
							  
							  */