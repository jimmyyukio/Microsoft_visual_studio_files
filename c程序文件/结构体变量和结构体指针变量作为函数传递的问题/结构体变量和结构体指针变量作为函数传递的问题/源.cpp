# include<stdio.h>
# include<string.h>

struct student
{
	int age;
	char sex;
	char name[100];
};



int main(void)
{
	void Inputstudent(struct student* );
	void Outputstudent(struct student* );
	struct student st;
	Inputstudent(& st);
	Outputstudent(& st);
	return 0;

}

void Inputstudent (struct student* pstu)
{
	(*pstu).age = 12;
	pstu->sex = 'F';
	strcpy(pstu->name, "¼×");
}

void Outputstudent (struct student const* ss)
{
	printf("%d %c %s\n", ss->age, ss->sex, ss->name);

}