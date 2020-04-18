/*
 * @Author: jimmy
 * @Date: 2020-04-18 13:04:18
 * @LastEditors: jimmy
 * @LastEditTime: 2020-04-18 14:09:08
 * @Description: ��չ���ƿռ��еĺ���
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
    for (int i = 0; i < n; i++)/* ����ṹ�� */
    {
        s.sales[i] = arr[i];
        if (arr[i] > max)/* ��¼���ֵ */
            max = arr[i];
        if (arr[i] < min)/* ��¼��Сֵ */
            min = arr[i];
        total += arr[i];/* ��¼�ܺ� */
    }
    s.max = max;/* ���������Сֵ */
    s.min = min;
    s.average = total / n;
}

void SALES::setSales(Sales& s)/* �ǽ���ʽ */
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

void SALES::showSales(const Sales& s)/* ������� */
{
    std::cout << "The Sales struct's value : \n"
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