#ifndef ANIMATION_H
#define ANIMATION_H

#include "State.h"

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
};

#endif
