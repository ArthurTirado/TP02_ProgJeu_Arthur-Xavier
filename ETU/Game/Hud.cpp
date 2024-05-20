#include "stdafx.h"
#include "Hud.h"
#include "ContentManager.h"
#include "HealthBonus.h"

Hud::Hud()
{
}

void Hud::draw(sf::RenderWindow& window) const
{
}

void Hud::initialize(const ContentManager& contentManager)
{
	hudView = sf::View(sf::FloatRect(0, 0, (float)Game::GAME_WIDTH, (float)Game::GAME_HEIGHT));

	pointsText.setString("00000");
	pointsText.setFont(contentManager.getMainFont());
	pointsText.setCharacterSize(22);
	pointsText.setFillColor(sf::Color::White);
	pointsText.setOutlineThickness(4);
	pointsText.setPosition(0, 0);

	gunHPText.setString("000");
	gunHPText.setFont(contentManager.getMainFont());
	gunHPText.setCharacterSize(22);
	gunHPText.setFillColor(sf::Color::White);
	gunHPText.setOutlineThickness(4);
	gunHPText.setPosition(Game::GAME_WIDTH - gunHPText.getGlobalBounds().width, 0);

	gunHPSymbol.setTexture(contentManager.getMiscTexture());
	gunHPSymbol.setTextureRect(sf::IntRect(311, 64, 13, 10));
	gunHPSymbol.setPosition(Game::GAME_WIDTH - gunHPText.getGlobalBounds().width - gunHPSymbol.getGlobalBounds().width, 0);

	hpText.setString("10000");
	hpText.setFont(contentManager.getMainFont());
	hpText.setCharacterSize(22);
	hpText.setFillColor(sf::Color::White);
	hpText.setOutlineThickness(4);
	hpText.setPosition(Game::GAME_WIDTH - gunHPText.getGlobalBounds().width - gunHPSymbol.getGlobalBounds().width - hpText.getGlobalBounds().width, 0);

	hpSymbol.setTexture(contentManager.getMiscTexture());
	hpSymbol.setTextureRect(sf::IntRect(229, 64, 10, 9));
	hpSymbol.setPosition(Game::GAME_WIDTH - gunHPText.getGlobalBounds().width - gunHPSymbol.getGlobalBounds().width - hpText.getGlobalBounds().width - hpSymbol.getGlobalBounds().width, 0);
}

void Hud::update(int points, int hp, int gunHP)
{
	changeNbPoints(points);
	changeHp(hp);
	changeHpAddtionnalGuns(gunHP);
}

void Hud::changeNbPoints(int points)
{
	pointsText.setString(std::to_string(points));
}

void Hud::changeHp(int HP)
{
	hpText.setString(std::to_string(HP));
}

void Hud::changeHpAddtionnalGuns(int gunHP)
{
	gunHPText.setString(std::to_string(gunHP));
}
