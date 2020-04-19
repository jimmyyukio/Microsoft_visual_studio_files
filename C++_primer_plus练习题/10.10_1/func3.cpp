/*
*时间:2020年4月19日18:20:02
*
*描述:
*
**/
# include<iostream>
# include"func1.h"

int main(void)
{
	Bank user1 = Bank();
	user1.show();

	std::cout << "Please rename your count : ";
	std::string name;
	std::cin >> name;
	std::cout << "enter your count : ";
	int account;
	std::cin >> account;
	std::cout << "enter your money : ";
	double money;
	std::cin >> money;
	user1 = Bank(name, account, money);
	user1.show();

	user1.save(6000);
	user1.show();

	user1.take_out(4000);
	user1.show();
	
	
	return 0;
}