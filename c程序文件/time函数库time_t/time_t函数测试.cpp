/*
2019��12��21�� 17:06:36
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
	time_t TIME;//����һ�������������յ�ǰʱ��,time_t�д���һ����ʼ����1970��1��1��0ʱ0��0�����ʼ�㣨��longlongint����
	time(&TIME);
	printf("%d\n",time);//4205312
	Sleep(5*1000);//����1000���� = 1�� ��mingw����Sleep������sleep
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
