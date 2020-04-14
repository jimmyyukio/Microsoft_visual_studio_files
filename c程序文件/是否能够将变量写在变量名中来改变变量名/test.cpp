/*
2019年12月20日20:14:43
*/

# include<stdio.h>
 int main(void)
 {
 	int i;
	int j = 1;
 	for(i = 0 ; i < 4; ++i)
 		{
 			int Ai = j;
 			printf("A%d = %d\n",i,Ai);
			j = j + 2;
 		}
 	
 	getchar();
 	return 0;
 }
 /*
 结论：该程序说明在变量名中可以使用变量来不断改变改变变量名从而创建新的变量
 */