# include<iostream>
# include"func1.h"

int main(void)
{
	stack STACK = stack();//´´½¨Õ»
	pcus one = new cus;
	one->fullname = "jimmy";
	one->payment = 1000;
	STACK.push(one);

	pcus two = new cus;
	two->fullname = "yukio";
	two->payment = 4000;
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);
	STACK.push(two);

	STACK.pop();
	STACK.pop();
	STACK.pop();

	system("pause");
	return 0;
}
