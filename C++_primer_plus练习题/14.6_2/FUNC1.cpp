/**************************************************************************
	*  @file	 : FUNC1.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/06 22:17
    *  @lastdate :
    *  @brief    : brief
**************************************************************************/
# include<iostream>
# include"head.h"

Gloam::Gloam(int g , const char* s )
{
    glip = g;
    fb = Frabjous(s);
}

Gloam::Gloam(int g, const Frabjous& f)
{
    glip = g;
    fb = f;
}

void Gloam::tell()
{
    cout << "glip : " << glip << endl;
    cout << "fb : ";
    fb.tell();
    cout << endl;
}

int main(void)
{
    Gloam one = Gloam(10, "jimmy");
    one.tell();
    Frabjous two = Frabjous("yukio");
    one = Gloam(20,two);
    one.tell();

    system("pause");
    return 0;
}