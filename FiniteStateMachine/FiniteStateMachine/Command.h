#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {}

};

class WalkCommand : public Command
{
	virtual void execute()
	{
		//Do the things
	}
};


#endif