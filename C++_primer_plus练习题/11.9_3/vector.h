#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT , POL};
	private:
		double x;
		double y;
		double mag;
		double ang;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
		Mode mode;// 设置模式 [4/23/2020 14257]
	public:
		Vector();//默认构造函数
		Vector(double n1, double n2, Mode form = RECT);//默认为RECT模式
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		// 内联函数,用于反馈x,y,mag,ang数据 [4/23/2020 14257]
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }

		// 设置使用表示位置的方式 [4/23/2020 14257]
		void polar_mode();//设置为大小和角度的表示方式
		void rect_mode();//设置为x，y轴表示方式

		// 函数重载 [4/23/2020 14257]
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// 友元函数 [4/23/2020 14257]
		friend Vector operator*(double n, const Vector& a);//重载*运算符
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);//重载<<运算符
	};

	struct record
	{
		Vector high;
		Vector low;
		double totalstep;
		double times;
	};
}

# endif