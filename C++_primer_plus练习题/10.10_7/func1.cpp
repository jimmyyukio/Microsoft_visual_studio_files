# include"head.h"
# include<iostream>
# include<cstring>

plorg::plorg(const char* name, const int CI)
{
	strcpy_s(m_name, 19, name);
	m_CI = CI;
}

void plorg::recomposeCI(const int CI)
{
	m_CI = CI;
}

void plorg::showplorg()
{
	static int num = 1;
	std::cout << "#" << num << " : " << std::endl;
	num++;
	std::cout << "The name of plorg is : " << m_name << std::endl
		<< "CI value is : " << m_CI << std::endl;
}