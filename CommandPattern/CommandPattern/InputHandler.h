#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Command.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "MacroCommand.h"
#include <iostream>

class InputHandler
{
public:
	void handleInput();
private:
	Command * buttonF_;
	Command * buttonShift_;
	Command * buttonSpace_;
	Command * buttonLCtrl_;
	JumpCommand * jump;
	CrouchCommand * crouch;
};

#endif
