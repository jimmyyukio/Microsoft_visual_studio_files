/*
 * @Author: jimmy
 * @Date: 2020-04-18 13:04:18
 * @LastEditors: jimmy
 * @LastEditTime: 2020-04-18 14:09:08
 * @Description: 拓展名称空间中的函数
 */
# include<iostream>
# include"func1.h"
# include<cstring>

using namespace SALES;
void SALES::setSales(Sales& s);
void SALES::setSales(Sales& s, const double arr[], int n);
void SALES::showSales(const Sales&);

void SALES::setSales(Sales& s, const double arr[], int n)
{
    double max = arr[0];
    double min = arr[0];
    double total = 0;
    for (int i = 0; i < n; i++)/* 存入结构体 */
    {
        s.sales[i] = arr[i];
        if (arr[i] > max)/* 记录最大值 */
            max = arr[i];
        if (arr[i] < min)/* 记录最小值 */
            min = arr[i];
        total += arr[i];/* 记录总和 */
    }
    s.max = max;/* 存入最大最小值 */
    s.min = min;
    s.average = total / n;
}

void SALES::setSales(Sales& s)/* 非交互式 */
{
    double init = 100;
    double total = 0;
    for (int i = 0; i < QUARTERS; i++)
    {
        s.sales[i] = init;
        total += init;
        init += init;
    }
    s.max = s.sales[3];
    s.min = s.sales[0];
    s.average = total / QUARTERS;
}

void SALES::showSales(const Sales& s)/* 输出数据 */
{
    std::cout << "The Sales struct value : \n"
        << "sales array : ";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout << " " << s.sales[i] << " ";
    }
    std::cout << "\nIn this array , the max num is : " <<
        s.max << std::endl;
    std::cout << "the min num is : " << s.min << std::endl;
    std::cout << "the average is : " << s.average << std::endl;
}