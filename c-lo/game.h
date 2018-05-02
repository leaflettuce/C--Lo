#ifndef GAME_H    
#define GAME_H

#include "stdafx.h"
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "player.h"

int get_number();
int get_roll();
std::string roll_name(int roll);
int get_players();
void compare_scores(Player player, Player ai_1, Player ai_2, Player ai_3);
#endif