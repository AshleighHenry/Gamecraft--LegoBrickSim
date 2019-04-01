#pragma once

// Particle.h
#include <SFML/Graphics.hpp>
class Particle
{
public:
	int timetoLive;
	sf::Vector2f m_velocity;
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	int m_timeAlive = 0; 
	float  dimension = (rand() % 30 *0.2) + 1;
	sf::Color m_color;
	sf::Color m_newColor;
	
	void Draw(sf::RenderWindow& t_window)
	{
		if (timetoLive > 0)
		{
			t_window.draw(m_body);
		}
	}
	void update()
	{
		dimension -= 0.008;
		updateColour();
		if (timetoLive > 0 || m_color.a > 1)
		{
			m_body.move(m_velocity);
			if (dimension > 7)
			{
				m_body.rotate(3);
			}
			else
			{
				m_body.rotate(3);
			}
			timetoLive--;
		}
	}

	int timetoLiveLeft()
	{
		return timetoLive;
	}

	float getDimension()
	{
		return dimension;
	}

	Particle(){}

	Particle(sf::Vector2f pos, sf::Vector2f vel)
	{
		dimension = rand() % 15 + 1;
		m_body.setSize(sf::Vector2f(dimension, dimension));
		m_body.setOrigin(dimension , dimension );
		m_body.setPosition(pos);
		m_position = pos;
		
		m_body.setFillColor(sf::Color(m_color));
		m_velocity = sf::Vector2f((vel.x * 2.5), (vel.y / 1.5f - 3 * 1.5));
		if (dimension < 12)
		{
			m_velocity = sf::Vector2f((vel.x *3), (vel.y / 1.5f - 3 * 0.5));
			timetoLive = rand() % 60 + 5;
		}
		else
		{
			
			m_velocity = sf::Vector2f((vel.x * 0.9f), (vel.y * .05));
			timetoLive = rand() % 100 + 60;
		}
		// 244, 66, 113 237, 109, 142)
		
		m_newColor = sf::Color(rand() % 244+200, rand() % 66+30, rand() % 150 + 70, 255);
		m_color = sf::Color(rand() % 234 + 200, rand() % 109 + 30, rand() % 142 + 70, 255);
	}
	void updateColour()
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
		if (m_color.a > 1)
		{
			if (dimension > 8)
			{
				m_color.a -= 0.005;
			}
			else
			{
				m_color.a -= 0.002;
			}
			
		}
		m_body.setFillColor(m_color);
	}


	void changeColor()
	{
		m_newColor = sf::Color(rand() % 255 + 30, rand() % 255 + 30, rand() % 255 + 30, 255);
	}
};

	