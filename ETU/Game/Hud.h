#pragma once
#include "game.h"

class ContentManager;
class HealthBonus;
class WeaponBonus;

class Hud
{
public:
	Hud();
	void draw(sf::RenderWindow& window)  const;
	void initialize(const ContentManager& contentManager);
	void update(int points, int hp, int gunHP);
	void pauseDraw(sf::RenderWindow& window) const;
private:
	sf::View hudView;
	sf::Text hpText;
	sf::Text gunHPText;
	sf::Text pointsText;
	sf::Sprite hpSymbol;
	sf::Sprite gunHPSymbol;
	void changeNbPoints(int points);
	void changeHp(int HP);
	void changeHpAddtionnalGuns(int gunHP);
};

