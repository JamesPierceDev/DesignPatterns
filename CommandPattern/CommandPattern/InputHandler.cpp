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
				std::cout << "SPACE pressed" << std::endl;
				jump->execute();
				
			}
			else if (e.key.keysym.sym == SDLK_LCTRL)
			{
				std::cout << "CTRL pressed" << std::endl;
				crouch->execute();
			}
		}
	}
}