#include "stdafx.h"
#include "game.h"

int get_roll()
{
	return 0;
}

int get_number()
{
	return  1 + (rand() % 6);
}

std::string roll_name(int roll)
{
	switch (roll)
	{
	case 1:
		return "1";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 111:
		return "triple 1";
	case 222:
		return "triple 2";
	case 333:
		return "triple 3";
	case 444:
		return "triple 4";
	case 555:
		return "triple 5";
	case 666:
		return "triple 6";
	case 123:
		return "1,2,3";
	case 456:
		return "4, 5, 6";
	default:
		return 0;
	}
}