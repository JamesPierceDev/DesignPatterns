#include "Animation.h"
#include "Idle.h"

Animation::Animation()
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