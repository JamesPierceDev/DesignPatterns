#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")

#include <iostream>
#include "Game.h"

int main(int argc, char * argv[])
{
	Game * game;
	game = new Game();
	game->run();
	return 0;
}