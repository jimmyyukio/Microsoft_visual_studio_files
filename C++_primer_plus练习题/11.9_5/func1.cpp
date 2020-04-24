# include<iostream>
# include"head.h"

stonewt stonewt::operator*(double num)//重载运算符*
{
	stonewt tem;
	double total = st * 14 + lb;//全部转化为石（st）单位
	total = total * num;
	tem.st = total / 14;
	tem.lb = total - tem.st * 14;

	return tem;
}

// 加减以lb为单位 [4/24/2020 yukio]
stonewt stonewt::operator-(double num)
{
	stonewt tem;
	double total = st * 14 + lb;//全部转化为石（st）单位
	total = total - num;
	tem.st = total / 14;
	tem.lb = total - tem.st * 14;

	return tem;
}

stonewt stonewt::operator+(double num)
{
	stonewt tem;
	double total = st * 14 + lb;//全部转化为石（st）单位
	total = total + num;
	tem.st = total / 14;
	tem.lb = total - tem.st * 14;

	return tem;
}

void stonewt::set_mode()
{
	std::cout << "please choose a mode to display" << std::endl
		<< "A) st   B）lb(int)\n"
		<< "C) lb(double)\n";
	char choose;
	std::cin >> choose;
	switch (choose)
	{
	case 'A':
	case'a':
		mode = ST;
		break;
	case 'b':
	case 'B':
		mode = LB;
		break;
	case 'c':
	case 'C':
		mode = DLB;
		break;
	}
}

std::ostream& operator<<(std::ostream& os, stonewt& one)
{

	if (one.mode == one.ST)
	{
		os << "ST : " << int(one.st) << " LB : " << int(one.lb) << std::endl;
	}
	else if (one.mode == one.LB)
	{
		os << "LB : " << int(one.st * 14 + one.lb) << std::endl;
	}
	else if(one.mode == one.DLB)
	{
		os << "DLB : " << one.st * 14 + one.lb << std::endl;
	}
	else
	{
		std::cout << "error ! \n";
	}
	return os;
}

int main(void)
{
	stonewt one = stonewt(10.5, 8.42);
	stonewt two = one * 2;
	two.set_mode();
	std::cout << two << std::endl;

	return 0;
}