/*
2019��12��20��22:13:07
*/
# include<stdio.h>

union A
{
	int i;
	int j;
	char name;
}st;
int main(void)
{
	st.i = 10;
	printf("st.i = %d\n", st.i);//10
	st.j = 30;
	printf("st.j = %d\n", st.j);//30
	printf("st.i = %d\n", st.i);//30
	st.name = 'i';
	printf("st.name = %c\n", st.name);//i
	printf("st.j = %d\n", st.j);//105
    printf("st.j = %c",st.j);//i

	getchar();
	return 0;
}

/*
���ۣ�union������ʹ�÷�����struct���Ƶ���union����Ĺ�����һ��ֻ�ܹ��洢�������е�һ��������
����һ��������ֵ��ʱ��Ὣ��һ����ֵ�ı������ǡ�
*/