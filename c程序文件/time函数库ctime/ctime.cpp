/*
2019��12��21�� 20:42:33
*/

# include<stdio.h>
# include<time.h>

int main(void)
{
	
	int test(time_t *);
	time_t T;
	time(&T);
	test(&T);
	printf("%d\n",test(&T));//7607328    2036768 ��Ϊʱ��һֱ�ڱ䶯������ת���Ժ���ַ���Ҳ�ڲ�ͣ�ĸı䣬��˷��ص�ָ��Ҳһֱ�ڸı�
	printf("%s\n",ctime(&T));//�����time���õ�����ת��Ϊ������ʱ��
	getchar();
	return 0;
}

char* test(time_t *p)//����ת�����ַ�����ָ��
{
	
	return ctime(p);
	
}