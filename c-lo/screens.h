#ifndef SCREENS_H    
#define SCREENS_H

#include "stdafx.h"
#include <iostream>
#include "player.h"
#include "game.h"

Player welcome_screen();
void main_screen(Player player, Player ai_1, Player ai_2, Player ai_3);
void end_screen();

#endif