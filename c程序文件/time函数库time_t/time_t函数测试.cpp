/*
2019年12月21日 17:06:36
*/

# include<stdio.h>
# include<time.h>
# include<windows.h>

int main(void)
{
	size_t E;
	int D;
	E = sizeof("jimmy");
	D = sizeof("jimmy");
	printf("%d\n",E);
    printf("%d\n",D);

	//long long int TIME;
	time_t TIME;//定义一个变量用来接收当前时间,time_t中存有一个开始日期1970年1月1日0时0分0秒的起始点（与longlongint区别）
	time(&TIME);
	printf("%d\n",time);//4205312
	Sleep(5*1000);//挂起1000毫秒 = 1秒 在mingw中用Sleep代替了sleep
	printf("%d\n",TIME);//1576927145
	printf("%d\n",&TIME);//6422040
	printf("%d\n",time(&TIME));//1576927145
	printf("\n\n\n\n");
	
/* 	time_t t;
	t = time();
	printf("%s",t); */
	
	getchar();
	return 0;
}
