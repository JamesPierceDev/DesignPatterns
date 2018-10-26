#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")

#include <iostream>
#include "Game.h"

/// <summary>
/// Program Entry Point
/// </summary>
/// <returns></returns>
int main(int argc, char* argv[])
{
	Game * game = new Game();
	game->run();

	return 0;
}