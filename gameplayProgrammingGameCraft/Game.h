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
#include "CheckPoint.h"


#include "Sparkle.h"
class SplashScreen;
class Player;

class Game
{
public:
	Game();
	void run();
	GameState m_gameState = GameState::SPLASH_SCREEN;
private:
	sf::Texture m_backgroundText;
	sf::Sprite m_background;
	void processEvents();
	void update(sf::Time dt);
	void render();
	void reset();
	Menu m_menu;
	sf::RenderWindow m_window;
	sf::Font m_font;
	SplashScreen * m_splashscreen;
	Credits m_credits;
	sf::Vector2i m_mousePos;
	//Block * m_block;
	int m_currentBlock = 0; // the block the player can currently spawn
	Player m_player;
	static const int s_MAX_BLOCKS = 7;
	Block * m_blocks[s_MAX_BLOCKS];
	CheckPoint * m_checkPoint;

	int particleCounter;
	Sparkle m_checkpointParticles;
	sf::Text m_blocksLeft;
	sf::Text m_score;
	int m_playerScore = 0;

	sf::SoundBuffer m_winBuffer;
	sf::SoundBuffer m_loseBuffer;

	sf::Sound m_win;
	sf::Sound m_lose;
};

#endif // !GAME
