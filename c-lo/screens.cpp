#include "stdafx.h"
#include "screens.h"

Player welcome_screen() //set up player
{
	using namespace std;

	cout << "Welcome to C++ Lo!" << endl << "." << endl << "." << endl << "." << endl; //welcome line

	cout << "What is your name?: ";  //get name
	std::string name("");
	cin >> name;

	cout << "How much would you like to bring to the table? (0 - 100,000): "; //get bank amount
	int bank(0);
	cin >> bank;

	Player player = make_player(name, bank);
	player.set_user();

	return player;
}

void main_screen(Player player, Player ai_1, Player ai_2, Player ai_3)
{
	using namespace std;

	cout << ".\n.\n" << "You have $" << player.get_money() << " in your wallet." << endl;
	cout << "You are betting $" << player.get_bet_amount() << " per roll" << endl << endl;
	
	cout << "What would you like to do?" << endl;
	cout << "(i) - information" << endl;
	cout << "(c) - change bet amount" << endl;
	cout << "(r) - roll! \n.\n." << endl;

	string input;   //get input
	cin >> input;
	
	//else do command
	if (input == "i") //info
	{
		player.get_info();
		ai_1.get_info();
		ai_2.get_info();
		ai_3.get_info();
	}

	else if (input == "c")
	{
		cout << "What amount would you like to bet?: ";
		int bet_amount;
		cin >> bet_amount;
		player.set_bet_amount(bet_amount);
		ai_1.set_bet_amount(bet_amount);
		ai_2.set_bet_amount(bet_amount);
		ai_3.set_bet_amount(bet_amount);

		cout << "Betting amounts changed to $" << bet_amount << endl;
	}

	else if (input == "r")
	{
		player.roll();
		ai_1.roll();
		ai_2.roll();
		ai_3.roll();
		std::cout << ".\n.\n";
		compare_scores(player, ai_1, ai_2, ai_3);
	}

	else
	{
		cout << "Invalid entry..." << endl;
		main_screen(player, ai_1, ai_2, ai_3);
	}

}


void end_screen()
{
	using namespace std;

	cout << "You ran out of money :(" << endl;
	cout << "Goodbye.";
}