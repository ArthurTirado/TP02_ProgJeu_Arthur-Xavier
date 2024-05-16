#pragma once
#include "AnimatedGameObject.h"
class Bonus 
	: public AnimatedGameObject
{
public:
	Bonus();
	virtual bool update(float deltaT) override;
	virtual bool init(const ContentManager& contentManager);
	void playSound();
	void setPosition();
	static const unsigned int BONUS_POINTS;
protected:
	sf::Sound bonusSFX;
	sf::SoundBuffer bonusSFXBuffer;
	sf::RectangleShape spriteHitbox;
	sf::Sprite bonusSprite;
private:

};

