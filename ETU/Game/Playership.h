#pragma once
#include "InputBasedAnimation.h"
#include "CyclicAnimation.h"

class Playership
	: public InputBasedAnimation, public CyclicAnimation
{
public:
	Playership(sf::Sprite& sprite);
	virtual void adjustNextFrame(const Inputs& inputs) override;
	virtual void init();
private:
	int nbFrameInState;
	sf::IntRect hardLeft;
	sf::IntRect left;
	sf::IntRect neutral1;
	sf::IntRect neutral2;
	sf::IntRect neutral3;
	sf::IntRect neutral4;
	sf::IntRect right;
	sf::IntRect hardRight;
};

