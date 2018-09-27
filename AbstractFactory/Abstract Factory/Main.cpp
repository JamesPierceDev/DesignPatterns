/// <summary>
/// @Author James Pierce
/// @Date 17/09/18
/// @Brief Basic implemenation of design patterns
/// @Brief Abstract factory, Cheshire cat, Bridge.
/// </summary>

#include <iostream>
#include "Factory.h"
#include "CharacterFactory.h"
#include <vector>
#include "DrawImpl.h"
#include "GraphicProxy.h"
#include "Player_AbsFactory.h"
#include "Player.h"

#include "HandleToCharacter.h"

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>true</returns>
int main()
{
	//ABSTRACT FACTORY
	std::cout << "ABSTRACT FACTORY DESIGN PATTERN" << std::endl;
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}
	std::cout << "/////////////////////" << std::endl;

	//BRIDGE/HANDLE/CHESHIRE CAT
	std::cout << "BRIDGE DESIGN PATTERN" << std::endl;

	HandleToCharacter handle;
	handle->Print();

	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->draw();


	std::cout << "/////////////////////" << std::endl;

	std::cout << "PROXY DESIGN PATTERN" << std::endl;
	//Proxy
	GraphicProxy gp;
	gp.Draw();

	std::cout << "/////////////////////" << std::endl;
	std::cin.get();
	
	return 1;
}