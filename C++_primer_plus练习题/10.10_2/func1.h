#pragma once
/*
*@ʱ��:2020��4��19��18:28:42
*
*@����:
*
**/
# ifndef _TEST_
# define _TEST_
# include<iostream>

class Person
{
private:
	static const int LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = "jimmy" ; fname[0] = '\0' ; }/*��������*/
	Person(const std::string & ln, const char* fn = "Heyyou");/*���캯��,��Ĭ��ֵ*/
	void show() const;
	void Formalshow() const;
	/*�ں����������const ���������߶����ʾ��Ϊconst��Ա���� */
};

# endif