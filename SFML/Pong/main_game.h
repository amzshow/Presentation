#pragma once
#include "game_state.h"
#include "entity.h"
#include "paddle_player.h"
#include "ball.h"
#include "score.h"

class main_game : public tinyState
{
public:
	void initialize(sf::RenderWindow *window);
	void update(sf::RenderWindow *window);
	void render(sf::RenderWindow *window);
	void destroy(sf::RenderWindow *window);
private:
	paddle_player *player1;
	paddle_player *player2;
	ball *ballObject;
	Score *score1;
	Score *score2;
	sf::Font *font;
};