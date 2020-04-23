#pragma once
# ifndef _TEST_
# define _TEST_

class stonewt
{
	int st;
	int lb;
public:
	stonewt operator*(int num);//ÖØÔØ*ÔËËã·û
	stonewt(const int t_st = 0, const int t_lb = 0) { st = t_st; lb = t_lb; };
	void show();
};

# endif