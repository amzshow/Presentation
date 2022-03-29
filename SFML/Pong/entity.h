#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
private:
	sf::Texture *texture;
protected:
	sf::Vector2f velocity;
public:
	Entity()
	{
		this->texture = new sf::Texture();
	}

	void load(std::string filename)
	{
		this->texture->loadFromFile("Resources/"+filename);
		this->setTexture(*this->texture);
	}

	virtual void update()
	{
		this->move(this->velocity);
	}

	bool checkCollision(Entity *entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity()
	{
		delete this->texture;
	}
};
