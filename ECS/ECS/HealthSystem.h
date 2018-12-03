#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include "System.h"
#include <iostream>
#include "Component.h"

class HealthSystem : public System
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
				if (c->getType() == "HEALTH")
				{				
					dynamic_cast<HealthComponent*>(c)->update();				
				}
			}
		}
	}
};

#endif
