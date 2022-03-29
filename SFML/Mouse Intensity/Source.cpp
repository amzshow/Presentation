#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

bool quitGame = false;

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Intensity");
	window.setFramerateLimit(120);
	long int time = 0;
	sf::Color list[] = {sf::Color(255, 255, 255), sf::Color(0,255,255), sf::Color(255,0,255), sf::Color(255,255,0), sf::Color(0,0,255), sf::Color(0,255,0), sf::Color(255,0,0)};
	int index = 0;
	sf::CircleShape circle(50);
	circle.setFillColor(list[0]);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();				
				
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				index = (index + 1) % (sizeof(list) / sizeof(sf::Color));
				circle.setFillColor(list[index]);
			}
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
            time++;
            circle.setRadius(time);
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            float x = position.x;
            float y = position.y;
            
            circle.setPosition(x - time, y - time);
		}
		else
		{
		    time = 0;
		    circle.setRadius(time);
		}
			
		window.clear(sf::Color::Black);
		window.draw(circle);
		window.display();
		if (quitGame)
			window.close();
	}

	return 0;

}
