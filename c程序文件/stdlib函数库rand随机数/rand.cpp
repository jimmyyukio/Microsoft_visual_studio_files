/*
2019��12��21�� 17:52:47
*/

# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define RAND_MAX 20//RAND_MAX�궨����<stdlib.h>ͷ�ļ��С�

int main(void)
{
	int b;
	int a = rand();
	printf("%d\n",a);
	srand((unsigned)time(NULL));//�ٲ���
	a = rand();
	printf("%d\n",a);
	
	//test1
	printf("long int :%d\n",sizeof(long int));//4
	printf("long :%d\n",sizeof(long));//4 long ��long int �ļ�д
	
	//test2
	time_t now;
	time(&now);
	printf("now is :%s\n",ctime(&now));
	printf("now is :%s\n",ctime(&now));
	printf("from Greenwich period to now have :%d second\n",time(&now));//once:1576922640  second:1576922653  
	getchar();
	return 0;
}