# pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(Time & one , const Time & two);
	friend Time operator-(Time& one, const Time& two);
	friend Time operator*(Time& one, const Time& two);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

# endif
