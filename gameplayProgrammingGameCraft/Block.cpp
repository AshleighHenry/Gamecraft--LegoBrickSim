#include "Block.h"



Block::Block(int t_colour, int t_size, sf::Vector2f t_position)
	: m_colour{ t_colour }
	, m_size{ t_size }
	, m_position{ t_position }
{
	if (!m_texture.loadFromFile("Resources\\Images\\spritesheet.png"))
	{
		cout << "block not lodeded" << endl;
	}
	if (!m_selectBuffer.loadFromFile("Resources\\Sounds\\Select.wav"))
	{
	}
	m_select.setBuffer(m_selectBuffer);
	m_blockSprite.setTexture(m_texture);
	switch (m_size)
	{
	case 0:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 0, 31 };
		m_width = 0;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 1:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 26, 31 };
		m_width = 26;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 2:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 50, 31 };
		m_width = 50;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 3:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 73, 31 };
		m_width = 73;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 4:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 97, 31 };
		m_width = 97;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 5:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 120, 31 };
		m_width = 120;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	case 6:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 146, 31 };
		m_width = 146;
		m_blockSprite.setTextureRect(m_blockRect);
		break;
	default:
		break;
	}
	m_blockSprite.setPosition(m_position);
	m_blockSprite.setOrigin(m_blockRect.width / 2, m_blockRect.height / 2);

	//initialise();
}


Block::~Block()
{
}

void Block::setPosition(sf::Vector2f t_position)
{
	m_blockSprite.setPosition(t_position);
}

void Block::render(sf::RenderWindow & t_window)
{
	if (m_active ==false)
	{
		m_blockSprite.setColor(sf::Color(255, 255, 255, 130));
	}
	else
	{
		m_blockSprite.setColor(sf::Color(255, 255, 255, 255));
	}
	t_window.draw(m_blockSprite);
}

sf::Vector2f Block::getPosition()
{
	return m_position;
}

int Block::getWidth()
{
	return m_width;
}

sf::Sprite const Block::getSprite()
{
	return m_blockSprite;
}

bool Block::collisions(Player & t_player)
{
	if (t_player.getBody().getGlobalBounds().intersects(m_blockSprite.getGlobalBounds()))
	{
   		t_player.activeCollision();

		return true;
	}
	else
	{
		t_player.deactiveCollision();

		return false;
	}

}

void Block::changeActive()
{
	m_active = true;
	m_select.play();
}

bool Block::getActive()
{
	return m_active;
}

void Block::reset(int t_size)
{
	m_active = false;
	m_blockSprite.setPosition(0, -30);
	m_size = t_size;
}

void Block::initialise()
{
	m_blockSprite.setTexture(m_texture);

	switch (m_size)
	{
	case 0:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 0, 31 };
		m_width = 0;
		break;
	case 1:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 26, 31 };
		m_width = 26;
		break;
	case 2:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 50, 31 };
		m_width = 50;
		break;
	case 3:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 73, 31 };
		m_width = 73;
		break;
	case 4:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 97, 31 };
		m_width = 97;
		break;
	case 5:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 120, 31 };
		m_width = 120;
		break;
	case 6:
		m_blockRect = sf::IntRect{ 0, 41 * m_colour, 146, 31 };
		m_width = 146;
		break;
	default:
		break;
	}
	m_blockSprite.setPosition(m_position);
	m_blockSprite.setTextureRect(m_blockRect);
	m_active = true;
}
