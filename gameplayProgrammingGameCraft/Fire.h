#pragma once

#include "Particle.h"
#define maxParticles 40
class Fire
{
public:
	
	Particle particles[maxParticles];
	sf::Vector2f m_position;

	void Initialise(sf::Vector2f pos, bool t_menu)
	{
		m_position=pos;
		for (int i =0;i<maxParticles;i++)
		{
			particles[i] = Particle(m_position,sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX)*4-2));
			if (t_menu)
			{
				particles[i].changeBool();
			}
		}
		
	}
	void update()
	{
		for (int i =0;i<maxParticles;i++)
		{
			particles[i].update();
		}
	}
	void render(sf::RenderWindow &win )
	{
		for (int i =0;i<maxParticles;i++)
		{
			particles[i].Draw(win);
		}
	}

	void reset()
	{
		for (int i = 0; i<maxParticles; i++)
		{
			if (particles[i].timetoLiveLeft() <= 0)
			{
				particles[i] = Particle(m_position, sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX) * 4 - 2));
			}
		}
	}

	void reset(sf::Vector2f t_position)
	{
		
		for (int i = 0; i<maxParticles; i++)
		{
			if (particles[i].timetoLiveLeft() <= 0)
			{
				m_position = t_position;
				particles[i] = Particle(t_position, sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX) * 4 - 2));
			}
		}
	}
	Fire(){}
};

