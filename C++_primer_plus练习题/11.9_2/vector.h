
#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		//double mag;
		//double ang;
		//void set_mag();
		//void set_ang();
		void set_x(double);
		void set_y(double);
		Mode mode;// ����ģʽ [4/23/2020 14257]
	public:
		Vector();//Ĭ�Ϲ��캯��
		Vector(double n1, double n2 , Mode m_mode = RECT);//Ĭ��ΪRECTģʽ
		void reset(double dstep ,double direction);
		~Vector();
		// ��������,���ڷ���x,y,mag,ang���� [4/23/2020 14257]
		double xval() const { return x; }
		double yval() const { return y; }
		//ͨ��x��y������м���
		/*double magval() const;
		double angval() const;*/
		double calculatemag();//����߳�
		double calculateang(double& len) const;//�����Ǻ���

		// ����ʹ�ñ�ʾλ�õķ�ʽ [4/23/2020 14257]
		void polar_mode();//����Ϊ��С�ͽǶȵı�ʾ��ʽ
		void rect_mode();//����Ϊx��y���ʾ��ʽ

		// �������� [4/23/2020 14257]
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// ��Ԫ���� [4/23/2020 14257]
		friend Vector operator*(double n, const Vector& a);//����*�����
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);//����<<�����
	};
}

# endif