# include<iostream>
# include"head.h"
# include<cstring>

Port::Port(const char* br, const char* st, int b)
{
	int len = strlen(br);
	brand = new char[len];//��̬����ռ�
	strcpy(brand, br);//��br�е����ݸ��ƹ�ȥ
	strcpy(style, st);
	bottles = b;
}
//�������캯��
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

void Port::Show() const// ֻ�г�Ա������������ʹ��const���� [5/2/2020 14257]
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

// ����Ϊ�����ಿ�� [5/2/2020 14257]
/*
 *�����๹�캯���ڳ�ʼ�������˽�г�Աʱ�����õ��ǳ�Ա��ʼ���б�ķ�����ͨ�������
 *���캯������ʼ�������˽�����ݳ�Ա����Ϊ�������޷�ֱ�ӷ��ʻ����˽�г�Ա��ֻ�ܹ�
 *ͨ���ӿڽ��м�ӷ���*/
VintagePort::VintagePort() : Port()// ���û���Ĺ��캯����ʼ�����ಿ�ֵĳ�Ա,�����Ĭ�Ϲ��캯�� [5/2/2020 14257]
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

VintagePort::VintagePort(const VintagePort& vp)//������Ŀ������캯��
{
	//Port(vp);
	nickname = new char[strlen(vp.nickname)];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	Port::operator=(vp);//��ʾ���û����еĸ�ֵ�������������ʽ�ĵ���������������е�
	//��������Ա����ʾ�ĵ��õ�Ŀ�����Ļ����Ա
	delete[] nickname;//���ָ��
	nickname = new char[strlen(vp.nickname)];//��̬����洢�ռ�
	strcpy(nickname, vp.nickname);//������ȥ
	year = vp.year;
	return *this;//��������
}

void VintagePort::Show() const
{
	Port::Show();
	if (nickname != nullptr)//�Կ�ָ����д���
		cout << "nickname : " << nickname << endl;
	else
		cout << "nickname is empty !" << endl;
	cout << "year : " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	//os << vp;//���û����е���������������ݳ�Ա
	// ����д����������������ݹ� [5/2/2020 14257]
	//vp.Port::Show();
	
	if (vp.nickname != nullptr)
		os << " , " << vp.nickname;
	else
		cout << "nickname is empty !";
	os << " , " << vp.year << endl;
	return os;
}
