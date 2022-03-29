#include "ball.h"

ball::ball(Score *score1, Score *score2, paddle_player *player1, paddle_player *player2)
{
	this->player1 = player1;
	this->player2 = player2;
	this->score1 = score1;
	this->score2 = score2;
	this->load("ball.png");
	this->velocity.x = 1.5f;
	this->velocity.y = 1.5f;
	this->buffer = new sf::SoundBuffer();
	this->buffer->loadFromFile("Resources/bounce.wav");
	this->sound = new sf::Sound(*this->buffer);
}

void ball::update(sf::RenderWindow *window)
{
	if (this->checkCollision(this->player1) || this->checkCollision(this->player2))
	{
		this->velocity.x *= -1;
		this->sound->play();
	}

	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
	{
		this->velocity.y *= -1;
		this->sound->play();
	}

	if (this->getPosition().x < this->player1->getGlobalBounds().width - 5)
	{
		this->score2->incrimentScore();
		this->reset(window);
	}

	if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x - this->player2->getGlobalBounds().width + 5)
	{
		this->score1->incrimentScore();
		this->reset(window);
	}

	Entity::update();
}

void ball::reset(sf::RenderWindow *window)
{
	this->velocity.x = 1.5f;
	this->velocity.y = 1.5f;
	this->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
}

ball::~ball()
{
	delete this->sound;
	delete this->buffer;
}