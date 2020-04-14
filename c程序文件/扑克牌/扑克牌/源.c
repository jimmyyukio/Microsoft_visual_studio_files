#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define CARDSIZE 52   /*�Ƶ�������*/
#define SUITSIZE 13   /*һɫ�Ƶ�����*/
/*�˿��ƽṹ*/
typedef struct Card
{
	char val;/*�˿������ϵĴ�С*/
	int  kind : 4; /*�˿��ƵĻ�ɫ*/
}Card;
/*************************************************
  Function:       // riffle
  Description:    // ϴ��,Ȼ������ĵõ�9����,Ҫ������Ʋ������ظ�.
  Calls:          //
  Called By:      // main()
  Table Accessed: //���޸ĵı����������ǣ�������ݿ�����ĳ���
  Table Updated:  // ���޸ĵı����������ǣ�������ݿ�����ĳ���
  Input:          //Card card[]  �ƽṹ, int size  �ṹ����Ĵ�С
  Output:         //
  Return:         // void
  Others:         // �˺����޸�card[]��ֵ,ϣ���õ����������
  Bug:            //�˺�����bug����ʱ�����������ͬ���ƣ��д��޶�
*************************************************/
void riffle(Card* cards, int size);
/*************************************************
  Function:       // show
  Description:    // ��ʾ���������
  Calls:          //
  Called By:      // main()
  Table Accessed: //���޸ĵı����������ǣ�������ݿ�����ĳ���
  Table Updated:  // ���޸ĵı����������ǣ�������ݿ�����ĳ���
  Input:          //Card *card  �ƽṹָ��, int size  �ṹ����Ĵ�С
  Output:         //
  Return:         // void
  Others:         //
*************************************************/
void show(const Card* cards, int size);
/*************************************************
  Function:       // grouping
  Description:    //��9���Ʒֱ�ŵ�3��������,ÿ��3��,a.e����
  Calls:          //
  Called By:      // main()
  Table Accessed: //���޸ĵı����������ǣ�������ݿ�����ĳ���
  Table Updated:  // ���޸ĵı����������ǣ�������ݿ�����ĳ���
  Input:          //Card *card  �ƽṹָ��, int size  �ṹ����Ĵ�С
  Output:         //
  Return:         // void
  Others:         // �˺����޸� *carr1,*carr2,* carr3��ֵ
*************************************************/
void grouping(const Card* cards, Card* carr1, Card* carr2, Card* carr3);
/*************************************************
  Function:       // result_process
  Description:    //�õݹ����,��ѡ����
  Calls:          // rshift
  Called By:      // main()
  Table Accessed: //���޸ĵı����������ǣ�������ݿ�����ĳ���
  Table Updated:  // ���޸ĵı����������ǣ�������ݿ�����ĳ���
  Input:          //Card *carr1, Card *carr2, Card *carr3
  Output:         //
Return:         // void
  Others:         // �˺����޸� *carr1,*carr2,* carr3��ֵ
*************************************************/
Card* result_process(Card* carr1, Card* carr2, Card* carr3, int counter);
/*************************************************
  Function:       // rshift
  Description:    //���Ʋ���
  Calls:          //
  Called By:      // result_process
  Table Accessed: //���޸ĵı����������ǣ�������ݿ�����ĳ���
  Table Updated:  // ���޸ĵı����������ǣ�������ݿ�����ĳ���
  Input:          //Card *carr1, Card *carr2, Card *carr3 ,int counter
  Output:         //
  Return:         // Card*
  Others:         // �˺����޸� *carr1,*carr2,* carr3��ֵ
*************************************************/
void rshift(Card* carr1, Card* carr2, Card* carr3, int counter);
void main()
{
	Card cards[9]; /*��ž�����*/
	Card carr1[3]; /*��һ����,cards array 1*/
	Card carr2[3]; /*�ڶ�����,cards array 2*/
	Card carr3[3]; /*��������,cards array 3*/
	int select = 0; /*��ҵ�ѡ��*/
	Card* selected_card;/*����������ס(ѡ)����*/
	int counter = 0;

	riffle(cards, 9); /*ϴ��,�õ�������*/
	puts("���סһ����ǧ��������!��ྭ����������������ĶԻ�,�Ҿͻ�֪�������ǵ�������!");
	puts("����������,��׼ȷ�Ļش������������,������ʾ�ش�!");
	puts("�����,�Ҳ���������ѡ�������Ƶ�!");
	grouping(cards, carr1, carr2, carr3); /*��9���Ʒֱ�ŵ�3��������,ÿ��3��,a.e����*/
	show(carr1, 3);
	show(carr2, 3);
	show(carr3, 3);
	puts("����������ס����������������");
	select = getchar();
	switch (select)/*��֧������Ҽ�ס����*/
	{
	case '1':
		selected_card = result_process(carr1, carr2, carr3, counter);
		break;
	case '2':
		selected_card = result_process(carr2, carr3, carr1, counter);
		break;
	case '3':
		selected_card = result_process(carr3, carr1, carr2, counter);
		break;
	default:
		puts("�������ѣ����������ˣ�");
		fflush(stdin);
		getchar();
		exit(0);
	}
	if (selected_card == NULL)
	{
		fflush(stdin);
		getchar();
		exit(0);
	}
	puts("��µ���Ϊ:");
	show(selected_card, 1);
	puts("�ҲµĶ԰�,����~~~~");
	fflush(stdin);
	getchar();
}
/*riffle��ԭ����*/
void riffle(Card* cards, int size)
{
	char deck[CARDSIZE];/*��ʱ���飬���ڴ洢��*/
	unsigned int seed;/*��Ϊ������������ֵ�*/
	int deckp = 0; /*���ƵĲ���������ָʾ����*/

	seed = (unsigned int)time(NULL);
	srand(seed);

	/*ϴ��*/
	while (deckp < CARDSIZE)
	{
		char num = rand() % CARDSIZE;
		if ((memchr(deck, num, deckp)) == 0)
		{
			assert(!memchr(deck, num, deckp));
			deck[deckp] = num;
			deckp++;
		}
	}

	/*��9���Ƹ�card*/
	for (deckp = 0; deckp < size; deckp++)
	{
		div_t card = div(deck[deckp], SUITSIZE);
		cards[deckp].val = "A23456789TJQK"[card.rem]; /*��������card.val*/
		cards[deckp].kind = "3456"[card.quot]; /*���̸�card.kind*/
	}
}
/*show��ԭ���룬�����Զ�����*/
void show(const Card* cards, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c%c  ", cards[i].kind, cards[i].val);
		if ((i != 0) && (((i + 1) % 3) == 0))
			puts("");
	}
	puts(""); /*�Զ�����*/
}
/*grouping ��ԭ����*/
void grouping(const Card * cards, Card * carr1, Card * carr2, Card * carr3)
{
	int i = 0;/*ѭ������*/

	/*�ָ�carr1������*/
	while (i < 3)
	{
		carr1[i].val = cards[i].val;
		carr1[i].kind = cards[i].kind;
		i++;
	}
	/*�ָ�carr2��������������*/
	while (i < 6)
	{
		carr2[i - 3].val = cards[i].val;
		carr2[i - 3].kind = cards[i].kind;
		i++;
	}
	/*�ָ�carr3��������������*/
	while (i < 9)
	{
		carr3[i - 6].val = cards[i].val;
		carr3[i - 6].kind = cards[i].kind;
		i++;
	}
}
/*rshift��ʵ��*/
void rshift(Card * carr1, Card * carr2, Card * carr3, int counter)
{
	Card temp2;/*���ڴ��carr2[counter]*/
	Card temp3;/*���ڴ��carr3[counter]*/
	/*temp = carr2*/
	temp2.val = carr2[counter].val;
	temp2.kind = carr2[counter].kind;

	/*carr2 = carr1*/
	carr2[counter].val = carr1[counter].val;
	carr2[counter].kind = carr1[counter].kind;

	/*temp3 = carr3*/
	temp3.val = carr3[counter].val;
	temp3.kind = carr3[counter].kind;
	/*carr3 = carr2*/
	carr3[counter].val = temp2.val;
	carr3[counter].kind = temp2.kind;
	/*carr1 = carr3*/
	carr1[counter].val = temp3.val;
	carr1[counter].kind = temp3.kind;
}
Card* result_process(Card * carr1, Card * carr2, Card * carr3, int counter)
{
	rshift(carr1, carr2, carr3, counter); /* ������ĵ�һ��Ԫ����������*/
	if (counter == 2)
	{
		return(&carr2[2]);
	}
	show(carr1, 3);
	show(carr2, 3);
	show(carr3, 3);
	puts("��������ס������������:");
	fflush(stdin);
	int input = 1;
	input = getchar(); /*��ȡ��ѡ����*/
	switch (input)
	{
	case '1':
		return(result_process(carr1, carr2, carr3, ++counter));
		break;
	case '2':
		return(&carr2[counter]);
		break;
	default:
		puts("�������ѣ����������ˣ�");
		return NULL;
	}
}
