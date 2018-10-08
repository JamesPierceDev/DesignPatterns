#ifndef ANIMATION_H
#define ANIMATION_H

#include "State.h"

class Animation
{
	class State* current;
	class State* previous;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void setPrevious(State* s)
	{
		previous = s;
	}
	void idle();
	void jumping();
	void climbing();
};

#endif
