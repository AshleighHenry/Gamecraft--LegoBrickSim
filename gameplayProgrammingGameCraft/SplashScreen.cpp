#include "SPLASHSCREEN.H"

SplashScreen::SplashScreen(Game & t_game) :
	m_game(t_game)
{
	loadAssets();
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_game.m_gameState = GameState::MAIN_MENU;
	}
}

void SplashScreen::render(sf::RenderWindow & t_window)
{

	t_window.draw(m_backgroundSprite);
	t_window.draw(m_msg);
}

void SplashScreen::loadAssets()
{
	//
	if (!m_backgroundText.loadFromFile("Resources\\Images\\SplashScreenIMG.png"))
	{
		std::cout << "error : splash screen img not loading" << std::endl;
	}
	else
	{
		m_backgroundSprite.setTexture(m_backgroundText);
		m_backgroundSprite.setPosition(sf::Vector2f(0.0f, 0.0f));
		m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1024, 720));
	}

	if (!m_font.loadFromFile("Resources\\Fonts\\LEGO BRIX.ttf"))
	{
		std::cout << "error : splash screen Font not loading" << std::endl;
	}
	else
	{
		m_msg.setFont(m_font);
		m_msg.setCharacterSize(50);
		m_msg.setFillColor(sf::Color::Black);
		m_msg.setString(sf::String("LEGO \n    BRICK  \n         SIM\n\n\n\n\n\n\n\n press a to continue"));
		m_msg.setPosition(sf::Vector2f(25, 25));
	}
}
