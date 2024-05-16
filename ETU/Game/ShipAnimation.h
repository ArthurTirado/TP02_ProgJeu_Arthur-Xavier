#pragma once
#include "InputBasedAnimation.h"
#include "LinearAnimation.h"
#include "ContentManager.h"

class ShipAnimation
	: public InputBasedAnimation, public LinearAnimation
{
public:
	ShipAnimation(sf::Sprite& sprite);
	virtual void adjustNextFrame(const Inputs& inputs) override;
	virtual void update(float deltaT, const Inputs& inputs) override;
	virtual bool init(const ContentManager& contentManager) override;
private:
	int nbFrameInStateX;
	sf::IntRect hardLeft;
	sf::IntRect left;
	sf::IntRect neutral1;
	sf::IntRect neutral2;
	sf::IntRect neutral3;
	sf::IntRect neutral4;
	sf::IntRect right;
	sf::IntRect hardRight;
};

