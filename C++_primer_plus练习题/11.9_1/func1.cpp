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

namespace VECTOR//�����ƿռ������չ
{
    const double Rad_to_deg = 45.0 / atan(1.0);//ת��Ϊ����

    void Vector::set_mag()//ʸ����С
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()//ʸ���ķ���
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

    Vector::Vector()//���캯��
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
            cout << "Incorrect 3rd argument to Vector(��-- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;//������ĳ�Ա����modeΪ��ǰ��ѡ��ı�ʾģʽ
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

    Vector::~Vector()//��������
    {
    }

    void Vector::polar_mode()//����ģʽ
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    // ������ʽ����Vector�����е�x��y��Ȼ����ʽ�ĵ������ö���b��x��y [4/23/2020 yukio]
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



    Vector operator*(double n, const Vector& a)//��Ԫ����������Vector����
    {
        return a * n;
    }

    std::ostream& operator<<(std::ostream& os, const Vector& v)//��Ԫ����������ostream���������
    {
        if (v.mode == Vector::RECT)//�Ե�ǰģʽ�����жϣ��ж��û�ѡ��ı�ʾ����
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
