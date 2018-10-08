#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "Animation.h"
#include <SDL.h>

class InputHandler
{
public:
	void init();
	void handleInput(SDL_Event & e);
private:
	Animation * a;
};

#endif
