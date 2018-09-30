#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <list>
#include <vector>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void undo(Command*);
	virtual void redo(Command*);
private:
	std::vector<Command *> commands;
};

#endif
