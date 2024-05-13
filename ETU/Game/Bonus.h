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
	static const unsigned int BONUS_POINTS;
protected:
	sf::Sound bonusSFX;
	sf::SoundBuffer bonusSFXBuffer;
private:

};

