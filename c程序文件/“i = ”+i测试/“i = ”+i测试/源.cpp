/*
 * @Author: mikey.jimmy 
 * @Date: 2019-12-22 08:48:45 
 * @Last Modified by: mikey.jimmy
 * @Last Modified time: 2019-12-22 08:51:32
 */

# include<stdio.h>
int main(void)
{
	int i = 10;
	printf("i = " +1);//无法输出i值
	getchar();
	return 0;
}
/* 
解决：2019.12.17    16：37
在java和c#中允许使用“+”（运算重载符）来讲两种不同类型的数据连接起来。
前面的“i = ”是以字符串输出而后面的i输出的是i的数据，组合起来为“i = i（数据）”。
*/