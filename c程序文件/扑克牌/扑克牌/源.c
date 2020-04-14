#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define CARDSIZE 52   /*牌的总张数*/
#define SUITSIZE 13   /*一色牌的张数*/
/*扑克牌结构*/
typedef struct Card
{
	char val;/*扑克牌面上的大小*/
	int  kind : 4; /*扑克牌的花色*/
}Card;
/*************************************************
  Function:       // riffle
  Description:    // 洗牌,然后随机的得到9张牌,要求九张牌不能有重复.
  Calls:          //
  Called By:      // main()
  Table Accessed: //被修改的表（此项仅对于牵扯到数据库操作的程序）
  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
  Input:          //Card card[]  牌结构, int size  结构数组的大小
  Output:         //
  Return:         // void
  Others:         // 此函数修改card[]的值,希望得到九张随机牌
  Bug:            //此函数有bug，有时会产生两个相同的牌，有待修订
*************************************************/
void riffle(Card* cards, int size);
/*************************************************
  Function:       // show
  Description:    // 显示数组的内容
  Calls:          //
  Called By:      // main()
  Table Accessed: //被修改的表（此项仅对于牵扯到数据库操作的程序）
  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
  Input:          //Card *card  牌结构指针, int size  结构数组的大小
  Output:         //
  Return:         // void
  Others:         //
*************************************************/
void show(const Card* cards, int size);
/*************************************************
  Function:       // grouping
  Description:    //把9张牌分别放到3个数组中,每组3张,a.e分组
  Calls:          //
  Called By:      // main()
  Table Accessed: //被修改的表（此项仅对于牵扯到数据库操作的程序）
  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
  Input:          //Card *card  牌结构指针, int size  结构数组的大小
  Output:         //
  Return:         // void
  Others:         // 此函数修改 *carr1,*carr2,* carr3的值
*************************************************/
void grouping(const Card* cards, Card* carr1, Card* carr2, Card* carr3);
/*************************************************
  Function:       // result_process
  Description:    //用递归计算,所选的牌
  Calls:          // rshift
  Called By:      // main()
  Table Accessed: //被修改的表（此项仅对于牵扯到数据库操作的程序）
  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
  Input:          //Card *carr1, Card *carr2, Card *carr3
  Output:         //
Return:         // void
  Others:         // 此函数修改 *carr1,*carr2,* carr3的值
*************************************************/
Card* result_process(Card* carr1, Card* carr2, Card* carr3, int counter);
/*************************************************
  Function:       // rshift
  Description:    //右移操作
  Calls:          //
  Called By:      // result_process
  Table Accessed: //被修改的表（此项仅对于牵扯到数据库操作的程序）
  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
  Input:          //Card *carr1, Card *carr2, Card *carr3 ,int counter
  Output:         //
  Return:         // Card*
  Others:         // 此函数修改 *carr1,*carr2,* carr3的值
*************************************************/
void rshift(Card* carr1, Card* carr2, Card* carr3, int counter);
void main()
{
	Card cards[9]; /*存放九张牌*/
	Card carr1[3]; /*第一组牌,cards array 1*/
	Card carr2[3]; /*第二组牌,cards array 2*/
	Card carr3[3]; /*第三组牌,cards array 3*/
	int select = 0; /*玩家的选择*/
	Card* selected_card;/*存放玩家所记住(选)的牌*/
	int counter = 0;

	riffle(cards, 9); /*洗牌,得到九张牌*/
	puts("请记住一张牌千万别告诉我!最多经过下面三次我与你的对话,我就会知道你所记的那张牌!");
	puts("如果想继续玩,请准确的回答我问你的问题,根据提示回答!");
	puts("请放心,我不会问你你选了哪张牌的!");
	grouping(cards, carr1, carr2, carr3); /*把9张牌分别放到3个数组中,每组3张,a.e分组*/
	show(carr1, 3);
	show(carr2, 3);
	show(carr3, 3);
	puts("请告诉我你记住的那张牌所在行数");
	select = getchar();
	switch (select)/*分支猜你玩家记住的牌*/
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
		puts("你在撒谎！不和你玩了！");
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
	puts("你猜的牌为:");
	show(selected_card, 1);
	puts("我猜的对吧,哈哈~~~~");
	fflush(stdin);
	getchar();
}
/*riffle的原代码*/
void riffle(Card* cards, int size)
{
	char deck[CARDSIZE];/*临时数组，用于存储牌*/
	unsigned int seed;/*最为产生随机数的种的*/
	int deckp = 0; /*在牌的产生中起着指示作用*/

	seed = (unsigned int)time(NULL);
	srand(seed);

	/*洗牌*/
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

	/*找9张牌给card*/
	for (deckp = 0; deckp < size; deckp++)
	{
		div_t card = div(deck[deckp], SUITSIZE);
		cards[deckp].val = "A23456789TJQK"[card.rem]; /*把余数给card.val*/
		cards[deckp].kind = "3456"[card.quot]; /*把商给card.kind*/
	}
}
/*show的原代码，将会自动换行*/
void show(const Card* cards, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c%c  ", cards[i].kind, cards[i].val);
		if ((i != 0) && (((i + 1) % 3) == 0))
			puts("");
	}
	puts(""); /*自动换行*/
}
/*grouping 的原代码*/
void grouping(const Card * cards, Card * carr1, Card * carr2, Card * carr3)
{
	int i = 0;/*循环参数*/

	/*分给carr1三个数*/
	while (i < 3)
	{
		carr1[i].val = cards[i].val;
		carr1[i].kind = cards[i].kind;
		i++;
	}
	/*分给carr2接下来的三个数*/
	while (i < 6)
	{
		carr2[i - 3].val = cards[i].val;
		carr2[i - 3].kind = cards[i].kind;
		i++;
	}
	/*分给carr3接下来的三个数*/
	while (i < 9)
	{
		carr3[i - 6].val = cards[i].val;
		carr3[i - 6].kind = cards[i].kind;
		i++;
	}
}
/*rshift的实现*/
void rshift(Card * carr1, Card * carr2, Card * carr3, int counter)
{
	Card temp2;/*用于存放carr2[counter]*/
	Card temp3;/*用于存放carr3[counter]*/
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
	rshift(carr1, carr2, carr3, counter); /* 把数组的第一个元素依次右移*/
	if (counter == 2)
	{
		return(&carr2[2]);
	}
	show(carr1, 3);
	show(carr2, 3);
	show(carr3, 3);
	puts("请给出你记住的牌所在行数:");
	fflush(stdin);
	int input = 1;
	input = getchar(); /*获取你选的组*/
	switch (input)
	{
	case '1':
		return(result_process(carr1, carr2, carr3, ++counter));
		break;
	case '2':
		return(&carr2[counter]);
		break;
	default:
		puts("你在撒谎！不和你玩了！");
		return NULL;
	}
}
