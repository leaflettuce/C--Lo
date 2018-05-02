#include "stdafx.h"
#include "player.h"
#include "game.h"


	Player::Player(std::string name) //Constructor
	{
		m_name = name;
		m_bet_amount = 1;
		m_type = "AI";
		m_money = 0;
		m_score = 9;
		m_wins = 0;
		m_total_rounds = 0;
	}

	void Player::set_user() //sets from AI to user
	{
		m_type = "User";
	}

	void Player::set_bet_amount(int amount) //sets from AI to user
	{
		while (m_type == "User" && amount > m_money)
		{
			std::cout << "You don't have enough money, set a new amount to bet: ";
			std::cin >> amount;
		}

		m_bet_amount = amount;
	}

	int Player::get_bet_amount() //sets from AI to user
	{
		return m_bet_amount;
	}

	void Player::set_money(int amount)  //edits player dollar allowance
	{
		if (amount > 100000) //Too much
		{
			std::cout << "Max allowance is $100,000.. Set another amount: ";
			std::cin >> amount;
			set_money(amount);
		}

		if (amount <= 0) //not enough
		{
			std::cout << "Need at least $1 to bet with... Set another amount: ";
			std::cin >> amount;
			set_money(amount);
		}

		m_money = amount;
	}

	int Player::get_money() //get cash balance of player
	{
		return m_money;
	}

	void Player::roll() //roll a hand
	{
		m_score = 9;

		while (m_score == 9)    //continue until a score is hit
		{
			m_score = get_roll();
		}

		std::cout << m_name << " rolled a: " << roll_name(m_score) << "\n" << std::endl;  //report roll
	}

	void Player::add_money(int bet)
	{
		m_money += bet;
	}

	void Player::lose_money(int bet)
	{
		m_money -= bet;
	}

	int Player::get_score()
	{
		return m_score;
	}

	std::string Player::get_name()
	{
		return m_name;
	}

	void Player::get_info()
	{
		std::cout << "Your name: " << m_name << std::endl;
		std::cout << "Player type: " << m_type << std::endl;
		std::cout << "Amount in Bank: " << m_money << std::endl;
		std::cout << "Games won: " << m_wins << std::endl;
		std::cout << "Games played: " << m_total_rounds << std::endl;
		std::cout << "Last score rolled: " << roll_name(m_score) << std::endl;
	};

	Player make_player(std::string name, int bank)
	{
		Player player(name); //create player
		player.set_money(bank); //set money

		return player;
	}