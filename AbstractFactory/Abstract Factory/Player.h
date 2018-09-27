#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "DrawAPI.h"

class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; }
	void draw() {
		api->Draw();
	}

private:
	DrawAPI * api;
};

#endif 