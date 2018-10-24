#include "Sprite.h"

Sprite::Sprite()
{
}

/// <summary>
/// 
/// </summary>
Sprite::Sprite(SDL_Texture& _tx, int _px, int _py, int _wx, int _wy):
	m_texture(&_tx),
	m_rect(new SDL_Rect({_px, _py, _wx, _wy}))
{

}

/// <summary>
/// 
/// </summary>
Sprite::~Sprite()
{
}
