#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "Factory.h"
#include "Character.h"
#include "Player_AbsFactory.h"
#include "Boss.h"

class CharacterFactory : public Factory
{
public:
	Character* CreatePlayer() {
		return new Player_AbsFactory;
	}
	Character* CreateOpponents() {
		return new Boss;
	}
};

#endif