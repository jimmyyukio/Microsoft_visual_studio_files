# include<iostream>
# include"func1.h"

using namespace SALES;
void enter(Sales&);

int main(void)
{
    Sales S = { 0 };
    std::cout << "Do you want which way to init The sales struct ?\n"
        << "A) interactive      B) non-interactive(automatically initization)\n"
        << "please type : ";
    char choose = 0;
    std::cin >> choose;
    switch (choose)
    {
    case 'A':
    case 'a':
        enter(S);
        break;
    case 'B':
    case 'b':
        setSales(S);
        break;
    default:
        std::cout << "enter error !" << std::endl;
        break;
    }

    //system("pause");
    showSales(S);
    system("pause");
    return 0;
}

void enter(Sales& S)
{
    std::cout << "please enter the sales : ";
    double arr[QUARTERS];
    for (int i = 0; i < QUARTERS; i++)
        std::cin >> arr[i];

    setSales(S, arr, QUARTERS);

    return;
}
/*
���ļ������ܽ᣺ ���Դ�ļ���Ҫ�໥����ʱ��Ӧ�ý����Ƿ���ͬһ������֮��
���ʵ�����ƿռ��������ĺ�����Ȼ����Ҫ������Դ�ļ��ж�����ж��壬��ô��Ҫ�ں�����ǰ�����������
�����ƿռ䣬��������������������ڸ������ռ����������ĺ����������Ǹ�Դ�ļ��ж���ģ�����ᵼ��
�����ԣ����±���ʧ�ܡ��ڹ�������A.cc�ļ��ж�����һ����������ôͬһ�������е�B.cc�����ֱ�ӵ����䶨��ĺ�
��������Ҫ�ٴ�����
2020��4��18��14:41:45
*/