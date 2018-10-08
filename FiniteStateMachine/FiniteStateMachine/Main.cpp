#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "Game.h"

/// <summary>
/// Program Entry Point
/// </summary>
/// <returns></returns>
int main(int argc, char* argv[])
{
	Game * game = new Game();
	game->initialize();

	while (game->isRunning())
	{
		//handle events
		game->update();
		game->render();
	}
	game->cleanUp();

	return 0;
}