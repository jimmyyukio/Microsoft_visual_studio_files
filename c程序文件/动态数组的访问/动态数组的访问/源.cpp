/*
��дʱ�䣺 2019.12.18   9��43
*/
# include<stdio.h>
# include<malloc.h>
int main(void)
{
	//test1
	int len;
	int k;
	int j;
	int i = 0;
	printf("��������Ҫ�����鳤�ȣ�");
	scanf_s("%d", &len);
	int* aprr = (int*)malloc(sizeof(int) * len);
	
	for (j = 0; j < len; j++)
	{
		i++;
		printf("�����������ֵ��%d��Ԫ�ص�ֵ��", i);
		scanf_s("%d", &aprr[j],len);
	}
	/*printf("��������Ҫ�鿴��Ԫ��λ��(Ԫ����Ŵ�0��ʼ)��");
	scanf_s("%d", &k,len);
	printf("��%d��Ԫ��Ϊ��%d\n\n",(k+1) ,aprr[k]);*/
	//ʹ���±���з���
	//test2
	int u;
	int o;
D:
	printf("��������Ҫ�޸ĵ�Ԫ���ǵڼ�����");
	scanf_s("%d", &u,len);
	getchar();//��Ϊgetchar���Զ���ȡ��һ�������еĻس������ᵼ�³������һ����ѭ��������ʹ��һ��getchar������������һ�������еĻس���
	printf("ȷ��Ҫ�޸ĵ�%d��Ԫ���𣿣�'Y'or'N'��\n",u);
	if (getchar() == 'Y')
		goto C;
	else if (getchar() == 'N')
		return 0;
	else
		goto D;
C:
	printf("��������Ҫ�޸�Ϊ��");
	scanf_s("%d", &o, len);
	*(aprr + (u-1)) = o;
	printf("�޸ĺ������Ϊ��");
	for (j = 0; j < len; ++j)
	{
		printf("%d ", *(aprr + j));
	}
	//ʹ��ָ����з���

	free(aprr);

	return 0;
}
/*
���ۣ�*��aprr + 1���ȼ��� aprr[1]      *aprr ���� aprr[0]
*/