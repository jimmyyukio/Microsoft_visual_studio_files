# include<iostream>
# include"head.h"

int main(void)
{
	Move one = Move(4,7);
	one.showmove();

	one = one.add(one);
	one.showmove();

	one.reset();
	one.showmove();

	return 0;
}