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

namespace VECTOR//�����ƿռ������չ
{
    const double Rad_to_deg = 45.0 / atan(1.0);//ת��Ϊ����

    //void Vector::set_mag()//ʸ����С
    //{
    //    mag = sqrt(x * x + y * y);
    //}

    //void Vector::set_ang()//ʸ���ķ���
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



    double Vector::calculatemag()//������ߵĳ���
    {
        double len;
        len = sqrt(this->x * this->x + this->y * this->y);
        return len;
    }

    double Vector::calculateang(double& len) const//��Ƕ�
    {
        double cosA = (len * len + this->x * this->x - this->y * this->y) / (2 * len * this->x);
        double ang = acos(cosA);

        return ang;
    }
    Vector::Vector()//Ĭ�Ϲ��캯��,Ĭ�ϱ�ʾ��ʽΪ�������ʾ��
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2 , Mode m_mode)//���캯��
    {
        x = n1;
        y = n2;
        mode = m_mode;
    }

    void Vector::reset(double dstep, double direction)//��������
    {
        x = dstep * cos(direction);
        y = dstep * sin(direction);
    }

    Vector::~Vector()//��������
    {
    }

    void Vector::polar_mode()//������ʾ����ʱʹ�õ�ģʽ
    {
        mode = POL;
    }

    void Vector::rect_mode()//ͬ��
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

    std::ostream& operator<<(std::ostream& os, const Vector& v)//��Ԫ����������ostream��������ã�������<<���ţ�����ֱ�ӶԶ���������
    {
        if (v.mode == Vector::RECT)//�Ե�ǰģʽ�����жϣ��ж��û�ѡ��ı�ʾ����
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
