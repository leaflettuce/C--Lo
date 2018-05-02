#include "stdafx.h"
#include "game.h"

int get_roll()  //Rolls three die and returns score
{
	int dice0, dice1, dice2;

	dice0 = get_number();
	dice1 = get_number();
	dice2 = get_number();

	std::cout << dice0 << ", " << dice1 << ", " << dice2 << "..." << std::endl;

	if (dice0 == 4)   //Check for 4,5,6
	{
		if ((dice1 == 5 || dice2 == 5) && (dice1 == 6 || dice2 == 6))
		{
			return 20;   //return top score
		}
	}

	if (dice0 == 5)   //Check for 4,5,6
	{
		if ((dice1 == 4 || dice2 == 4) && (dice1 == 6 || dice2 == 6))
		{
			return 20;   //return top score
		}
	}

	if (dice0 == 6)   //Check for 4,5,6
	{
		if ((dice1 == 5 || dice2 == 5) && (dice1 == 4 || dice2 == 4))
		{
			return 20;   //return top score
		}
	}

	if (dice0 == 1)   //Check for 1, 2, 3
	{
		if ((dice1 == 2 || dice2 == 2) && (dice1 == 3 || dice2 == 3))
		{
			return 0;   //return lowest score
		}
	}

	if (dice0 == 2)   //Check for 1, 2, 3
	{
		if ((dice1 == 1 || dice2 == 1) && (dice1 == 3 || dice2 == 3))
		{
			return 0;   //return lowest score
		}
	}

	if (dice0 == 3)   //Check for 1, 2, 3
	{
		if ((dice1 == 1 || dice2 == 1) && (dice1 == 2 || dice2 == 2))
		{
			return 0;   //return lowest score
		}
	}

	if (dice0 == dice1 && dice0 == dice2) //roll trips.
	{
		return (10 + dice0);
	}

	if (dice0 == dice1) //Return point
	{
		return dice2;
	}

	if (dice1 == dice2) //Return point
	{
		return dice0;
	}

	if (dice0 == dice2) //Return point
	{
		return dice1;
	}

	return 9;
}


int get_number()  //RNG for rolls
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
	case 11:
		return "triple 1";
	case 12:
		return "triple 2";
	case 13:
		return "triple 3";
	case 14:
		return "triple 4";
	case 15:
		return "triple 5";
	case 16:
		return "triple 6";
	case 0:
		return "1,2,3";
	case 20:
		return "4, 5, 6";
	default:
		return "Not Valid";
	}
}

int get_players()
	{
		int player_count(0);

		while (player_count <= 0 || player_count >= 11)
		{
			std::cout << "How many players would you like to bet against? (1 - 10): ";
			std::cin >> player_count;
		}
		return player_count;
	}



void compare_scores(Player player, Player ai_1, Player ai_2, Player ai_3)
{
	int bet_amount = player.get_bet_amount();
	//player wins
	if (player.get_score() > ai_1.get_score() && player.get_score() > ai_2.get_score() && player.get_score() > ai_3.get_score())
	{
		std::cout << player.get_name() << " won the round!" << std::endl;
		std::cout << bet_amount * 3 << " added to wallet! \n.\n." << std::endl;
		player.add_money(bet_amount * 3);
		ai_1.lose_money(bet_amount);
		ai_2.lose_money(bet_amount);
		ai_3.lose_money(bet_amount);
	}

	//ai_1 wins
	else if (ai_1.get_score() > player.get_score() && ai_1.get_score() > ai_2.get_score() && ai_1.get_score() > ai_3.get_score())
	{
		std::cout << ai_1.get_name() << " won the round." << std::endl;
		std::cout << "$" << bet_amount << " lost.. \n.\n." << std::endl;
		ai_1.add_money(bet_amount * 3);
		player.lose_money(bet_amount);
		ai_2.lose_money(bet_amount);
		ai_3.lose_money(bet_amount);
	}

	//ai_2 wins
	else if (ai_2.get_score() > ai_1.get_score() && ai_2.get_score() > player.get_score() && ai_2.get_score() > ai_3.get_score())
	{
		std::cout << ai_2.get_name() << " won the round." << std::endl;
		std::cout << "$" << bet_amount << " lost.. \n.\n." << std::endl;
		ai_2.add_money(bet_amount * 3);
		ai_1.lose_money(bet_amount);
		player.lose_money(bet_amount);
		ai_3.lose_money(bet_amount);
	}

	//ai_3 wins
	else if (ai_3.get_score() > ai_1.get_score() && ai_3.get_score() > ai_2.get_score() && ai_3.get_score() > player.get_score())
	{
		std::cout << player.get_name() << " won the round." << std::endl;
		std::cout << "$" << bet_amount << " lost.. \n.\n." << std::endl;
		ai_3.add_money(bet_amount * 3);
		ai_1.lose_money(bet_amount);
		ai_2.lose_money(bet_amount);
		player.lose_money(bet_amount);
	}

	else
	{
		std::cout << "Push -- No change in money! \n.\n.";
	}

}