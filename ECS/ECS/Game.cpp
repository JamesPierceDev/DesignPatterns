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
	m_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	m_player = new Entity();
	m_alien = new Entity();
	m_cat = new Entity();
	m_dog = new Entity();

	//Player components
	hc = new HealthComponent();
	pc = new PositionComponent();
	rc = new RenderComponent();
	cc = new ControlComponent();

	//Alien components
	alien_health = new HealthComponent();
	alien_pos = new PositionComponent();
	alien_render = new RenderComponent();

	//Cat Components
	cat_health = new HealthComponent();
	cat_pos = new PositionComponent();
	cat_render = new RenderComponent();

	//Dog Components
	dog_health = new HealthComponent();
	dog_pos = new PositionComponent();
	dog_render = new RenderComponent();
	dog_control = new ControlComponent();

	//Systems
	cs = new ControlSystem();
	rs = new RenderSystem();
	ps = new PositionSystem();
	hs = new HealthSystem();
	as = new AISystem();

	//Link Entity, system, and components
	//m_player->addComponent(hc);
	//hs->addEntity(m_player);
	//m_player->addComponent(pc);
	//ps->addEntity(m_player);
	//m_player->addComponent(rc);
	//rs->addEntity(m_player);
	//m_player->addComponent(cc);
	//cs->addEntity(m_player);

	//Alien
	//m_alien->addComponent(alien_health);
	//hs->addEntity(m_alien);
	//m_alien->addComponent(alien_pos);
	//ps->addEntity(m_alien);
	//m_alien->addComponent(alien_render);
	//rs->addEntity(m_alien);
	//as->addEntity(m_alien);

	//Cat
	//m_cat->addComponent(cat_health);
	//hs->addEntity(m_cat);
	//m_cat->addComponent(cat_pos);
	//ps->addEntity(m_cat);
	//m_cat->addComponent(cat_render);
	//rs->addEntity(m_cat);
	//as->addEntity(m_cat);

	//Dog
	m_dog->addComponent(dog_health);
	hs->addEntity(m_dog);
	m_dog->addComponent(dog_pos);
	ps->addEntity(m_dog);
	m_dog->addComponent(dog_render);
	rs->addEntity(m_dog);
	m_dog->addComponent(dog_control);
	cs->addEntity(m_dog);

	//as->addEntity(m_dog);
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
	const Uint16 fps = 1000;
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
	SDL_Event e;

	hs->update();
	ps->update();
	rs->update();
	cs->update(e);
	as->update();
}

/// <summary>
/// 
/// </summary>
void Game::render()
{
	SDL_Rect * m_dst = new SDL_Rect();
	m_dst->x = 400;
	m_dst->y = 400;
	m_dst->w = 16;
	m_dst->h = 32;

	if (m_renderer == nullptr) {
		std::cout << "Failed to create renderer" << std::endl;
	}

	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderPresent(m_renderer);
}