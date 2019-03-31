#pragma once
// ParticleSystem.h
#include "Particle.h"
#define maxParticles 50
class ParticleSystem
{
public:
	
	Particle particles[maxParticles];
	sf::Vector2f m_position;
	void initialise(sf::Vector2f t_position)
	{
		m_position=t_position;
		for (int i =0;i<maxParticles;i++)
		{
			particles[i] = Particle(m_position, sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX) * 4 - 2));
		}
	}
	void update()
	{
		for (int i =0;i<maxParticles;i++)
		{
			particles[i].update();		
		}
	}
	void render(sf::RenderWindow &t_window )
	{
		for (int i =0;i<maxParticles;i++)
		{
			particles[i].Draw(t_window);
		}
	}

	ParticleSystem(){}
};

