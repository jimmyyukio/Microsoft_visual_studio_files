# include<iostream>
# include"vector.h"
# include<cstdlib>
# include<ctime>
# include<fstream>

int main(void)
{
	using namespace VECTOR;
	using namespace std;
	
	ofstream fout;
	fout.open("d://test.txt");
	srand(time(0));//ˢ�����������
	double direction;//���߷���
	/*��������step��result��stepʹ��Ĭ�Ϲ��캯�����й��죬��resultʹ�����غ�Ĵ������Ĺ��캯�����й���*/
	Vector step;
	Vector result(0.0, 0.0);
	// calssname object = value -- ����ֻ����һ�������Ĺ��캯������ʹ�ø�ֵ���﷨���������ʼ��Ϊһ��ֵ [4/23/2020 yukio]

	unsigned long steps = 0;//��¼����
	double target;//Ŀ��λ�õ�ֱ�߾���;
	double dstep;//�洢ÿһ������
	int time = 0;//�߶�����
	cout << "enter target distance (q to quit): ";
	while (cin >> target)//�ڽ��յ��޷�ת��Ϊdouble���͵�����ʱ�˳�����
	{
		cout << "Enter step length: ";//����
		if (!(cin >> dstep))//��������м��
			break;
		fout << "Target Distance : " << target << " , " << "Step size : " << dstep << endl;
		while (result.magval() < target)
		{
			fout << "#" << time << " : (x,y) = " << result << endl;//���λ��
			direction = rand() % 360;//�����ȡһ������
			step.reset(dstep, direction, Vector::POL);//����step����ĳ�Ա����
			result = result + step;//ʹ�����غ��+�������������������ӣ�������һ�����󣬽��÷��صĶ��󸲸ǵ�result����
			steps++;//ÿ��ѭ������һ�Σ���ʾ����һ��
			time++;
		}

		//����1������
		cout << "After " << steps << " steps,the subject "
			"has the following location:\n";
		cout << result << endl;

		//������ƶ����ļ�����,��ͷ
		fout << "Target Distance : " << target << " , " << "Step size : " << dstep << endl;
		//���
		fout << "After " << steps << " steps,the subject "
			"has the following location:\n";
		fout << result << endl;

		result.polar_mode();//�л�ģʽ
		//����2������
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		//����
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye ! \n";
	cin.clear();
	fout.close();
// ������仰�����ú�system("pause");��ͬ [4/23/2020 yukio]
	while (cin.get() != '\n')
		continue;

	system("pause");
	return 0;
}
