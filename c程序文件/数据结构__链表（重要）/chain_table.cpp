/*
2019年12月23日 20:29:08
2019年12月24日 16:32:51
*/
# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<windows.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
} *PNODE, NODE;//构建节点的结构

/************函数声明部分****************/
PNODE creat_list(void);
void mould_list();
void traverse_list(PNODE);
bool choose(void);
bool is_empty(PNODE);
int length_list(PNODE);//用于测量目前链表长度，为后续提供数据
bool insert_list(PNODE pHead,int pos,int val);//pos提供要插入的位置，val用于存放要输入的数据
bool delete_list(PNODE pHead , int pos , int *pval);//pval用于取回被删除的元素的数据，pos用于确定要删除的元素的位置
void sort_list(PNODE pHead);
/****************************************/
void test1(void)



int main(void)
{
	PNODE pHead = NULL;
	int val;
	int len = 0;

	pHead = creat_list();
	void mould_list(pHead);//用于调用功能
	//traverse_list(pHead);
	//增强功能用于判断当前链表是否为空链表
	//if(choose())
		//is_empty(pHead);
	//printf("当前链表长度为：%d",len);
	
	
	Sleep(2 * 1000);
	getchar();
	return 0;
}



PNODE creat_list(void)//创建链表
{
	int len;//用于存放有效节点个数
	int i;//临时变量
	int val;//用于存放新生成结点要被赋予的值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//生成头结点，pHead中存储的是链表头结点的第一个字节的地址
	if (pHead == NULL)
	{
		printf("头结点内存分配失败，链表生成失败！\n");
		Sleep(3 * 1000);//延时三秒以后退出程序
		exit(-1);
	}
	PNODE Ptail = pHead;//定义一个临时的struct Node类型的指针,pHead和Ptail两个同类型指针之间进行赋值，使Ptail也指向头结点
	//Ptail是为了代替pHead作为一个临时指针，一直指向最后一个结点，以防丢失链表的头结点地址。
	Ptail->pNext = NULL;//清空头结点（Ptail也指向头结点）的指针域（初始化）

	printf("请输入要生成的链表的有效节点数：");
	scanf("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值：", i + 1);
		scanf("%d", &val);

		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		/*
		复习动态内存的分配：PNODE pnew = (PNODE)malloc(sizeof(NODE)); -》struct Node* pnew = (struct Node*)malloc(sizeof（NODE）);
				因为malloc函数只能够将第一个字节的地址作为返回值返回给pnew,所以pnew必须是指针类型
		详见“结构体的内存分配与指针问题”中的测试结果并且malloc是通过(struct Node*)来向后寻找字节数。pnew也是这个
		动态分配的结构体的变量名。
		*/
		if (pnew == NULL)
		{
			printf("节点分配失败，即将退出程序！");
			Sleep(3 * 1000);
			exit(-1);
		}
		pnew->data = val;//将val赋值给新节点的数据域
		Ptail->pNext = pnew;//将新节点的地址赋值给上一个节点的指针域
		pnew->pNext = NULL;//清空新节点的指针域（初始化）
		Ptail = pnew;//将新节点的地址赋值给Ptail，使临时指针Ptail指向新生成的节点
	}

	return pHead;//返回头结点的地址，用于寻找链表的头结点
}

void traverse_list(PNODE pHead)//遍历链表一次
{
	PNODE p = pHead->pNext;//定义一个临时的指针，将头结点的指针域中所存放的地址赋值给临时指针

	while (NULL != p)//只要指针指向的地址不为空，就会不断循环
	{
		printf("%d", p->data);
		p = p->pNext;//将指针指向下一个节点
	}
	printf("\n");
	return;//即使没有返回值也用return;表明此函数已经结束，方便辨认
}

bool is_empty(PNODE pHead)//检查链表是否为空
{
	if(pHead->pNext = NULL)//如果头结点的指针域指向空则返回真值
		return true;
	else
		return false;
}

bool choose(void)//对是否需要检查链表进行选择
{
	int a;
	printf("\n\n请问是否要检测当前链表是否为空?\n");
	printf("1.是\n");
	printf("2.否\n");
A:
	printf("请输入序号：");
	scanf("%d",&a);
	
	if(a == 1)
		return true;
	else if(a == 2)
		return false;
	else
	{
		printf("您的输入有误请重新输入正确的序号！");
		goto A;
	}
}

int length_list(PNODE pHead)//为排序做准备，提供长度数据
{
	int len = 0;
	PNODE p = pHead->pNext;
	
	while(p != NULL)
	{
		++len;
		p = p->pNext;
	}
	
	return len;//返回链表长度
}

bool insert_list(PNODE pHead,int pos,int val)//插入新的节点
{
	int i;
	PNODE p = pHead;//将临时指针p指向头结点
	
	while(p != NULL && i < pos-1)//将指针移向要插入的位置的前面的一个结点；   &&与； ||或者
	{
		p = p->pNext;
		++i;
	}
	
	if(i > pos-1 || p = NULL)//如果指针指向为空或者
		return false;
	
	PNODE pNew  = (PNODE)malloc(sizeof(NODE));
	if(pNew = NULL)
	{
		printf("内存不足，分配失败！");
		exit(-1);
	}
	pNew->data = val;//将要赋的值存入新的节点中
	PNODE q = p->pNext;//为断开原来的链表准备，用一个临时的指针指向要插入位置的后面一个节点，以防链表丢失
	p->pNext = pNew;//将新的节点与前面的节点相连
	pNew->pNext = q;//将新节点与后面的一个节点相连
	
	return true;
}

bool delete_list(PNODE pHead, int pos ,int *pval)//删除一个结点
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

/* void sort_list(PNODE pHead)//排序
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

void mould_list(PNODE pHead)//用于接收头结点的地址，功能选择区块
{
	int a;
	
	
	printf("接下来将要进行的操作");
	printf("1. 加入新的数据");
	printf("2. 删除数据");
	printf("3. 查看当前所有的数据信息");
	printf("4. 对当前的数据信息进行排序");
	printf("5. 清除链表数据");
	printf("6. 销毁链表，并退出");
	printf("请输入序号：");
	
	scanf("%d",&a);
	
	switch(a)
	{
		case 1://加入新的数据
		    test1(pHead);//需要头结点地址
			break;
		case 2://删除数据
			  test2(pHead);
			break;
		case 3://查看当前所有的数据信息
		    traverse_list(pHead);
			break;
		case 4://对当前的数据信息进行排序
				//test3
			break;
		case 5://清除链表数据
				//test4
			break;
		case 6://销毁链表，并退出
				//test5
			break;
			
	}
}
/* 
void test1(PNODE pHead)
{
	int pos;
	int val;
	printf("请输入要插入的位置：");
	scanf("%d",&pos);
	printf("请输入要插入的数据：");
	scanf("%d",&val)
	insert_list(PONDE pHead,int pos,int val)
	if(insert_list(PONDE pHead,int pos,int val))
}

void test2(PNODE pHead)
{

	
} */