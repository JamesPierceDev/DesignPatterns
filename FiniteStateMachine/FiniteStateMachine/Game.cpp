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
	handler->init();
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
		handler->handleInput(event);
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
