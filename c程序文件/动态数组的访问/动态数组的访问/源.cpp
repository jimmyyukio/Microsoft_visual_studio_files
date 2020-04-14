/*
编写时间： 2019.12.18   9：43
*/
# include<stdio.h>
# include<malloc.h>
int main(void)
{
	//test1
	int len;
	int k;
	int j;
	int i = 0;
	printf("请输入你要的数组长度：");
	scanf_s("%d", &len);
	int* aprr = (int*)malloc(sizeof(int) * len);
	
	for (j = 0; j < len; j++)
	{
		i++;
		printf("请输入数组的值第%d个元素的值：", i);
		scanf_s("%d", &aprr[j],len);
	}
	/*printf("请输入想要查看的元素位置(元素序号从0开始)：");
	scanf_s("%d", &k,len);
	printf("第%d个元素为：%d\n\n",(k+1) ,aprr[k]);*/
	//使用下标进行访问
	//test2
	int u;
	int o;
D:
	printf("请输入想要修改的元素是第几个：");
	scanf_s("%d", &u,len);
	getchar();//因为getchar会自动获取上一个输入中的回车符，会导致程序进入一个死循环，所以使用一个getchar（）来回收上一个输入中的回车符
	printf("确定要修改第%d个元素吗？（'Y'or'N'）\n",u);
	if (getchar() == 'Y')
		goto C;
	else if (getchar() == 'N')
		return 0;
	else
		goto D;
C:
	printf("请输入想要修改为：");
	scanf_s("%d", &o, len);
	*(aprr + (u-1)) = o;
	printf("修改后该数组为：");
	for (j = 0; j < len; ++j)
	{
		printf("%d ", *(aprr + j));
	}
	//使用指针进行访问

	free(aprr);

	return 0;
}
/*
结论：*（aprr + 1）等价于 aprr[1]      *aprr 就是 aprr[0]
*/