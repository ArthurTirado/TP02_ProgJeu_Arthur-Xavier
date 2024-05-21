#include "stdafx.h"
#include "Hud.h"
#include "ContentManager.h"
//#include "HealthBonus.h"
const float Hud::SYMBOL_SCALE = 2.0f;
const float Hud::BOTTOM_MARGIN = 50;

Hud::Hud()
{

}

void Hud::draw(sf::RenderWindow& window) const
{
	window.setView(hudView);
	window.draw(hpText);
	window.draw(hpSymbol);

	window.draw(pointsText);

	window.draw(gunHPText);
	window.draw(gunHPSymbol);
}

void Hud::initialize(const ContentManager& contentManager)
{
	hudView = sf::View(sf::FloatRect(0, 0, (float)Game::GAME_WIDTH, (float)Game::GAME_HEIGHT));

	pointsText.setString("POINTS: ");
	pointsText.setFont(contentManager.getMainFont());
	pointsText.setCharacterSize(20);
	pointsText.setFillColor(sf::Color::White);
	pointsText.setOutlineThickness(4);
	pointsText.setPosition(BOTTOM_MARGIN, Game::GAME_HEIGHT- BOTTOM_MARGIN);

	gunHPText.setString("");
	gunHPText.setFont(contentManager.getMainFont());
	gunHPText.setCharacterSize(20);
	gunHPText.setFillColor(sf::Color::White);
	gunHPText.setOutlineThickness(4);
	gunHPText.setPosition(400, Game::GAME_HEIGHT - BOTTOM_MARGIN);

	gunHPSymbol.setTexture(contentManager.getMiscTexture());
	gunHPSymbol.setTextureRect(sf::IntRect(248, 104, 16, 16));
	gunHPSymbol.setScale(SYMBOL_SCALE, SYMBOL_SCALE);
	gunHPSymbol.setPosition(350, Game::GAME_HEIGHT - BOTTOM_MARGIN);

	hpText.setString("");
	hpText.setFont(contentManager.getMainFont());
	hpText.setCharacterSize(20);
	hpText.setFillColor(sf::Color::White);
	hpText.setOutlineThickness(4);
	hpText.setPosition(550, Game::GAME_HEIGHT - BOTTOM_MARGIN);

	hpSymbol.setTexture(contentManager.getMiscTexture());
	hpSymbol.setTextureRect(sf::IntRect(229, 64, 11, 9));
	hpSymbol.setScale(SYMBOL_SCALE, SYMBOL_SCALE);
	hpSymbol.setPosition(500, Game::GAME_HEIGHT - BOTTOM_MARGIN);
}

void Hud::update(int points, int hp, int gunHP)
{
	changeNbPoints(points);
	changeHp(hp);
	changeHpAddtionnalGuns(gunHP);
}

void Hud::changeNbPoints(int points)
{
	pointsText.setString("POINTS : " + std::to_string(points));
}

void Hud::changeHp(int HP)
{
	hpText.setString(std::to_string(HP));
}

void Hud::changeHpAddtionnalGuns(int gunHP)
{
	gunHPText.setString(std::to_string(gunHP));
}
