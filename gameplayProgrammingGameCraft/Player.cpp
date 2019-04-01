#include "Player.h"

Player::Player()
{
	m_rectangle.setSize(sf::Vector2f(20, 20));
	sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setPosition(400, 10);
	m_rectangle.setOrigin(10, 10);
	m_playerState = playerJumpState::Ground;
}

Player::~Player()
{
}
void Player::update(sf::Time t_dt)
{
	time = t_dt.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jump();
	}

	collisions();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x += 1;
		m_rectangle.rotate(3);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x -= 1;
		m_rectangle.rotate(-3);
	}
	else if (m_velocity.x > 0)
	{
		m_velocity.x--;
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x++;
	}
	updateColour();
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

		m_playerState = playerJumpState::Ground;
		m_rectangle.setPosition(m_rectangle.getPosition() + sf::Vector2f((m_velocity * time)) + (m_acceleration * (time * time)));
		m_velocity = m_velocity + (m_acceleration * time);
	}
	else
	{
		m_playerState = playerJumpState::Air;

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

void Player::jump()
{
	if (colliding == true)
	{
		colliding = false;

		m_velocity.y = -100;
	}
}
void Player::reset(sf::Vector2f t_position, int t_win)
{
	
	m_rectangle.setPosition(sf::Vector2f(t_position.x,10));
	if (t_win == 1)
	{
		// velocity.y doesn't change
	}
	else
	{
		m_velocity = sf::Vector2f(0, 0);
	}
}

sf::RectangleShape Player::getBody() const
{
	return m_rectangle;
}


void Player::changeColor()
{
	m_newColor = sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
}

void Player::updateColour()
{
	if (m_color == m_newColor)
	{
		changeColor();
	}
	if (m_color.r > m_newColor.r)
	{
		m_color.r--;
	}
	else if (m_color.r < m_newColor.r)
	{
		m_color.r++;
	}

	if (m_color.g > m_newColor.g)
	{
		m_color.g--;
	}
	else if (m_color.g < m_newColor.g)
	{
		m_color.g++;
	}
	if (m_color.b > m_newColor.b)
	{
		m_color.b--;
	}
	else if (m_color.b < m_newColor.b)
	{
		m_color.b++;
	}
	m_rectangle.setFillColor(m_color);
}