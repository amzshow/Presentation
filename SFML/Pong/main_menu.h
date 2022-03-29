#pragma once
#include "game_state.h"

class main_menu : public tinyState
{
public:
	void initialize(sf::RenderWindow *window);
	void update(sf::RenderWindow *window);
	void render(sf::RenderWindow *window);
	void destroy(sf::RenderWindow *window);
private:
	sf::Font *font;
	sf::Text *title;
	sf::Text *play;
	sf::Text *quit;
	int selected;
	bool upKey, downKey;
};