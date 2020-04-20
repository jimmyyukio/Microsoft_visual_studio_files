#pragma once
# ifndef _TEST_
# define _TEST_

class Move
{
	double x;
	double y;
public:
	Move(double a = 0, double b = 0 );//≥ı ºªØ
	void showmove() const;
	Move add(const Move& m) const;
	void reset(double a = 0, double b = 0);
};

# endif