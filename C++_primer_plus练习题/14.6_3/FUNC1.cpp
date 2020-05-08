/**************************************************************************
	*  @file	 : FUNC1.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/08 11:27
    *  @lastdate :
    *  @brief    : brief
**************************************************************************/
# include<iostream>
# include"head.h"

Gloam::Gloam(int g, const char* s) : glip(g) , Frabjous(s) {}

Gloam::Gloam(int g, const Frabjous& f) : glip(g) , Frabjous(f) {}

void Gloam::tell()
{
	std::cout << "glip : " << glip << endl;
	std::cout << "fabs : ";
	Frabjous::tell();//ͨ��������������������û����е�tell����
}

int main(void)
{
	std::cout << "\nThis is test one!\n";
	Gloam one = Gloam(10, "yukio");
	one.tell();

	std::cout << "\nThis is test two!\n";

	Frabjous three = Frabjous("jimmy");
	Gloam two = Gloam(20, three);
	two.tell();

	system("pause");
	return 0;
}