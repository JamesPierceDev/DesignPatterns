#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include "InputHandler.h"
#include "Animation.h"

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
	Animation * a;
	AnimatedSprite * m_sprite;
	bool is_Running;

	SDL_Texture * walk_Texture;
};

#endif