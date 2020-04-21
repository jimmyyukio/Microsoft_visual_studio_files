# include<iostream>
# include"head.h"

int main(void)
{
	list one = list();
	std::cout << "#1" << std::endl;
	one.is_empty();
	one.creatnode("yukio" , 50);
	one.creatnode("jimmy" , 100);
	one.creatnode("makiro" , 300);
	one.showlist();
	//one.showlist();
	std::cout << "#2" << std::endl;
	one.re_delete(3);
	one.showlist();
	std::cout << "#3" << std::endl;
	one.changename(2, "bilibili");
	one.changevalue(1, 0);
	one.showlist();
	std::cout << "#4" << std::endl;
	one.insert(0);
	std::cout << std::endl;
	one.showlist();

	system("pause");
	return 0;
}