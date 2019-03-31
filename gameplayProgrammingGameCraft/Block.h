#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

class Block
{
public:
	Block(int t_colour, int t_size, sf::Vector2f t_position);
	~Block();

	void setPosition(sf::Vector2f t_position);
	void render(sf::RenderWindow & t_window);
	sf::Vector2f getPosition();
	int getWidth();

	sf::Sprite const getSprite();


	bool collisions(Player & t_player);

private:
	sf::Texture m_texture;
	sf::Sprite m_blockSprite;
	sf::IntRect m_blockRect;

	int m_colour{ 0 };
	int m_size{ 5 };
	int m_width{ 0 };
	sf::Vector2f m_position;

	void initialise();
};

