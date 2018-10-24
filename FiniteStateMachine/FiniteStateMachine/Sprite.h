#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

class Sprite
{
public:
	Sprite();
	Sprite(SDL_Texture&, int, int, int, int);
	~Sprite();

private:
	SDL_Texture * m_texture;
	SDL_Rect * m_rect;

protected:


};

#endif
