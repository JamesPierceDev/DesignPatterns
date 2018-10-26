#include "Game.h"
#include <iostream>

/// <summary>
/// 
/// </summary>
Game::Game()
{
	m_window = NULL;
	m_renderer = NULL;
	isRunning = true;
	SDL_Event event;
	SDL_PollEvent(&event);
	SDL_Delay(3000);
	handler = new InputHandler();
	m_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	std::string fp = "assets\\mario_sprite_run.png";

	int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(img_flags) != img_flags)
	{
		std::cout << "Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		walk_Texture = IMG_LoadTexture(m_renderer, "assets\\mario_sprite_run.png");
	}

	m_sprite = new AnimatedSprite(walk_Texture);
	a = new Animation(m_sprite);
}

/// <summary>
/// 
/// </summary>
Game::~Game()
{
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
void Game::run()
{
	const Uint16 fps = 60;
	const Uint16 minFrameTime = 1000 / fps;

	Uint16 frameTime;
	Uint16 previousFrameTime = 0;
	Uint16 dt = 0;

	while (isRunning)
	{
		processEvents();
		frameTime = SDL_GetTicks();

		dt = frameTime - previousFrameTime;
		previousFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minFrameTime)
		{
			SDL_Delay(minFrameTime - (SDL_GetTicks() - frameTime));
		}
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::processEvents()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
				break;
			}
		}
	}
}

/// <summary>
/// 
/// </summary>
void Game::update()
{

}

/// <summary>
/// 
/// </summary>
void Game::render()
{
	SDL_Rect * m_rect = new SDL_Rect();
	SDL_Rect * m_dst = new SDL_Rect();
	m_rect->x = 0;
	m_rect->y = 0;
	m_rect->w = 16;
	m_rect->h = 32;
	m_dst->x = 100;
	m_dst->y = 100;
	m_dst->w = 16;
	m_dst->h = 32;
	std::cout << "Render loop" << std::endl;



	if (m_renderer == nullptr) {
		std::cout << "Norenderere dude" << std::endl;
	}

	
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderCopy(m_renderer, walk_Texture, m_rect, m_dst);

	SDL_RenderPresent(m_renderer);
}