# include<iostream>
# include"func1.h"

int main(void)
{
	std::cout << "#1 : " << std::endl;
	GOLF user;
	user.showgolf();

	std::cout << "#2 : " << std::endl;
	std::cout << "please enter the name and handicap : ";
	char name[40];
	std::cin >> name;
	int handicap;
	std::cin >> handicap;
	user = GOLF(name, handicap);
	user.showgolf();

	std::cout << "#3 : " << std::endl;
	std::cout << "enter the handicap again : ";
	std::cin >> handicap;
	user.Handicap(handicap);
	user.showgolf();

	std::cout << "Done ! \n";
}