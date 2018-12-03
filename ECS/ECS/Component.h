#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

class Component
{
public:
	virtual ~Component() {};
	std::string getType() { return m_type; }
	
protected:
	Component();
	std::string m_type;
	void setType(std::string s) { m_type = s; }
};

#endif
