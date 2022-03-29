#pragma once
#include "paddle_player.h"
#include "score.h"
#include <SFML/Audio.hpp>


class ball: public Entity
{
private:
	paddle_player *player1;
	paddle_player *player2;
	Score *score1;
	Score *score2;
	sf::SoundBuffer *buffer;
	sf::Sound *sound;
public:
	ball(Score *score1, Score *score2, paddle_player *player1, paddle_player *player2);
	void update(sf::RenderWindow *window);
	void reset(sf::RenderWindow *window);
	~ball();
};
