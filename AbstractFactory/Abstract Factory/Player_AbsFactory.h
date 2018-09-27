#ifndef PLAYER_ABSFACTORY_H
#define PLAYER_ABSFACTORY_H

#include "Character.h"
#include <iostream>

class Player_AbsFactory : public Character
{
public:
	void draw() {
		std::cout << "Draw Player" << std::endl;
	}
};

#endif