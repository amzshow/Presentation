#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

bool quitGame = false;

class Board
{
private:
	sf::RenderWindow *window;
	sf::RectangleShape block[3][3];
	sf::RectangleShape line;
	int map[3][3];
	float sizeX;
	float sizeY;
	bool player1Turn;
	bool gameOver;
	int winner;
	sf::Font font;
	int availablePositions;
	sf::Text text;
	sf::Texture texture1;
	sf::Texture texture2;
public:
	Board(sf::RenderWindow *window, float sizeX, float sizeY)
	{
	
		//Load resources
	    if (!font.loadFromFile("font.ttf"))
    	    return;
    	if(!texture1.loadFromFile("X.jpg"))
    		return;
    	if(!texture2.loadFromFile("O.jpg"))
    		return;
	
		//Info
		this->winner = -1;
		this->window = window;
		this->gameOver = false;
		this->text.setFont(font);
		this->player1Turn = true;
		this->availablePositions = 9;
		this->sizeX = (float)((int)(sizeX));
		this->sizeY = (float)((int)(sizeY));
		
		//Text
		this->text.setCharacterSize(64);
		this->text.setString("Player 1 Turn");
		this->text.setFillColor(sf::Color::Yellow);
		this->text.setPosition(50, (sizeY * 3) + 10);
		
		//Line
		this->line.setSize(sf::Vector2f(10, sizeY * 3));
		this->line.setFillColor(sf::Color::Red);
		this->line.setPosition(sf::Vector2f(-100, -100));
		
		//Texture
		this->texture1.setSmooth(true);
		this->texture2.setSmooth(true);
		
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{				
				map[i][j] = 0;
				
				sf::Vector2f bSize(sizeX, sizeY);
				block[i][j].setSize(bSize);
				
				sf::Vector2f position((j * sizeX) + j, (i * sizeY) + i);
				block[i][j].setPosition(position.x, position.y);
			}
		}
	}
	
	sf::RectangleShape getBlock(int i, int j)
	{
		return block[i][j];
	}
	
	bool checkWinner()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int player = 1; player <= 2; player++)
			{	
				if((map[i][0] == player && map[i][1] == player && map[i][2] == player))	//left right win
				{
					line.setPosition(0, block[i][0].getPosition().y + (block[i][0].getSize().y / 2));
					line.rotate(-90);
					winner = player;
					return true;					
					
				}
				else if((map[0][i] == player && map[1][i] == player && map[2][i] == player)) //up down win
				{
					line.setPosition(block[0][i].getPosition().x + (block[0][i].getSize().x / 2), 0);
					winner = player;
					return true;
				}
				else if((map[0][0] == player && map[1][1] == player && map[2][2] == player))
				{
					line.setPosition(block[0][0].getPosition().x + (block[0][0].getSize().x / 2), block[0][0].getPosition().y + (block[0][0].getSize().y / 2));
					line.rotate(-45);
					winner = player;
					return true;
				}
				else if((map[0][2] == player && map[1][1] == player && map[2][0] == player) )
				{
					line.setPosition(block[0][2].getPosition().x + (block[0][2].getSize().x / 2), block[0][2].getPosition().y + (block[0][2].getSize().y / 2));
					line.rotate(45);
					winner = player;
					return true;
				}
			}
		}
		return false;
	}
	
	void update()
	{
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		sf::RectangleShape temp;
		sf::Vector2f tempSize(1, 1);
		temp.setSize(tempSize);
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				temp.setPosition(pos.x, pos.y);
				if(block[i][j].getGlobalBounds().intersects(temp.getGlobalBounds()))
				{
					if(map[i][j] != 0)
						return;
					
					availablePositions--;
					if(player1Turn)
					{
						this->text.setString("Player 2 Turn");
						block[i][j].setTexture(&texture1);
						map[i][j] = 1;
					}
					else
					{
						this->text.setString("Player 1 Turn");
						block[i][j].setTexture(&texture2);
						map[i][j] = 2;
					}
					
					player1Turn = !player1Turn;
					
					checkGameOver();
					
					std::cout << i << ' ' << j << std::endl;
										
					return;
				}
	        }
        }
	}
	
	void checkGameOver()
	{
		if(getAvailablePositions() < 1 || checkWinner())
				setGameOver(true);
		if(gameOver)
		{
			if(winner == 0)
				text.setString("Draw");
			else if(winner == 1)
				text.setString("Player 1 Wins");
			else
				text.setString("Player 2 Wins");
		}
		
	}
	
	int getAvailablePositions()
	{
		return availablePositions;
	}
	
	void setGameOver(bool b)
	{	
		gameOver = b;
	}
	
	bool getGameOver()
	{
		return gameOver;
	}
		
	int getWinnder()
	{
		return winner;
	}
		
	void draw()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				window->draw(block[i][j]);
			}
		}
		window->draw(text);
		window->draw(line);
	}

};

int main()
{

	const int WIDTH = 600;
	const int HEIGHT = 800;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TicTacToe");
	window.setFramerateLimit(120);

	Board board(&window, WIDTH  / 3, (HEIGHT - 200) / 3);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();				
				
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(!board.getGameOver())
					board.update();
			}
		}
		
		if(board.getGameOver())
		{
			//quitGame = true;
		}
					
		window.clear(sf::Color::Black);
		board.draw();
		window.display();
		if (quitGame)
			window.close();
	}

	return 0;

}
