#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "player.h"
#include "screens.h"

int main()
{
	srand(time(NULL));
	Player player = welcome_screen(); //Initiate
	

	//create AI
	int bank = player.get_money();
	Player ai_1 = make_player("AI - Ben", bank);
	Player ai_2 = make_player("AI - Tissue", bank);
	Player ai_3 = make_player("AI - Kyle", bank);

	//Main screen
	main_screen(player, ai_1, ai_2, ai_3);

	return 0;
}

