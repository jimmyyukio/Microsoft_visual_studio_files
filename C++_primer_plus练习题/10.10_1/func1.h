# ifndef BANK
# define BANK
# include<iostream>

class Bank
{
	std::string name;//����
	int account;//�˺�
	double money;//���
public:
	//bank(std::string& name_, int account_, double money_);//Ĭ�Ϲ��캯��
	Bank(std::string name_ = "jimmy", int account_ = 1425, double money_ = 1000.00);//���캯��2
	//~bank();
	void show();
	void save(double);
	void take_out(double);
};

# endif