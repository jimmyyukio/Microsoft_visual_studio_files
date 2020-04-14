/*
2019年12月21日 17:52:47
*/

# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define RAND_MAX 20//RAND_MAX宏定义在<stdlib.h>头文件中。

int main(void)
{
	int b;
	int a = rand();
	printf("%d\n",a);
	srand((unsigned)time(NULL));//再播种
	a = rand();
	printf("%d\n",a);
	
	//test1
	printf("long int :%d\n",sizeof(long int));//4
	printf("long :%d\n",sizeof(long));//4 long 是long int 的简写
	
	//test2
	time_t now;
	time(&now);
	printf("now is :%s\n",ctime(&now));
	printf("now is :%s\n",ctime(&now));
	printf("from Greenwich period to now have :%d second\n",time(&now));//once:1576922640  second:1576922653  
	getchar();
	return 0;
}