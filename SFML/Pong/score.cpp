#include "score.h"

Score::Score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size)
{
	this->value = 0;
}

void Score::incrimentScore()
{
	this->value = this->value + 1;
}

void Score::update()
{
	this->setString("Score: " + std::to_string(this->value));
}

int Score::getScore()
{
	return this->value;
}