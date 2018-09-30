#ifndef MELEECOMMAND_H
#define MELEECOMMAND_H

#include "Command.h"

class MeleeCommand : public Command
{
public:
	virtual void execute() { melee(); }
};

#endif
