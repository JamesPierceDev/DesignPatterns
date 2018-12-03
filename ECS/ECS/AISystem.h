#ifndef AISYSTEM_H
#define AISYSTEM_H

#include "System.h"
#include <iostream>
#include "Component.h"
#include "PositionComponent.h"
#include <SDL.h>

class AISystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	bool moving = false;
	bool posTaken = false;
	std::pair<int, int> tmp_pos;
	PositionComponent * pc = new PositionComponent();

	void update()
	{
		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{

				if (c->getType() == "POSITION")
				{
					pc = dynamic_cast<PositionComponent*>(c);

					pc->setPosition(std::make_pair<int, int>(pc->getPosition().first + 1, pc->getPosition().second + 1));
				}

			}
		}
	}
};

#endif