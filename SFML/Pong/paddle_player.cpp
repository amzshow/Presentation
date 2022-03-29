#include "paddle_player.h"

paddle_player::paddle_player(int player_number)
{
	this->player_number = player_number;
	this->load("paddle.png");
}

void paddle_player::update()
{
	if (player_number == 0)
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	else
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	Entity::update();

	if (this->getPosition().y < 0)
		this->move(0, 1.0f);
	if (this->getPosition().y + this->getGlobalBounds().height > 600)
		this->move(0, -1.0f);
}
