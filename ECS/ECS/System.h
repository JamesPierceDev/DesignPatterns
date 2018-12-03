#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity.h"
#include <vector>

class System
{
public:
	virtual ~System() {};

protected:
	System();
	std::vector<Entity*> m_entities;
	void addEntity(Entity *);
	void update();
};

#endif
