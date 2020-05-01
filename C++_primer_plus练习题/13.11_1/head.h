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
    char performers[50];//������
    char label[20];//��ǩ�����֣�
    int selections;//ѡ��ĸ���
    double playtime;//ʱ��
public:
    cd(const char* s1,const char* s2, int n, double x);
    cd(const cd& d);
    cd();
    virtual ~cd();
    virtual void Report() const;
    virtual cd& operator=(const cd& d);
    int selectnum() const { return selections; }//�鿴�Ѿ�ѡ�е�cd��
    void addselectnum() { selections++; }//����һ��cd��
};

class Classic : public cd
{
    const static int MAXNUM = 10;//�����Ŀ����Ϊ10
    char* arr[MAXNUM];
public:
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic& operator=(const Classic& test);
    void add();//���һ���ղ�
};
# endif