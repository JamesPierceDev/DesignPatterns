#include "InputHandler.h"
#include <SDL.h>

void InputHandler::handleInput()
{
	jump = new JumpCommand();
	crouch = new CrouchCommand();
	fire = new FireCommand();
	melee = new MeleeCommand();
	macro = new MacroCommand();

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				jump->execute();
				macro->add(jump);
			}
			else if (e.key.keysym.sym == SDLK_LCTRL)
			{
				crouch->execute();
				macro->add(crouch);
			}
			else if (e.key.keysym.sym == SDLK_f)
			{
				fire->execute();
				macro->add(fire);
			}
			else if (e.key.keysym.sym == SDLK_m)
			{
				melee->execute();
				macro->add(melee);
			}
			else if (e.key.keysym.sym == SDLK_u)
			{
				
			}
		}
	}
}