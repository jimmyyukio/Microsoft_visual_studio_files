/**************************************************************************
	*  @file	 : func1.h
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/04/20 13:39
    *  @brief    : brief
**************************************************************************/
#pragma once
# ifndef _TEST_
# define _TEST_
# include<iostream>

// 定义一个 [4/20/2020 14257]
typedef struct customer
{
	std::string fullname;
	double payment;
}*pcus,cus;

class stack
{
	enum {MAX = 10};//定义作用域为类区域的常量
	pcus items[MAX];//结构体指针数组，充当一个栈
	pcus* bottom;//栈底指针
	pcus* top;//栈顶指针
	double total;//总数
	int num;
public:
	stack() { items[0] = NULL; top = items; bottom = items; total = 0; num = 0; };//构造函数,建立一个空栈
	bool isempty();//判断栈是否为空 
	bool isfull();//判断栈是否为满
	bool push(cus* item);//压栈,引用用户创建的用户
	bool pop();//出栈
};


# endif

/*
 * 在C++中，类相当于一个用户自定义的“数据类型”，是某一种对象所具有的属性和行为的集合。
 * 类中的成员变量一般情况下都为声明，也就是说，系统并没有为他们分配内存。但在类中同样也可以
 * 定义静态常量。因为静态常量是从程序开始直到结束期间一直存在。在通过类创建出一个对象的同时，
 * 无论用户是否有显式的将类中的数据成员初始化，都会分配内存（因为存在默认构造函数）。
 *
 *
 * 引用，引用（reference）在C++中也是经常被用到，尤其是在作为函数参数的时候，需要在函数内部修改更新函数外部的值的时候。
 * 首先我们必须明确的一点就是：引用是一种特殊的指针。引用是一个指向其它对象的常量指针，它保存着所指对象的存储地址。
 * 并且使用的时候会自动解引用，而不需要像使用指针一样显式提领。
 **/