# include<stdio.h>
int main(void)
{
	bool Isprime(int i);
	int val;
	char ch[3];
	do
	{
		printf("������һ��ֵ val= ");
		scanf_s("%d", &val);//��һ��
		if (Isprime(val))
			printf("yes\n");
		else
			printf("NO\n");
		ch[3] = getchar();
	} while (ch[3] = getchar("yes") !='\n');
	return 0;
}

bool Isprime(int i)
{
	int k;
	for (k = 2;k < i;++k)
		if (i % k == 0)
			break;
	if (i == k)
		return true;
	else
		return false;

}