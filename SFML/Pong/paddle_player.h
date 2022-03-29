#pragma once
#include "entity.h"

class paddle_player : public Entity
{
private:
	int player_number;
public:
	paddle_player(int player_number);
	void update();	
};