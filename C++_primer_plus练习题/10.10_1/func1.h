# ifndef BANK
# define BANK
# include<iostream>

class Bank
{
	std::string name;//名字
	int account;//账号
	double money;//存款
public:
	//bank(std::string& name_, int account_, double money_);//默认构造函数
	Bank(std::string name_ = "jimmy", int account_ = 1425, double money_ = 1000.00);//构造函数2
	//~bank();
	void show();
	void save(double);
	void take_out(double);
};

# endif