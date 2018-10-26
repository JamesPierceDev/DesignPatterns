#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <stdlib.h>
#include "InputHandler.h"
#include "Animation.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	bool isRunning;
private:
	void processEvents();
	void update();
	void render();

	SDL_Window * m_window; 
	SDL_Renderer * m_renderer;
	InputHandler * handler; 
	Animation * a;
	AnimatedSprite * m_sprite;


	SDL_Texture* walk_Texture;
};

#endif