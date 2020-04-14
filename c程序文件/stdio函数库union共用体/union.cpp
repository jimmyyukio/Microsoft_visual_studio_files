/*
2019年12月20日22:13:07
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
结论：union共用体使用方法和struct相似但是union定义的共用体一次只能够存储共用体中的一个变量在
给另一个变量赋值的时候会将上一个赋值的变量覆盖。
*/