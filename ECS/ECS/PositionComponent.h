#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : m_position(std::make_pair(100, 100)) { setType("POSITION"); }

	void update() {
		//this->m_position.first++;
		//this->m_position.second++;
		std::cout << "Position X: " << this->m_position.first <<
			"Position Y: " << this->m_position.second << std::endl;
	}
	std::string getType() { return this->m_type; }
	std::pair<int, int> getPosition() { return m_position; }
	void setPosition(std::pair<int, int> p) { m_position = p; }
private:
	std::pair<int, int> m_position;
};

#endif
