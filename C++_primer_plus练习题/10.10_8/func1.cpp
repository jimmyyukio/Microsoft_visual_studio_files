# include<iostream>
# include"head.h"

bool list::is_empty()
{
	if (phead == lp)
	{
		std::cout << "链表为空 ！" << std::endl;
		return true;
	}
	else
		return false;
}

list::list()
{
	phead = new node;//创建一个头结点
	phead->next = NULL;//初始化指针域
	lp = phead;
	nodenum = 0;
}

bool list::creatnode(const std::string name , const double value)
{
	PNODE tem;
	tem = new node;
	if ( !tem )
		return false;
	// 初始化 [4/21/2020 14257]
	tem->m_name = name;
	tem->m_value = value;
	tem->next = NULL;

	lp->next = tem;
	lp = lp->next;
	nodenum++;
	return true;
}

void list::showlist()
{
	PNODE p = phead;
	for (int i = 0; i < nodenum; i++)
	{
		p = p->next;
		std::cout << "name is : " << p->m_name << std::endl;
		std::cout << "value is : " << p->m_value << std::endl << std::endl;
	}
	//while (p->next != NULL)
	//{
	//	p = p->next;
	//	//std::cout << "name is : " << p->m_name << std::endl;
	//	//std::cout << "value is : " << p->m_value << std::endl << std::endl;
	//	num++;
	//}
}

void list::changename(const int position , const std::string name)
{
	PNODE p = phead;
	for (int i = 0; i < position; i++)
		p = p->next;
	p->m_name = name;
}

void list::changevalue(const int position, const double value)
{
	PNODE p = phead;
	for (int i = 0; i < position; i++)
		p = p->next;
	p->m_value = value;
}

list::PNODE list::re_delete(const int position)
{
	PNODE p = phead;
	
	for (int i = 0; i < position-1; i++)
		p = p->next;//指向要删除的结点前一个结点
	temnode = p->next;//将要删除的结点的地址传递给临时结点指针
	
	if (p->next->next != NULL)//如果删除元素后还有元素
		p->next = p->next->next;//将要删除的结点的前一个结点和后一个结点相连接
	else//否则直接断开连接
		p->next = NULL;
	nodenum--;
	return temnode;
}

bool list::insert(int fposition)
{
	PNODE p = phead;
	for (int i = 0; i < fposition; i++)
		p = p->next;//插入位置前一个结点

	// 创建新结点 [4/21/2020 14257]
	PNODE newnode = new node;
	if ( !newnode )
		return false;
	std::cout << "enter the name of new node : ";
	std::string newname;
	std::cin >> newname;
	newnode->m_name = newname;
	std::cout << "enter the value if new node : ";
	double value;
	std::cin >> value;
	newnode->m_value = value;
	//  [4/21/2020 14257]

	if ( p->next != NULL )//如果后面有元素
	{
		newnode->next = p->next;
		p->next = newnode;
	}
	else
		p->next = newnode;


	// 前后和新结点连接上 [4/21/2020 14257]
	nodenum++;
	return true;
}