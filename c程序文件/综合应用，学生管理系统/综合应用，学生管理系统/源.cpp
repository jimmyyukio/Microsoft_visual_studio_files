# include<stdio.h>
# include<malloc.h>

struct student
{
	int age;
	float score;
	char name[100];

};

int main(void)
{
	struct student* parr;
	int len;
	struct student t;
	int i, j;
	printf("=======================\n");
    printf("请输入学生个数：");
	scanf_s("%d", &len);
	printf("=======================\n\n\n");
	parr = (struct student *)malloc(4 * sizeof(struct student));

	for(i = 0;i < len;++i)
	{
		printf("***********************\n");
		printf("请输入第%d个学生的信息：\n", (i + 1));
		printf("age = ");
		scanf_s("%d", &parr[i].age,3);
		printf("score = ");
		scanf_s("%f", &parr[i].score,3);
		printf("name = ");
		scanf("%s", parr[i].name);
		printf("***********************\n");
		printf("\n\n");
	}
	for (i = 0;i < len - 1;++i)
	{
		for (j = 0;j < len - 1 - i;++j)
		{
			if (parr[j].score > parr[j + 1].score)
			{
				t = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = t;
			}
		}

	}
	printf("\n \n学生信息如下：\n");
	for (i = 0;i < len; ++i)
	{
		printf("*********************\n");
		printf("第%d位学生：\n", i + 1);
		printf("age = %d\n", parr[i].age);
		printf("score = %f\n", parr[i].score);
		printf("name = %s\n", parr[i].name);
		printf("*********************\n");
		printf("\n");
	}
	return 0;
}