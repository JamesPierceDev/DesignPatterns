#ifndef HANDLETOCHARACTER_H
#define HANDLETOCHARACTER_H

#include "Character_Bridge.h"

class HandleToCharacter
{
public:
	HandleToCharacter() : character(new Character_Bridge()) {}
	Character_Bridge* operator->() { return character;  }
private:
	Character_Bridge * character;
};

#endif