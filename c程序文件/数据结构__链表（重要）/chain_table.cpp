/*
2019��12��23�� 20:29:08
2019��12��24�� 16:32:51
*/
# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<windows.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
} *PNODE, NODE;//�����ڵ�Ľṹ

/************������������****************/
PNODE creat_list(void);
void mould_list();
void traverse_list(PNODE);
bool choose(void);
bool is_empty(PNODE);
int length_list(PNODE);//���ڲ���Ŀǰ�����ȣ�Ϊ�����ṩ����
bool insert_list(PNODE pHead,int pos,int val);//pos�ṩҪ�����λ�ã�val���ڴ��Ҫ���������
bool delete_list(PNODE pHead , int pos , int *pval);//pval����ȡ�ر�ɾ����Ԫ�ص����ݣ�pos����ȷ��Ҫɾ����Ԫ�ص�λ��
void sort_list(PNODE pHead);
/****************************************/
void test1(void)



int main(void)
{
	PNODE pHead = NULL;
	int val;
	int len = 0;

	pHead = creat_list();
	void mould_list(pHead);//���ڵ��ù���
	//traverse_list(pHead);
	//��ǿ���������жϵ�ǰ�����Ƿ�Ϊ������
	//if(choose())
		//is_empty(pHead);
	//printf("��ǰ������Ϊ��%d",len);
	
	
	Sleep(2 * 1000);
	getchar();
	return 0;
}



PNODE creat_list(void)//��������
{
	int len;//���ڴ����Ч�ڵ����
	int i;//��ʱ����
	int val;//���ڴ�������ɽ��Ҫ�������ֵ

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//����ͷ��㣬pHead�д洢��������ͷ���ĵ�һ���ֽڵĵ�ַ
	if (pHead == NULL)
	{
		printf("ͷ����ڴ����ʧ�ܣ���������ʧ�ܣ�\n");
		Sleep(3 * 1000);//��ʱ�����Ժ��˳�����
		exit(-1);
	}
	PNODE Ptail = pHead;//����һ����ʱ��struct Node���͵�ָ��,pHead��Ptail����ͬ����ָ��֮����и�ֵ��ʹPtailҲָ��ͷ���
	//Ptail��Ϊ�˴���pHead��Ϊһ����ʱָ�룬һֱָ�����һ����㣬�Է���ʧ�����ͷ����ַ��
	Ptail->pNext = NULL;//���ͷ��㣨PtailҲָ��ͷ��㣩��ָ���򣨳�ʼ����

	printf("������Ҫ���ɵ��������Ч�ڵ�����");
	scanf("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ��", i + 1);
		scanf("%d", &val);

		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		/*
		��ϰ��̬�ڴ�ķ��䣺PNODE pnew = (PNODE)malloc(sizeof(NODE)); -��struct Node* pnew = (struct Node*)malloc(sizeof��NODE��);
				��Ϊmalloc����ֻ�ܹ�����һ���ֽڵĵ�ַ��Ϊ����ֵ���ظ�pnew,����pnew������ָ������
		������ṹ����ڴ������ָ�����⡱�еĲ��Խ������malloc��ͨ��(struct Node*)�����Ѱ���ֽ�����pnewҲ�����
		��̬����Ľṹ��ı�������
		*/
		if (pnew == NULL)
		{
			printf("�ڵ����ʧ�ܣ������˳�����");
			Sleep(3 * 1000);
			exit(-1);
		}
		pnew->data = val;//��val��ֵ���½ڵ��������
		Ptail->pNext = pnew;//���½ڵ�ĵ�ַ��ֵ����һ���ڵ��ָ����
		pnew->pNext = NULL;//����½ڵ��ָ���򣨳�ʼ����
		Ptail = pnew;//���½ڵ�ĵ�ַ��ֵ��Ptail��ʹ��ʱָ��Ptailָ�������ɵĽڵ�
	}

	return pHead;//����ͷ���ĵ�ַ������Ѱ�������ͷ���
}

void traverse_list(PNODE pHead)//��������һ��
{
	PNODE p = pHead->pNext;//����һ����ʱ��ָ�룬��ͷ����ָ����������ŵĵ�ַ��ֵ����ʱָ��

	while (NULL != p)//ֻҪָ��ָ��ĵ�ַ��Ϊ�գ��ͻ᲻��ѭ��
	{
		printf("%d", p->data);
		p = p->pNext;//��ָ��ָ����һ���ڵ�
	}
	printf("\n");
	return;//��ʹû�з���ֵҲ��return;�����˺����Ѿ��������������
}

bool is_empty(PNODE pHead)//��������Ƿ�Ϊ��
{
	if(pHead->pNext = NULL)//���ͷ����ָ����ָ����򷵻���ֵ
		return true;
	else
		return false;
}

bool choose(void)//���Ƿ���Ҫ����������ѡ��
{
	int a;
	printf("\n\n�����Ƿ�Ҫ��⵱ǰ�����Ƿ�Ϊ��?\n");
	printf("1.��\n");
	printf("2.��\n");
A:
	printf("��������ţ�");
	scanf("%d",&a);
	
	if(a == 1)
		return true;
	else if(a == 2)
		return false;
	else
	{
		printf("������������������������ȷ����ţ�");
		goto A;
	}
}

int length_list(PNODE pHead)//Ϊ������׼�����ṩ��������
{
	int len = 0;
	PNODE p = pHead->pNext;
	
	while(p != NULL)
	{
		++len;
		p = p->pNext;
	}
	
	return len;//����������
}

bool insert_list(PNODE pHead,int pos,int val)//�����µĽڵ�
{
	int i;
	PNODE p = pHead;//����ʱָ��pָ��ͷ���
	
	while(p != NULL && i < pos-1)//��ָ������Ҫ�����λ�õ�ǰ���һ����㣻   &&�룻 ||����
	{
		p = p->pNext;
		++i;
	}
	
	if(i > pos-1 || p = NULL)//���ָ��ָ��Ϊ�ջ���
		return false;
	
	PNODE pNew  = (PNODE)malloc(sizeof(NODE));
	if(pNew = NULL)
	{
		printf("�ڴ治�㣬����ʧ�ܣ�");
		exit(-1);
	}
	pNew->data = val;//��Ҫ����ֵ�����µĽڵ���
	PNODE q = p->pNext;//Ϊ�Ͽ�ԭ��������׼������һ����ʱ��ָ��ָ��Ҫ����λ�õĺ���һ���ڵ㣬�Է�����ʧ
	p->pNext = pNew;//���µĽڵ���ǰ��Ľڵ�����
	pNew->pNext = q;//���½ڵ�������һ���ڵ�����
	
	return true;
}

bool delete_list(PNODE pHead, int pos ,int *pval)//ɾ��һ�����
{
	int i = 0;
	PNODE p = pHead;
	
	while(p->pNext != NULL && i < pos-1)
	{
		p = p->pNext;
		++i;
	}
	
	if(i > pos-1 || p -> pNext == NULL)
		return false;
	
	PNODE q = p->pNext;
	*pval = q->data;
	
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	
	return true;
	
}

/* void sort_list(PNODE pHead)//����
{
	int i,j,t;
	int len = length_list(pHead)
	PNODE p,q;
	
	for(i = 0,p = pHead->pNext;i < len-1 ; ++i,p = p->pNext)
	{
		for(j = i+1 ; j < len ; ++j,q = q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
} */

void mould_list(PNODE pHead)//���ڽ���ͷ���ĵ�ַ������ѡ������
{
	int a;
	
	
	printf("��������Ҫ���еĲ���");
	printf("1. �����µ�����");
	printf("2. ɾ������");
	printf("3. �鿴��ǰ���е�������Ϣ");
	printf("4. �Ե�ǰ��������Ϣ��������");
	printf("5. �����������");
	printf("6. �����������˳�");
	printf("��������ţ�");
	
	scanf("%d",&a);
	
	switch(a)
	{
		case 1://�����µ�����
		    test1(pHead);//��Ҫͷ����ַ
			break;
		case 2://ɾ������
			  test2(pHead);
			break;
		case 3://�鿴��ǰ���е�������Ϣ
		    traverse_list(pHead);
			break;
		case 4://�Ե�ǰ��������Ϣ��������
				//test3
			break;
		case 5://�����������
				//test4
			break;
		case 6://�����������˳�
				//test5
			break;
			
	}
}
/* 
void test1(PNODE pHead)
{
	int pos;
	int val;
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&pos);
	printf("������Ҫ��������ݣ�");
	scanf("%d",&val)
	insert_list(PONDE pHead,int pos,int val)
	if(insert_list(PONDE pHead,int pos,int val))
}

void test2(PNODE pHead)
{

	
} */