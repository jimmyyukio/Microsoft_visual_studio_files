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
	srand(time(0));//刷新随机数种子
	double direction;//行走方向
	/*创建对像step和result，step使用默认构造函数进行构造，而result使用重载后的带参数的构造函数进行构造*/
	Vector step;
	Vector result(0.0, 0.0);
	// calssname object = value -- 对于只接受一个参数的构造函数允许使用赋值的语法，将对象初始化为一个值 [4/23/2020 yukio]

	unsigned long steps = 0;//记录步数
	double target;//目标位置的直线距离;
	double dstep;//存储每一步步长
	int time = 0;//走动次数
	cout << "enter target distance (q to quit): ";
	while (cin >> target)//在接收到无法转换为double类型的数据时退出程序
	{
		cout << "Enter step length: ";//步长
		if (!(cin >> dstep))//对输入进行检查
			break;
		fout << "Target Distance : " << target << " , " << "Step size : " << dstep << endl;
		while (result.calculatemag() < target)
		{
			fout << "#" << time << " : (x,y) = " << result << endl;//输出位置
			direction = rand() % 360;//随机获取一个方向
			step.reset(dstep, direction);//更新step对象的成员变量
			result = result + step;//使用重载后的+运算符，将两个对象相加，并返回一个对象，将该返回的对象覆盖到result上面
			steps++;//每次循环结束一次，表示走了一步
			time++;
		}

		//方法1输出结果
		cout << "After " << steps << " steps,the subject "
			"has the following location:\n";
		cout << result << endl;

		//输入的制定的文件流中,开头
		fout << "Target Distance : " << target << " , " << "Step size : " << dstep << endl;
		//结果
		fout << "After " << steps << " steps,the subject "
			"has the following location:\n";
		fout << result << endl;

		result.polar_mode();//切换模式
		//方法2输出结果
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.calculatemag() / steps << endl;

		//输入到文件中
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.calculatemag() / steps << endl << endl;

		//重置
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye ! \n";
	cin.clear();
	fout.close();
// 下面这句话的作用和system("pause");相同 [4/23/2020 yukio]
	while (cin.get() != '\n')
		continue;

	system("pause");
	return 0;
}
