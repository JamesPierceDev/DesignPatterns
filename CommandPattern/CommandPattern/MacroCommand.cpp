#include "MacroCommand.h"
#include <iterator>
#include <list>

void MacroCommand::execute()
{
	std::_List_iterator<Command*> i(commands);
}