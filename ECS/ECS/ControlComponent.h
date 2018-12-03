#ifndef CONTROLCOMPONENT_H
#define CONTROLCOMPONENT_H

#include "Component.h"
#include <SDL.h>

class ControlComponent : public Component
{
public:
	ControlComponent() { setType("CONTROL"); }

	void update(SDL_Event & e) {
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_SPACE)
				{
					std::cout << "Space Pressed" << std::endl;
					move = true;
				}
			}
		}
	}
	bool getMoving() { return move; }
	std::string getType() { return this->m_type; }
	bool move = false;
private:

};

#endif
