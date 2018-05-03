#ifndef PLAYER_H    
#define PLAYER_H

#include "stdafx.h"
#include <string>
#include <iostream>

class Player
{
private:
	std::string m_type;
	std::string m_name;
	int m_money;
	int m_score;
	int m_wins;
	int m_total_rounds;
	int m_bet_amount;

public:
	Player(std::string name);
	void set_user();
	void set_money(int amount);
	int get_money();
	void roll();
	void add_money(int bet);
	void lose_money(int bet);
	void get_info();
	int get_bet_amount();
	void set_bet_amount(int amount);
	int get_score();
	void add_win();
	int get_wins();
	std::string get_name();
};

Player make_player(std::string name, int bank);

#endif