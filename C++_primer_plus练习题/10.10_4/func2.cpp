/**************************************************************************
	*  @file	 : func2.cpp
	*  @version  : C++ 11
    *  @author   : jimmy
    *  @date     : 2020/04/20 10:16
    *  @brief    : 
**************************************************************************/
# include<iostream>
# include"func1.h"

//Sales::Sales(double arr[])
//{
//    double total = 0;
//    double maxvalue = 0 , minvalue = 0;
//    for (int i = 0; i < SALES::QUARTERS; i++)
//    {
//        m_sales[i] = arr[i];
//        total += arr[i];
//        if (maxvalue < arr[i])
//            maxvalue = arr[i];
//        if (minvalue > arr[i])
//            minvalue = arr[i];
//    }
//}
SALES::Sales::Sales(double* arr) /*使用构造函数进行初始化*/
{
    double total = 0;
    double max = *arr;
    double min = *arr;
    for (int i = 0; i < SALES::QUARTERS; i++)
    {
        m_sales[i] = *arr;
        total += *arr;
        if (max < *arr)
            max = *arr;
        if (min > * arr)
            min = *arr;
        arr++;
    }
    m_max = max;
    m_min = min;
    m_average = total / SALES::QUARTERS;
}

void SALES::Sales::SetSales(double arr[])/*使用方法进行初始化*/
{
    double max = arr[0];
    double min = arr[0];
    double total = 0;
    for (int i = 0; i < SALES::QUARTERS; i++)
    {
        m_sales[i] = arr[i];
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
        total += arr[i];
    }

    m_max = max;
    m_min = min;
    m_average = total / SALES::QUARTERS;
}

void SALES::Sales::showsales()
{
    std::cout << "The sales list is : " << std::endl;
    for (int i = 0; i < SALES::QUARTERS; i++)
    {
        std::cout << "# " << i + 1 << " : " << m_sales[i] << std::endl;
    }
    std::cout << "The max value is : " << m_max << std::endl;
    std::cout << "min value is : " << m_min << std::endl;
    std::cout << "Average is : " << m_average << std::endl;
}