#ifndef IDLE_H
#define IDLE_H

#include "Animation.h"
#include "State.h"

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation* a);
	void climbing(Animation * a);
};

#endif
