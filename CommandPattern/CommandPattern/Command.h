#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command() {}
	void jump() { std::cout << "Jump!" << std::endl; }
	void crouch() { std::cout << "Crouch!" << std::endl; }
	void fireGun() { std::cout << "Fire Gun!" << std::endl; }
};

#endif