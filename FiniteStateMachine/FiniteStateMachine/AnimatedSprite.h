#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL.h>
#include <vector>
#include "Sprite.h"
#include <iostream>

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(SDL_Texture *);
	AnimatedSprite(SDL_Texture&);
	AnimatedSprite( SDL_Texture&, SDL_Rect&);
	~AnimatedSprite();

	void LoadTexture(std::string fileName);
	const std::vector<SDL_Rect>& getFrames();
	const SDL_Rect& getFrame(int);
	void addFrame(SDL_Rect&);
	const int getCurrentFrame();
	SDL_Texture * getTexture();
	void update();
	void render();
	
private:
	Uint32 currentTime;
	std::vector<SDL_Rect> m_frames;
	std::vector<SDL_Rect*> m_srcs;
	SDL_Rect * m_src;
	SDL_Rect * dst_Rect;
	SDL_Texture * m_texture;
	int m_current_frame;
};

#endif // !ANIMATED_SPRITE_H
