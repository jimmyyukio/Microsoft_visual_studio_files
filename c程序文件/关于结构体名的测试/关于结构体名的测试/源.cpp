/*
����ʱ�䣺  2019.12.17   16��40
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
    st = { 6,"��","zhangsan" };
	printf(" age = %d\n sex = %s\n name = %s\n", st.age, st.sex, st.name);//��ȷ�ڹ���ṹ���ͬʱд����һ��������������ֱ��ʹ�øñ�����
	printf("\n\n\n");
	struct student st2 = { 8,"Ů","lili" };
	printf(" age = %d\n sex = %s\n name = %s\n", st2.age, st2.sex, st2.name);//һ���Ѿ��ڹ���ṹ��ͬʱ������һ���������Ľṹ�廹���Լ������������Ķ��󣨱���������
	printf("\n\n\n");
	printf("test 2\n");
	struct female st3 = { "yukio",150 };
	//struct female = {"yukio",150};�Ǵ���ı���Ҫ��һ����������
	printf("test 3\n");
	ml = { "Y",200 };
	ml1 = { "z",150 };
	ml2 = { "H",163 };
	printf(" name = %s\n high = %d\n",ml.name,ml.high);
	printf(" name = %s\n high = %d\n", ml2.name, ml2.high);//�������ṹ��˵�����ڽṹ��Ľ�β������ͬʱ��������������ʹ��
	return 0;
}