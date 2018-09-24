#ifndef BOSS_H
#define BOSS_H

#include <iostream>

class Boss : public Character
{
public:
	void draw()
	{
		std::cout << "Boss : Draw" << std::endl;
	}
};

#endif