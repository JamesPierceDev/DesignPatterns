#ifndef POSITIONSYSTEM_H
#define POSITIONSYSTEM_H

#include "System.h"
#include <iostream>

#include "Component.h"

class PositionSystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	void update()
	{
		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{
				if (c->getType() == "POSITION")
				{
					dynamic_cast<PositionComponent*>(c)->update();
				}
			}
		}
	}
};

#endif
