#include "InputHandler.h"

/// <summary>
/// 
/// </summary>
/// <param name="e"></param>
void InputHandler::handleInput(SDL_Event & e)
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_SPACE)
			{

			}
			else if (e.key.keysym.sym == SDLK_LCTRL)
			{

			}
		}
		else
		{

		}
	}
}


