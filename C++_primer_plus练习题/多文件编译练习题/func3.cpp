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
多文件编译总结： 多个源文件需要相互调用时，应该将他们放在同一个工程之中
如果实在名称空间中声明的函数，然后需要在其他源文件中对其进行定义，那么需要在函数名前面加上其所属
的名称空间，来表明这个函数是来自于该命名空间中所声明的函数，而不是该源文件中定义的，否则会导致
二义性，导致编译失败。在工程中若A.cc文件中定义了一个函数，那么同一个工程中的B.cc则可以直接调用其定义的函
数，不需要再次声明
2020年4月18日14:41:45
*/