#ifndef FACTORY_H
#define FACTORY_H

#include "Character.h"

class Factory
{
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};

#endif