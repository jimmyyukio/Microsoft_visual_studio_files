# include<iostream>
# include"mytime3.h"

int main(void)
{
	Time one = Time(2, 40);
	Time two = Time(1, 30);
	std::cout << one - two << std::endl << std::endl;
	std::cout << one + two << std::endl << std::endl;
	std::cout << one * two << std::endl << std::endl;


	system("pause");
	return 0;
}