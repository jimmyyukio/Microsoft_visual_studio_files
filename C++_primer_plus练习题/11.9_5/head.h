#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

class stonewt
{
	enum Mode { LB , ST , DLB};
	double st;
	double lb;
	Mode mode;
public:
	stonewt operator*(double num);//ÖØÔØ*ÔËËã·û
	stonewt(const double t_st = 0, const double t_lb = 0) { st = t_st; lb = t_lb; };
	void set_mode();
	double convert();
	stonewt operator-(double num);
	stonewt operator+(double num);
	friend std::ostream& operator<<(std::ostream& os, stonewt& one);
};

# endif