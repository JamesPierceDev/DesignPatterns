#ifndef JUMPING_H
#define JUMPING_H

#include "Animation.h"
#include "State.h"

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
};

#endif