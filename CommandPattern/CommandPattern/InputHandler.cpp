#include "InputHandler.h"
#include <SDL.h>

void InputHandler::init()
{
	jump = new JumpCommand();
	crouch = new CrouchCommand();
	fire = new FireCommand();
	melee = new MeleeCommand();
	macro = new MacroCommand();
}

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
				macro->add(jump);
			}
			else if (e.key.keysym.sym == SDLK_LCTRL)
			{
				macro->add(crouch);
			}
			else if (e.key.keysym.sym == SDLK_f)
			{
				macro->add(fire);
			}
			else if (e.key.keysym.sym == SDLK_m)
			{
				macro->add(melee);
			}
			else if (e.key.keysym.sym == SDLK_u)
			{
				macro->undo();
			}
			else if (e.key.keysym.sym == SDLK_r)
			{
				macro->redo();
			}
		}
		macro->execute();
		macro->clear();
	}
}
