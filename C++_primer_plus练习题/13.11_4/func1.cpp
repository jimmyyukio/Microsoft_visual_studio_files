# include<iostream>
# include"head.h"
# include<cstring>

Port::Port(const char* br, const char* st, int b)
{
	int len = strlen(br);
	brand = new char[len];//动态分配空间
	strcpy(brand, br);//将br中的内容复制过去
	strcpy(style, st);
	bottles = b;
}
//拷贝构造函数
Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand)];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	brand = p.brand;
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles = bottles + b;

	return *this;
}

Port& Port::operator-=(int b)
{
	bottles = bottles - b;
	return *this;
}

void Port::Show() const// 只有成员函数才能这样使用const修饰 [5/2/2020 14257]
{
	cout << "Brand : " << brand << endl;
	cout << "Kind : " << style << endl;
	cout << "Bottles : " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << " , ";
	os << p.style << " , ";
	os << p.bottles << endl;
	return os;
}

// 以下为派生类部分 [5/2/2020 14257]
/*
 *派生类构造函数在初始化基类的私有成员时，采用的是成员初始化列表的方法，通过基类的
 *构造函数来初始化基类的私有数据成员，因为派生类无法直接访问基类的私有成员，只能够
 *通过接口进行间接访问*/
VintagePort::VintagePort() : Port()// 借用基类的构造函数初始化基类部分的成员,这个是默认构造函数 [5/2/2020 14257]
{
	nickname = nullptr;
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "none", b)
{
	nickname = new char[strlen(nn)];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp)//派生类的拷贝构造函数
{
	//Port(vp);
	nickname = new char[strlen(vp.nickname)];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	Port::operator=(vp);//显示调用基类中的赋值运算符，其中隐式的调用了派生类对象中的
	//基类基类成员，显示的调用的目标对象的基类成员
	delete[] nickname;//清空指针
	nickname = new char[strlen(vp.nickname)];//动态分配存储空间
	strcpy(nickname, vp.nickname);//拷贝过去
	year = vp.year;
	return *this;//返回自身
}

void VintagePort::Show() const
{
	Port::Show();
	if (nickname != nullptr)//对空指针进行处理
		cout << "nickname : " << nickname << endl;
	else
		cout << "nickname is empty !" << endl;
	cout << "year : " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	//os << vp;//借用基类中的重载输出基类数据成员
	// 错误写法，这样会进入死递归 [5/2/2020 14257]
	//vp.Port::Show();
	
	if (vp.nickname != nullptr)
		os << " , " << vp.nickname;
	else
		cout << "nickname is empty !";
	os << " , " << vp.year << endl;
	return os;
}
