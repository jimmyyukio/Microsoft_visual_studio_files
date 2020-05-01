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
using std::acos;

namespace VECTOR//对名称空间进行拓展
{
    const double Rad_to_deg = 45.0 / atan(1.0);//转化为度数

    //void Vector::set_mag()//矢量大小
    //{
    //    mag = sqrt(x * x + y * y);
    //}

    //void Vector::set_ang()//矢量的方向
    //{
    //    if (x == 0.0 && y == 0.0)
    //        ang = 0.0;
    //    else
    //        ang = atan2(y, x);
    //}

	void Vector::set_x(double m_x)
	{
        x = m_x;
	}

	void Vector::set_y(double m_y)
	{
		y = m_y;
	}



    double Vector::calculatemag()//求第三边的长度
    {
        double len;
        len = sqrt(this->x * this->x + this->y * this->y);
        return len;
    }

    double Vector::calculateang(double& len) const//求角度
    {
        double cosA = (len * len + this->x * this->x - this->y * this->y) / (2 * len * this->x);
        double ang = acos(cosA);

        return ang;
    }
    Vector::Vector()//默认构造函数,默认表示方式为坐标轴表示法
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2 , Mode m_mode)//构造函数
    {
        x = n1;
        y = n2;
        mode = m_mode;
    }

    void Vector::reset(double dstep, double direction)//用于重置
    {
        x = dstep * cos(direction);
        y = dstep * sin(direction);
    }

    Vector::~Vector()//析构函数
    {
    }

    void Vector::polar_mode()//更改显示数据时使用的模式
    {
        mode = POL;
    }

    void Vector::rect_mode()//同上
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
            double mag = sqrt(v.x * v.x + v.y * v.y);
            double ang = v.calculateang(mag);
            os << "(m,a) = (" << mag << ", "
                << ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invaild";
        return os;
    }
}
