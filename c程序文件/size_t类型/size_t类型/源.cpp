/*
时间：2019.12.17   21:39
*/
# include<stdio.h>

int main(void)
{
	size_t mylen(const char*);
	char line[] = "hello";
    printf("mylen = %lu\n", mylen(line));//输出值为5
	printf("sizeof = %lu\n", sizeof(line));//输出结果为6，因为sizeof将结尾的'\0'也统计在内，其返回的数据类型和mylen一样是size_t类型
	printf("mylen+sizeof = %d\n",mylen(line)+sizeof(line));//可以进行运算
	return 0;
}

size_t mylen(const char* s)//size_t类型属于一种“整形”，用来记录一个（size）大小的数据类型
{
	int cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}
/*
函数sizeof(),所得到的结构就是size_t类型
因为size_t类型的数据保存的是一个整数，所以可以加减乘除，也可以转化为int类型并赋值给int类型的变量

类似的数据类型还有  wchar_t     ptrdiff_t
*/