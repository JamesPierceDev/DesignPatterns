#ifndef FIRECOMMAND_H
#define FIRECOMMAND_H

#include "Command.h"

class FireCommand : public Command
{
public:
	virtual void execute() { fireGun(); }
};

#endif