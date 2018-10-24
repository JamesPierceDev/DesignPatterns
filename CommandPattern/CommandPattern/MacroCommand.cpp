#include "MacroCommand.h"
#include <iterator>

/// <summary>
/// 
/// </summary>
MacroCommand::MacroCommand()
{
}

/// <summary>
/// Execute the function of the current
/// command
/// </summary>
void MacroCommand::execute()
{
	auto iter = commands.begin(); //Set iterator to start of vector
	auto endIter = commands.end(); //Set iterator to end of vector
	for (iter; iter != endIter; iter++) //Loop while iter is not equal to end
	{
		auto c = *iter; //Deref iterator to get object
		c->execute(); //Call execute for that command
	}
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
void MacroCommand::undo()
{
	if (command_log.size() > 0)
	{
		//Add the last command performed to a stack
		undone_commands.push(command_log.top());
		//Pop the last command off the stack
		command_log.pop();
		std::cout << "Undo last command" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
void MacroCommand::redo()
{
	if (undone_commands.size() > 0)
	{
		commands.insert(commands.end(), undone_commands.top());
		std::cout << "Redo last command" << std::endl;
		undone_commands.pop();
	}
}

/// <summary>
/// Push back a new command into the
/// vector
/// </summary>
/// <param name="c"></param>
void MacroCommand::add(Command * c)
{
	commands.push_back(c);
	command_log.push(c);
}

/// <summary>
/// Removes the element C from the vector
/// using Erase-Remove
/// </summary>
/// <param name="c"></param>
void MacroCommand::remove(Command * c)
{
	//Erase Remove the element
	for (auto i = commands.begin(); i != commands.end(); i++)
	{
		//If c is found
		if (*i = c)
		{
			i = commands.erase(i); //Erase element
			--i; //Decrement iterator
			break; //Break out of loop
		}
	}
}

void MacroCommand::clear()
{
	commands.clear();
}
