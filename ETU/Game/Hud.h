#pragma once
#include "game.h"

class ContentManager;
class HealthBonus;
class WeaponBonus;

class Hud
{
public:
	static const float SYMBOL_SCALE;
	static const float BOTTOM_MARGIN;
	Hud();
	void draw(sf::RenderWindow& window)  const;
	void initialize(const ContentManager& contentManager);
	void update(int points, int hp, int gunHP);
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

