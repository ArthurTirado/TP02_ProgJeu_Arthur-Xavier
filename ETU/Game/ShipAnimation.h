#pragma once
#include "InputBasedAnimation.h"
#include "LinearAnimation.h"
#include "ContentManager.h"

class ShipAnimation
	: public InputBasedAnimation, public LinearAnimation
{
public:	
	static const int NEUTRAL_ANIMATION_LENGTH_IN_SECONDS;
	static const int NBS_NEUTRAL_ANIMATION_FRAMES;
public:
	ShipAnimation(sf::Sprite& sprite);
	virtual void adjustNextFrame(const Inputs& inputs) override;
	virtual void update(float deltaT, const Inputs& inputs) override;
	virtual bool init(const ContentManager& contentManager) override;
private:
	int nbFrameInStateX;

	sf::IntRect	hardLeft = sf::IntRect(182, 87, 13, 27);
	sf::IntRect left = sf::IntRect(156, 87, 17, 28);
	sf::IntRect neutral1 = sf::IntRect(36, 87, 22, 27);
	sf::IntRect neutral2 = sf::IntRect(7, 87, 22, 27);
	sf::IntRect neutral3 = sf::IntRect(65, 87, 22, 29);
	sf::IntRect neutral4 = sf::IntRect(95, 87, 22, 30);
	sf::IntRect right = sf::IntRect(225, 87, 17, 28);
	sf::IntRect hardRight = sf::IntRect(203, 87, 13, 27);
};

