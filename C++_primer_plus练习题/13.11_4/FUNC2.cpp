# include<iostream>
# include"head.h"

int main(void)
{
	cout << "test 1" << endl;

	Port one = Port("yukio", "jimmy", 3);
	one.Show();
	cout << one;

	cout << endl << "test 2" << endl;

	Port three;
	three.Show();
	three = one;//测试赋值运算符
	three.Show();

	cout << "\ntest 2.1\n";
	three += 3;
	cout << three;

	cout << "\ntest 2.2\n";
	three -= 1;
	cout << three;

	cout << "\ntest 3\n";


	//经过测试，拷贝构造函数只需要管理派生类的新成员的拷贝，而基类数据的拷贝会自动调用基类中的拷贝构造函数
	Port four("makiro", "bilibili", 10);
	Port five = Port(four);//测试拷贝构造函数
	cout << "\nthis is foue : \n";
	four.Show();
	cout << "\nthis is five : \n";
	five.Show();

	cout << endl << "test 4" << endl;

	VintagePort two = VintagePort();//派生类的初始化
	two.Show();

	cout << "\ntest 5\n";
	cout << two;

	system("pause");
	return 0;
}

/*问题：
 *（1）brand 需不需要动态分配？*/