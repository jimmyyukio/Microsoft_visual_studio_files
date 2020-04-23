# include<iostream>
# include"head.h"

stonewt stonewt::operator*(int num)//ÖØÔØÔËËã·û*
{
	int total = st * 14 + lb;
	total = total * num;
	stonewt tem;
	tem.lb = total % 14;
	total = total / 14;
	tem.st = total;
	return tem;
}

void stonewt::show()
{
	std::cout << "st : " << st << "  " << "lb : " << lb << std::endl;
}

int main(void)
{
	stonewt one = stonewt(10, 8);
	stonewt two = one * 2;
	two.show();


	return 0;
}