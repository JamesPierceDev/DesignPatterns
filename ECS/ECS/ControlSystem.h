#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include "System.h"
#include <iostream>
#include "Component.h"
#include "ControlComponent.h"
#include "PositionComponent.h"
#include <SDL.h>

class ControlSystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	bool moving = false;
	bool posTaken = false;
	std::pair<int, int> tmp_pos;
	PositionComponent * pc = new PositionComponent();
	ControlComponent * cc = new ControlComponent();
	
	void update(SDL_Event &ev)
	{
		

		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{
				if (c->getType() == "CONTROL")
				{
					cc = dynamic_cast<ControlComponent*>(c);
				}

				if (c->getType() == "POSITION")
				{
					pc = dynamic_cast<PositionComponent*>(c);
				}
				
			}
			cc->update(ev);
			if (cc->move)
			{
				pc->setPosition(std::make_pair<int, int>(pc->getPosition().first + 10, pc->getPosition().second + 10));
				cc->move = false;
			}
		}

	}
};

#endif