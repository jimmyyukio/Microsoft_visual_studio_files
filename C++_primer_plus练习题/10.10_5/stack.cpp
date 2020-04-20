# include<iostream>
# include"func1.h"

bool stack::isfull()
{
	if (top == bottom + 10)
		return true;
	else
		return false;
}

bool stack::isempty()
{
	if (top == bottom)
		return true;
	else
		return true;
}

bool stack::push(pcus item)
{
	if (top == bottom + 10)
	{
		std::cout << "Õ»ÒÑÂú£¡" << std::endl;
		return false;
	}
	*top = item;
	top++;
	num++;
	return true;
}

bool stack::pop()
{
	if (bottom == top)
	{
		std::cout << "Õ»Îª¿Õ£¡\n" << std::endl;
		return false;
	}
	top--;
	num--;
	total += (*top)->payment;
	std::cout << "Now total is : " << total << std::endl
			<< "The stack surplus element have : " << num << std::endl;
	return true;
}