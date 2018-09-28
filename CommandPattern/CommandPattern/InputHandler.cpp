#include "InputHandler.h"
#include <SDL.h>

void InputHandler::handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				//Do stuff for space
				buttonSpace_->execute();

			}
			else if (e.key.keysym.sym == SDLK_LCTRL)
			{
				//Do stuff for l-ctrl
				buttonLCtrl_->execute();
			}
		}
	}
}