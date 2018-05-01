#include "stdafx.h"
#include <iostream>
#include "game.h"

int main()
{

	int one(0), two(0), three(0), four(0), five(0), six(0), total(0);

	for (int i = 0; i < 10000; i++)
	{
		switch (get_number())
		{
		case 1:
			one += 1;
			break;
		case 2:
			two += 1;
			break;
		case 3:
			three += 1;
			break;
		case 4:
			four += 1;
			break;
		case 5:
			five += 1;
			break;
		case 6:
			six += 1;
			break;
		}
	}

	total = one + two + three + four + five + six;

	std::cout << "one: " << one << "      Percentage: " << ((float)one/total)*100 << std::endl;
	std::cout << "two: " << two << "      Percentage: " << ((float)two/total)*100 << std::endl;
	std::cout << "three: " << three << "      Percentage: " << ((float)three/total)*100 << std::endl;
	std::cout << "four: " << four << "      Percentage: " << ((float)four/total)*100 << std::endl;
	std::cout << "five: " << five << "      Percentage: " << ((float)five/total)*100 << std::endl;
	std::cout << "six: " << six << "      Percentage: " << ((float)six/total)*100 << std::endl;
	return 0;
}

