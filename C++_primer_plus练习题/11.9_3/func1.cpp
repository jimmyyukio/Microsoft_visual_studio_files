/**************************************************************************
	*  @file	 : func1.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/23 17:51
    *  @lastdate :
    *  @brief    : brief
**************************************************************************/
# include<iostream>
# include"vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR//对名称空间进行拓展
{
    const double Rad_to_deg = 45.0 / atan(1.0);//转化为度数

    void Vector::set_mag()//矢量大小
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()//矢量的方向
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

    Vector::Vector()//构造函数
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = RECT;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector(）-- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;//更改类的成员函数mode为当前所选择的表示模式
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incoorect 3rd argument to Vector() -- ";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()//析构函数
    {
    }

    void Vector::polar_mode()//设置模式
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    // 首先隐式调用Vector对象中的x和y，然后显式的调用引用对象b的x和y [4/23/2020 yukio]
    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }



    Vector operator*(double n, const Vector& a)//友元函数，返回Vector对象
    {
        return a * n;
    }

    std::ostream& operator<<(std::ostream& os, const Vector& v)//友元函数，返回ostream对象的引用，重载了<<符号，方便直接对对象进行输出
    {
        if (v.mode == Vector::RECT)//对当前模式进行判断，判断用户选择的表示方法
        {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        }
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", "
                << v.ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invaild";
        return os;
    }
}
