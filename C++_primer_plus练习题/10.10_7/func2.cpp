# include"head.h"
# include<iostream>

int main(void)
{
	plorg one = plorg();
	one.showplorg();

	one = plorg("jimmy", 100);
	one.showplorg();

	one.recomposeCI(200);
	one.showplorg();

	system("pause");
	return 0;
}