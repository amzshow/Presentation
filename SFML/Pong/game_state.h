#pragma once
#include <SFML/Graphics.hpp>

class tinyState
{
public:
	virtual void initialize(sf::RenderWindow *window)
	{

	}

	virtual void update(sf::RenderWindow *window)
	{

	}

	virtual void render(sf::RenderWindow *window)
	{

	}

	virtual void destroy(sf::RenderWindow *window)
	{

	}
};

class game_state
{
private:
	tinyState *state;
	sf::RenderWindow *window;
public:
	game_state()
	{
		this->state = NULL;
	}

	void setState(tinyState *state)
	{
		if (this->state != NULL)
			this->state->destroy(this->window);
		this->state = state;
		if (this->state != NULL)
			this->state->initialize(this->window);
	}

	void setWindow(sf::RenderWindow *window)
	{
		this->window = window;
	}

	void update()
	{
		if (this->state != NULL)
			this->state->update(this->window);
	}

	void render()
	{
		if (this->state != NULL)
			this->state->render(this->window);
	}

	~game_state()
	{
		if (this->state != NULL)
			this->state->destroy(this->window);
	}
};

extern game_state coreState;
extern bool  quitGame;
