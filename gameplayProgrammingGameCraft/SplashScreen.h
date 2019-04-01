#ifndef SPLASH
#define SPLASH

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Game.h"

class Game;

class SplashScreen
{
public:
	SplashScreen(Game & t_game);
	~SplashScreen();

	void update(sf::Event &t_event);
	void render(sf::RenderWindow & t_window);

private:

	void loadAssets();

	Game & m_game;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundText;

	sf::Font m_font;
	sf::Text m_msg;
};
#endif //SPLASH