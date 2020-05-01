
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

}//cd����������

/*
 *�������캯��һ�����ڣ�
 *
 *��1��ͨ��ʹ����һ��ͬ���͵Ķ�������ʼ���´����Ķ���
 *
 *��2�����ƶ��������Ϊ�������ݸ�������
 *
 *��3�����ƶ��󣬲��Ӻ��������������*/
cd::cd(const cd& d)//�������캯��
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

Classic::Classic() : cd("yukio" , "makri" , 0 , 4.3)//���๹�캯����
{
	*arr = { nullptr };//��ʼ���ַ�ָ������
}

Classic::~Classic()
{

}

void Classic::Report() const
{
	std::cout << "The labels arr : " << std::endl;
	//int vaildnum = selectnum();
	// ��Ϊ�ڻ������Ѿ���¼��ѡ�������������������Խ��������������ʾ�ַ�ָ�������е���ЧԪ�� [5/1/2020 14257]
	for(int i = 0 ; i < selectnum(); i++)
	{
		std::cout << "#" << i+1 << " : ";
		char* str = arr[i];//����һ����ʱָ��ָ���ַ�ָ�������Ӧ��Ԫ��ָ����ַ���
		std::cout << str << std::endl;
	}
	if (*arr == nullptr)//����ַ�ָ������Ϊ�գ���ô�����ʾ
	{
		std::cout << "this arr is empty !" << std::endl;
	}
	//��C++ָ����nullptr��0�ȼ�
}

Classic& Classic::operator=(const Classic& test)
{
	cd::operator=(test);//��ʾ���ã��������Աȫ�����ƹ�ȥ���ٴ����������������Ա
	memcpy(arr, test.arr, sizeof(MAXNUM));
	return *this;
}

void Classic::add()
{
	std::cout << "��������Ʒ����";
	char name[20];
	std::cin >> name;
	//��̬�����ַ�������Ҫ���ڴ棬���̶ȵĽ�ʡ����Ҫ�Ĵ洢�ռ�
	int size = strlen(name);
	char* _name = new char[size];
	strcpy(_name, name);
	arr[selectnum()] = _name;
	addselectnum();//������һ
}
