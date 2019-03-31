#pragma once
#include "Player.h"
class CheckPoint
{
public:
	CheckPoint(sf::Vector2f t_position);
	
	void setPosition(sf::Vector2f t_position);
	void update();
	bool checkCollision(Player &t_player);
	void render(sf::RenderWindow &t_window);
	void changeColor();
	void updateColour();
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_size;
	sf::Color m_color;
	sf::Color m_newColor;
};

