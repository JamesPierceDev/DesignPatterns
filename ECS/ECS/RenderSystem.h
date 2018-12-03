#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "System.h"
#include <iostream>
#include "Component.h"
#include "RenderComponent.h"

class RenderSystem : public System
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
				if (c->getType() == "RENDER")
				{
					dynamic_cast<RenderComponent*>(c)->update();
				}
			}
		}
	}
};

#endif