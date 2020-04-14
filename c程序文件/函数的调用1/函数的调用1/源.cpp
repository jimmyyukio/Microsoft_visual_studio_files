# include<stdio.h>
//程序设计从n个数中将素数挑选出来
int main(void)
{
	void Isprime(int i);//函数的声明
	int val;

	printf("请输入val的值 val = ");
	scanf_s("%d", &val);
	Isprime(val);//将val的值发送给形式参数i

	return 0;
}
//被除数的循环
void Isprime(int i)
{
	int k;//定义被除数
	int j;//定义除数
	for (k = 2; k <= i; ++k)//被除数循环
	{
		for (j = 2; j <k;++j)//除数循环
			if (0 == k%j)
				break;//如果在达到k值之前取余数为0则退出循环
		if (k == j)/*退出循环后零时值j为上个循环中的j+1，判断此时的j值是否与被除数k相等，若是
				   从break退出循环则一定为非素数，若是由循环条件退出循环则为素数*/
			printf("k=%d\n",k);//将判断所得到的素数输出
	}

}



