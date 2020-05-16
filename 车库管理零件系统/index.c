# include<stdlib.h>
# include<stdio.h>
# include<windows.h>

# define MAX_LEN 20//������ֳ���

typedef struct MyNode
{
	int ID;//���ӵı��
	char Name[40];//���ӵ�����
	int price;//���ӵļ۸�
	int ByYear;//�����ʱ��
	int weight;//����
	struct MyNode* next;
}CAR, * PCAR;

PCAR initdata(void);//��ʼ������
void mainmune(PCAR);//���ܲ˵�
void printmenu(void);//��ӡ�˵�
void ReadFronmFile(PCAR);//���ⲿ��������
void WriteToFile(PCAR);//����ͬ��
void Display(PCAR);//��ʾ���е�����
void InputRecord(PCAR);//д������
void DeleteRecord(PCAR);//ɾ��ָ������
void Finddata(PCAR);//��������
void changedata(PCAR);//��������
void printmenu2(void);//�����˵�
void displaymassage(PCAR);
PCAR position(PCAR);

int main(void)
{
	PCAR phead = initdata();
	mainmune(phead);//�������˵�
	//system("pause");
	return 0;
}

void mainmune(PCAR phead)
{
	static int status = 1;
	while (status)
	{
		printmenu();
		printf("����������ѡ��");
		char choose;
		fflush(stdin);
		scanf("%c", &choose);
		switch (choose)
		{
		case '1'://��������
			system("cls");
			ReadFronmFile(phead);
			system("cls");
			break;
		case '2'://ͬ������
			system("cls");
			WriteToFile(phead);
			system("cls");
			break;
		case '3'://��ʾ��������
			system("cls");
			Display(phead);
			system("cls");
			break;
		case '4'://�������
			system("cls");
			InputRecord(phead);
			system("cls");
			break;
		case '5'://ɾ������
			system("cls");
			DeleteRecord(phead);
			system("cls");
			break;
		case '6'://��������
			system("cls");
			Finddata(phead);
			system("cls");
			break;
		case '7'://��д����
			system("cls");
			changedata(phead);
			system("cls");
			break;
		case '8':
			system("cls");
			printf("��л����ʹ�ã������˳�����\n");
			Sleep(2 * 1000);
			status = 0;
			break;
		default:
			system("cls");
			printf("�Ƿ������룡\n");
			Sleep(1 * 1000);
			system("cls");
			//printmenu();
			break;
		}
	}
}

void printmenu()
{
	printf("***************************************************\n");
	printf("                     --��ѡ��--                     \n");
	printf("\n");
	printf("		��1����������\n");
	printf("\n");
	printf("		��2��ͬ������\n");
	printf("\n");
	printf("		��3����ʾ��ǰ�������е�����\n");
	printf("\n");
	printf("		��4���������\n");
	printf("\n");
	printf("		��5��ɾ������\n");
	printf("\n");
	printf("		��6����������\n");
	printf("\n");
	printf("		��7����д����\n");
	printf("\n");
	printf("		��8���˳�����\n");
	printf("\n");
	printf("***************************************************\n");
}


PCAR initdata()//����ʱ�Գ���ĳ�ʼ��
{
	PCAR phead = (PCAR)malloc(sizeof(CAR));
	phead->next = NULL;
	return phead;
}

void ReadFronmFile(PCAR phead)//���ⲿ��ȡ����
{
	PCAR lp = phead;//����һ����ʱָ��
	while (lp->next != NULL)//���ȡʱ�������ݲ�Ϊ�գ��⽫��ʱָ���ƶ������һ������λ��
	{
		lp = lp->next;
	}
	FILE* fp = fopen("./message.txt", "rt");
	if (fp == NULL)//���ⲿ�ļ�������
	{
		printf("�ⲿ�ļ������ڣ�");
		Sleep(1 * 1000);
		return;
	}
	if (feof(fp))//���ļ�Ϊ��
	{
		printf("�ⲿ�ļ�Ϊ���ļ���");
		Sleep(1 * 1000);
		return;
	}
	else//���ļ���Ϊ��
	{
		while (!feof(fp))
		{
			PCAR node = (PCAR)malloc(sizeof(CAR));//����һ���µĽ��
			node->next = NULL;//��ʼ��ָ��
			if (node == NULL)
			{
				exit(-1);
			}

			fscanf(fp, "%d %s %d %d %d", &(node->ID), node->Name, &(node->price), &(node->ByYear), &(node->weight));
			lp->next = node;
			lp = lp->next;
			node = NULL;
		}
		fclose(fp);
		system("cls");
		printf("���ݶ�ȡ�ɹ���");
		Sleep(1 * 1000);
	}
	return;
}

void WriteToFile(PCAR phead)
{
	if (phead->next == NULL)//�Կտ���д���
	{
		printf("��ǰ�������κ���Ϣ��");
		Sleep(1 * 1000);
		return;
	}
	FILE* fp = fopen("./message.txt", "wt+");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	PCAR tem = phead;
	while (tem->next != NULL)
	{
		tem = tem->next;
		if (tem != phead->next)//��һ�����ݲ��ӿո�
			fputs(" ", fp);
		fprintf(fp, "%d",tem->ID);
		fputs(" ", fp);
		fprintf(fp, "%s", tem->Name);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->price);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->ByYear);
		fputs(" ", fp);
		fprintf(fp, "%d", tem->weight);
	}
	fclose(fp);
	printf("����ͬ���ɹ���");
	Sleep(1 * 1000);
	return;

}

void Display(PCAR phead)
{
	PCAR tem = phead;//��ʱָ��
	if (tem->next == NULL)
	{
		printf("��ǰ�ֿ�Ϊ�գ�\n");
		Sleep(1 * 1000);
	}
	else
	{
		int num = 1;
		while (tem->next != NULL)
		{
			tem = tem->next;
			printf("#%d : \n", num);
			printf("ID: %d\n", tem->ID);
			printf("Name: %s\n", tem->Name);
			printf("Price: %d\n", tem->price);
			printf("ByYear: %d\n", tem->ByYear);
			printf("Weight: %d\n\n", tem->weight);
			num++;
		}
	}
	system("pause");
	return;
}

void InputRecord(PCAR phead)
{
	PCAR tem = phead;
	while (tem->next != NULL)
	{
		tem = tem->next;//�ƶ������һ�����
	}
	PCAR node = (PCAR)malloc(sizeof(CAR));
	if (node == NULL)
	{
		exit(-1);
	}
	printf("ID:");
	scanf("%d", &(node->ID));
	printf("Name:");
	scanf("%s", node->Name);	
	printf("Price:");
	scanf("%d", &(node->price));	
	printf("ByYear:");
	scanf("%d", &(node->ByYear));	
	printf("weight:");
	scanf("%d", &(node->weight));
	node->next = NULL;
	tem->next = node;
	Sleep(1 * 1000);
	system("cls");
	printf("��Ϣ¼��ɹ���\n");
	Sleep(1 * 1000);
	return;
}

void DeleteRecord(PCAR phead)
{
	PCAR tem = phead;//��ʱָ��1
	PCAR tem2 = phead;//��ʱָ��2
	printf("������Ҫɾ����Ϣ�ڿ��е�����λ��(����-1�˳�)��");
	int num;
	scanf("%d", &num);
	if (num == -1)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		if (tem->next == NULL)//�Դ����������д���
		{
			printf("����ı�ţ�\n");
			Sleep(1 * 1000);
			return;
		}
		tem = tem->next;//temָ��ָ��Ҫɾ���Ľ���λ��
	}
	while (tem2->next != tem)//tem2�ƶ���Ҫɾ���Ľ���ǰ��
	{
		tem2 = tem2->next;
	}
	if (tem->next == NULL)//��Ҫɾ�����ĺ���Ϊ��
	{
		tem2->next = NULL;//ֱ��������ָ��
		free(tem);//�ͷ���ռ�õĿռ�
	}
	else 
	{
		tem2->next = tem->next;
		free(tem);
	}
	printf("\nɾ���ɹ���\n");
	Sleep(1 * 1000);
	return;
}

void Finddata(PCAR phead)
{
	PCAR tem = phead;
	printf("������Ҫ���ҵ�������֣�����q�˳�����");
	char* name = (char*)malloc(MAX_LEN);
	scanf("%s", name);
	if (name == "q")
	{
		exit(-1);
	}
	int position = 1;
	while (tem->next != NULL)
	{
		tem = tem->next;
		if (!strcmp(name, tem->Name))
		{
			system("cls");
			printf("������ڿ��е�����λ��Ϊ��%d\n", position);
			printf("ID��%d\n", tem->ID);
			printf("name : %s\n", tem->Name);
			printf("price: %d\n",tem->price);
			printf("ByYear: %d\n", tem->ByYear);
			printf("Weight: %d\n", tem->weight);
			system("pause");
			break;
		}
		position++;
		if (tem->next == NULL)//�Դ���������д���
		{
			system("cls");
			printf("\nû����������κ���Ϣ��\n\n");
		}
	}
	return;
}

void changedata(PCAR phead)
{
	printmenu2();
	printf("����������ѡ��");
	char choose;
	fflush(stdin);
	scanf("%c", &choose);
	PCAR tem;
	int test;
	switch (choose)
	{
	case '1'://�޸�ID
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("��������Ҫ�޸ĵ�IDֵ��");
		scanf("%d", &test);
		tem->ID = test;
		printf("�޸ĳɹ���");
		Sleep(1 * 1000);
		system("cls");
		break;
	case '2'://�޸ļ۸�
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("��������Ҫ�޸ĵļ۸�");
		scanf("%d", &test);
		tem->price = test;
		printf("�޸ĳɹ���");
		Sleep(1 * 1000);
		system("cls");
		break;
	case '3'://�޸Ĺ��������
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("��������Ҫ�޸ĵĹ�����ݣ�");
		scanf("%d", &test);
		tem->ByYear = test;
		printf("�޸ĳɹ���");
		Sleep(1 * 1000);
		system("cls");
		system("cls");
		break;
	case '4'://�޸����������
		system("cls");
		tem = position(phead);
		displaymassage(tem);
		printf("��������Ҫ�޸ĵ�������");
		scanf("%d", &test);
		tem->weight = test;
		printf("�޸ĳɹ���");
		Sleep(1 * 1000);
		system("cls");
		system("cls");
		break;
	case '5'://�˳�
		system("cls");
		break;
	default:
		system("cls");
		printf("�Ƿ������룡\n");
		Sleep(1 * 1000);
		system("cls");
		//printmenu();
		break;
	}
	return;
}

void printmenu2()
{
	printf("***************************************************\n");
	printf("              --��ѡ��Ҫ���еĲ���--                  \n");
	printf("\n");
	printf("  (1)�޸�ID\n");
	// printf("\n");
	// printf("  (2)�޸�����\n");
	printf("\n");
	printf("  (2)�޸ļ۸�\n");
	printf("\n");
	printf("  (3)�޸Ĺ��������\n");
	printf("\n");
	printf("  (4)�޸����������\n");
	printf("\n");
	printf("  (5)�˳�\n");
	printf("\n");
	printf("***************************************************\n");
}

void displaymassage(PCAR tem)
{
	printf("ID��%d\n", tem->ID);
	printf("name : %s\n", tem->Name);
	printf("price: %d\n", tem->price);
	printf("ByYear: %d\n", tem->ByYear);
	printf("Weight: %d\n", tem->weight);
}

PCAR position(PCAR phead)
{
	PCAR tem = phead;
	printf("������Ҫ�޸ĵ�����ڿ���������λ�ã�");
	int num;
	scanf("%d", &num);
	int i;
	for (i = 0; i < num; i++)
	{
		if (tem->next == NULL)
		{
			printf("��������룡");
			break;
		}
		tem = tem->next;//�ƶ���Ҫ�޸ĵ�λ��
	}
	return tem;
}
