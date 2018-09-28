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
		}
	}
}

/// <summary>
/// 
/// </summary>
void Game::update()
{
	std::cout << "Running Game Loop" << std::endl;
}

/// <summary>
/// 
/// </summary>
void Game::render()
{
	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_ACCELERATED);


	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer");
	}

	SDL_SetRenderDrawColor(m_renderer, 100, 149, 237, 255);
	SDL_RenderClear(m_renderer);

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
	SDL_DestroyRenderer(m_renderer);
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
