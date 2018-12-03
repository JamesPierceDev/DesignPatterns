#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Component.h"

class Entity
{
public:
	Entity() {};
	std::vector<Component *> getComponents() { return m_components; }

	void addComponent(Component * c) { m_components.push_back(c); }
	void removeComponents(Component *) {}
	std::string getName() { return name; }
private:
	std::vector<Component *> m_components;
	int id;
	std::string name;
};

#endif
