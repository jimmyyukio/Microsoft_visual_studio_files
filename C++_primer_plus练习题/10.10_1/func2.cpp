# include<iostream>
# include"func1.h"

//bank::bank(std::string& name_, int account_, double money_)
//{
//	name = name_;
//	account = account_;
//	money = money_;
//}

Bank::Bank(std::string name_value, int account_value, double money_value)
{
	name = name_value;
	account = account_value;
	money = money_value;
}

void Bank::show()
{
	std::cout << "The name is : " << name << std::endl;
	std::cout << "account is : " << account << std::endl;
	std::cout << "money have : " << money << std::endl;
}

void Bank::save(double money_)
{
	money += money_;//追加存款
}

void Bank::take_out(double money_)
{
	money -= money_;//取出存款
}
 