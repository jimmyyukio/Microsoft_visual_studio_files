# include<stdio.h>
//������ƴ�n�����н�������ѡ����
int main(void)
{
	void Isprime(int i);//����������
	int val;

	printf("������val��ֵ val = ");
	scanf_s("%d", &val);
	Isprime(val);//��val��ֵ���͸���ʽ����i

	return 0;
}
//��������ѭ��
void Isprime(int i)
{
	int k;//���屻����
	int j;//�������
	for (k = 2; k <= i; ++k)//������ѭ��
	{
		for (j = 2; j <k;++j)//����ѭ��
			if (0 == k%j)
				break;//����ڴﵽkֵ֮ǰȡ����Ϊ0���˳�ѭ��
		if (k == j)/*�˳�ѭ������ʱֵjΪ�ϸ�ѭ���е�j+1���жϴ�ʱ��jֵ�Ƿ��뱻����k��ȣ�����
				   ��break�˳�ѭ����һ��Ϊ��������������ѭ�������˳�ѭ����Ϊ����*/
			printf("k=%d\n",k);//���ж����õ����������
	}

}



