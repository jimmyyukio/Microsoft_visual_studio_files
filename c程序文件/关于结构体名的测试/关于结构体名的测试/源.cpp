/*
测试时间：  2019.12.17   16：40
*/
# include<stdio.h>
//1
struct student
{
	int age;
	char sex[5];
	char name[100];
	
}st;
//2
struct female
{
	char name[100];
	int high;

};
//3
struct male
{
	char name[100];
	int high;

}ml , ml1, ml2;

int main(void)
{
	printf("test 1\n");
    st = { 6,"男","zhangsan" };
	printf(" age = %d\n sex = %s\n name = %s\n", st.age, st.sex, st.name);//正确在构造结构体的同时写上了一个变量名，可以直接使用该变量名
	printf("\n\n\n");
	struct student st2 = { 8,"女","lili" };
	printf(" age = %d\n sex = %s\n name = %s\n", st2.age, st2.sex, st2.name);//一个已经在构造结构体同时给予了一个变量名的结构体还可以继续创造其他的对象（变量名）。
	printf("\n\n\n");
	printf("test 2\n");
	struct female st3 = { "yukio",150 };
	//struct female = {"yukio",150};是错误的必须要有一个变量名。
	printf("test 3\n");
	ml = { "Y",200 };
	ml1 = { "z",150 };
	ml2 = { "H",163 };
	printf(" name = %s\n high = %d\n",ml.name,ml.high);
	printf(" name = %s\n high = %d\n", ml2.name, ml2.high);//第三个结构体说明了在结构体的结尾处可以同时创造多个变量名并使用
	return 0;
}