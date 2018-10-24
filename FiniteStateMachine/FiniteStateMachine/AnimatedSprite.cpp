#include "AnimatedSprite.h"
#include <SDL_image.h>

/// <summary>
/// 
/// </summary>
AnimatedSprite::AnimatedSprite(SDL_Texture* t)
{
	dst_Rect = new SDL_Rect();
	m_src = new SDL_Rect();
	dst_Rect->x = 100;
	dst_Rect->y = 100;
	dst_Rect->w = 16;
	dst_Rect->h = 32;
	m_src->x = 0;
	m_src->y = 0;
	m_src->w= 16;
	m_src->h = 32;

	m_current_frame = 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
AnimatedSprite::AnimatedSprite(SDL_Texture& t) : m_texture(&t), m_current_frame(0), currentTime(0.5f) {}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <param name="rect"></param>
AnimatedSprite::AnimatedSprite(SDL_Texture& t, SDL_Rect& rect) : m_texture(&t), m_current_frame(0), currentTime(0.5f) {
	m_frames.push_back(rect);
}

/// <summary>
/// 
/// </summary>
AnimatedSprite::~AnimatedSprite() {}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
const std::vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

/// <summary>
/// 
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
const SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

/// <summary>
/// 
/// </summary>
/// <param name="frame"></param>
void AnimatedSprite::addFrame(SDL_Rect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

SDL_Texture * AnimatedSprite::getTexture()
{
	return m_texture;
}

/// <summary>
/// 
/// </summary>
void AnimatedSprite::update(){
	Uint32 lastTime = 0;
	currentTime = SDL_GetTicks();
	if (currentTime > lastTime) {
		if (m_frames.size() > m_current_frame + 1)
		{
			m_current_frame++;
		}
		else {
			m_current_frame = 0;
		}
		lastTime = currentTime;
		currentTime = 0;
	}
}

/// <summary>
/// Utilises SDL_RenderCopy to render the sprite to
/// the window
/// </summary>
/// <param name="renderer"></param>
void AnimatedSprite::render()
{
	//Renders the current src rectangle at the the destination
	//SDL_RenderCopy(m_rendererRef, m_texture, m_srcs.at(m_current_frame), dst_Rect);
}