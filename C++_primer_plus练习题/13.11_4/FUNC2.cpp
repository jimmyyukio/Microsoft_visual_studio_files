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
	three = one;//���Ը�ֵ�����
	three.Show();

	cout << "\ntest 2.1\n";
	three += 3;
	cout << three;

	cout << "\ntest 2.2\n";
	three -= 1;
	cout << three;

	cout << "\ntest 3\n";


	//�������ԣ��������캯��ֻ��Ҫ������������³�Ա�Ŀ��������������ݵĿ������Զ����û����еĿ������캯��
	Port four("makiro", "bilibili", 10);
	Port five = Port(four);//���Կ������캯��
	cout << "\nthis is foue : \n";
	four.Show();
	cout << "\nthis is five : \n";
	five.Show();

	cout << endl << "test 4" << endl;

	VintagePort two = VintagePort();//������ĳ�ʼ��
	two.Show();

	cout << "\ntest 5\n";
	cout << two;

	system("pause");
	return 0;
}

/*���⣺
 *��1��brand �費��Ҫ��̬���䣿*/