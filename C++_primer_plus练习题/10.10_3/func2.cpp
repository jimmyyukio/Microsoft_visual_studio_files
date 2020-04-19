# include<iostream>
# include<cstring>
# include"func1.h"

GOLF::GOLF(const char* name, const int handicap )
{
	strcpy(m_fullname, name);
	m_handicap = handicap;
}

void GOLF::Handicap(int handicap)
{
	m_handicap = handicap;
}

void GOLF::showgolf()
{
	std::cout << "The fullname of golf is : " << m_fullname << std::endl;
	std::cout << "handicap is : " << m_handicap << std::endl;
}