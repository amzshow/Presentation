#include "main_menu.h"
#include "main_game.h"
#include "entity.h"
#include "paddle_player.h"

void main_game::initialize(sf::RenderWindow *window)
{
	this->font = new sf::Font;
	this->font->loadFromFile("font.ttf");
	this->score1 = new Score(*font, 64U);
	this->score2 = new Score(*font, 64U);

	this->score2->setPosition(window->getSize().x - this->score2->getGlobalBounds().width, 0);

	this->player1 = new paddle_player(0);
	this->player2 = new paddle_player(1);
	this->player1->setPosition(0, window->getSize().y / 2.0f - this->player1->getGlobalBounds().height / 2.0f);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2.0f - this->player2->getGlobalBounds().height / 2.0f);

	this->ballObject = new ball(this->score1, this->score2, this->player1, this->player2);
	this->ballObject->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
}

void main_game::update(sf::RenderWindow *window)
{
	this->player1->update();
	this->player2->update();
	this->ballObject->update(window);
	this->score1->update();
	this->score2->update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		coreState.setState(new main_menu());
}

void main_game::render(sf::RenderWindow *window)
{
	window->draw(*this->score1);
	window->draw(*this->score2);
	window->draw(*this->ballObject);
	window->draw(*this->player1);
	window->draw(*this->player2);
}

void main_game::destroy(sf::RenderWindow *window)
{
	delete this->player1;
	delete this->player2;
	delete this->ballObject;
	delete this->score1;
	delete this->score2;
}