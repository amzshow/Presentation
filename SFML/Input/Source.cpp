#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

int main()
{
		
	const int WIDTH = 800;
	const int HEIGHT = 600;
	
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TicTacToe");
	window.setFramerateLimit(120);
	
	sf::Text text;
	sf::Font font;
	sf::String playerInput;
	if(!font.loadFromFile("font.ttf"))
		return -1;
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
	text.setCharacterSize(64);
	text.setPosition(10,HEIGHT / 2);
	text.setFillColor(sf::Color::White);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();				
				
			if (event.type == sf::Event::TextEntered)
			{
				if((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z') || 						(event.text.unicode >= '0' && event.text.unicode <= '9') || event.text.unicode == ' ')
				{
					playerInput += event.text.unicode;
					text.setString(playerInput);
				}
				else if (event.text.unicode == *"\u0008")
				{	
					playerInput = playerInput.substring(0, playerInput.getSize() - 1);
					text.setString(playerInput);
				}
			}
		}
							
		window.clear(sf::Color::Black);
		window.draw(text);
		window.display();
	}

	return 0;

}
