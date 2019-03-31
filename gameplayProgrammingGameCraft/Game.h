#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <list>
#include "Enums.h"
#include "Menu.h"
#include "SplashScreen.h"
#include "Player.h"
#include "Block.h"
#include "Credits.h"
class SplashScreen;
class Player;

class Game
{
public:
	Game();
	void run();
	GameState m_gameState = GameState::MAIN_MENU;
private:
	void processEvents();
	void update(sf::Time dt);
	void render();
	void reset();
	Menu m_menu;
	sf::RenderWindow m_window;
	sf::Font m_font;
	SplashScreen * m_splashscreen;
	Credits m_credits;

	Block * m_block;

	Player m_player;

	Block * m_blocks[30];
	std::list<Block> m_madeBlocks;

};

#endif // !GAME
