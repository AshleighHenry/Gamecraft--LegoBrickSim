#include "Game.h"
#include <iostream>


#include "Sparkle.h"


Game::Game() :
	m_window{ sf::VideoMode{ 1024, 720 }, "SMFL Game" }
{
	if (!m_backgroundText.loadFromFile("Resources\\Images\\SplashScreenIMG.png"))
	{
		std::cout << "error : splash screen img not loading" << std::endl;
	}
	m_background.setTexture(m_backgroundText);
	if (!m_font.loadFromFile("Resources\\Fonts\\LEGO BRIX.ttf"))
	{//error
	}
	m_blocksLeft.setFont(m_font);
	m_blocksLeft.setString("Available Blocks : " + std::to_string(s_MAX_BLOCKS - m_currentBlock));
	m_blocksLeft.setCharacterSize(20);
	m_blocksLeft.setPosition(500, 25);
	m_blocksLeft.setFillColor(sf::Color::Black);

	m_score.setFont(m_font);
	m_score.setString("Score : ");
	m_score.setCharacterSize(20);
	m_score.setPosition(500, 50);
	m_score.setFillColor(sf::Color::Black);

	m_splashscreen = new SplashScreen(*this);

	srand(static_cast<unsigned>(time(NULL)));

	for (int i = 0; i < s_MAX_BLOCKS; i++)
	{
		m_blocks[i] = new Block((rand() % 6), (rand() % 6) + 1,
			sf::Vector2f(0, -30));
	}
	m_checkPoint = new CheckPoint(sf::Vector2f(rand() % 980 + 20, 200 + rand() % 500));

	
	particleCounter = 0;
	m_checkpointParticles.Initialise( m_checkPoint->getPosition());
	
	if (!m_winBuffer.loadFromFile("Resources\\Sounds\\resetWin.wav"))
	{
	}
	m_win.setBuffer(m_winBuffer);
	if (!m_loseBuffer.loadFromFile("Resources\\Sounds\\lose2.wav"))
	{
	}
	m_lose.setBuffer(m_loseBuffer);
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
		if (event.type == sf::Event::MouseButtonPressed && m_gameState == GameState::PLAY)
		{
			if (event.key.code == sf::Mouse::Left)
			{	
				if (m_currentBlock < s_MAX_BLOCKS )
				{
					m_blocks[m_currentBlock]->changeActive();
					m_currentBlock++;
					m_blocksLeft.setString("Available Blocks : " + std::to_string(s_MAX_BLOCKS - m_currentBlock));
				}
			}
		}
		switch (m_gameState)
		{
		case GameState::SPLASH_SCREEN:
			m_splashscreen->update(event);
			break;
		case GameState::MAIN_MENU:
			m_menu.processEvents(event);
			break;
		case GameState::PLAY:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_gameState = GameState::MAIN_MENU;
				reset();
				m_player.reset(m_checkPoint->getPosition(), 0);
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
	m_score.setString("Score : " + std::to_string(m_playerScore));
	if (index <= 30)
	{
		index = 0;
	}
	switch (m_gameState)
	{
	case GameState::SPLASH_SCREEN:
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
		if (m_checkPoint->checkCollision(m_player))
		{
			m_player.reset(m_checkPoint->getPosition(), 1);
			m_playerScore++;
			m_win.play();
			reset();
		}
		if (m_player.getBody().getPosition().y > 720)
		{
			m_player.reset(m_checkPoint->getPosition(), 0);
			if (m_playerScore > 0)
			{
				m_playerScore--;
				
			}
			m_lose.play();
			reset();
		}
		m_checkpointParticles.update();
		m_checkpointParticles.reset();
		m_player.update(dt);
		m_checkPoint->update();
		
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
		m_window.draw(m_background);
		for (int i = 0; i <s_MAX_BLOCKS; i++)
		{
			m_blocks[i]->render(m_window);
		}
		m_player.render(m_window);
		m_checkPoint->render(m_window);
		m_checkpointParticles.render(m_window);
		m_window.draw(m_blocksLeft);
		m_window.draw(m_score);
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
	m_checkPoint = new CheckPoint(sf::Vector2f(rand() % 980 + 20,200 + rand() % 500 ));
	m_checkpointParticles.Initialise(m_checkPoint->getPosition());
	for (int i = 0; i < s_MAX_BLOCKS; i++)
	{
		m_blocks[i]->reset((rand() % 6));

		m_currentBlock = 0;
	}
	
	m_blocksLeft.setString("Available Blocks : " + std::to_string(s_MAX_BLOCKS - m_currentBlock));
}
