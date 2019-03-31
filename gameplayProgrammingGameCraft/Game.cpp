#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 1024, 720 }, "SMFL Game" }
{
	m_splashscreen = new SplashScreen(*this);

	srand(static_cast<unsigned>(time(NULL)));

	for (int i = 0; i < s_MAX_BLOCKS; i++)
	{
		m_blocks[i] = new Block((rand() % 6), (rand() % 6) + 1,
			sf::Vector2f(0, -10));
	}
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		m_mousePos =  sf::Mouse::getPosition(m_window);

		if (event.type == sf::Event::Closed || m_gameState == GameState::EXIT)
		{
			m_window.close();
		}

		switch (m_gameState)
		{
		case GameState::SPLASH_SCREEN:
			break;
		case GameState::MAIN_MENU:
			m_menu.processEvents(event);
			break;
		case GameState::PLAY:
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if(event.key.code == sf::Mouse::Left)
				{
					if (m_currentBlock < s_MAX_BLOCKS)
					{
						m_blocks[m_currentBlock]->changeActive();
						m_currentBlock++;
					}
				}
			}
			break;
		case GameState::CREDITS:
			m_credits.processEvents(event, m_gameState);
			break;
		case GameState::EXIT:
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time dt)
{
	int index = 0;
	if (index <= 30)
	{
		index = 0;
	}
	switch (m_gameState)
	{
	case GameState::SPLASH_SCREEN:
		m_splashscreen->update();
		break;
	case GameState::MAIN_MENU:
		m_menu.update(m_gameState);
		break;
	case GameState::PLAY:
		m_player.update(dt);

		for (int i = 0; i < s_MAX_BLOCKS; i++)
		{
			if (m_blocks[i]->getActive())
			{
				if (m_blocks[i]->collisions(m_player))
				{
					break; // break when colliding
				}
				
			}
		}

		break;
	case GameState::CREDITS:
		break;
	case GameState::EXIT:
		break;
	default:
		break;
	}
	m_blocks[m_currentBlock]->setPosition( static_cast<sf::Vector2f>(m_mousePos));

}

void Game::render()
{
	m_window.clear(sf::Color::White);

	switch (m_gameState)
	{
	case GameState::SPLASH_SCREEN:

		m_splashscreen->render(m_window);

		break;
	case GameState::MAIN_MENU:
		m_menu.render(m_window);
		break;
	case GameState::PLAY:
		for (int i = 0; i <s_MAX_BLOCKS; i++)
		{
			m_blocks[i]->render(m_window);
		}
		m_player.render(m_window);
		break;
	case GameState::CREDITS:
		m_credits.render(m_window);
		break;
	case GameState::EXIT:
		break;
	default:
		break;
	}


	m_window.display();
}

void Game::reset()
{

}
