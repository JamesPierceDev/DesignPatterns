#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <stdlib.h>
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "RenderComponent.h"
#include "RenderSystem.h"
#include "ControlComponent.h"
#include "ControlSystem.h"
#include "AISystem.h"
#include "Entity.h"

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

	//Entities
	Entity * m_player;
	Entity * m_alien;
	Entity * m_cat;
	Entity * m_dog;

	//Player Components
	HealthComponent * hc;
	PositionComponent * pc;
	RenderComponent * rc;
	ControlComponent * cc;

	//Alien Components
	HealthComponent * alien_health;
	PositionComponent * alien_pos;
	RenderComponent * alien_render;

	//Cat components
	HealthComponent * cat_health;
	PositionComponent * cat_pos;
	RenderComponent * cat_render;

	//Dog Components
	HealthComponent * dog_health;
	PositionComponent * dog_pos;
	RenderComponent * dog_render;
	ControlComponent * dog_control;

	//Systems
	ControlSystem * cs;
	AISystem * as;
	HealthSystem * hs;
	RenderSystem * rs;
	PositionSystem * ps;
};

#endif