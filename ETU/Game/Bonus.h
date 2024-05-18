#pragma once
#include "AnimatedGameObject.h"
class Bonus 
	: public AnimatedGameObject
{
public:
	static const unsigned int BONUS_POINTS;
public:
	Bonus();
	virtual bool update(float deltaT) override;
	virtual bool init(const ContentManager& contentManager);
	void playSound();
protected:
	sf::Sound bonusSFX;
	sf::SoundBuffer bonusSFXBuffer;
	sf::RectangleShape spriteHitbox;
	sf::Sprite bonusSprite;
private:

};

