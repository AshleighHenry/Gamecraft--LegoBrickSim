#pragma once
#include <SFML\Graphics.hpp>
#include "Enums.h"
#include <SFML\Audio.hpp>
class Menu
{
public:
	Menu();
	void processEvents(sf::Event &t_event);
	void update(GameState &t_gamestate);
	void render(sf::RenderWindow &t_window);
	void changeSelected();

private:
	sf::Vector2f m_buttonPositionStart = sf::Vector2f(200, 200);
	static const int S_MENU_BUTTONS = 3;
	sf::RectangleShape m_buttons[S_MENU_BUTTONS];
	int m_selected = 0;
	sf::Vector2f m_buttonSize;


	sf::Font m_font;
	sf::Text m_messages[S_MENU_BUTTONS];
	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundText;

	sf::CircleShape m_cursor;
	sf::Vector2f m_cursorPosition;
	bool m_upPressed = false;
	bool m_downPressed = false;
	bool m_spacePressed = false;

	//sf::SoundBuffer m_selectBuffer;
	//sf::SoundBuffer m_switchBuffer;

	//sf::Sound m_select;
	//sf::Sound m_switch;
};
