#include "CheckPoint.h"



CheckPoint::CheckPoint(sf::Vector2f t_position)
{
	m_color = sf::Color::Red;
	m_body.setFillColor(m_color);
	m_size = sf::Vector2f(20, 20);
	m_body.setSize(m_size);
	m_body.setOrigin(m_size.x / 2, m_size.y / 2);
	m_body.setPosition(t_position);
}

void CheckPoint::setPosition(sf::Vector2f t_position)
{

}

void CheckPoint::update()
{
	m_body.rotate(1.0f);
}

bool CheckPoint::checkCollision(Player & t_player)
{
	if (t_player.getBody().getGlobalBounds().intersects(m_body.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CheckPoint::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}

