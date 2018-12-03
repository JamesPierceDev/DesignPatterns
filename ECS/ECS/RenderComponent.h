#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent() { m_type = "RENDER"; }

	void update()
	{
		std::cout << "Render" << std::endl;
	}
	std::string getType() { return this->m_type; }
private:

};

#endif
