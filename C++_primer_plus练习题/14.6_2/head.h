#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>
# include<cstring>
using namespace std;

class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") { strcpy(fab, s); }
	virtual void tell() { cout << fab; }//����Ϊ�麯�����Ա���ȷ�ĵ��ú���
};

class Gloam
{
private:
	int glip;
	Frabjous fb;
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);//�ö�����Ϊ��������ʼ��Gloam����
	void tell();
};

# endif
