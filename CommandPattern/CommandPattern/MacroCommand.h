#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <list>
#include <vector>
#include <stack>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void clear();
	virtual void execute();
	virtual void undo();
	virtual void redo();
private:
	std::vector<Command *> commands;
	std::stack<Command *> command_log;
	std::stack<Command *> undone_commands;
};

#endif
