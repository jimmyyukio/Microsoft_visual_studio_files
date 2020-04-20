# include<iostream>
# include"head.h"

Move::Move(double a , double b )
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "x : " << x << " ";
	std::cout << "y : " << y << std::endl;
}

Move Move::add(const Move& m) const//引用对象m
{
	Move two = Move();
	two.x = x + m.x;
	two.y = y + m.y;
	return two;//返回一个对象
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}