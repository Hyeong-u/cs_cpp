#include <iostream>
#include "cal.h"

 
int main()
{
	char choice;
	std::cout << "c(C) or r(R) or t(T) 를 입력하시오." << std::endl;
	std::cin >> choice;
	int radious = 3;
	int width = 8;
	int height = 3;
	int bottom = 6;
	int t_height = 9;

	if (choice == 'c' || choice == 'C')
	{
		std::cout << "Radious for Circle = " << radious << std::endl;
		std::cout << "Circle[radious: 3] = " << calculateCircle(radious) << std::endl;
	}
	else if (choice == 'r' || choice == 'R')
	{
		std::cout << "width for Rectangle = " << width << std::endl;
		std::cout << "height for Rectangle = " << height << std::endl;
		std::cout << "Rectangle[width : 8, height :3 ] = " << calculateRectangle(width, height) << std::endl;
	}
	else if (choice == 't' || choice == 'T')
	{
		std::cout << "bottom for Rectangle = " << bottom << std::endl;
		std::cout << "height for Rectangle = " << t_height << std::endl;
		std::cout << "Rectangle[width : 8, height :3 ] = " << calculateRectangle(bottom, t_height) << std::endl;
	}
	else
	{
		std::cout << "잘못된 입력입니다.." << std::endl;
	}
	
	
	switch (choice)
	{
	case 'c' ://브레이크를 만나기 전까지 계속해서 간다 (의도적인 break 빼기)
		case 'C':
		std::cout << "Radious for Circle = " << radious << std::endl;
		std::cout << "Circle[radious: 3] = " << calculateCircle(radious) << std::endl;
		break;
	case 'r':
		case 'R':
		std::cout << "width for Rectangle = " << width << std::endl;
		std::cout << "height for Rectangle = " << height << std::endl;
		std::cout << "Rectangle[width : 8, height :3 ] = " << calculateRectangle(width, height) << std::endl;
		break;
	case 't':
		case 'T':
		std::cout << "bottom for Rectangle = " << bottom << std::endl;
		std::cout << "height for Rectangle = " << height << std::endl;
		std::cout << "Rectangle[width : 8, height :3 ] = " << calculateRectangle(bottom, t_height) << std::endl;
		break;
	default:
		std::cout << "잘못된 입력입니다." << std::endl;
		break;
	}
	



}