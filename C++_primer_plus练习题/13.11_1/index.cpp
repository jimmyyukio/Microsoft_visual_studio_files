
# include<iostream>
# include<cstring>
# include"head.h"

cd::cd()
{
	*performers = { 0 };
	*label = { 0 };
	selections = 0;
	playtime = 0.0;
}

cd::cd(const char* s1,const char* s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

cd::~cd() 
{

}//cd类析构函数

/*
 *拷贝构造函数一般用于：
 *
 *（1）通过使用另一个同类型的对象来初始化新创建的对象。
 *
 *（2）复制对象把它作为参数传递给函数。
 *
 *（3）复制对象，并从函数返回这个对象。*/
cd::cd(const cd& d)//拷贝构造函数
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

void cd::Report() const
{
	std::cout << "performers : " << performers << std::endl
		<< "label : " << label << std::endl
		<< "selections : " << selections << std::endl
		<< "playtime : " << playtime << std::endl;
}

cd& cd::operator=(const cd& d)
{
	strcpy(performers , d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic() : cd("yukio" , "makri" , 0 , 4.3)//基类构造函数，
{
	*arr = { nullptr };//初始化字符指针数组
}

Classic::~Classic()
{

}

void Classic::Report() const
{
	std::cout << "The labels arr : " << std::endl;
	//int vaildnum = selectnum();
	// 因为在基类中已经记录了选择的总数，所以这里可以借用这个总数来表示字符指针数组中的有效元素 [5/1/2020 14257]
	for(int i = 0 ; i < selectnum(); i++)
	{
		std::cout << "#" << i+1 << " : ";
		char* str = arr[i];//定义一个临时指针指向字符指针数组对应单元所指向的字符串
		std::cout << str << std::endl;
	}
	if (*arr == nullptr)//如果字符指针数组为空，那么输出提示
	{
		std::cout << "this arr is empty !" << std::endl;
	}
	//在C++指针中nullptr和0等价
}

Classic& Classic::operator=(const Classic& test)
{
	cd::operator=(test);//显示调用，将基类成员全部复制过去，再处理派生类的新增成员
	memcpy(arr, test.arr, sizeof(MAXNUM));
	return *this;
}

void Classic::add()
{
	std::cout << "请输入作品名：";
	char name[20];
	std::cin >> name;
	//动态分配字符串所需要的内存，最大程度的节省所需要的存储空间
	int size = strlen(name);
	char* _name = new char[size];
	strcpy(_name, name);
	arr[selectnum()] = _name;
	addselectnum();//总数加一
}
