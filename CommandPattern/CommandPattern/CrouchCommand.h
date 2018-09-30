#ifndef CROUCHCOMMAND_H
#define CROUCHCOMMAND_H

#include "Command.h"
#include <iostream>

class CrouchCommand : public Command
{
public:
	virtual void execute() { crouch(); }
};

#endif
