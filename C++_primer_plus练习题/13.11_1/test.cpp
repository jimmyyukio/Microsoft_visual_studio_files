# include<iostream>
# include"head.h"

using namespace std;

void Bravo(const cd& disk);

int main(void)
{
	cd c1 ("jimmy" , "yukio" , 0 , 4.3);
	Classic c2;
	cd* pcd = &c1;

	std::cout << "Using object directory:\n";
	c1.Report();
	c2.Report();

	cout << "Calling a function with a cd refrence argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	copy.Report();

	c2.add();
	c2.Report();

	system("pause");
	return 0;
}

void Bravo(const cd & disk)
{
	disk.Report();
}
