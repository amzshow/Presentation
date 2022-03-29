#include "game_state.h"
#include "main_menu.h"
#include "main_game.h"

game_state coreState;
bool quitGame = false;

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(120);
	coreState.setWindow(&window);
	coreState.setState(new main_menu());

	sf::Texture texture;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		coreState.update();
		coreState.render();
		window.display();
		if (quitGame)
			window.close();
	}

	return 0;

}
















/*
void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GAME");
	sf::Texture texture;
	texture.loadFromFile("mario.png");				//sprite image source location
	texture.setRepeated(true);
	window.setFramerateLimit(60);					//set frame rate limit
	sf::Sprite sprite(texture);						//set sprite
	sprite.setScale(sf::Vector2f(0.25f, 0.25f));	//scale the sprite
	sprite.setTextureRect(sf::IntRect(0,0,200*1,200*1));		//0,0, Repeat right 1X... Repeat down 1X
	sprite.setOrigin(sf::Vector2f(0,-2000));		//X,Y origin position
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				sprite.move(sf::Vector2f(2, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				sprite.move(sf::Vector2f(-2, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{

				texture.loadFromFile("marioJump.png");
				for (int c = 20; c > 0; c--)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						sprite.move(sf::Vector2f(2, 0));
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						sprite.move(sf::Vector2f(-2, 0));
					sprite.move(0, -4.0);
					window.clear();
					window.draw(sprite);
					window.display();
				}

				for (int c = 20; c > 0; c--)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						sprite.move(sf::Vector2f(2, 0));
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						sprite.move(sf::Vector2f(-2, 0));
					sprite.move(0, 4.0);
					window.clear();
					window.draw(sprite);
					window.display();
				}
				texture.loadFromFile("mario.png");
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				sprite.move(sf::Vector2f(2, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				sprite.move(sf::Vector2f(-2, 0));
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	

}
*/
