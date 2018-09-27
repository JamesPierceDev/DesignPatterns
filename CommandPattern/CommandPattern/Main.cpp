#ifdef _DEBUG
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#else
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#endif

#include <SDL.h>
#include <iostream>

/// <summary>
/// Program Entry Point
/// </summary>
/// <returns></returns>
int main(int argc, char* argv[] )
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed, SDL Error: " << std::endl;
	}
	else
	{
		std::cout << "SDL initialization succeeded!" << std::endl;
	}

	std::cin.get();
	return 0;
}