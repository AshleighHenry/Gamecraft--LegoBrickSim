#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <SFML\Audio.hpp>
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
	void changeActive();
	bool getActive();
	void reset(int t_size);
private:
	sf::Texture m_texture;
	sf::Sprite m_blockSprite;
	sf::IntRect m_blockRect;
	bool m_active = false;

	int m_colour{ 0 };
	int m_size{ 5 };
	int m_width{ 0 };
	sf::Vector2f m_position;
	sf::SoundBuffer m_selectBuffer;
	sf::Sound m_select;
	void initialise();
};

