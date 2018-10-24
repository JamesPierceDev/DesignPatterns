#include "Game.h"
#include <iostream>

/// <summary>
/// 
/// </summary>
Game::Game()
{
	is_Running = true;
	SDL_Event event;
	SDL_PollEvent(&event);
	SDL_Delay(3000);
	handler = new InputHandler();
	m_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	std::string fp = "assets\\mario_sprite_run.png";

	int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(img_flags) != img_flags)
	{
		std::cout << "Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		walk_Texture = IMG_LoadTexture(m_renderer, "FiniteStateMachine\\assets\\mario_sprite_run.png");
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
void Game::handleEvents()
{
	while (true)
	{
		SDL_Event event;
		
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
			update();
		}
		handler->handleInput(event);
		render();
	}

}

/// <summary>
/// 
/// </summary>
void Game::update()
{
	handleEvents();
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
	SDL_RenderCopy(m_renderer, walk_Texture, m_rect, m_dst);
	SDL_RenderPresent(m_renderer);
}

/// <summary>
/// 
/// </summary>
void Game::initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed, SDL Error: " << std::endl;
	}
	else
	{
		std::cout << "SDL initialization succeeded!" << std::endl;
	}

	m_window = SDL_CreateWindow("Demo Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1366,
		768,
		SDL_WINDOW_OPENGL);
	if (m_window == nullptr)
	{
		std::cout << "Could not create window" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
void Game::cleanUp()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

/// <summary>
/// Getter method for is_Running
///  private bool
/// </summary>
/// <returns></returns>
bool Game::isRunning()
{
	return is_Running;
}
