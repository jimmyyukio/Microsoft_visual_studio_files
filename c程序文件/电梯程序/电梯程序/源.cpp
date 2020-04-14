# include<stdio.h>
int main(void)
{
	int val;
	int num;
	printf("请输入要去的层数 val = ");
	scanf("%d", &val);
	switch (val)
	{
	case 1:
		printf("第一层门开\n");
		printf("请输入要去的房间号 num = ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("1号房间已解锁");
			break;
		case 2:
			printf("2号房间已解锁");
			break;
		}
		break;
	case 2:
		printf("第二层门开");
		break;
	case 3:
		printf("第三层门开");
		break;
	default:
		printf("没有此层");
		break;
	}
	return 0;
}