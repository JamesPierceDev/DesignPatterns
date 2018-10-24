#include "Animation.h"
#include "Idle.h"

Animation::Animation(AnimatedSprite * a) :
	a_sprite(a)
{
	current = new Idle();
}

void Animation::idle()
{
	this->setPrevious(this->current);
	current->idle(this);
}

void Animation::jumping()
{
	this->setPrevious(this->current);
	current->jumping(this);
}

void Animation::climbing()
{
	this->setPrevious(this->current);
	current->climbing(this);
}
