#include "Credits.h"

Credits::Credits()
{
	if (!m_backgroundText.loadFromFile("Resources\\Images\\SplashScreenIMG.png"))
	{

	}
	else
	{
		m_backgroundSprite.setTexture(m_backgroundText);
		m_backgroundSprite.setPosition(sf::Vector2f(0.0f, 0.0f));
		m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1024, 720));
	}

	if (!m_font.loadFromFile("Resources\\Fonts\\LEGO BRIX.ttf"))
	{//error
	}
	m_creditText.setString("GAME MADE BY \n MATEUSZ STEPIEN \n MOHAMMAD ALHOURANI \n ASHLEIGH HENRY\n \n \n \n hit escape");
	m_creditText.setFont(m_font);
	m_creditText.setPosition(sf::Vector2f(200, 100));
	m_creditText.setFillColor(sf::Color::Black);
	m_creditText.setCharacterSize(60);
}

void Credits::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_creditText);
}

void Credits::processEvents(sf::Event & t_event, GameState & t_gameState)
{

	if (t_event.key.code == sf::Keyboard::Escape)
	{
		t_gameState = GameState::MAIN_MENU;
	}


}
