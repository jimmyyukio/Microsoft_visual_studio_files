# include<iostream>
# include"func1.h"

int main(void)
{
	using namespace std;

	cout << "#1 : " << endl;
	Person one;
	one.show();
	one.Formalshow();

	cout << "#2 : " << endl;
	Person two { "Smythecraft" };
	two.show();
	two.Formalshow();

	cout << "#3 : " << endl;
	Person three { "Dimwiddy", "Sam" };
	three.show();
	three.Formalshow();

	cout << endl;

	return 0;
}
