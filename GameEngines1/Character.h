#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
	Character() {}
	virtual ~Character() {}

	virtual void draw() = 0;
};

#endif

