# include<iostream>
# include"func1.h"

int main(void)
{	
	using namespace std;
	using namespace SALES;
	std::cout << "#1 -> please enter : ";
	double Arr[SALES::QUARTERS];
	for (int i = 0; i < SALES::QUARTERS; i++)
		std::cin >> Arr[i];

	SALES::Sales one = SALES::Sales(Arr);
	//--2020/04/20 12:58--创建对象,使用构造函数返回一个临时的对象，再将该临时对象复制到创建的对象one中
	one.showsales();

	std::cout << "#2 -> please enter : ";
	double arr[SALES::QUARTERS];
	for (int i = 0; i < SALES::QUARTERS; i++)
		std::cin >> arr[i];
	one.SetSales(arr);
	//--2020/04/20 13:05--通过类的方法对该类的成员函数进行修改
	one.showsales();

	return 0;
}