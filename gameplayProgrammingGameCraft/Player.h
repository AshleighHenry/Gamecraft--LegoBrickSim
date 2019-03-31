#ifndef PLAYER
#define PLAYER

#include <SFML\Graphics.hpp>
#include <iostream>

enum playerJumpState
{
	Ground,
	Air
};

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time t_dt);
	void render(sf::RenderWindow & t_window);

	void collisions();
	void activeCollision();
	void deactiveCollision();

	void jump();

	sf::RectangleShape const getBody();

private:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	sf::RectangleShape m_rectangle;

	const sf::Vector2f m_gravity{ 0, 90.8f };

	sf::Vector2f m_velocity{ 0,0 };

	sf::Vector2f m_acceleration{ 0,0 };

	float time;

	bool colliding{ false };

	playerJumpState m_playerState{ playerJumpState::Air };
};
#include "Block.h"

#endif // !Player