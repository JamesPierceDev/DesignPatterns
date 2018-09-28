#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Command.h"

class InputHandler
{
public:
	void handleInput();
private:
	Command * buttonF_;
	Command * buttonShift_;
	Command * buttonSpace_;
	Command * buttonLCtrl_;
};

#endif
