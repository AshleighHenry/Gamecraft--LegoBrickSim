#include "Player.h"

Player::Player()
{
	m_rectangle.setSize(sf::Vector2f(10, 10));
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setPosition(10, 10);
}

Player::~Player()
{
}

void Player::update(sf::Time t_dt)
{
	time = t_dt.asSeconds();

	collisions();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_velocity.x += 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_velocity.x -= 1;
	}
	else if (m_velocity.x > 0)
	{
		m_velocity.x--;
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x++;
	}
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_rectangle);
}

void Player::collisions()
{
	if (colliding)
	{
		m_velocity.y = 0;
		m_acceleration.y = 0;

		m_rectangle.setPosition(m_rectangle.getPosition() + sf::Vector2f((m_velocity * time)) + (m_acceleration * (time * time)));
		m_velocity = m_velocity + (m_acceleration * time);
	}
	else
	{
		m_rectangle.setPosition(m_rectangle.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * m_gravity * (time * time)));
		m_velocity = m_velocity + (m_gravity * time);
	}

}

void Player::activeCollision()
{
	colliding = true;
}

void Player::deactiveCollision()
{
	colliding = false;
}

sf::RectangleShape Player::getBody() const
{
	return m_rectangle;
}
