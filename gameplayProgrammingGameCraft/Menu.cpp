#include "Menu.h"

Menu::Menu()
{
	m_selected = 0;
	m_buttonSize = sf::Vector2f(300, 70);
	m_buttonPositionStart = sf::Vector2f(200, 200);
	for (int i = 0; i < S_MENU_BUTTONS; i++)
	{
		m_buttons[i].setPosition(m_buttonPositionStart.x + (i * 100), m_buttonPositionStart.y + (i * 100));
		m_buttons[i].setFillColor(sf::Color::Red);
		m_buttons[i].setSize(m_buttonSize);
	}
	m_cursor.setPosition(m_buttonPositionStart);
	m_cursor.setFillColor(sf::Color::Black);
	m_cursor.setOrigin(5, 5);
	m_cursor.setRadius(10);

	if (!m_font.loadFromFile("Resources\\Fonts\\LEGO BRIX.ttf"))
	{//error
	}
	if (!m_backgroundText.loadFromFile("Resources\\Images\\SplashScreenIMG.png"))
	{
	}
	else
	{
		m_backgroundSprite.setTexture(m_backgroundText);
		m_backgroundSprite.setPosition(sf::Vector2f(0.0f, 0.0f));
		m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1024, 720));
	}

	for (int i = 0; i < S_MENU_BUTTONS; i++)
	{
		m_messages[i].setFont(m_font);
		m_messages[i].setFillColor(sf::Color::White);
		m_messages[i].setCharacterSize(60);
		m_messages[i].setPosition(m_buttonPositionStart.x + +20 + (i * 100), m_buttonPositionStart.y + 5 + (i * 100));
	}
	m_messages[0].setString("PLAY!");
	m_messages[1].setString("CREDITS");
	m_messages[2].setString("EXIT");

	if (!m_selectBuffer.loadFromFile("Resources\\Sounds\\Select.wav"))
	{
	}
	m_select.setBuffer(m_selectBuffer);
	if (!m_switchBuffer.loadFromFile("Resources\\Sounds\\Switch.wav"))
	{
	}
	m_switch.setBuffer(m_switchBuffer);
}

void Menu::processEvents(sf::Event & t_event)
{
	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::Down)
		{
			m_downPressed = true;
			m_switch.play();
		}
		if (t_event.key.code == sf::Keyboard::Up)
		{
			m_upPressed = true;
			m_switch.play();
		}
		if (t_event.key.code == sf::Keyboard::Space)
		{
			m_spacePressed = true;
			m_select.play();
		}

	}

}

void Menu::update(GameState & t_gamestate)
{
	changeSelected();
	for (int i = 0; i < S_MENU_BUTTONS; i++)
	{
		if (i == m_selected)
		{
			m_buttons[i].setFillColor(sf::Color::Blue);
		}
		else
		{
			m_buttons[i].setFillColor(sf::Color::Red);
		}
	}
	if (m_spacePressed)
	{
		switch (m_selected)
		{
		case 0:
			t_gamestate = GameState::PLAY;
			m_spacePressed = false;
			break;
		case 1:
			t_gamestate = GameState::CREDITS;
			m_spacePressed = false;
			break;
		case 2:
			t_gamestate = GameState::EXIT;
			m_spacePressed = false;
		default:
			break;
		}
	}

}

void Menu::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	for (int i = 0; i < S_MENU_BUTTONS; i++)
	{
		t_window.draw(m_buttons[i]);
		t_window.draw(m_messages[i]);
	}
	t_window.draw(m_cursor);

}

void Menu::changeSelected()
{
	if (m_downPressed)
	{
		if (m_selected == 2)
		{
			m_selected = 0;
		}
		else
		{
			m_selected++;
		}
		m_downPressed = false;
	}
	if (m_upPressed)
	{
		if (m_selected == 0)
		{
			m_selected = 2;
		}
		else
		{
			m_selected--;
		}
		m_upPressed = false;
	}
	m_cursor.setPosition(m_buttonPositionStart.x + (m_selected * 100),
		m_buttonPositionStart.y + (m_selected * 100 + (m_buttonSize.y / 2)));
}

sf::Vector2f Menu::getCursorPosition()
{
	return m_cursor.getPosition();
}
