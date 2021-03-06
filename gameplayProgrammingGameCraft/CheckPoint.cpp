#include "CheckPoint.h"



CheckPoint::CheckPoint(sf::Vector2f t_position)
{
	m_newColor = sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
	m_color = sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
	m_body.setFillColor(m_color);
	m_size = sf::Vector2f(30, 30);
	m_body.setSize(m_size);
	m_body.setOrigin(m_size.x / 2, m_size.y / 2);
	m_body.setPosition(t_position);
	m_size = sf::Vector2f(20+10, 20+10);
	m_bodyTwo.setFillColor(m_color);
	m_bodyTwo.setSize(sf::Vector2f(m_size.x, m_size.y ));
	m_bodyTwo.setOrigin(m_size.x / 2, m_size.y / 2);
	m_bodyTwo.setPosition(t_position);
}

void CheckPoint::setPosition(sf::Vector2f t_position)
{

}

void CheckPoint::update()
{
	m_body.rotate(1.0f);
	m_bodyTwo.rotate(-1.0f);
	updateColour();
}

bool CheckPoint::checkCollision(Player & t_player)
{
	if (t_player.getBody().getGlobalBounds().intersects(m_bodyTwo.getGlobalBounds()))
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
	t_window.draw(m_bodyTwo);
	t_window.draw(m_body);
	
}

void CheckPoint::changeColor()
{
	m_newColor = sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
	m_bodyTwo.setFillColor(m_newColor);
}

void CheckPoint::updateColour()
{
	if (m_color == m_newColor)
	{
		changeColor();
	}
	if (m_color.r > m_newColor.r)
	{
		m_color.r--;
	}
	else if  (m_color.r < m_newColor.r)
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
	m_body.setFillColor(m_color);
}

sf::Vector2f CheckPoint::getPosition()
{
	 return m_body.getPosition();
}

