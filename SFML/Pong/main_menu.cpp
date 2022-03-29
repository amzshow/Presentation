#include "main_menu.h"
#include "main_game.h"

void main_menu::initialize(sf::RenderWindow *window)
{
	this->selected = 0;
	font = new sf::Font();
	this->font->loadFromFile("font.ttf");
	title = new sf::Text("Pong", *this->font, 256U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2.0f, window->getSize().y / 8.0f);

	play = new sf::Text("Play", *this->font, 128U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);

	quit = new sf::Text("Quit", *this->font, 128U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f + this->quit->getGlobalBounds().height);
}

void main_menu::update(sf::RenderWindow *window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		this->selected = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		this->selected = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if (this->selected == 0)
			coreState.setState(new main_game());
		if (this->selected == 1)
			quitGame = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		quitGame = true;
}

void main_menu::render(sf::RenderWindow *window)
{
	this->play->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);
	switch (this->selected)
	{
	case 0 :
		this->play->setFillColor(sf::Color::Yellow);
		break;
	case 1:
		this->quit->setFillColor(sf::Color::Yellow);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
}

void main_menu::destroy(sf::RenderWindow *window)
{
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
}