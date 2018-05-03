#include "stdafx.h"
#include "screens.h"

Player welcome_screen() //set up player
{
	using namespace std;

	cout << "Welcome to C++ Lo!" << endl << "." << endl << "." << endl << "." << endl; //welcome line
	this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << "What is your name?: ";  //get name
	std::string name("");
	cin >> name;

	this_thread::sleep_for(std::chrono::milliseconds(350));
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

	bool loop_test = 1;

	while (loop_test)
	{
		this_thread::sleep_for(std::chrono::milliseconds(300));
		cout << ".\n.\n" << "You have $" << player.get_money() << " in your wallet." << endl;
		this_thread::sleep_for(std::chrono::milliseconds(200));
		cout << "You are betting $" << player.get_bet_amount() << " per roll" << endl << endl;
		this_thread::sleep_for(std::chrono::milliseconds(750));

		cout << "What would you like to do?" << endl;
		cout << "(i) - information" << endl;
		cout << "(c) - change bet amount" << endl;
		cout << "(r) - roll!" << endl;
		cout << "(e) - end game. \n.\n." << endl;

		string input;   //get input
		cin >> input;

		//else do command
		if (input == "i") //info
		{
			player.get_info();
			cout << "\n.\n";
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			ai_1.get_info();
			cout << "\n.\n";
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			ai_2.get_info();
			cout << "\n.\n";
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			ai_3.get_info();
			this_thread::sleep_for(std::chrono::milliseconds(1500));
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

			this_thread::sleep_for(std::chrono::milliseconds(200));
			cout << "Betting amounts changed to $" << bet_amount << endl;
		}

		else if (input == "r")
		{
			cout << "You are rolling.." <<endl;
			this_thread::sleep_for(std::chrono::milliseconds(250));
			player.roll();
			std::this_thread::sleep_for(std::chrono::milliseconds(750));

			cout << ai_1.get_name() << " is rolling.." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(250));
			ai_1.roll();
			std::this_thread::sleep_for(std::chrono::milliseconds(750));

			cout << ai_2.get_name() << " is rolling.." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(250));
			ai_2.roll();
			std::this_thread::sleep_for(std::chrono::milliseconds(750));

			cout << ai_3.get_name() << " is rolling.." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(250));
			ai_3.roll();
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
			std::cout << ".\n.\n";

			string winner = compare_scores(player, ai_1, ai_2, ai_3); //returns name of winner
			int bet_amount = player.get_bet_amount();

			if (winner == player.get_name())     //player wins
			{
				std::cout << "You won the round!!" << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));
				std::cout << "$"<< bet_amount * 3 << " added to your wallet! \n.\n." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));

				player.add_money(bet_amount * 3);
				player.add_win();
				ai_1.lose_money(bet_amount);
				ai_2.lose_money(bet_amount);
				ai_3.lose_money(bet_amount);
			}

			if (winner == ai_1.get_name())     //ai 1 wins
			{
				std::cout << ai_1.get_name() << " won the round.." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));
				std::cout << "You lost $" << bet_amount << " :( \n.\n." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));

				ai_1.add_money(bet_amount * 3);
				ai_1.add_win();
				player.lose_money(bet_amount);
				ai_2.lose_money(bet_amount);
				ai_3.lose_money(bet_amount);
			}


			if (winner == ai_2.get_name())     //ai 2 wins
			{
				std::cout << ai_2.get_name() << " won the round.." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));
				std::cout << "You lost $" << bet_amount << " :( \n.\n." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));

				ai_2.add_money(bet_amount * 3);
				ai_2.add_win();
				player.lose_money(bet_amount);
				ai_1.lose_money(bet_amount);
				ai_3.lose_money(bet_amount);
			}

			if (winner == ai_3.get_name())     //ai 3 wins
			{
				std::cout << ai_3.get_name() << " won the round.." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));
				std::cout << "You lost $" << bet_amount << " :( \n.\n." << std::endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));

				ai_3.add_money(bet_amount * 3);
				ai_3.add_win();
				player.lose_money(bet_amount);
				ai_2.lose_money(bet_amount);
				ai_1.lose_money(bet_amount);
			}

			if (winner == "push")
			{
				cout << "PUSH -- No change in money... Reroll!. \n" << endl;
				this_thread::sleep_for(std::chrono::milliseconds(150));
			}
		}

		else if (input == "e") //ending game
		{
			loop_test = 0;
			break;
		}

		else   //inproper key entry
		{
			cout << "Invalid entry..." << endl;
			main_screen(player, ai_1, ai_2, ai_3);
		}

		if (player.get_money() <= 0) { loop_test = 0; } //break while if under $1
	}

	end_screen(player, ai_1, ai_2, ai_3);
}


void end_screen(Player player, Player ai_1, Player ai_2, Player ai_3)
{
	using namespace std;

	if (player.get_money() <= 0)
	{
		cout << "You ran out of money :(\n.\n." << endl;
	}
	else
	{
		cout << "You ended with $" << player.get_money() << endl;
	}
	this_thread::sleep_for(std::chrono::milliseconds(350));
	cout << ai_1.get_name() << " ended with $" << ai_1.get_money() << endl;
	this_thread::sleep_for(std::chrono::milliseconds(350));
	cout << ai_2.get_name() << " ended with $" << ai_2.get_money() << endl;
	this_thread::sleep_for(std::chrono::milliseconds(350));
	cout << ai_3.get_name() << " ended with $" << ai_3.get_money() << endl;
	this_thread::sleep_for(std::chrono::milliseconds(1500));
	cout << ".\n.\n.\n.";
	cout << "Goodbye.";
}