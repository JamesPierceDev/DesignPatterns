#ifndef CLIMBING_H
#define CLIMBING_H

#include "Animation.h"
#include "State.h"
#include "Idle.h"

class Climbing
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a)
	{
		std::cout << "Going from Climbing to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};

#endif
