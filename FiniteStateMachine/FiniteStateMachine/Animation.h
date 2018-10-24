#ifndef ANIMATION_H
#define ANIMATION_H

#include "State.h"
#include "AnimatedSprite.h"
#include <SDL.h>

class Animation
{
	class State* current;
	class State* previous;
public:
	Animation(AnimatedSprite * a);
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
private:
	AnimatedSprite * a_sprite;
};

#endif
