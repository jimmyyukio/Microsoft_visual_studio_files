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
	//--2020/04/20 12:58--��������,ʹ�ù��캯������һ����ʱ�Ķ����ٽ�����ʱ�����Ƶ������Ķ���one��
	one.showsales();

	std::cout << "#2 -> please enter : ";
	double arr[SALES::QUARTERS];
	for (int i = 0; i < SALES::QUARTERS; i++)
		std::cin >> arr[i];
	one.SetSales(arr);
	//--2020/04/20 13:05--ͨ����ķ����Ը���ĳ�Ա���������޸�
	one.showsales();

	return 0;
}