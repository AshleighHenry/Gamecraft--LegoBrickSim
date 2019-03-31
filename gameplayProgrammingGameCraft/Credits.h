#pragma once
#include <SFML\Graphics.hpp>
#include "Enums.h"
class Credits
{
public:
	Credits();
	void render(sf::RenderWindow &t_window);
	void processEvents(sf::Event &t_event, GameState &t_gameState);


private:
	sf::Font m_font;
	sf::Text m_creditText;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundText;

};
