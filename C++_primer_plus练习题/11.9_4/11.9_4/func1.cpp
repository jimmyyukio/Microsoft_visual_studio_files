# include<iostream>
# include"mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(Time& one, const Time& two)
{
	Time sum;
	sum.minutes = one.minutes + two.minutes;
	sum.hours = one.hours + two.hours + sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}

Time operator-(Time& one, const Time& two)
{
	Time diff;
	int tot1, tot2;//存储转化过来的分钟数
	tot1 = two.minutes + 60 * two.hours;
	tot2 = one.minutes + 60 * one.hours;
	diff.hours = (tot2 - tot1) / 60;
	diff.minutes = (tot2 - tot1) % 60;
	return diff;
}

Time operator*(Time& one, const Time& two)
{
	Time result;
	int totalminutes = (one.minutes + one.hours * 60) * (two.minutes + two.hours * 60);
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours , " << t.minutes << " minutes";
	return os;
}
