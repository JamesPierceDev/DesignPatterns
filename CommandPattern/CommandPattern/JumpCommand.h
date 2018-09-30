#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

#include "Command.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	virtual void execute() { jump(); }
};

#endif