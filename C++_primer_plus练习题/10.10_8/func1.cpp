# include<iostream>
# include"head.h"

bool list::is_empty()
{
	if (phead == lp)
	{
		std::cout << "����Ϊ�� ��" << std::endl;
		return true;
	}
	else
		return false;
}

list::list()
{
	phead = new node;//����һ��ͷ���
	phead->next = NULL;//��ʼ��ָ����
	lp = phead;
	nodenum = 0;
}

bool list::creatnode(const std::string name , const double value)
{
	PNODE tem;
	tem = new node;
	if ( !tem )
		return false;
	// ��ʼ�� [4/21/2020 14257]
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
		p = p->next;//ָ��Ҫɾ���Ľ��ǰһ�����
	temnode = p->next;//��Ҫɾ���Ľ��ĵ�ַ���ݸ���ʱ���ָ��
	
	if (p->next->next != NULL)//���ɾ��Ԫ�غ���Ԫ��
		p->next = p->next->next;//��Ҫɾ���Ľ���ǰһ�����ͺ�һ�����������
	else//����ֱ�ӶϿ�����
		p->next = NULL;
	nodenum--;
	return temnode;
}

bool list::insert(int fposition)
{
	PNODE p = phead;
	for (int i = 0; i < fposition; i++)
		p = p->next;//����λ��ǰһ�����

	// �����½�� [4/21/2020 14257]
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

	if ( p->next != NULL )//���������Ԫ��
	{
		newnode->next = p->next;
		p->next = newnode;
	}
	else
		p->next = newnode;


	// ǰ����½�������� [4/21/2020 14257]
	nodenum++;
	return true;
}