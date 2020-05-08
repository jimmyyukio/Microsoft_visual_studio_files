#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>;
# include<cstring>

using namespace std;

class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") { strcpy(fab, s); }
	virtual void tell() { cout << fab; }
};

class Gloam : private Frabjous
{
private:
	int glip;
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);
	void tell();
};

# endif