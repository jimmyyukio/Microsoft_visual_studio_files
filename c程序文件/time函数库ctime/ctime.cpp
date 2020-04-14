/*
2019年12月21日 20:42:33
*/

# include<stdio.h>
# include<time.h>

int main(void)
{
	
	int test(time_t *);
	time_t T;
	time(&T);
	test(&T);
	printf("%d\n",test(&T));//7607328    2036768 因为时间一直在变动，所以转换以后的字符串也在不停的改变，因此返回的指针也一直在改变
	printf("%s\n",ctime(&T));//输出将time所得到的秒转化为的日历时间
	getchar();
	return 0;
}

char* test(time_t *p)//返回转换后字符串的指针
{
	
	return ctime(p);
	
}