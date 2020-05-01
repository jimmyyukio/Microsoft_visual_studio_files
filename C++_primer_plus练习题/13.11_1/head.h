/**************************************************************************
	*  @file	 : head.cpp
	*  @version  : C++ 11
	*  @coding   : GBK
    *  @author   : jimmy
    *  @date     : 2020/05/01 13:09
    *  @lastdate :
    *  @brief    : brief
**************************************************************************/
# ifndef _TEST_
# define _TEST_

class cd
{
    char performers[50];//出演者
    char label[20];//标签（名字）
    int selections;//选择的个数
    double playtime;//时长
public:
    cd(const char* s1,const char* s2, int n, double x);
    cd(const cd& d);
    cd();
    virtual ~cd();
    virtual void Report() const;
    virtual cd& operator=(const cd& d);
    int selectnum() const { return selections; }//查看已经选中的cd数
    void addselectnum() { selections++; }//增加一个cd数
};

class Classic : public cd
{
    const static int MAXNUM = 10;//最大数目设置为10
    char* arr[MAXNUM];
public:
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic& operator=(const Classic& test);
    void add();//添加一个收藏
};
# endif