#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "InputHandler.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void render();
	void handleEvents();
	void initialize();
	void cleanUp();

	bool isRunning();
private:
	SDL_Window * m_window; 
	SDL_Renderer * m_renderer;
	InputHandler * handler;
	bool is_Running;

};

#endif