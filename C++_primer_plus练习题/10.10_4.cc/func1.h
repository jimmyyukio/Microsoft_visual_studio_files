#pragma once
# ifndef _TEST_
# define _TEST_

namespace SALES
{
    const int QUARTERS = 4;
    //double init[QUARTERS] = { 1.0,2.0,3.0,4.0 };
    class Sales
    {
        double m_sales[QUARTERS];
        double m_average;
        double m_max;
        double m_min;
    public:
        Sales(double* arr);
        void SetSales(double arr[]);
        void showsales();
    };
}

# endif